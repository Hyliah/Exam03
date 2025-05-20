/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:30:53 by hlichten          #+#    #+#             */
/*   Updated: 2025/05/20 18:31:58 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

int	ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
	
}

void	swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bubble_sort(char *str, int len)
{
	int i = 0;
	int j;

	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			if (str[j] > str[j + 1])
				swap(&str[j], &str[j + 1]);
			j++;
		}
		i++;
	}
}

t_bool is_reverse(char *str, int len)
{
	int i = 0;
	while (i < len - 1)
	{
		if (str[i] < str[i + 1])
			return FALSE;
		i++;
	}
	return TRUE;
}

void	swap_current(char *str, int first, int last)
{
	while (first < last)
	{
		swap(&str[first], &str[last]);
		first++;
		last--;
	}
}

void perm(char *str, int len)
{
	int i;
	int j;

	// etape 1 : fonction de sortie, des que notre entree est a l envers (1 step)
	if (is_reverse(str, len))
		return;

	// etape 2 : reset les i & j (2 steps)
	i = len - 2;
	while (i >= 0 && str[i] >= str[i + 1])
		i--;

	j = len - 1;
	while (str[j] <= str[i])
		j--;

	// etape 3 : 2 swap + print + recursive (3 (4) steps)
	swap(&str[i], &str[j]);
	swap_current(str, i + 1, len - 1);
	puts(str);
	perm(str, len);
}

int	main(int ac, char **av)
{
	// etape 1 : verification
	if (ac != 2 || av[1][0] == '\0')
		return (1);

	// etape 2 : initialisation
	int len = ft_strlen(av[1]);
	char *str = av[1];
	
	//etape 3 : sorting de verification + print la base + permutation (2 steps)
	bubble_sort(str, len);
	puts(str);
	perm(str, len);

	return (0);
}

// 7 fonctions + 1 t_bool