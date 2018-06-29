#ifndef ACROSS_GRAPH
#define ACROSS_GRAPH
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;
typedef char Vertextype;
typedef int SideType;
#define MAXVERTEXNUM 100
#define INFINITY 0
#define DEBUG
#define NOREAD 0
#define READ 1
//2是为了不和其他头文件的节点冲突
struct VertexNode2;
//定义边节点　
struct SideNode2 {
    int headvex;  //弧的起点下标
    int tailvex;  //弧的终点下标
    SideType w;
    SideNode2 *headlink; //指向下一个起点相同的弧
    SideNode2 *taillink; //指向下一个终点相同的弧
    SideNode2() {
        headlink = NULL;
        taillink = NULL;
    }
    SideNode2(int head, int tail, SideType weight) {
        w = weight;
        headvex = head;
        tailvex = tail;
    }
};

//定义顶点节点
struct VertexNode2 {
    Vertextype data;
    SideNode2 *firstin;
    SideNode2 *firstout;
    int flag;
    VertexNode2() {
        firstin = NULL;
        firstout = NULL;
        flag = NOREAD;
    }
};


class AcrossGraph {
private:
    VertexNode2 vertex[MAXVERTEXNUM];
    int vertex_num; //图顶点数
    int side_num; //图边数

public:
    AcrossGraph() {
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

    bool AddSide(char head, char tail, SideType w) {
        //由弧两边的点找出对应指针
        VertexNode2 *phead = NULL;
        int headvex, tailvex;
        for(headvex = 0; headvex < vertex_num; headvex++) {
            if(vertex[headvex].data == head) {
                phead = &vertex[headvex];
                break;
            }
        }
        if(phead == NULL)
            return false;

        VertexNode2 *ptail = NULL;
        for(tailvex = 0; tailvex < vertex_num; tailvex++) {
            if(vertex[tailvex].data == tail) {
                ptail = &vertex[tailvex];
                break;
            }
        }
        if(ptail == NULL)
            return false;
        //生成新节点
        SideNode2 *pside = new SideNode2(headvex, tailvex, w);

        //将节点加入十字链表中
        //先加入出度相同的链表中
        if(phead->firstout == NULL)
            phead->firstout = pside;
        else {
            SideNode2 *temp = phead->firstout;
            for(; temp->headlink != NULL; temp = temp->headlink);
            temp->headlink = pside;
        }

        if(ptail->firstin == NULL)
            ptail->firstin = pside;
        else {
            SideNode2 *temp = ptail->firstin;
            for(; temp->taillink != NULL; temp = temp->taillink);
            temp->taillink = pside;
        }
        return true;
    }
    void Print() {
        cout << "print the same firstin node:" << endl;
        for(int i = 0; i < vertex_num; i++) {
            cout << vertex[i].data << ": ";
            for(SideNode2 *temp = vertex[i].firstout; temp != NULL; temp = temp->headlink) {
                cout << vertex[temp->tailvex].data << "(" << temp->w << ")  ";
            }
            cout << endl;
        }
        cout << "print the same firstin node:" << endl;
        for(int i = 0; i < vertex_num; i++) {
            cout << vertex[i].data << ": ";
            for(SideNode2 *temp = vertex[i].firstout; temp != NULL; temp = temp->taillink) {
                cout << vertex[temp->headvex].data << "(" << temp->w << ")  ";
            }
            cout << endl;
        }
    }

    //depth first search 深度优先遍历
    void DFS() {
        if(vertex_num == 0) {
            cout << "please init first!" << endl;
            return;
        }
        if(vertex[0].flag == READ)
            for(int i = 0; i < vertex_num; i++)
                vertex[i].flag = NOREAD;

        for(int i = 0; i < vertex_num; i++) {
            Dfs(i);
        }
    }

    void Dfs(int index) {
        if(index >= vertex_num) {
            cout << "the index is larger than " << vertex << endl;
            exit(1);
        }

        if(vertex[index].flag == READ)
            return;
        cout << vertex[index].data << "->" << endl;
        vertex[index].flag = READ;
        if(vertex[index].firstout == NULL)
            return;
        SideNode2 *temp = vertex[index].firstout;
        for(; temp!= NULL; temp = temp->headlink) {
            if(vertex[temp->tailvex].flag == READ)
                continue;
            Dfs(temp->tailvex);
        }
    }

    void BFS() {
        if(vertex_num == 0) {
            cout << "please init first!" << endl;
            return;
        }
        if(vertex[0].flag == READ)
            for(int i = 0; i < vertex_num; i++)
                vertex[i].flag = NOREAD;

        for(int i = 0; i < vertex_num; i++) {
            Bfs(i);
        }
    }
    void Bfs(int index) {
        if(index >= vertex_num) {
            cout << "the index is larger than " << vertex << endl;
            exit(1);
        }
        if(vertex[index].flag == READ)
            return;
        cout << vertex[index].data << "-> " ;
        vertex[index].flag = READ;
        if(vertex[index].firstout == NULL)
            return;
        SideNode2 *temp = vertex[index].firstout;
        for(; temp != NULL; temp = temp->headlink) {
            if(vertex[temp->tailvex].flag == READ)
                continue;
            else {
                cout << vertex[temp->tailvex].data << " -> ";
				vertex[temp->tailvex].flag = READ;
            }
        }
        temp = vertex[index].firstout;
        for(; temp != NULL; temp = temp->headlink) {
            Bfs(temp->tailvex);
        }

    }
};

#endif
