#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

struct task {
  char command[MAX_LENGTH];
  int required_time;
};

struct node {
  struct task task_data;
  struct node *parent;
  struct node *first_child;
  struct node *next_sibling;
};

struct node *create_node(struct task task_data, struct node *parent) {
  struct node *new_node = (struct node*) malloc(sizeof(struct node));
  if (new_node == NULL) {
    printf("Error: memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  strcpy(new_node->task_data.command, task_data.command);
  new_node->task_data.required_time = task_data.required_time;
  new_node->parent = parent;
  new_node->first_child = NULL;
  new_node->next_sibling = NULL;
  return new_node;
}

void add_child(struct node *parent, struct node *child) {
  if (parent->first_child == NULL) {
    parent->first_child = child;
  }
  else {
    struct node *current = parent->first_child;
    while (current->next_sibling != NULL) {
      current = current->next_sibling;
    }
    current->next_sibling = child;
  }
}

void print_tree(struct node *root, int indent) {
  if (root == NULL) {
    return;
  }
  for (int i = 0; i < indent; i++) {
    printf("  ");
  }
  printf("%s (%d)\n", root->task_data.command, root->task_data.required_time);
  struct node *current = root->first_child;
  while (current != NULL) {
    print_tree(current, indent + 1);
    current = current->next_sibling;
  }
}

int main() {
  struct task task1 = {"cmd1", 5};
  struct task task2 = {"cmd2", 7};
  struct task task3 = {"cmd3", 2};
  struct task task4 = {"cmd4", 10};
  
  struct node *root = create_node(task1, NULL);
  struct node *child1 = create_node(task2, root);
  struct node *child2 = create_node(task3, root);
  struct node *child3 = create_node(task4, root);
  
  add_child(root, child1);
  add_child(root, child2);
  add_child(root, child3);
  
  struct task task5 = {"cmd5", 8};
  struct task task6 = {"cmd6", 3};
  
  struct node *child4 = create_node(task5, child1);
  struct node *child5 = create_node(task6, child1);
  
  add_child(child1, child4);
  add_child(child1, child5);
  
