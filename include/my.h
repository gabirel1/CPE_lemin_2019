/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char *my_strcat(char *start, char *line);
char **my_str_to_word_array(char *str, char separator);
int my_strlen(char const *str);
int my_showstr_remastered(char const *str);
int my_putnbr_base_unsigned(unsigned int nbr, char const *base);
int my_putnbr_base(long nbr, char const *base);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
void my_printf(char *str, ...);

#endif /* !MY_H_ */