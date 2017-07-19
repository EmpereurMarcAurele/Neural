#include "neural.h"

#define	IN_NUM	3
#define	OUT_NUM	2
#define PATTERN_NUM	5

#define	IN_LAYER	1
#define	HID_LAYER	2
#define	OUT_LAYER	3

t_neural	*init_node(t_layer *layer, t_neural *new,  char type)
{
  new = malloc(sizeof(t_neural));
  /*type == 1 ? new->type = IN_LAYER : type == 2 ? new->type = HID_LAYER : new->type = OUT_LAYER;*/
  new->type = 0;
  new->w_sum = 0;
  new->w_in = 1 / rand();
  new->w_out = 1 / rand();
  new->value = 0;
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
	int	inputs[PATTERN_NUM][IN_NUM] = { {0,0,0}, {0,0,1}, {0,1,0}, {1,0,0}, {1,1,0} };
	int	targets[PATTERN_NUM][OUT_NUM] = { {0,0}, {0,1}, {0,0}, {1,0}, {1,1} };
	int	num_training = 10000;

	/*network initalisation*/
	network = init_network(2, 3, 1, network);
	print_layer(network->input_l);
	print_layer(network->hidden_l);
	print_layer(network->output_l);
	//fill_network(inputs, targets, network);

	/*training begin*/
	//train_network(inputs, outputs, num_training);
}
