/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:30:56 by hlichten          #+#    #+#             */
/*   Updated: 2025/05/20 19:10:35 by hlichten         ###   ########.fr       */
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
	int j;
	while(av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int check(int result, int *retour, int cnt)
{
	int sub = result;
	int i = 0;
	while (i < cnt)
		sub -= retour[i++];
	return (sub);
}

void print_tab(int *tab, int count)
{
	int i = 0;

	while (i < count - 1)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("%d\n", tab[i]);
}

t_bool	powerset(int *tab, int *retour, int i, int size, int result, int *count)
{
	// condition de sortie
	if (i == size) // quand on arrive a la fin 
	{
		if (check(result, retour, *count) == 0)
			print_tab(retour, *count);
		return (TRUE);
	}
	
	//branche 1:
	retour[*count] = tab[i];
	(*count)++;
	powerset(tab, retour, i + 1, size, result, count);
	(*count)--;

	//branche 2:
	powerset(tab, retour, i + 1, size, result, count);


	return (FALSE);
}

int	main(int ac, char **av)
{
	// etape 1 : verif (2 steps)
	if (is_valid_av(av) == FALSE || ac < 3)
		return (1);
		
	// etape 2 :  initiation (6 steps) 
	int 	i = 0;
	
	int		result = atoi(av[1]);
	int		size = ac - 2;
	int		tab[size];
	int		retour[size];
	int		cnt = 0;

	// etape 3 : initialisation du tableau (1 step)
	while (i < size)
	{
		tab[i] = atoi(av[i + 2]); // a cause du programme + valeur
		i++;
	}
	
	// etape 4 : la recursive en arbre super style (1 step)
	powerset(tab, retour, 0, size, result, &cnt);

	return(0);
}

// 5 fonctions + 1 t_bool