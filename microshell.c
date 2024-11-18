/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:20:21 by jedusser          #+#    #+#             */
/*   Updated: 2024/11/18 12:54:24 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

// si PAS DE PIPE et que la cmd produit un stdout :: rien.
//si PIPE et que cmd produit un stdou :: stdout >> tmp;
// tmp >> [stdin]prochaine commande[stdout]


//  [STDIN]cmd1[STDOUT]

//  PIPE : cration de tmp.txt
    //--> read DONC creation de read fd
    //-->  STDIN[read fd]STDOUT
//  [STDIN]cmd2[STDOUT]

// if (strncmp(argv[i + 1], "|", 1))
// {
//     handle_pipes();
// }
// // printf("Hello from child, pid = %d, executing: %s\n", pid, argv[i]);
void print_tab(char **tab)
{
    int i = 0;
    while (tab[i])
    {
        printf("[%s]\n", tab[i]);
        i++;
    }
    printf("\n");
    
}
int main(int argc, char **argv, char **envp)
{
    int i;
    pid_t pid;
    int pipe_fds[2];
    
    // loop through argv to check for pipes or ;
    
    i = 1;
    printf("tab at start : \n");
    print_tab(argv);
    while (i < argc)
    {
        pid = fork();
        if (pid == 0)
        {
            
            if (execve(argv[i], &argv[i], envp) != -1)
            {
                printf("tab in execve : \n");
                print_tab(&argv[i]);
                
                perror("execve");
                exit(1);
            }
        }
        else if (pid > 0)
        {
            // printf("hello from parent, pid = %d\n", pid);
            wait(NULL);
        }
        else
        {
            perror("fork");
            return 1;
        }
        i++;
    }
    return 0;
}