#include	"neural.h"

void		load_serializer(char *pathname)
{
if ((fd = open(pathname, O_RDONLY)) == -1)
	{print_open_error();exit(EXIT_FAILURE);}

}

void		serialize_network(t_network *network)
{

}

