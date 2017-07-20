#include "neural.h"

#define	IN_NUM	12
#define	OUT_NUM	4

#define	IN_LAYER	1
#define	HID_LAYER	2
#define	OUT_LAYER	3

t_neural	*init_node(t_layer *layer, t_neural *new,  char type)
{
  new = malloc(sizeof(t_neural));
  /*type == 1 ? new->type = IN_LAYER : type == 2 ? new->type = HID_LAYER : new->type = OUT_LAYER;*/
  new->type = 0;
  new->w_sum = 0;
  int r = rand() % 99 + 1;
  new->link = NULL;
  new->w_out = (double)r / 10;
  new->value = 0;
  new->target = 0;
  if(layer->start == NULL)
    {
      new->prev = NULL;
      layer->start = new;
      layer->tmp = new;
    }
  else
    {
      new->prev = layer->tmp;
      layer->tmp->next = new;
      layer->tmp = new;
    }
  new->next = NULL;
  layer->end = new;
  return (new);
}

t_layer		*init_layer(int nb_node, char type)
{
  t_layer	*newlayer;
  newlayer = malloc(sizeof(t_layer));
  newlayer->start = NULL;
  newlayer->end = NULL;
  int i = 0;
  while (i < nb_node)
    {
      t_neural	*new;
      new = init_node(newlayer, new, type);
      i++;
    }
  return (newlayer);
}

t_network	*init_network(int nb_in, int nb_hi, int nb_out, t_network *network)
{
	network = malloc(sizeof(t_network));
	network->input_l = init_layer(nb_in, IN_LAYER);
	network->hidden_l = init_layer(nb_hi, HID_LAYER);
	network->output_l = init_layer(nb_out, OUT_LAYER);
	return (network);
}

int	main(int ac, char **av)
{
	t_network	*network;
	int	inputs[IN_NUM] = {0,0,0,0,0,1,1,1,0,1,0,0};
	int	targets[OUT_NUM] = {0,1,0,1};
	if (ac <= 1)
		{printf("need 1 arg\n");return (0);}
	int	nb_it = atoi(av[1]);
	if (nb_it < 100)
		nb_it = 1000;
	/*network initalisation*/
	network = init_network(IN_NUM, 3, OUT_NUM, network);
	print_layer(network->input_l);
	print_layer(network->hidden_l);
	print_layer(network->output_l);
	fill_network(inputs, targets, network);

	/*training begin*/
	run_network(network, nb_it);
}
