#include "builtin.h"

static t_list	*create_env(char **env)
{
	t_list *head;
	t_list *new;

	new = NULL;
	head = ft_lstnew(ft_strdup(*env));
	if (!head)
		return (NULL);
	env++;
	while(*env)
	{
		new = ft_lstnew(ft_strdup(*env));
		if(!new)
		{
			ft_lstclear(&head, free);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		env++;
	}
	return (head);
}

int main(int ac, char **av, char **ev)
{
	t_list	*env;

	//printf("%s\n", av[2]);
	env = create_env(ev);
	if (ac == 0)
		return (0);
	av++;
	//printf("%s\n", *av);
	if (ft_strnstr("export", *av, ft_strlen(*av)))
	{
		ft_export(av, env);
		//ft_env(env);
	}
	if (ft_strnstr("env", *av, ft_strlen(*av)))
		ft_env(env);
	if (ft_strnstr("echo", *av, ft_strlen(*av)))
		ft_echo(av, env);
	if (ft_strnstr("pwd", *av, ft_strlen(*av)))
		ft_pwd();
	if (ft_strnstr("cd", *av, ft_strlen(*av)))
	{
		printf("before:%s\n", getcwd(NULL, 0));
		ft_cd(av, env);
		printf("after:%s\n", getcwd(NULL, 0));
		printf("---------------------\n");
		ft_env(env);
	}
	if (ft_strnstr("unset", *av, ft_strlen(*av)))
	{
		ft_export(av, env);
		ft_env(env);
		ft_unset(av, &env);
		printf("-----------------------------------------------------------------\n");
		ft_env(env);
	}
	//ft_env(env);
	ft_lstclear(&env, free);
}
