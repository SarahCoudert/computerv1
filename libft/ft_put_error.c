#include "includes/libft.h"
#include <stdlib.h>

void	ft_put_error(char *msg, int fd, int exit_flag)
{
	ft_putendl_fd(msg, fd);
	ft_putendl("We are exiting the programm");
	exit(exit_flag);
}
