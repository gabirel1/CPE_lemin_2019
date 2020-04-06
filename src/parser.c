/*
** EPITECH PROJECT, 2020
** parser.c
** File description:
** parser.c
*/

#include "../include/my.h"

char *my_check(char *tunnel, char *string)
{
    char **tmp = NULL;
    char *nb1 = NULL;
    char *nb2 = NULL;

    tmp = my_str_to_word_array(tunnel, '-');
    nb1 = tmp[0];
    nb2 = tmp[1];

    if (my_strcmp(string, nb1) == 0)
        return (nb2);
    else if (my_strcmp(string, nb2) == 0)
        return (nb1);
    else
        return (NULL);
}

void get_nb_of_ants(lemin_t *lemin, char *string)
{
    char *tmp = malloc(sizeof(char) *5);
    int j = 0;


    for (int i = 0; string[i] != 0 && string[i] != '\n'; i++) {
        if (string[i] >= '0' && string[i] <= '9') {
            tmp[j] = string[i];
            j++;
        }
    }

    tmp[j] = 0;
    lemin->nb_of_ants = my_getnbr(tmp);
    free(tmp);
}