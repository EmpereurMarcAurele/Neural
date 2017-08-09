#include "neural.h"

void		back_propagationIH(t_network *network)
{
t_neural	*node_in = network->input_l->start;

	while (node_in)
	{
		t_neural	*node_hi = network->hidden_l->start;
		int i = 0;
		while (node_hi)
		{
		node_in->link[i] += node_hi->d_error * node_in->value * node_in->r_learn;
		node_hi = node_hi->next;
		i++;
		}
	node_in = node_in->next;
	}
}

void		process_hidden_l_error(t_network *network)
{
t_neural	*node_hi = network->hidden_l->start;

	while (node_hi)
		{
		t_neural	*node_out = network->output_l->start;
		int i = 0;
		double tmp = 0;
		while (node_out)
			{
			tmp += node_out->d_error * node_hi->link[i];
			node_out = node_out->next;
			i++;
			}
		node_hi->d_error = node_hi->value * (1 - node_hi->value) * tmp;
		node_hi = node_hi->next;
		}
}

void		back_propagationHO(t_network *network)
{
t_neural	*node_out = network->output_l->start;
int		i = 0;
	while (node_out)
		{
		node_out->d_error = node_out->value * (1 - node_out->value) * (node_out->target - node_out->value);
		t_neural *node_hi = network->hidden_l->start;
		while (node_hi)
			{
			double delta_w = node_hi->r_learn * node_out->d_error * node_hi->value;/*node_hi->value? -> node_out->value?*/
			node_hi->link[i] = node_hi->link[i] + delta_w + (INERTIA * node_hi->prev_delta);
			node_hi->prev_delta = delta_w;
			node_hi = node_hi->next;
			}
		node_out = node_out->next;
		i++;
		}
}

void		get_value_out(t_network *network)
{
t_neural	*node_out = network->output_l->start;
int		i = 0;
	while (node_out)
		{
		t_neural	*node_hi = network->hidden_l->start;
		while (node_hi)
			{
			node_out->w_sum += node_hi->link[i] * node_hi->value;
			node_hi = node_hi->next;
			}
		node_out->value = sigmoid_func(node_out->w_sum);
		node_out = node_out->next;
		i++;
		}
}

void		get_value_hid(t_network *network)
{
t_neural	*node_hi = network->hidden_l->start;
int		i = 0;
	while (node_hi)
		{
		t_neural        *node_in = network->input_l->start;
		while (node_in)
			{
			node_hi->w_sum += (node_in->link[i] * node_in->value);
			node_in = node_in->next;
			}
		node_hi->value = sigmoid_func(node_hi->w_sum);
		node_hi = node_hi->next;
		i++;
		}
}

void	run_network(t_network *network, int nb_it)
{
	int i = 0;
	while (i < nb_it)
	{
		get_value_hid(network);
		get_value_out(network);
		back_propagationHO(network);
		process_hidden_l_error(network);
		back_propagationIH(network);
		i++;
	}
}
