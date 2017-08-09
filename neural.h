#ifndef	NEURAL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <fcntl.h>

#define IN_NUM  12
#define HID_NUM 3
#define OUT_NUM 4

#define	INERTIA		0.9
#define IN_LAYER        1
#define HID_LAYER       2
#define OUT_LAYER       3

typedef struct  s_neural        t_neural;
struct  s_neural
{
        char		type;/* input?hidden?output? RESERVED*/
	double		r_learn;
	double		prev_delta;
	double		d_error;
        double		w_sum;
	double		value;
	double		target;
	double		*link;
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
/* neural.c (main)*/
t_neural	*init_node(t_layer *, t_neural *, char);
t_layer		*init_layer(int, char);
t_network	*init_network(int, int, int, t_network *);
/* print.c */
void		print_only_res(t_network *);
void		print_layer(t_layer *);
/* fill_network.c */
void		fill_layer_out(double *, t_layer *);
void		fill_layer_hi(t_layer *);
void		fill_layer_in(double *, t_layer *);
void		fill_network(double *,double *, t_network *);
/* run_network.c */
void		back_propagationIH(t_network *);
void		process_hidden_l_error(t_network *);
void		back_propagationHO(t_network *);
void		get_value_out(t_network *);
void		get_value_hid(t_network *);
void		run_network(t_network *, int);
/* function.c */
double		sigmoid_deriv(double);
double		sigmoid_func(double);
#endif /*NEURAL_H_*/
