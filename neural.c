#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>


#define	IN_NUM	3
#define	OUT_NUM	2
#define PATTERN_NUM	5

#define	INPUT_LAYER	1
#define	HIDDEN_LAYER	2
#define	OUTPUT_LAYER	3

typedef struct	s_network	t_network;
struct	s_network
{
	s_neural	*input_l;
	s_neural	*hidden_l;
	s_neural	*output_l;
}

typedef	struct	s_neural	t_neural;
struct	s_neural
{
	char	type;/* input?hidden?output?*/
	double	w_in;
	double	w_out;
	s_neural	*prev;
	s_neural	*next;
}

void	init_layer(int nb_node)
{

}

void	init_network(int nb_in, int nb_hi, int nb_out, t_network *network)
{
	network = sizeof(t_network);
	network->input_l = init_layer(nb_in);
	network->hidden_l = init_layer(nb_hi);
	network->output_l = init_layer(nb_out);
}

int	main(int ac, char **av)
{
	t_network	*network;
	int	inputs[PATTERN_NUM][IN_NUM] = { {0,0,0}, {0,0,1}, {0,1,0}, {1,0,0}, {1,1,0} };
	int	targets[PATTERN_NUM][OUT_NUM] = { {0,0}, {0,1}, {0,0}, {1,0}, {1,1} };
	int	num_training = 10000;

	network = init_network(2, 3, 1);/*init_network(nb_in, nb_hi, nb_out)*/

	train_network(inputs, outputs, num_training);
}
