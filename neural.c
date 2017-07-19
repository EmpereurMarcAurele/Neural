#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>


#define	IN_NUM	3
#define	OUT_NUM	2
#define PATTERN_NUM	5

int	main(int ac, char **av)
{
t_struct	*neural;
int	inputs[PATTERN_NUM][IN_NUM] = { {0,0,0}, {0,0,1}, {0,1,0}, {1,0,0}, {1,1,0} };
int	outputs[PATTERN_NUM][OUT_NUM] = { {0,0}, {0,1}, {0,0}, {1,0}, {1,1} };
int	num_training = 10000;

neural = init_network();

train_network(inputs, outputs, num_training);


}
