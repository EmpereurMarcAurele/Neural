#include "neural.h"

void		get_input_w(t_network *network)
{
t_neural	*node_hi = network->hidden_l->start;

	while (node_hi)
		{
		t_neural        *node_in = network->input_l->start;
		while (node_in)
			{
			int r = rand() % 99 + 1;
			node_in->w_out = (double)r / 10;
			node_hi->sum_w += (node_in->w_out * node_in->value);
			node_in = node_in->next;
			}
		node_hi->value = sigmoid_func(node_hi->sum_w);
		node_hi = node_hi->next;
		}
}

void	run_network(t_network *network, int nb_it)
{
	int i = 0;
	while (i < nb_it)
	{
		get_input_w(network);
	}
}
