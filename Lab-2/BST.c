
#include<stdio.h>
#include<stdlib.h>

 typedef struct node
 {
    int data;
    struct node * left;
    struct node * right;
 }node;

 node * create_node(int value)
 {
    node * newnode= (node *)malloc(sizeof(node));
    newnode->data=value;
    newnode->left=newnode->right=NULL;
    return newnode;
 }

    node *   insert(node * root,int value)
       {
        if(root==NULL)
        {
            return create_node(value);
        }
        else if(root->data>value)
        {
            root->left=insert(root->left,value);
        }
        else if(root->data<value)
        {
            root->right=insert(root->right,value);

        }
        return root;
       }
 void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        
        inorder(root->right);
    }
}

 int main()
 {

    node * root=NULL;
   root= insert(root,50);
    insert(root,40);
    insert(root,30);
    insert(root,45);
    insert(root,60);
    printf("Inorder Traversal:");
    inorder(root);
 }
