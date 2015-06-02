#ifndef COMPUTER_H
# define COMPUTER_H

#include "libft.h"

typedef struct		s_stru
{
	int				sign;
	double			multi;
	int				exp;
}					t_stru;

// t_env 	*get_env();
void		parse(char *s);

// get_env()
// {
// 	t_env env;
// 	env = get_specified_env(NULL, 0);
// 	return (env);
// }

// get_specified_env(void *data, int option)
// {
// 	static *env = NULL;
// 	if (env == NULL)
// 		env = dup data;
// 	return (env);
// }
#endif
