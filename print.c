#include "neural.h"

void	print_only_res(t_network *network)
{
t_neural	*node_out = network->output_l->start;

	int i = 0;
	while(node_out)
		{
		printf("nde number %d; value output = %f\n", i, node_out->value);
		node_out = node_out->next;
		i++;
		}
	printf("\n");
}

void	print_layer(t_layer *layer)
{
  t_neural	*tmp;

  tmp = layer->start;
  while (tmp)
	{
	printf("target = %f ", tmp->target);
	printf("value = %f ; w_sum = %f\n", tmp->value, tmp->w_sum);
	tmp = tmp->next;
	}
	printf("\n");
}
