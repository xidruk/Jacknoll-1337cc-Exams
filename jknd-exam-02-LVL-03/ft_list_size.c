#include "ft_list.h"


// header file : ft_list.h
/*
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/


t_list *gen_new_node(void *data)
{
    t_list *new_node;
    new_node = malloc(sizeof(t_list));
    if (!new_node)
    {
        printf("Error ! <Malloc Fails , line 6 >");
        exit(1);
    }
    new_node->data = (char *)data;
    new_node->next = NULL;
    return (new_node);
}

void link_nodes(t_list *flist, t_list *nlist)
{
    flist->next = nlist;
}

int	ft_list_size(t_list *begin_list)
{
    int size;
    t_list *current_node;

    size = 0;
    current_node = begin_list;
    while (current_node != NULL)
    {
        size++;
        current_node = current_node->next;
    }
    return (size);
}

/*
//===> Example test !
int main()
{
    t_list *f_node = gen_new_node("Jack");
    t_list *s_node = gen_new_node("Bojack");
    t_list *t_node = gen_new_node("Pamela");

    link_nodes(f_node, s_node);
    link_nodes(s_node, t_node);
    int size = ft_list_size(f_node);
    printf("Size : %d", size);
    return (0);
}

*/
