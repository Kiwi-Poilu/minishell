#include "../include/minishell.h"

int	main(void)
{
	char	*rl_rt;
	
	while (1)
	{
		rl_rt = readline("kiwishell$ ");
		printf("%s\n", rl_rt);
		lexer(rl_rt);
	}
}
