#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *right_node;
    struct node *left_node;
}Node;

Node *init_node(int input_value){
    Node *temp = (struct node *) malloc(sizeof(struct node));
    temp ->value = input_value;
    temp ->left_node = temp ->right_node = NULL;
    return temp;
}

Node *insert_node(Node *node, int input_value){
    if (node == NULL) return init_node(input_value);
    if (input_value < node ->value)
        node->left_node = insert_node(node->left_node, input_value);
    else if(input_value > node ->value)
        node ->right_node = insert_node(node ->right_node, input_value);

    return node;
}

void in_order(Node *node){
    if (node != NULL)
    {    
        in_order(node ->left_node);
        printf("%d\n", node ->value);
        in_order(node ->right_node);
    }
    
}

int main(){
    Node *a = NULL;
    int input_arr[] = {10, 7, 11, 6, 8, 20, 1, 9, 14, 22};
    for (int i = 0; i < (sizeof input_arr/ sizeof input_arr[0]); i++)
    {
        a = insert_node(a, input_arr[i]);
    }
    in_order(a);
    return 0;
}