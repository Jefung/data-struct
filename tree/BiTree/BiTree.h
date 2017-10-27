#ifdef BITREE
#include <iostream>
using namespace std
    class BiTree {
    private:
        BiTree *lchild;
        BiTree *rchild;
        BiTree *parent;
        char *val;
    public:
        BiTree(char v = "") {
            if(v = "") {
                root = NULL;
            } else {
                initTree(v);
            }
        }
        void initTree(char &v, BiTree *p = NULL) {
            parent = p;
            lchild = NULL;
            rchild = NULL;
            val = v;
        }
        void createBiTree(BiTree *T, BiTree *p = NULL) {
            //树不为空，则已经初始化过
            if( T != NULL) {
                createBiTree(T->lchild);
                createBiTree(T->rchild);
                return;
            }

            char v;
            cout << "please enter a character to buid the next node, the space will make the node NULL:" << endl;
            ch = getchar();
            if(ch == ' ')
                n = NULL;
            else {
                T = new BiTree(ch, this);
                createBiTree(T->lchild);
                createBiTree(T->rchild);
            }
        }

        void preOrderTraverse(BiTree T) {
            if(T->lchild == NULL && T->rchild == NULL) {
                cout << T.val << endl;
                return;
            }
            if(T->lchild != NULL)
                preOrderTraverse(T->lchild);
            if(T->rchild != NULL)
                preOrderTraverse(T->rchild);
			cout << T.val << endl;
        }

    };


#endif
