/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:26:51 by jedusser          #+#    #+#             */
/*   Updated: 2024/12/30 14:17:37 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void parsing(char **tab, char **argv)
{
   
    int i = 1;
    int j = 0;
    
    while (argv[i])
        tab[j++] = argv[i++];
    tab[j] = NULL;
    
    
    //debug
    j = -1;
    while (tab[j++])
        printf("tab[%d] = %s\n",j, tab[j]);
    //debug
}


int main(int argc, char **argv, char **envp)
{
    (void)argc;
    char *tab[1024];
    char **big_tab[1024];
    
    parsing(tab, argv);

    
    int i = 0;
    big_tab[i] = tab;
    
    

    if (execve(big_tab[i][0], big_tab[0], envp) == -1)
    {
        perror("error :");
        return (-1);
    }
}