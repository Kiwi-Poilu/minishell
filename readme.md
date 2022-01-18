char	*readline(const char *prompt);
affiche prompt sur le terminal en attendant de recevoir un input puis le return.
usage possible : afficher le prompt de notre minishell et recevoir les inputs


void	rl_clear_history(void)
readline utilise de la memoire et la garde en reference pour gerer un historique. On peut free avec la fonction ft_clear_history. 
usage possible : limiter les leaks, pas sur que ca soit suffisant pour eviter tout les still reachable

int	rl_on_new_line(void)
informe les fonctions d'update qu'on est passe a une nouvelle ligne
usage possible : je sais pas encore

void	rl_replace_line(const char*text, int clear_undo)
remplace le contenu de rl_line_buffer avec du texte

rl_redisplay

printf(char *format, ...)
tu coco


