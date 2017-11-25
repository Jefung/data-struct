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
using namespace std;
int main(){
	RedBlackTree<int> RBT = RedBlackTree<int>();
	RBT.RBInsert(7);
	// RBT.RBInsert(4);
	RBT.RBInsert(8);
	RBT.RBInsert(15);
	RBT.RBInsert(11);
	// RBT.RBInsert(11);
	RBT.RBInsert(2);
	RBT.RBInsert(1);
	RBT.RBInsert(5);
	RBT.RBInsert(4);
	// RBT.RBInsert(15);
	RBT.RBInsert(14);
	// RBT.RBInsert(11);
	RBT.RBInsert(17);
	RBT.RBInsert(18);
	RBT.RBInsert(19);
	RBT.RBInsert(20);
	
	RBT.PreOrder();	
	cout << endl;
	cout << "------------------" << endl;
	RBT.RBDelete(2);
	RBT.PreOrder();	
}
