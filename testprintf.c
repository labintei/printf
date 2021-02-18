/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labintei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:37:27 by labintei          #+#    #+#             */
/*   Updated: 2021/02/18 15:20:32 by labintei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int			main(void)
{
	printf("TEST LARGEUR\n");
	printf("Pour d (meme comportement u, p, X, x, %%)\n");
	printf("largeur sans indicateur   I%5dI",5);
	printf("\nlargeur avec indicateur 0 I%05dI",5);
	printf("\nlargeur avec indicateur - I%-5dI", 5);
	printf("\nPour s");
	printf("\nlargeur sans indicateur   I%5sI", "AB");
	printf("\nlargeur avec indicateur 0 I%05sI non define par default", "AB");
	printf("\nlargeur avec indicateur - I%-5sI", "AB");
	printf("\nTEST PRECISION");
	printf("\nPour d (meme comportement u, p, X, x, %%)");
	printf("\nprecision 5 sur nb = 5 : %.5d", 5);
	printf("\ncomportement sans precision 0 : %d", 0);
	printf("\ncomportement speciale precision 0 sur 0 : %.0d(vide)", 0);
	printf("\ncomportement normale precision 0 sur 5 : %.0d", 5);
	printf("\nPour s");
	printf("\nprecision 5 sur ILauranne va a la plageI : %.5s", "Lauranne va a la plage");
	printf("\nprecision 5 sur ILauI : I%.5sI", "Lau");
	return(1);
}
