#include "../include/minishell.h"

void	display_tokens(t_token *token, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%c -> ", token[i].c);
		if (token[i].type == 0)
			printf("%s\n", "token_alpha");
		if (token[i].type == 1)
			printf("%s\n", "token_number");
		if (token[i].type == 2)
			printf("%s\n", "token_space");
		if (token[i].type == 3)
			printf("%s\n", "token_open_bracket");
		if (token[i].type == 4)
			printf("%s\n", "token_close_bracket");
		if (token[i].type == 5)
			printf("%s\n", "token_open_paren");
		if (token[i].type == 6)
			printf("%s\n", "token_close_paren");
		if (token[i].type == 7)
			printf("%s\n", "token_single_quote");
		if (token[i].type == 8)
			printf("%s\n", "token_double_quote");
		if (token[i].type == 9)
			printf("%s\n", "token_unknown");
		i++;
	}
}

void	tokeniser(char c, t_token *token)
{
	token->c = c;
	if (ft_isspace(c) == 1)
		token->type = token_space; 
	else if (ft_isnumber(c) == 1)
		token->type = token_number;
	else if (ft_isalpha(c) == 1)
		token->type = token_alpha;
	else if (c == '(')
		token->type = token_open_paren;
	else if (c == ')')
		token->type = token_close_paren;
	else if (c == '{')
		token->type = token_open_bracket;
	else if (c == '}')
		token->type = token_close_bracket;
	else if (c == '\'')
		token->type = token_single_quote;
	else if (c == '\"')
		token->type = token_double_quote;
	else
		token->type = token_unknown;
}

void	lexer(char *str)
{
	int i;
	t_token *token;

	token = malloc(sizeof(t_token) * ft_strlen(str));
	i = 0;

	while (i < ft_strlen(str) && str[i] != '\0')
	{
		if (str[i] != ' ')
			tokeniser(str[i], &token[i]);
		i++;
	}
	display_tokens(token, i);
}