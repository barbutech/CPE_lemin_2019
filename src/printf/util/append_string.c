/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** append_string.c
*/

#include <stdlib.h>
#include "printf/util.h"

char *append_string(char *str, int size, char *append)
{
    char *temp = malloc(sizeof(char) * (size + my_strlen(append)));
    int i = 0;

    for (; i < size; i++) {
        temp[i] = str[i];
    }
    for (int j = 0; append[j] != '\0'; i++, j++) {
        temp[i] = append[j];
    }
    free(str);
    free(append);
    return (temp);
}
