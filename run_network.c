#include "neural.h"

void		back_propagationHO(t_network *network)
{
t_neural	*node_out = network->output_l->start;
int		i = 0;
	while (node_out)
		{
		double m_error = node_out->target - node_out->value;
		double delta_osum = sigmoid_deriv(node_out->w_sum) * m_error;
		t_neural *node_hi = network->hidden_l->start;
		while (node_hi)
			{
			double delta_w = delta_osum / node_hi->value;
			node_hi->link[i] += delta_w;
			node_hi = node_hi->next;
			}
		node_out = node_out->next;
		i++;
		}
}

void		get_hidden_w(t_network *network)
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

void		get_input_w(t_network *network)
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
		get_input_w(network);
		get_hidden_w(network);
		back_propagationHO(network);
		i++;
	}
}
