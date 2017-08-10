#include "neural.h"

double	sigmoid_deriv(double entry)
{
	return (entry);
}

double	sigmoid_func(double entry)
{
	entry = 1 / (1 + exp(-1 * entry));
	return (entry);
}
