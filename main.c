#include "minishell.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\r' ||
			c == '\t' || c == '\n' || c == '\v')
		return (1);
	return (0);
}

int	ft_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_isnumber(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}
void	tokeniser(char c, t_token *token)
{
	token->c = c;
	if (ft_isspace(c))
		token->type = token_space;
	else if (ft_isnumber(c))
		token->type = token_number;
	else if (ft_isalpha(c))
		token->type = token_alpha;
	else if (c == '(')
		token->type = token_open_paren;
	else if (c == ')')
		token->type = token_close_paren;
	else
		token->type = token_unknown;
}

void	sender(char *str)
{
	int i;

	i = 0;
	t_token *token = malloc(sizeof(t_token) * ft_strlen(str));
	while (str[i])
	{
		tokeniser(str[i], &token[i]);
		printf("%c = ", token[i].c);
		printf("%u\n", token[i].type);
		i++;
	}
	i = 0;
	free(token);
}

/*
int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	sender(av[1]);	
	return (0);
}*/

int	main(void)
{
	char	*prompt;
	
	prompt = readline("kiwishell$ ");
	printf("%s\n", prompt);
	free(prompt);
}
