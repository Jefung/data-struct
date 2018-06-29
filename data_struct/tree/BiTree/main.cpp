/*
* auth        : Jefung
* version     : v1.0
* description :
*
* analyse     :
*
*/

#include <iostream>
#include <string>
// #include "BiTree.h"
using namespace std;

struct TreeNode {
    TreeNode *parent;
    TreeNode *lchild;
    TreeNode *rchild;
    char val;
};

class BiTree {
private:
	int i;
    TreeNode *root;
public:
    BiTree() {
        // root = NULL;

    }
    void createBiTree(TreeNode *&T, TreeNode *p = NULL) {
        char v;
        cout << "please enter a character to buid the next node, input '@' or ' ' or <CR> will make the node NULL:" << endl;
        cin.get(v);
        // v = getchar();
        // cin >> v;
        if(v == '@' || v == ' ' || v == '\n') {
            // cout << "space " << endl;
            T = NULL;
            return;
        } else {
            T = new TreeNode();
            T->val = v;
            T->parent = p;
            createBiTree(T->lchild, T);
            createBiTree(T->rchild, T);
        }
    }

    void preOrderTraverse(const TreeNode *T ) {
       if(T == NULL) {
            cout << "the root node is NULL" << endl;
            return;
        }
        if(T->lchild == NULL && T->rchild == NULL) {
            cout << T->val << endl;
            return;
        }
        if(T->lchild != NULL)
            preOrderTraverse(T->lchild);
        if(T->rchild != NULL)
            preOrderTraverse(T->rchild);
        cout << T->val << endl;
    }

    void clearBiTree(TreeNode *&T) {
        if(T == NULL)
            return;
        if(T->lchild != NULL)
            clearBiTree(T->lchild);
        if(T->rchild != NULL)
            clearBiTree(T->rchild);

        delete T;
        T = NULL;
    }

    bool isEmpty(TreeNode *T) {
        if(T == NULL)
            return true;
        else return false;
    }

    int getDepth(const TreeNode *node) {
        int depth = 1;
        if(node == NULL) {
            return 0;
        }
        if(node->rchild == NULL && node->lchild == NULL) {
            return 1;
        }
        depth = getDepth(node->lchild) >= getDepth(node->rchild) ? getDepth(node->lchild) + 1 : getDepth(node->rchild) + 1;
        return depth;
    }

    TreeNode* getRoot(TreeNode *node) {
        if(node == NULL) {
            throw("the node is NULL");
        }
        if(node->parent == NULL)
            return node;
        else return getRoot(node->parent);
    }

    void getValue(const TreeNode*T, const TreeNode *item) {
        if(!isIn(T, item)) {
            cout << " the item is not in the T" << endl;
            return;
        }
        cout << "item's value: " << item->val << endl;

    }

    //判断节点是否在树T内
    bool isIn(const TreeNode *T, const TreeNode *item) {
        if(T == NULL)
            return false;
        if(T == item || isIn(T->lchild, item) || isIn(T->rchild, item))
            return true;
        else return false;
    }

	void PostOderByNonrecursive(TreeNode *T){
		

	}

};
int main() {
    /* test input: 239  82  j  41  5  */
    BiTree biTree = BiTree();

    TreeNode * r = new TreeNode;
    // biTree.initBiTree(r);
    biTree.createBiTree(r);
    biTree.preOrderTraverse(r);
    // biTree.getValue(r, r->rchild->rchild->rchild);
	// TreeNode *testroot = biTree.getRoot(r->rchild);
	// cout << testroot->val << endl;
	// cout << biTree.getDepth(r);
	// biTree.clearBiTree(r);
	// biTree.preOrderTraverse(r);

}
