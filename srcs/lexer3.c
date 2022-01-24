#include "../include/parsing.h"

char    *get_token(char *str, int *pos)
{
    char    *token;
    int     quote;
    int     squote;
    int     to_malloc;
    int     i;

    i = 0;
    quote = 0;
    token = malloc(sizeof(char) * 50);
    printf("%c\n", str[*pos]);
    while (str[*pos] != '\0')
    {
        if (str[*pos] == '"' && quote == 0)
                quote = 1;
        else if (str[*pos == '"'] && quote == 1)
                quote = 0;
        if (str[*pos] == ' ' && quote != 1)
        {
            while (str[*pos] == ' ')
                *pos++;
            return (token);
        }
        token[i] = str[*pos];
        i++;
        *pos++;
    }
    token[i] = '\0';
    return (token);
}

/*
void    lexer(char *cmd)
{
    int pos;
    char *token;

    pos = 0;
    while (cmd[pos] == ' ')
        pos++;
    while (token != NULL)
    {
        token = get_token(cmd, &pos);
    }
}


int     main(void)
{
    char    *rl_rt;

    rl_rt = NULL;
    while (1)
    {
        rl_rt = readline("kiwishell: ");
        lexer(rl_rt);
    }
}
*/

int     main(void)
{
    int pos = 0;

    printf("%s\n", get_token("sofiane", &pos));
}