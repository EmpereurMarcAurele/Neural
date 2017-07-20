#include "neural.h"

void	fill_layer_out(double *tab, t_layer *layer)
{
	t_neural	*tmp = layer->start;
	int i = 0;
	while (tmp)
		{
		tmp->target = tab[i];
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
			printf("link %f ", tmp->link[i]);
			i++;
			}
			printf("\n");
		tmp = tmp->next;
		}
}

void	fill_layer_in(double *tab, t_layer *layer)
{
	t_neural	*tmp = layer->start;
	int i = 0;
	while (tmp)
		{
		tmp->value = tab[i];
		int j = 0;
		tmp->link = malloc(sizeof(double) * HID_NUM);
		while (j < HID_NUM)
			{
			int r = rand() % 9 + 1;
			tmp->link[j] = (double)r / 10;
			printf("link %f ", tmp->link[j]);
			j++;
			}
			printf("\n");
		tmp = tmp->next;
		i++;
		}
}

void	fill_network(double *inputs, double *target, t_network *network)
{
	fill_layer_in(inputs, network->input_l);
	fill_layer_hi(network->hidden_l);
	fill_layer_out(target, network->output_l);
}
