#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key;
    int index;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
	newNode->index = 1;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key){
    	root->left = __bst__insert(root->left, value);
    	root->index++; 
		}
       
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}



/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

int index(BST *bst, int val){
	
}

int bst_findindex(BSTNode *bst, int value, int *counter) {
    if(bst==NULL) return 0;
    else if(bst->key==value) return (*counter)+bst->index;
    else if(value <bst->key) return (bst_findindex(bst->left, value, counter));
    else if(value>bst->key){
        (*counter)+=bst->index;
        return(bst_findindex(bst->right, value, counter));
    }
    return 0;
}


int main(){
	
	BST tree;
	bst_init(&tree);
	
	int n;
	cin>>n;
	while(n--){
		char cmd;
		int val;
		cin>>cmd>>val;
		if(cmd == 'T'){
			bst_insert(&tree, val);
		}else if(cmd == 'L'){
			int counter = 0;
			int index = bst_findindex(tree._root, val, &counter);
			cout<< index <<endl;
		}
	}
	return 0;
}
