#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

enum Type
{
	token_open_paren,
	token_close_paren,
	token_alpha,
	token_number,
	token_unknown,
	token_space,
};

typedef struct s_token
{
	enum Type type;
	char c;
}		t_token;

//utils.c
int	ft_isspace(char c);
int	ft_isalpha(char c);
int	ft_isnumber(char c);
int	ft_strlen(char *str);


#endif
