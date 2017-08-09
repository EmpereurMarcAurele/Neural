#include "neural.h"

double	sigmoid_deriv(double entry)
{
	return (entry);
}

double	sigmoid_func(double entry)
{
	entry = 1 / (1 + exp(entry));
	return (entry);
}
