/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:30:56 by hlichten          #+#    #+#             */
/*   Updated: 2025/05/18 20:42:04 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

t_bool is_valid_av(char **av)
{
	int i = 2;

	while(av[i])
	{
		if (av[i][0] < '0' || av[i][0] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int check(int result, int *tab)
{
	int sus = result;
	int i = 0;
	while (tab[i])
	{
		sus = sus - tab[i];
		i++;
	}
	return (sus);
}

t_bool	powerset(int *tab, char *retour, int i, int size, int result)
{
	// condition de sortie
	if (i == size || check(result, tab) == 0) // quand on arrive a la fin 
	{
		retour[i] = '\0';	// on met le dernier caractere a 0
		if (check(result, tab) == 0)
			puts(retour);
		return (TRUE);
	}

	// recursive a deux branches
	//branche 1:
	if (check(result, tab) > 0)
	{
		retour[i] = tab[i] + 48; // on envoie dans une premiere branche avec le remplacement en mode espace
		powerset(tab, retour, i + 1, size, result); // on augmente i de 1 et du coup le count de space de 1
	}

	//branche 2:
	if (i + 1 != size && check(result, tab) > 0)
	{
		retour[i] = tab[i + 1] + 48 ; // on envoie dans une secnonde branche avec la parenthese actuelle
		powerset(tab, retour, i + 1, size, result); // on augmente i de 1
	}
	else
	{
		retour[i] = '\0';	// on met le dernier caractere a 0
		if (check(result, tab) == 0)
			puts(retour);
		return (TRUE);
	}
	
	return (FALSE);
}


int	main(int ac, char **av)
{
	// etape 1 : verif (2 steps)
	if (is_valid_av(av) == FALSE || ac < 3)
		return (1);
	
	// etape 2 :  initiation (5 steps) 
	int 	i = 0;
	int		result = atoi(av[1]);
	int		size = ac;
	int		tab[ac - 1];
	char	retour[ac - 1]; //creation d'une string a imprimer pour le printage de solution 
	//            	        (ac - valeur - programme + '\0')
	
	// etape 3 : initialisation du tableau (2 steps)
	while (size > 2)
	{
		tab[i] = atoi(av[i + 2]); // a cause du programme + valeur
		i++;
		size--;
	}
	tab[i] = '\0';
	
	// etape 3 : la recursive en arbre super style (1 step)
	powerset(tab, retour, 0, ac - 2, result); // l argument recu && les init && deux count pour la recursive

	return(0);
}
