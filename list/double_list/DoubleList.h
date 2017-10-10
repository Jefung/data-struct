#pragma once
#include <iostream>
#include <string>
using namespace std;
struct node {
	string data;
	int llink;
	int rlink;
	node* next;
};
class DoubleList {
public:
	node *head, *tail;
	int size;
	DoubleList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	void insert() {
		node* p = new node;
		size++;
		cout << "please enter name:" << endl;
		cin >> p->data;
		p->llink = 0;
		p->rlink = 0;
		p->next = NULL;

		if (head == NULL) {
			head = p;
			tail = p;
			return;
		}
		tail->next = p;
		tail = tail->next;

	}
	

	void showList() {
		node* p = head;
		int i;
		for (i = 1; p->next != NULL; p = p->next,i++) {
			cout << i << "    " <<  p->data << "    " <<   p->llink << "    " <<   p->rlink << endl;
		}
		cout << i << "    " << p->data << "    " << p->llink << "    " << p->rlink << endl;
	}

	void del(int i) {
		if (size < i || i < 1) {
			cout << "请输入正确的索引" << endl;
			return;
		}
		node *q = head;
		if (size == 1) {
			head = tail = NULL;
			delete q;
			q = NULL;
			size--;
			return;
		}
		else if(i == size) {
			for (; q->next != tail; q = q->next);
			tail = q;
			
			q = tail->next;
			delete q;
			tail->next = NULL;
			size--;
			return;
		}
		for (int j = 2; j < i; q = q->next,j++);
		tail = q;
		q = tail->next;
		tail->next = NULL;
		delete q;
		q = NULL;
	}

	void book(int i) {
		if (size < i || i < 1) {
			cout << "请输入正确的索引" << endl;
			return;
		}
		node *p = head;
		for (int j = 1; j < i; j++, p = p->next);
		p->llink++;
	}
	
	void refund(int i) {
		if (size < i || i < 1) {
			cout << "请输入正确的索引" << endl;
			return;
		}
		node *p = head;
		for (int j = 1; j < i; j++, p = p->next);
		if (p->rlink <= 0) {
			cout << "数据不能小于0" << endl;
			return;
		}

		p->rlink--;
	}

};
