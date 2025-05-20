/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:30:49 by hlichten          #+#    #+#             */
/*   Updated: 2025/05/20 18:38:31 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum e_bool
{
    FALSE,
    TRUE
}    t_bool;

t_bool is_safe(int *chess_board, int col, int row)
{
    int i = 0;
    while (i < col)
    {
        if (chess_board[i] == row || chess_board[i] + i == row + col || chess_board[i] - i == row - col)
            return FALSE;
        i++;
    }
    return TRUE;
}

void    queens(int *chess_board, int n, int col)
{
    int i = 0;
    int row = 0;

    if (col >= n)
    {
        while (i < n)
        {
            fprintf(stdout, "%d", chess_board[i]);
            i++;
        }
        fprintf(stdout, "\n");
    }

    while (row < n)
    {
        if (is_safe(chess_board, col, row))
        {
            chess_board[col] = row;
            queens(chess_board, n, col + 1);
        }
        row++;
    }
}

int    main(int ac, char **av)
{
    // etape 1 : verification + print si erreur -> stderr (1 step)
    if (ac != 2)
    {
        fprintf(stderr, "Error: usage ./queens n");
        return 1;
    } 
    // etape 2 : creation du tableau de int sur la taille n (3 steps)
    int    n = atoi(av[1]);
    int chess_board[n];
    queens(chess_board, n, 0);

    return(0);
}

// 3 fonctions + 1 t_bool