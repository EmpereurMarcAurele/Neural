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

void	print_arg_error()
{
printf("Need 3 argument.\n");
printf("1st Iteration number. Typically must set to 10K to be efficient.\n");
printf("2nd number of hidden layers\n");
printf("3rd number of nodes on a hidden layer\n\n");
}
void	print_layer(t_layer *layer)
{
  t_neural	*tmp;

  tmp = layer->start;
  while (tmp)
	{
	printf("target = %f ", tmp->target);
	printf("value = %f ; r_learn = %f, d_error = %f, w_sum = %f\n", tmp->value, tmp->r_learn, tmp->d_error, tmp->w_sum);
	tmp = tmp->next;
	}
	printf("\n");
}
