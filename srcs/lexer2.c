#include "../include/parsing.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int     get_token_size(char *str)
{
    static int i = 0;
    int ret;
    int quote;

    quote = 0;
    ret = 0;
    while (str[i])
    {
        if (str[i] == '"')
        {
            if (quote == 0)
                quote = 1;
            else
                quote = 0;
            ret--;
        }
        if (str[i] == ' ' && quote != 1)
        {
            while (str[i] == ' ')
                i++;
            return (ret);
        }
        i++;
        ret++;
    }
    return (ret);
}

char    *get_token(char *str)
{
    static int i = 0;
    int j;
    char *token;
    int quote;
    
    j = 0;
    quote = get_token_size(str);
    if (quote == 0)
        return (NULL); 
    token = malloc(sizeof(char) * quote);
    if (!token)
        return (NULL);
    quote = 0;
    while (str[i])
    {
        if (str[i] == '"')
        {
            if (quote == 0)
                quote = 1;
            else
                quote = 0; 
        }
        if (str[i] == ' ' && quote != 1)
        {
            while (str[i] == ' ')
                i++;
            return (token);
        }
        token[j] = str[i];
        j++;
        i++;
    }
    return (token);
}

int     get_type(char *token)
{
    int i;

    i = 0;
    if (token[i] == '|')
        return (token_pipe);
    if (ft_strcmp(token, "<<") == 0|| ft_strcmp(token, ">>") == 0
        || ft_strcmp(token, "<") == 0 || ft_strcmp (token, ">") == 0)
        return (token_operand);
    return (token_word);
}

char    *display_type(int type)
{
    if (type == 0)
        return("token_word");
    if (type == 1)
        return("token_operand");
    if (type == 2)
        return("token_pipe");
    return ("token_unknown");
    
}
void    display_tokens(t_token *token)
{
    while (token)
    {
        printf("%s -> ", token->token);
        printf("%s\n", display_type(token->type));
        token = token->next;
    }
}

t_token    *lexer(char *str)
{
    t_token *first_token;
    t_token *new_node;
    char *token;

    token = get_token(str);
    if (token != NULL)
        first_token = ft_lstnew(token, get_type(token));
    while (token != NULL)
    {
        free(token);
        token = get_token(str);
        if (token != NULL)
        {
            new_node = ft_lstnew(token, get_type(token));
            ft_lstadd_back(&first_token, new_node);
        }
    }
    display_tokens(first_token);
    return (first_token);
}

int     main(int ac, char **av)
{
    int i;
    char *rl_rt;

    i = 0;
    while (1)
    {
        rl_rt = readline("kiwishell: ");
        lexer(rl_rt);
    }
  //  lexer(av[1]);
}