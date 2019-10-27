# include <stdio.h>
# include <stdlib.h>

struct node { int i; struct node *next; };

void print_list(struct node *list);
struct node * insert_front(struct node *list, int val);
struct node * free_list(struct node *list);
struct node * remove_data(struct node *front, int data);
void free_nullify(struct node *val);
// int * get_vals(struct node *list);
