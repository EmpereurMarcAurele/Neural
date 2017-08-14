#include "neural.h"

t_neural	*init_node(t_layer *layer, t_neural *new,  char type)
{
  new = malloc(sizeof(t_neural));
  /*type == 1 ? new->type = IN_LAYER : type == 2 ? new->type = HID_LAYER : new->type = OUT_LAYER;*/
  new->r_learn = 0.33;
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

t_network	*init_network(int nb_hid_layer, int nb_hi, t_network *network)
{
	network = malloc(sizeof(t_network));
	network->input_l = init_layer(IN_NUM, IN_LAYER);
	int	i = 0;
	while (i < nb_hid_layer)
		{
		network->hidden_l = init_layer(nb_hi, HID_LAYER);
		i++;
		}
	network->output_l = init_layer(OUT_NUM, OUT_LAYER);
	return (network);
}

int	main(int ac, char **av)
{
	t_network	*network = NULL;;
/*HERE you can modify values of Input layer and the desire Output layer.*/
/*If you want add some neurons on layers, don't forget to change marco values on neural.h file*/
	double	inputs[IN_NUM] = {0,0,1,0,0,1,1,1,0,1,0,0};
	double	targets[OUT_NUM] = {0.125,0.375,0.625,0.875};

	if (ac <= 2)
		{print_arg_error();return (0);}
	if (atoi(av[1]) == 1 && ac == 2)
		{load_serializer(av[2]);goto label1;}
	if (ac <= 3)
		{print_arg_error();return (0);}
	int	nb_it = atoi(av[1]);
	int	nb_hid_layer = atoi(av[2]);
	int	nb_size_hid_layer = atoi(av[3]);
if (nb_it < 100 || nb_it > 150000)
{nb_it = 1000;}
if (nb_hid_layer > 100 || nb_hid_layer < 2)
{nb_hid_layer = 2;}

	struct timeval t1;
	gettimeofday(&t1, NULL);
	srand(t1.tv_usec * t1.tv_sec);

	/*network initalisation*/
	network = init_network(nb_hid_layer, nb_size_hid_layer, network);
	fill_network(inputs, targets, network);

printf("input layer before run\n");
	print_layer(network->input_l);
printf("hidden layer before run\n");
	print_layer(network->hidden_l);
printf("output layer before run\n");
	print_layer(network->output_l);
	/*training begin*/
label1:
	run_network(network, nb_it);
	return (0);
}
