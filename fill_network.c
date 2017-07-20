#include "neural.h"

void	fill_layer_out(int *tab, t_layer *layer)
{
	t_neural	*tmp = layer->start;
	int i = 0;
	while (tmp)
		{
		tmp->target = (double)tab[i];
		tmp = tmp->next;
		i++;
		}
}

void	fill_layer_in(int *tab, t_layer *layer)
{
	t_neural	*tmp = layer->start;
	int i = 0;
	while (tmp)
		{
		tmp->value = (double)tab[i];
		tmp->w_in = 0;
		tmp = tmp->next;
		i++;
		}
}

void	fill_network(int *inputs, int *target, t_network *network)
{
	fill_layer_in(inputs, network->input_l);
	fill_layer_out(target, network->output_l);
}
