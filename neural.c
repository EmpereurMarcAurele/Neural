#include "neural.h"

t_neural	*init_node(t_layer *layer, t_neural *new,  char type)
{
  new = malloc(sizeof(t_neural));
  /*type == 1 ? new->type = IN_LAYER : type == 2 ? new->type = HID_LAYER : new->type = OUT_LAYER;*/
  new->r_learn = 0.45;
  new->prev_delta = 0;
  new->d_error = 0;
  new->type = 0;
  new->w_sum = 0;
  new->link = NULL;
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
	t_network	*network = NULL;;
	double	inputs[IN_NUM] = {0.5,0.5,0.5,0.5,0.5,1,1,1,0.5,1,0.5,0.5};
	double	targets[OUT_NUM] = {0,1,0,1};
	if (ac <= 1)
		{printf("Need 1 argument.\nIteration number. Typically must set to 10K to be efficient.\n\n");return (0);}
	int	nb_it = atoi(av[1]);
	if (nb_it < 100)
		nb_it = 1000;
	struct timeval t1;
	gettimeofday(&t1, NULL);
	srand(t1.tv_usec * t1.tv_sec);
	/*network initalisation*/
	network = init_network(IN_NUM, HID_NUM, OUT_NUM, network);
	fill_network(inputs, targets, network);

printf("input layer before run\n");
	print_layer(network->input_l);
printf("hidden layer before run\n");
	print_layer(network->hidden_l);
printf("output layer before run\n");
	print_layer(network->output_l);

	/*training begin*/
	run_network(network, nb_it);
	return (0);
}
