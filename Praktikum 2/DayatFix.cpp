#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <set>
using namespace std;

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key;
    struct bstnode_t \
        *left, *right, *parent;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value,BSTNode *parent) {
    BSTNode *newNode = new BSTNode;
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    newNode->parent = parent;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value, BSTNode *parent) {
    if (root == NULL) 
        return __bst__createNode(value, parent);

    if (value < root->key)
        root->left = __bst__insert(root->left, value, root);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value, root);
    
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

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("%d ", root->key);
        __bst__inorder(root->right);
    }
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
        bst->_root = __bst__insert(bst->_root, value, bst->_root);
        bst->_size++;
    }
}

void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}

int main(){
	
	BST tree;
	set<int>index;
	bst_init(&tree);
	
	int n;
	cin>>n;
	
	while(n--){
		int val;
		char cmd[10];
		cin>>cmd>>val;
		if(strcmp(cmd,"Insert")==0){
			bst_insert(&tree,val);
			index.insert(val);
		}else if(strcmp(cmd,"Parent")==0){
			BSTNode *temp = __bst__search(tree._root,val);
			if(val==tree._root->key){
				cout<<"Orphanage, here it comes"<<endl;
			}else if(temp == NULL){
                cout<<"Orphanage, here it comes"<<endl;
            }else{
				cout<<"Child of "<<temp->parent->key<<endl;
			}
		}else if(strcmp(cmd,"Order")==0){
			if(!bst_find(&tree,val)){
				cout<<"Orphanage, here it comes"<<endl;
			}else{
				int j = 0;
				for(auto i:index){
					j++;
					if(i == val){
						cout<<"Order : "<<j<<endl;
					}
				}
			}
		}
	}
	return 0;
}
