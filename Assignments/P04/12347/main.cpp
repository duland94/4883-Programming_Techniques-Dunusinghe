#include <cstdlib>
#include <cstdio>

const int data_size = 10001;

//CREATING THE NODE
typedef struct _node
{
    _node *left;
    _node *right;
    int data;
} node;
node Node[data_size];
int numTrees = 0;

void insert(node *&r, int data)
{
    if (!r)
    {
        r = &Node[numTrees++];
        r->data = data;
        r->left = NULL;
        r->right = NULL;
    }
    else if (data < r->data)
    {
        insert(r->left, data);
    }
    else
    {
        insert(r->right, data);
    }
}

void print(node *r)
{
    if (r)
    {
        print(r->left);
        print(r->right);
        printf("%d\n", r->data);
    }
}

int data[data_size];

int main()
{
    int size = 0;
    while (~scanf("%d", &data[size]))
    {
        size++;
    }
    if (size)
    {
        node *root = NULL;
        for (int i = 0; i < size; ++i)
        {
            insert(root, data[i]);
        }
        print(root);
    }

    return 0;
}
