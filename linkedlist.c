#include "linkedlist.h"

void print_list(struct node *list) {
  printf("list [%d", list->i);
  int tmp = -1;
  struct node *node = list->next;
  //struct node *node = calloc(1, sizeof(struct node));
  //node = list->next;
  while(1) {
    if(!node) {
      printf("]\n");
      //free(node);
      break;
    }
    printf(", %d", node->i);
    node = node->next;
  }
}

struct node * insert_front(struct node *list, int val) {
  struct node * new_front = malloc(sizeof(struct node));
  new_front->i = val;
  new_front->next = list;
  return new_front;
}

struct node * free_list(struct node *list) {
  if(!list) return NULL;
  printf("Freeing list:\n");
  struct node * prev = list;
  struct node * node = list->next;
  free_nullify(prev);
  while(1) {
    if(!node || !node->next) break;
    prev = node;
    node = node->next;
    free_nullify(prev);
  }
  if(node) {
    free_nullify(node);
    return NULL;
  }
  if(node->next) free_nullify(node->next);
  return NULL;
}

void free_nullify(struct node *val) {
  printf("Freeing node: %d\n", val->i);
  free(val);
  val = NULL;
}

struct node * remove_data(struct node *front, int data) {
  struct node * prev = front;
  struct node * next = front->next;
  if(front->i == data) {
    printf("Removing %d\n", front->i);
    free_nullify(front);
    print_list(front);
    return front->next ? front->next : NULL;
  }
  while(next) {
    if(next->i == data) {
      prev->next = next->next;
      printf("Removing %d\n", next->i);
      free_nullify(next);
      print_list(front);
      return front;
    }
    prev = next;
    if(!next->next) return front;
    next = next->next;
  }
}

/*
int * get_vals(struct node *list) {
  int *arr = malloc(10 * sizeof(int));
  int index = 0;
  struct node node = list;
  while(1) {
    if(node == NULL) break;
    if(index > size) arr = realloc(arr, (index + 1) * sizeof(int));
    arr[index] = node.i;
  }
  return arr;
}
*/
