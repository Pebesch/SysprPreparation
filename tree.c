#include <stdio.h>
#include <stdlib.h>

#define MAX_CHILDREN 3

typedef struct node {
  // Pointer to label string
  char *label;
  // Pointer to array of nodes
  struct node *children[MAX_CHILDREN];
} Node;

void traverse(struct node* root);

int main(int argc, char *argv[])
{
  Node *n00 = malloc(sizeof(Node));
  n00->label = "I am left left";
  n00->children[0] = NULL;
  n00->children[1] = NULL;
  n00->children[2] = NULL;

  Node *n01 = malloc(sizeof(Node));
  n01->label = "I am left middle";
  n01->children[0] = NULL;
  n01->children[1] = NULL;
  n01->children[2] = NULL;

  Node *n02 = malloc(sizeof(Node));
  n02->label = "I am left right";
  n02->children[0] = NULL;
  n02->children[1] = NULL;
  n02->children[2] = NULL;

  Node *n0 = malloc(sizeof(Node));
  n0->label = "I am left";
  n0->children[0] = n00;
  n0->children[1] = n01;
  n0->children[2] = n02;

  Node *n1 = malloc(sizeof(Node));
  n1->label = "I am right";
  n1->children[0] = NULL;
  n1->children[1] = NULL;
  n1->children[2] = NULL;

  Node *root = malloc(sizeof(Node));
  root->label = "root";
  root->children[0] = n0;
  root->children[1] = NULL;
  root->children[2] = n1;

  printf("Traversing\n");
  traverse(root);
  printf("Finished\n");

  free(root);
  free(n1);
  free(n0);
  free(n02);
  free(n01);
  free(n00);

  return 0;
}

void traverse(struct node* root)
{
  if(root == NULL)
  {
    return;
  }
  

  printf("%s\n",root->label);
  traverse(root->children[0]);
  traverse(root->children[1]);
  traverse(root->children[2]);
}
