/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:30:56 by hlichten          #+#    #+#             */
/*   Updated: 2025/05/18 23:37:38 by hlichten         ###   ########.fr       */
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

int check(int result, int *retour)
{
	int sub = result;
	int i = 0;
	int size = (sizeof(retour) / sizeof(int));
	printf("%d\n", size);
	while (i < size)
	{
		sub = sub - (retour[i]);
		i++;
	}
	return (sub);
}

void print_tab(int *tab, int size)
{
	int i = 0;

	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
}

t_bool	powerset(int *tab, int *retour, int i, int size, int result)
{
	// condition de sortie
	if (i == size || check(result, retour) == 0) // quand on arrive a la fin 
	{
		if (check(result, retour) == 0)
			print_tab(retour, (sizeof(retour) / sizeof(int)));
		return (TRUE);
	}

	// recursive a deux branches
	
	//branche 1:
	//if (check(result, retour, size) > 0)
	//{
	retour[i] = tab[i]; // on envoie dans une premiere branche avec le remplacement en mode espace
	powerset(tab, retour, i + 1, size, result); // on augmente i de 1 et du coup le count de space de 1
	//}

	//branche 2:
	if (i + 1 < size)
	{
		retour[i] = tab[i + 1]; // on envoie dans une secnonde branche avec la parenthese actuelle
		powerset(tab, retour, i + 1, size, result); // on augmente i de 1
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
		int		tab[ac - 2];
		int		retour[ac - 1]; //creation d'une string a imprimer pour le printage de solution 
		//            	        (ac - valeur - programme + '\0')

	// etape 3 : initialisation du tableau (2 steps)
	while (size > 2)
	{
		tab[i] = atoi(av[i + 2]); // a cause du programme + valeur
		i++;
		size--;
	}
	
	// etape 3 : la recursive en arbre super style (1 step)
	powerset(tab, retour, 0, ac - 2, result); // l argument recu && les init && deux count pour la recursive

	return(0);
}
