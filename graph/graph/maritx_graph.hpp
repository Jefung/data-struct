#ifndef MARITX_GRAPH
#define MARITX_GRAPH
#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
// struct Graph{
//     int vertex_num
// }

typedef char Vertextype;// 顶点类型
typedef int SideType; //权值类型 

#define MAXVERTEXNUM 100
#define INFINITY 0
#define DEBUG

class MaritxGraph{
	private:
		Vertextype vertex[MAXVERTEXNUM];
		SideType maritx[MAXVERTEXNUM][MAXVERTEXNUM];
	public:
		int vertex_num; //图顶点数
		int side_num; //图边数
		MaritxGraph(){
			vertex_num = 0;
			side_num = 0;
			//初始化邻接矩阵 
			for(int i = 0; i < MAXVERTEXNUM; i++){
				for(int j = 0; j < MAXVERTEXNUM; j++){
					maritx[i][j] = INFINITY;	
				}	
			}
		}
		void Init(){
			if(vertex_num != 0 || side_num != 0){
				cout << "the graph have inited" << endl;
				return;
			}
			cout << "please enter the vertex number: ";
			cin >> vertex_num;
			while(vertex_num > MAXVERTEXNUM || vertex_num <= 0){
				cout << "the vertex num is greater than " << MAXVERTEXNUM <<", or less than zero, please enter again: ";
				cin >> vertex_num;
				cout << endl;
			}
			cout << endl;
			cout << "please enter the side number: ";
			cin >> side_num;
			while(side_num < 0){
				cout << "the side number is less than zero, please enter again: ";
				cin >> side_num;
				cout << endl;
			}
			cout << endl;
			cout << " please enter char for the graph vertex value: ";
			for(int i = 0; i < vertex_num; i++){
				vertex[i] = getchar();
				while(vertex[i] == '\n' || vertex[i] == ' ')
					vertex[i] = getchar();	
			}

			for (int i = 0; i < side_num; i++) {
				char c1,c2;
				SideType w;
				cout << "please enter the index i,j of side (vi,vj),and the weight: ";
				c1 = getchar();
				while(c1 == '\n'|| c1 == ' ')
					c1 = getchar();
				c2 = getchar();
				while(c2 == '\n'|| c2 == ' ')
					c2 = getchar();	
				cin >> w;
				 
				int m = -1;
				int n = -1;
				m = Locate(c1);
				n = Locate(c2);

				if(m < 0 || n < 0){
					cout << "the index is error, enter again:" << endl;
					i--;
					continue;
				}
				
				maritx[m][n] = w;
				maritx[n][m] = w;
			}
		}

		int Locate(Vertextype x){
			int i = 0;
			for(;i < vertex_num;i++){
				if( x == vertex[i] )
					break;
			}
			if(i>vertex_num)
				return -1;
			else return i;
		}

		void Print(){
			cout << setw(4) << " ";
			for(int i = 0; i < vertex_num; i++){
				cout <<  setw(4) << vertex[i];	
			}			
			cout << endl;
			for(int i = 0; i < vertex_num; i++){

				cout << setw(4) << vertex[i];
				for(int j = 0; j < vertex_num; j++){
					cout << setw(4) << maritx[i][j];	
				}	
				cout << endl;
			}
		}
};
#endif
