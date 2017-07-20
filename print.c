#include "neural.h"

void	print_layer(t_layer *layer)
{
  t_neural	*tmp;
  
  tmp = layer->start;
  while (tmp)
    {
      printf("w_in = %f\n", tmp->w_in);
      tmp = tmp->next;
    }
printf("\n");
}
