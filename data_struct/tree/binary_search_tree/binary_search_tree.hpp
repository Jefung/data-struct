#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <class T>
class Node {

public:
    Node<T> *lchild, *rchild, *parent;
    T data;
    Node() {
        lchild = NULL;
        rchild = NULL;
        parent = NULL;
    }
};

template <class T>
class BinarySearchTree {
private:
public:
    Node<T> *root;
    Node<T> *head; //线索使用，左孩子指向最左元素前驱，右孩子指向最右元素的前驱
    BinarySearchTree() {
        root = NULL;
        head = new Node<T>;
        head->data = 99999;
    }

    BinarySearchTree(T item) {
        root = new Node<T>;
        root->data = item;
        root->parent = NULL;
        root->lchild = NULL;
        root->rchild = NULL;
    }

    // 传入值，增加节点
    void AddNode(T item, Node<T> *&child, Node<T> *p = NULL) {
        if(child == NULL) {
            child = new Node<T>;
            child->data = item;
            child->parent = p;
            return;
        }
        if( item >= child->data ) {
            AddNode(item, child->rchild, child);
        } else {
            AddNode(item, child->lchild, child);
        }
    }
    //前序遍历树
    void PreOrder(Node<T> *p) {
        cout << p->data << " ";
        if(p->lchild != NULL)
            PreOrder(p->lchild);
        if(p->rchild != NULL)
            PreOrder(p->rchild);
    }
    //用文件初始化树
    void InitByFile(const char *filename) {
        ifstream in(filename);
        T item;
        in >> item;
        while(item != 0) {
            AddNode(item, root);
            in >> item;
        }
    }
    //获取最小值
    T GetMinimum(Node<T> *p = NULL) {
        if(IsEmpty()) {
            throw("please init the binary search tree first!");
        }
        if(p == NULL)
            p = root;
        if(p->lchild == NULL) {
            return p->data;
        } else return GetMinimum(p->lchild);

    }

    //获取最大值
    T GetMaximum(Node<T> *p = NULL) {
        if(IsEmpty()) {
            throw("please init the binary search tree first!");
        }
        if(p == NULL)
            p = root;
        if(p->rchild == NULL) {
            return p->data;
        } else return GetMaximum(p->rchild);

    }



    bool IsEmpty() {
        return root == NULL ? true : false;
    }

    //由值获取节点（相同节点只获取第一个遍历到的)
    Node<T>* GetNodeByValue(T item, Node<T> * p) {
        if( p == NULL )
            return NULL;
        if(item == p->data)
            return p;
        if(item > p->data)
            return GetNodeByValue(item, p->rchild);
        else return GetNodeByValue(item, p->lchild);
    }

    //获取节点的前驱(按照中序)
    Node<T>* GetPredesessor(Node<T> *p) {
        //传入空节点
        if(p == NULL)
            return NULL;

        if(p->lchild == NULL) {
            //如果是根元素，且没有左子树，返回head
            if(p->parent == NULL)
                return head;
            //左孩子为空，如果处于最左边的元素，则返回head,否则返回其父元素
            if(p->parent->lchild == p)
                return head;
            return p->parent;
        } else {
            //左孩子不为空，则返回其左子树的最右元素
            Node<T> *temp = p->lchild;
            for(; temp->rchild != NULL; temp = temp->rchild);
            return temp;
        }
    }

    Node<T>* GetSuccessor(Node<T> *p) {
        if(p == NULL)
            return NULL;
        if(p -> rchild == NULL) {
            //p的右孩子为空，则寻找他的父亲，直到找到比他大的元素，找不到则表示在线索最后，返回head
            int data = p->data;
            while(p->parent != NULL) {
                p = p->parent;
                if(p->data > data)
                    return p;
            }
            return head;
        } else {
            //存在右子树，返回右子树的最小值
            p = p->rchild;
            for(; p->lchild != NULL; p = p->lchild);
            cout << endl;
            return p;
        }
    }


    //删除节点
    bool DeleteNode(T item) {
        Node<T> *del_node = GetNodeByValue(item, root);
        if(del_node == NULL)
            return false;

        //删除节点是根节点的情况
        if(del_node->parent == NULL) {
            if(del_node->rchild == NULL && del_node->lchild == NULL) {
                delete del_node;
                del_node = NULL;
                root = NULL;
                return true;
            }
            if(del_node->rchild == NULL && del_node->lchild != NULL) {
                root = del_node->lchild;
                root->parent = NULL;
                delete del_node;
                del_node = NULL;
                return true;
            }

            if(del_node->rchild != NULL && del_node->lchild == NULL) {
                root = del_node->rchild;
                root->parent = NULL;
                delete del_node;
                return true;
            }

            if(del_node->rchild != NULL && del_node->lchild != NULL) {
                Node<T> *sucessor = GetSuccessor(del_node);
                root->data = sucessor->data;
                if(sucessor->parent->rchild == sucessor)
                    sucessor->parent->rchild = sucessor->rchild;
                else
                    sucessor->parent->lchild = sucessor->rchild;
                if(sucessor->rchild != NULL)
                    sucessor->rchild->parent = sucessor->parent;
                delete sucessor;
                sucessor = NULL;
                return true;
            }
        }

        //节点没子女，直接删除（修改父节点指向为空）
        if(del_node->rchild == NULL && del_node->lchild == NULL) {
            Node<T> *del_parent = del_node->parent;
            if(del_parent->rchild == del_node)
                del_parent->rchild = NULL;
            else del_parent->lchild = NULL;
            delete del_node;
            del_node = NULL;
            return true;
        }

        //一个子女，删除，将其子女连接在父元素后面
        if((del_node->rchild != NULL && del_node->lchild == NULL) || (del_node->rchild == NULL && del_node->lchild != NULL) ) {
            Node<T> *temp = del_node->rchild != NULL ? del_node->rchild : del_node->lchild;
            if(del_node->parent->rchild == del_node)
                del_node->parent->rchild = temp;
            else del_node->parent->lchild = temp;
            temp->parent = del_node->parent;
            delete del_node->rchild;
            del_node = NULL;
            return true;
        }

        //二个子女，寻找其后继，用后继内容取代待删除节点内容（不删除原本要删除的节点），删除后继节点
        if(del_node->rchild != NULL && del_node->lchild != NULL) {
            Node<T> * sucessor = GetSuccessor(del_node);
			del_node->data = sucessor->data;
            if(sucessor->parent->rchild == sucessor)
                sucessor->parent->rchild = sucessor->rchild;
            else
                sucessor->parent->lchild = sucessor->rchild;
            if(sucessor->rchild != NULL)
                sucessor->rchild->parent = sucessor->parent;
            delete sucessor;
            sucessor = NULL;
            return true;
        }
        return true;
    }
};


#endif
