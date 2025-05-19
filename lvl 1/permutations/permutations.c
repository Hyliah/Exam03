/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:30:53 by hlichten          #+#    #+#             */
/*   Updated: 2025/05/19 22:08:37 by hlichten         ###   ########.fr       */
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

void	swap_current(char *str, int current, int last)
{
	while (current < last)
	{
		swap(&str[current], &str[last]);
		current++;
		last--;
	}
}

void perm(char *str, int len)
{
	int i;
	int j;

	if (is_reverse(str, len)) // fonction de sortie, des que notre entree est a l envers
		return;

	// but final etant de ermuter jusqu a ce que la string de depart soit  l envers
	i = len - 2; //on part 1 avant la fin
	while (i >= 0 && str[i] >= str[i + 1]) // tant que la phrase est dans l ordre inverse alphabetique -> on diminue
		i--;

	j = len - 1; // len - 1 = le dernier index
	while (str[j] <= str[i]) // aller jusqu a ce qu on soit a plus loin dans l aplphabet
		j--;

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