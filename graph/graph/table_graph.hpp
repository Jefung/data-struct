#ifndef TABLE_GRAPH
#define TABLE_GRAPH
#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

typedef char Vertextype;// 顶点类型
typedef int SideType; //权值类型

#define MAXVERTEXNUM 100
#define INFINITY 0
#define DEBUG
struct SideNode {
    int adjvex;  //邻接点域，即邻接点的下标
    SideType w;
    SideNode *next;
    SideNode() {
        next = NULL;
    }
};
struct VertexNode {
    Vertextype data;
    SideNode *first_side;
    VertexNode() {
        first_side = NULL;
    }
};

class TableGraph {
private:
    VertexNode vertex[MAXVERTEXNUM];
    int vertex_num; //图顶点数
    int side_num; //图边数
public:
    TableGraph() {
        vertex_num = 0;
        side_num = 0;
    }
    void Init() {
        if(vertex_num != 0 || side_num != 0) {
            cout << "the graph have inited" << endl;
            return;
        }
        cout << "please enter the vertex number: ";
        cin >> vertex_num;
        while(vertex_num > MAXVERTEXNUM || vertex_num <= 0) {
            cout << "the vertex num is greater than " << MAXVERTEXNUM << ", or less than zero, please enter again: ";
            cin >> vertex_num;
            cout << endl;
        }
        cout << endl;
        cout << "please enter the side number: ";
        cin >> side_num;
        while(side_num < 0) {
            cout << "the side number is less than zero, please enter again: ";
            cin >> side_num;
            cout << endl;
        }
        cout << endl;
        cout << " please enter char for the graph vertex value: ";
        for(int i = 0; i < vertex_num; i++) {
            vertex[i].data = getchar();
            while(vertex[i].data == '\n' || vertex[i].data == ' ')
                vertex[i].data = getchar();
        }
        for (int i = 0; i < side_num; i++) {
            char c1, c2;
            SideType w;
            cout << "please enter the index i,j of side (vi,vj),and the weight: ";
            c1 = getchar();
            while(c1 == '\n' || c1 == ' ')
                c1 = getchar();
            c2 = getchar();
            while(c2 == '\n' || c2 == ' ')
                c2 = getchar();
            cin >> w;

            if(!AddSide(c1, c2, w)) {
                cout << "the index is error, enter again:" << endl;
                i--;
                continue;
            }
        }
    }

	void Print(){
		for(int i = 0; i < vertex_num; i++){
			cout << vertex[i].data << ": ";
			for(SideNode *temp = vertex[i].first_side; temp != NULL; temp = temp->next){
				cout << temp->adjvex << "(" << temp->w << ")  ";
			}
			cout << endl;
		}
	}
    bool AddSide(Vertextype v1, Vertextype v2, SideType w) {
        VertexNode *temp = NULL;
        for(int i = 0; i < vertex_num; i++) {
            if(vertex[i].data == v1) {
                temp = &vertex[i];
                break;
            }
        }
        if(temp == NULL)
            return false;
        if(temp->first_side == NULL) {
            temp->first_side = new SideNode;
            temp->first_side->adjvex = v2;
            temp->first_side->w = w;
            return true;
        } else {
            SideNode *p;
            for(p = temp->first_side; p->next != NULL; p = p->next);
            p->next = new SideNode;
            p->next->adjvex = v2;
            p->next->w = w;
            return true;
        }
    }

};
#endif
