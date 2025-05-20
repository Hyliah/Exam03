/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:31:01 by hlichten          #+#    #+#             */
/*   Updated: 2025/05/20 19:08:01 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

t_bool is_valid_av(char *str)
{
	int i = 0;

	while(str[i])
	{
		if (str[i] != '(' && str[i] != ')')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	count_min_space(char *str)
{
	int count = 0;
	int balance = 0;
	int i = 0;

	while (str[i])
	{
		if (str[i] == '(')
			balance++;
		else if (str[i] == ')')
		{
			if (balance == 0)
				count++;
			else
				balance--;
		}
		i++;
	}
	return (count + balance);
}

t_bool is_balanced(char *retour)
{
	int i = 0;
	int	balance = 0;

	while(retour[i])
	{
		if (retour[i] == '(')
			balance++;
		else if (retour[i] == ')')
		{
			if (balance == 0)
				return (FALSE); 
			balance--;
		}
		i++;	
	}

	if (balance == 0)
		return (TRUE);
	return (FALSE);
}

t_bool	rip(char *str, char *retour, int min_space, int space_count, int i)

{
	// condition de sortie
	if (str[i] == '\0') // quand on arrive a la fin 
	{
		retour[i] = '\0';	// on met le dernier caractere a 0
		if (is_balanced(retour) == TRUE && space_count == min_space)
			puts(retour);
		return (TRUE);
	}

	// recursive a deux branches
	//branche 1:
	retour[i] = ' '; // on envoie dans une premiere branche avec le remplacement en mode espace
	rip(str, retour, min_space, space_count + 1, i + 1); // on augmente i de 1 et du coup le count de space de 1
	
	//branche 2:
	retour[i] = str[i]; // on envoie dans une secnonde branche avec la parenthese actuelle
	rip(str, retour, min_space, space_count, i + 1); // on augmente i de 1
	
	return (FALSE);
}

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}
int	main(int ac, char **av)
{
	// etape 1 : verif (3 steps)
	if (ac != 2 || av[1][0] == '\0' || is_valid_av(av[1]) == FALSE)
		return (1);
	
	// etape 2 :  initiation (2 steps) 
	int		min_space = count_min_space(av[1]);;
	char	retour[(ft_strlen(av[1])) + 1]; //creation d'une string a imprimer pour le printage de solution

	// etape 3 : la recursive en arbre super style (1 step)
	rip(av[1], retour, min_space, 0 ,0); // l argument recu && les init && deux count pour la recursive

	return(0);
}

// 5 fontions + 1 t_tool