/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** my_strcat.c
*/

#include <stdlib.h>

char *my_strcat(char *src, char const *buffer)
{
    int a = 0;
    int b = 0;
    int c = 0;
    char *src2 = NULL;

    for (; src[a] != '\0'; a += 1);
    for (; buffer[b] != '\0'; b += 1);
    src2 = malloc(sizeof(char) * (a + b + 2));
    for (int i = 0; src[i] != '\0'; i += 1) {
        src2[c] = src[i];
        c += 1;
    }
    src2[c++] = '/';
    for (int j = 0; buffer[j] != '\0'; j += 1) {
        src2[c] = buffer[j];
        c += 1;
    }
    src2[c] = '\0';
    return (src2);
}