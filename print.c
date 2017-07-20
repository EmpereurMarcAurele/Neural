#include "neural.h"

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
