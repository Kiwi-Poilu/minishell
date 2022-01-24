#include "../include/parsing.h"

t_token	*ft_lstnew(char *token, enum Type type)
{
	t_token *new;

	if (!(new = malloc(sizeof(t_token))))
		return (NULL);
    new->type = type;
	new->token = ft_strdup(token);
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_token **alst, t_token *new)
{
	t_token *tmp;

	if (!alst)
		return ;
	tmp = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_lstadd_front(t_token **alst, t_token *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}