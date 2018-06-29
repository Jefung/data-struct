/*
* auth        : Jefung
* version     : v1.0
* description :
*
* analyse     :
*
*/

#include <iostream>
#include "main.hpp"
#include <stdio.h>
using namespace std;

int main() {
    BinarySearchTree<int> T = BinarySearchTree<int>();

    T.InitByFile("data.txt");//直接文件初始化

    // 手动初始化
    // int x;
    // cin >> x;
    // while(x != 0){
    //     T.AddNode(x,T.root);
    //     cin >> x;
    // }
	T.PreOrder(T.root);
    // int min = T.GetMinimum();
    // int max = T.GetMaximum();
    // cout << max << endl;
	// return 0 ;
    Node<int> *temp;
    temp = T.GetNodeByValue(55, T.root);
    // if(temp == NULL)
    //     cout << "the value is not storage in the tree" << endl;
    // else
    //     cout << temp->data << endl;
    temp =  T.GetSuccessor(temp);
    if(temp == NULL)
        cout << "the value is not storage in the tree" << endl;
    else
        cout << temp->data << endl;
	T.DeleteNode(66);
	T.PreOrder(T.root);

}
