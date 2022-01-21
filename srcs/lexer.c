#include "../include/minishell.h"

void	display_chr(t_chr *chr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%c -> ", chr[i].c);
		if (chr[i].type == 0)
			printf("%s\n", "chr_alpha");
		if (chr[i].type == 1)
			printf("%s\n", "chr_number");
		if (chr[i].type == 2)
			printf("%s\n", "chr_space");
		if (chr[i].type == 3)
			printf("%s\n", "chr_open_bracket");
		if (chr[i].type == 4)
			printf("%s\n", "chr_close_bracket");
		if (chr[i].type == 5)
			printf("%s\n", "chr_open_paren");
		if (chr[i].type == 6)
			printf("%s\n", "chr_close_paren");
		if (chr[i].type == 7)
			printf("%s\n", "chr_single_quote");
		if (chr[i].type == 8)
			printf("%s\n", "chr_double_quote");
		if (chr[i].type == 9)
			printf("%s\n", "chr_unknown");
		i++;
	}
}

void	chriser(char c, t_chr *chr)
{
	chr->c = c;
	if (ft_isspace(c) == 1)
		chr->type = chr_space; 
	else if (ft_isnumber(c) == 1)
		chr->type = chr_number;
	else if (ft_isalpha(c) == 1)
		chr->type = chr_alpha;
	else if (c == '(')
		chr->type = chr_open_paren;
	else if (c == ')')
		chr->type = chr_close_paren;
	else if (c == '{')
		chr->type = chr_open_bracket;
	else if (c == '}')
		chr->type = chr_close_bracket;
	else if (c == '\'')
		chr->type = chr_single_quote;
	else if (c == '\"')
		chr->type = chr_double_quote;
	else
		chr->type = chr_unknown;
}

void	lexer(char *str)
{
	int i;
	t_chr *chr;

	chr = malloc(sizeof(t_chr) * ft_strlen(str));
	i = 0;

	while (i < ft_strlen(str) && str[i] != '\0')
	{
		if (str[i] != ' ')
			chriser(str[i], &chr[i]);
		i++;
	}
	
	display_chr(chr, i);
}