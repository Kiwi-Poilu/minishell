#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

enum Type
{
	token_alpha,
	token_number,
	token_space,
	token_open_bracket,
	token_close_bracket,
	token_open_paren,
	token_close_paren,
	token_single_quote,
	token_double_quote,
	token_unknown,
};

typedef struct s_token
{
	enum Type type;
	char c;
}				t_token;

//utils.c
int	ft_isspace(char c);
int	ft_isalpha(char c);
int	ft_isnumber(char c);
int	ft_strlen(char *str);

//lexer.c
void	display_tokens(t_token *token, int size);
void	tokeniser(char c, t_token *token);
void	lexer(char *str);

#endif
