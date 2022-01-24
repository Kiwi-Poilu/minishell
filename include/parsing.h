#ifndef PARSING_H
#define PARSING_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
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
    token_word,
    token_operand,
    token_pipe,
};

typedef struct s_token
{
    enum Type type;
    char *token;
    struct s_token *next;
}               t_token;

//list.c
t_token	*ft_lstnew(char *token, enum Type type);
void	ft_lstadd_back(t_token **alst, t_token *new);
void	ft_lstadd_front(t_token **alst, t_token *new);


#endif
