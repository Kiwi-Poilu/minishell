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
	chr_alpha,
	chr_number,
	chr_space,
	chr_open_bracket,
	chr_close_bracket,
	chr_open_paren,
	chr_close_paren,
	chr_single_quote,
	chr_double_quote,
	chr_unknown,
};

typedef struct	s_chr
{
	enum Type type;
	char c;
}				t_chr;

//utils.c
int	ft_isspace(char c);
int	ft_isalpha(char c);
int	ft_isnumber(char c);
int	ft_strlen(char *str);

//lexer.c
void	display_chr(t_chr *chr, int size);
void	chriser(char c, t_chr *chr);
void	lexer(char *str);

#endif
