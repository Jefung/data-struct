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

int main(int argc, char *argv[] ){
	// MaritxGraph graph = MaritxGraph();
	// TableGraph graph = TableGraph();
	AcrossGraph graph = AcrossGraph();
	graph.Init();
	graph.Print();
	graph.BFS();
}
