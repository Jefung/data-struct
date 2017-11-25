#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE
#include <iostream>
using namespace std;
template <class T>
class Node {
public:
    Node *parent, *lchild, *rchild;
    T data;
    int color; //0黑1红
    Node() {
        parent = NULL;
        lchild = this;
        rchild = this;
        color = 0;
    }
};

// template <class T>
// Node<T> *NIL = new Node<T>();
template <class T>
class RedBlackTree {

public:
    Node<T> *root;
    Node<T> *NIL;
	Node<T> *head;
    RedBlackTree() {
        NIL = new Node<T>;
        root = NIL;  //为空时指向自定义空节点
		head = NIL;
    }

    void RBInsert(T item) {
        //构造新节点
        Node<T> *insert_node = new Node<T>;
        insert_node->color = 1;
        insert_node->data = item;

        //判断待入节点的父元素（插入节点一定是叶子）
        Node<T> *insert_pos = NIL;
        Node<T> *temp = root;
        while(temp != NIL)	{
            insert_pos = temp;
            if(insert_node->data < temp->data)
                temp = temp->lchild;
            else temp = temp->rchild;
        }

        insert_node->parent = insert_pos;
        if(root == NIL)
            root = insert_node;
        else {
            if(insert_node->data < insert_pos->data)
                insert_pos->lchild = insert_node;
            else insert_pos->rchild = insert_node;
        }

        insert_node->lchild = NIL;
        insert_node->rchild = NIL;

        RBInsertFixup(insert_node);
    }

    void RBInsertFixup(Node<T> *insert_node) {
        while(insert_node->parent->color == 1) {
            if(insert_node->parent->parent->lchild == insert_node->parent) {
                //叔处于父的右边
                Node<T> *insert_uncle = insert_node->parent->parent->rchild;
                if(insert_uncle->color == 1) {
                    insert_uncle->color = 0;
                    insert_node->color = 0;
                    insert_node->parent->parent->color = 1;
                    insert_node = insert_node->parent->parent;
                } else {
                    //插入节点处于右子树
                    if(insert_node->parent->rchild == insert_node) {
                        insert_node = insert_node->parent;
                        LeftRotate(insert_node);
                        insert_node->parent->color = 0;
                        insert_node->parent->parent->color = 1;
                        RightRotate(insert_node->parent->parent);
                    } else {
                        insert_node = insert_node->parent;
                        RightRotate(insert_node);
                        insert_node->parent->color = 0;
                        insert_node->parent->parent->color = 1;
                        RightRotate(insert_node->parent->parent);
                    }
                }
            } else {
                Node<T> *insert_uncle = insert_node->parent->parent->lchild;
                if(insert_uncle->color == 1) {
                    insert_uncle->color = 0;
                    insert_node->color = 0;
                    insert_node->parent->parent->color = 1;
                    insert_node = insert_node->parent->parent;
                } else {

                    if(insert_node->parent->rchild == insert_node) {
                        insert_node = insert_node->parent;
                        LeftRotate(insert_node);
                        insert_node->parent->color = 0;
                        insert_node->parent->parent->color = 1;
                        LeftRotate(insert_node->parent->parent);
                    } else {
                        insert_node = insert_node->parent;
                        RightRotate(insert_node);
                        insert_node->parent->color = 0;
                        insert_node->parent->parent->color = 1;
                        LeftRotate(insert_node->parent->parent);
                    }
                }
            }

        }
        root->color = 0;
    }

    //左旋
    void LeftRotate(Node<T> *p) {
        //提上右孩子
        Node<T> *p_rchild = p->rchild;
        p->rchild = p_rchild->lchild;
        if(p_rchild->lchild != NIL)
            p_rchild->lchild->parent = p;
        p_rchild->parent = p->parent;
        if(p->parent == NIL) {
            root = p_rchild;
            root->parent = NIL;
        } else {
            if(p->parent->lchild == p)
                p->parent->lchild = p_rchild;
            else p->parent->rchild = p_rchild;
        }
        p_rchild->lchild = p;
        p->parent = p_rchild;
    }

    //右旋
    void RightRotate(Node<T> *origin) {
        Node<T> *origin_lchild = origin->lchild;
        // origin->lchild = origin_lchild->rchild;
        // if(origin_lchild->rchild != NIL)
        //     origin_lchild->rchild->parent = origin;

        //提上左孩子
        origin_lchild->parent = origin->parent;
        if(origin->parent == NIL) {
            root = origin_lchild;
            root->parent = NIL;
        } else {
            if(origin->parent->lchild == origin)
                origin->parent->lchild = origin_lchild;
            else origin->parent->rchild = origin_lchild;
        }
        //移动原主节点的左孩子
        origin->lchild = origin_lchild->rchild;
        if(origin_lchild->rchild != NIL)
            origin_lchild->rchild->parent = origin;

        //降下原主节点
        origin_lchild->rchild = origin;
        origin->parent = origin_lchild;
    }

    void PreOrder(Node<T> *p = NULL) {
        if(root == NULL) {
            cout << "please create tree first!" << endl;
            return;
        }
        if(p == NULL) {
            p = root;
        }
        if(p->lchild == NULL && p->rchild == NULL) {
            cout << p->data << " " << endl;
            return;
        }
        cout << p->data << " " << endl;
        if(p->lchild != NIL) {
            PreOrder(p->lchild);
        }
        if(p->rchild != NIL) {
            PreOrder(p->rchild);
        }
    }

    //删除节点
    bool RBDelete(T item) {
		//获取待删除节点
        Node<T> *del_node = GetNodeByValue(item, root);
        if(del_node == NULL)
            return false;
		
		//
		Node<T> *temp;
		if(del_node->rchild == NIL || del_node->lchild == NIL)
			temp = del_node;
		else temp = GetSuccessor(del_node);	

		
		Node<T> *del_child;
		if(temp->rchild != NIL)
			del_child = temp->rchild;
		else del_child = temp->lchild;

		del_child->parent = temp->parent;
		if(temp->parent == NIL){
			root = del_node;
			root->parent = NIL;
		}
		else {
			if(temp->parent->lchild == temp)
				temp->parent->lchild = del_child;
			else temp->parent->rchild = del_child;
		}

		if(temp != del_node){
			del_node->data = temp->data;
		}

		return true;
	}	

    Node<T>* GetSuccessor(Node<T> *p) {
        if(p == NIL)
            return NULL;
        if(p -> rchild == NIL) {
            //p的右孩子为空，则寻找他的父亲，直到找到比他大的元素，找不到则表示在线索最后，返回head
            int data = p->data;
            while(p->parent != NIL) {
                p = p->parent;
                if(p->data > data)
                    return p;
            }
            return NIL;
        } else {
            //存在右子树，返回右子树的最小值
            p = p->rchild;
            for(; p->lchild != NIL; p = p->lchild);
            cout << endl;
            return p;
        }
    }


    //由值获取节点（相同节点只获取第一个遍历到的)
    Node<T>* GetNodeByValue(T item, Node<T> * p) {
        if( p == NIL )
            return NULL;
        if(item == p->data)
            return p;
        if(item > p->data)
            return GetNodeByValue(item, p->rchild);
        else return GetNodeByValue(item, p->lchild);
    }
};

#endif
