#ifndef	NEURAL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>

typedef struct  s_neural        t_neural;
struct  s_neural
{
        char		type;/* input?hidden?output?*/
        double		w_sum;
        double		w_in;
        double		w_out;
	double		value;
        t_neural        *prev;
        t_neural        *next;
};

typedef struct	s_layer	t_layer;
struct	s_layer
{
  t_neural	*start;
  t_neural	*tmp;
  t_neural	*end;
};
  
typedef struct  s_network       t_network;
struct  s_network
{
        t_layer        *input_l;
        t_layer        *hidden_l;
        t_layer        *output_l;
};

/*PROTOTYPES*/
/* main.c */
t_neural	*init_node(t_layer *, t_neural *, char);
t_layer		*init_layer(int, char);
t_network	*init_network(int, int, int, t_network *);
/* print.c */
void		print_layer(t_layer *);

#endif /*NEURAL_H_*/
