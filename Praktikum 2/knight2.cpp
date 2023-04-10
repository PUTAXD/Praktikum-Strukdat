#include <iostream>
#include <math.h>

using namespace std;
typedef struct bstnode_t
{
    unsigned long long key;
    struct bstnode_t *left, *right;
} BSTNode;

typedef struct bst_t
{
    long long ganjil, genap;
    BSTNode *_root;
    unsigned long long _size;
} BST;

BSTNode *__bst__createNode(long long value)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *__bst__insert(BSTNode *root,unsigned long long value)
{
    if (root == NULL)
        return __bst__createNode(value);

    if (value < root->key)
    {
        root->left = __bst__insert(root->left, value);
    }
    else if (value > root->key)
    {
        root->right = __bst__insert(root->right, value);
    }

    return root;
}

BSTNode *__bst__search(BSTNode *root, unsigned long long value)
{
    while (root != NULL)
    {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst)
{
    return bst->_root == NULL;
}

bool bst_find(BST *bst, unsigned long long value)
{
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, long long value)
{
    if (!bst_find(bst, value))
    {
        if (value % 2 == 0)
        {
            bst->genap = value;
        }
        else if (value % 2 != 0)
        {
            bst->ganjil = value;
        }
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

unsigned long long power(unsigned long long x, unsigned long long y, unsigned long long p)
{
    unsigned long long res = 1;
    while (y > 0)
    {
        if (y % 2 == 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res % p;
}

int main()
{
    BST set;
    bst_init(&set);
    unsigned long long input;
    bool flag = 1;
    while (scanf("%lld", &input) != EOF && flag)
    {
        if (bst_find(&set, input))
            flag = 0;
        bst_insert(&set, input);
    }
    if (flag)
    {
        puts("Tidak ada duplikat");
        return 0;
    }
    cout << power(set.genap, set.ganjil, 1e9 + 7);
    return 0;
}