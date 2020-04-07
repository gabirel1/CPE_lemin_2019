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
    if (final == NULL)
        return (NULL);
    return (final);
}

int check_error(char *str)
{
    if (str == NULL)
        return (1);
    return (0);
}

int find_bigger(lemin_t *lemin)
{
    int max = my_getnbr(lemin->tab[0]);

    for (int i = 0; lemin->tab[i]; i++) {
        if (my_getnbr(lemin->tab[i]) > max)
            max = my_getnbr(lemin->tab[i]);
    }
    // printf("\n%d\n", max);
    return (max);
}

int parser(lemin_t *lemin, char *str)
{
    lemin->tab = my_str_to_word_array(str, '\n');
    return (0);
}

int tab_len(char **tab)
{
    int i = 0;

    for (; tab[i]; i += 1);
    return (i);
}

void my_free(lemin_t *lemin, char *str)
{
    for (int i = 0; lemin->tab[i] != NULL; i++) {
        free(lemin->tab[i]);
    }
    free(str);
}

void add_node_at_back(char *line, node_t **node)
{
    node_t *new = malloc(sizeof(node_t));
    node_t *tmp = *node;
    char **tab = my_str_to_word_array(line, ' ');

    new->start = NULL;
    new->end = NULL;
    new->next = NULL;
    new->name = tab[0];
    new->neighbourg = NULL;
    new->x = my_getnbr(tab[1]);
    new->y = my_getnbr(tab[2]);
    if (*node == NULL) {
        *node = new;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
}

node_t *get_room(node_t *head, char *to_find)
{
    for (node_t *tmp = head; tmp; tmp = tmp->next)
        if (my_strcmp(tmp->name, to_find) == 0)
            return (tmp);
    return (NULL);
}

void add_neighbour(neigh_t **head, char *room)
{
    neigh_t *new = malloc(sizeof(neigh_t));
    neigh_t *tmp = *head;

    new->next = NULL;
    new->name = room;
    if (*head == NULL) {
        *head = new;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
}

void create_rooms(char **tab, node_t *head)
{
    node_t *tmp = head;
    char *s = NULL;

    for (int i = 0; tab[i]; i += 1) {
        if (tab_len(my_str_to_word_array(tab[i], ' ')) == 3) {
            if (i > 0 && my_strcmp(tab[i - 1], "##start") == 0)
                add_node_at_back(tab[i], &head->start);
            else if (i > 0 && my_strcmp(tab[i - 1], "##end") == 0)
                add_node_at_back(tab[i], &head->end);
            else
                add_node_at_back(tab[i], &head);
        }
    }
    for (node_t *tmp = head; tmp; tmp = tmp->next) {
        while ((s = my_check(tab, tmp->name)))
            add_neighbour(&tmp->neighbourg, s);
    }
    while ((s = my_check(tab, head->start->name)))
        add_neighbour(&head->start->neighbourg, s);
    while ((s = my_check(tab, head->end->name)))
        add_neighbour(&head->end->neighbourg, s);
}

int main(void)
{
    lemin_t lemin;
    char *buffer = get_file();
    node_t *head = NULL;

    if (check_error(buffer) == 1) {
        free(buffer);
        return (84);
    }
    lemin.tab = my_str_to_word_array(buffer, '\n');
    for (int a = 0; lemin.tab[a]; a++) {
        if (lemin.tab[a][0] == '#' && lemin.tab[a][1] != '#')
            lemin.tab[a][0] = '\0';
    }
    create_rooms(lemin.tab, head);
    get_nb_of_ants(&lemin, buffer);
    my_printf("#number_of_ants\n%d\n", lemin.nb_of_ants);
    my_free(&lemin, buffer);
    // find_bigger(&lemin);
    // start(&lemin);
    // my_free(&lemin, buffer);
    return (0);
}