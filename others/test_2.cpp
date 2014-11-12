#include<iostream>

#include<iostream>

struct tree
{
    int data;
    tree *left, *right;
};

class Btree
{
    static int n;
    static int m;
public:
    tree *root;
    Btree()
    {
        root=NULL;
    }

    int absDiff();

private:
    void create_Btree(int);
    void minMax(int *min, int *max);
    void Preorder(tree *, int *, int *);
};

int Btree::n=0;
int Btree::m=0;

void Btree::create_Btree(int x)
{
    tree *newnode = new tree;
    newnode->data = x;
    newnode->right = newnode->left = NULL;
    if(root == NULL) {
        root=newnode;
    } else {
        tree *back = NULL;
        tree *current = root;
        while(current != NULL)
        {
            back = current;
            if(current->data > x)
                current = current->left;
            else
                current = current->right;
        }
        if(back->data > x)
            back->left = newnode;
        else
            back->right = newnode;
    }
}

void Btree::Preorder(tree *tree, int *min, int *max)
{
    if(tree != NULL)
    {
        int value = tree->data;
        if (value > *max)
        {
            *max = value;
        }

        if (value < *min)
        {
            *min = value;
        }

        Preorder(tree->left, min, max);
        Preorder(tree->right, min, max);
    }
}

void Btree::minMax(int *min, int *max)
{
    Preorder(root, min, max);
}

int Btree::absDiff()
{
    int min = root->data;
    int max = min;
    minMax(&min, &max);
    return abs(min - max);
}

int main()
{
    Btree A;
    int array[] = {1, 2, 3, 4, 10, 21};
    int k;
    k = sizeof(array) / sizeof(array[0]);
    for(int i=0;i<k;i++)
    {
        A.create_Btree(array[i]);
    }

    int min = array[0], max = array[0];
    A.minMax(&min, &max);
    return 0;
}


