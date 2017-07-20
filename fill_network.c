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

void	fill_layer_hi(t_layer *layer)
{
	t_neural	*tmp = layer->start;
	while (tmp)
		{
		tmp->link = malloc(sizeof(double) * OUT_NUM);
		int i = 0;
		while (i < OUT_NUM)
			{
			int r = rand() % 9 + 1;
			tmp->link[i] = (double)r / 10;
			i++;
			}
		tmp = tmp->next;
		}
}

void	fill_layer_in(int *tab, t_layer *layer)
{
	t_neural	*tmp = layer->start;
	int i = 0;
	while (tmp)
		{
		tmp->value = (double)tab[i];
		tmp = tmp->next;
		i++;
		}
}

void	fill_network(int *inputs, int *target, t_network *network)
{
	fill_layer_in(inputs, network->input_l);
	fill_layer_hi(network->hidden_l);
	fill_layer_out(target, network->output_l);
}