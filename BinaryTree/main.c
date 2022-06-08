#include <stdio.h>
#include <stdlib.h>
//this is a demo program to describe how tree works
//here i used pointer to a pointer
//run the program repeatedly will realise some parts.
//for easy understanding i am using function almost for every work

typedef struct node {
int data;
struct bin_tree * right, * left;
}node;


void insert(node ** tree, int val)
{
    node *temp = NULL;
    if((*tree==NULL)){
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data){
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

void print_preorder(node * tree)
{
    if (tree)
    {
        printf("%d, ",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}

void print_inorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d, ",tree->data);
        print_inorder(tree->right);
    }
}

void print_postorder(node * tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d, ",tree->data);
    }
}

void deltree(node * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

node* search(node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}



int main()
{
    node *root;
    node *tmp;
    //int i;

    root = NULL;
    int arr[]={9,4,15,6,12,17,2,33,23,18,19,21,71,2};
    int i=0;
    /* Inserting nodes into tree from array*/
    while(i<14){
        insert(&root, arr[i++]);
    }


    /* Printing nodes of tree */
    printf("\nPre Order Display\n");
    print_preorder(root);

    printf("\nIn Order Display\n");
    print_inorder(root);

    printf("\nPost Order Display\n");
    print_postorder(root);

    /* Search node into tree */
    tmp = search(&root, 4);
    if (tmp)
    {
        printf("\nSearched node=%d\n", tmp->data);
    }
    else
    {
        printf("\nData Not found in tree.\n");
    }

    /* Deleting all nodes of tree */
    deltree(root);
    return 0;
}
