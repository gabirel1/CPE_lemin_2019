#include "include/my.h"
#include "include/struct.h"

char *get_file(void)
{
    size_t len;
    char *buffer = NULL;
    char *final = NULL;

    while (getline(&buffer, &len, stdin) != -1) {
        final = my_strcat(final, buffer);
    }
    return (final);
}

int check_error(char *str)
{
    return (0);
}

int parser(lemin_t *lemin, char *str)
{
    int i = 0;
    int j = 0;
    char *tmp = malloc(sizeof(char) * my_strlen(str));

    for (; str[i + 1] != '-' && str[i + 1] != 0; i++);
    for (; str[i] != 0; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            tmp[j] = str[i];
            j++;
            tmp[j] = '-';
            j++;
        }
    }
    tmp[j] = 0;

    lemin->tab = my_str_to_word_array(tmp, '-');

    for (int i = 0; lemin->tab[i] != NULL; i++) {
        my_printf("%s\n", lemin->tab[i]);
    }
    free(tmp);
    return (0);
}

int main(void)
{
    lemin_t lemin;
    char *buffer = get_file();

    if (check_error(buffer) == 1)
        return (84);

    parser(&lemin, buffer);
    for (int i = 0; lemin.tab[i] != NULL; i++) {
        free(lemin.tab[i]);
    }
    free(buffer);
    return (0);
}