#include<stdio.h>
#include<assert.h>

typedef struct node 
{
    int value;
    struct node *left, *right;
} Node;

Node *genNode(int value, Node *left, Node *right)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    assert(ptr != NULL);
    ptr->value = value;
    ptr->left = left;
    ptr->right = right;
    return ptr;
}

/* treeAND */
Node *treeAND(Node *root1, Node *root2)
{
    if (root1 != NULL && root2 != NULL)
    {
        return genNode(root1->value * root2->value, treeAND(root1->left, root2->left), treeAND(root1->right, root2->right)); 
    }                  // 在 genNode 就會把每個根節點以二元樹的方式連接起來
    return NULL;
}

/* treeOR */
Node *treeOR(Node *root1, Node *root2)
{
    if (root1 != NULL && root2 != NULL)
    {
        return genNode(root1->value + root2->value, treeOR(root1->left, root2->left), treeOR(root1->right, root2->right));
    }
    if (root1 != NULL)
    {
        return root1;
    }
    else if(root2 != NULL)
    {
        return root2;
    }
    return NULL;
}

/* preorder */
void preorder(Node *root)
{
    if(root == NULL) return;
    printf("%d ", root->value);
    preorder(root->left);
    preorder(root->right);
}

/* inorder */
void inorder(Node *root)
{
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

Node *insertBST(Node *root, int value)
{
    if (root == NULL)
    {
        return (genNode(value, NULL, NULL));
    }
    if (value < root->value)
    {
        root->left = insertBST(root->left, value);
    }
    else
    {
        root->right = insertBST(root->right, value);
    }
    return root;
}

int main(void) 
{  
    Node *tree[2] = {NULL, NULL}; // 指標陣列喔喔, 有兩棵二元樹
    for(int t = 0; t < 2; t++)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int value;
            scanf("%d", &value);
            tree[t] = insertBST(tree[t], value);
        }
    }
    
    Node *result = treeAND(tree[0], tree[1]);
    preorder(result);
    printf("\n");
    inorder(result);
    printf("\n");
    
    result = treeOR(tree[0], tree[1]);
    preorder(result);
    printf("\n");
    inorder(result);
    printf("\n");
    
    return 0;
}