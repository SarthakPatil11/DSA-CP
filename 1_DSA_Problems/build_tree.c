#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node * buildtree(node *root) {
    int data = 0;
    printf("Enter data :");
    scanf("%d", &data);

    if (data == -1)
    {
        return NULL;
    }
    
    root = (node *) malloc(sizeof(node));
    root->data = data;

    printf("Enter left of %d", root->data);
    root->left = buildtree(root->left);

    printf("Enter right of %d", root->data);
    root->right = buildtree(root->right);

    return root;
}

int main(void) {
    node *root;
    root = buildtree(root);
    printf("%d", root->data);
    return 0;
}