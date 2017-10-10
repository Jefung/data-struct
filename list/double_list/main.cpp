#include "main.h"

int main() {
	while (1) {
		DoubleList* L = new DoubleList();
		cout << "请输入你要的操作" << endl;
		cout << "0: 增加用户" << endl;
		cout << "1: 删除用户" << endl;
		cout << "2: 用户预定" << endl;
		cout << "3: 用户退票" << endl;
		cout << "4: 显示信息" << endl; int i;
		cin >> i;
		switch (i) {
		case 0:
			L->insert();
			break;
		case 1:
			cout << "输入删除用户索引（第一个）：" << endl;
			cin >> i;
			L->del(i);
			break;
		case 2:
			cout << "输出要预定用户的索引" << endl;
			cin >> i;
			L->book(i);
			break;
		case 3:
			cout << "输入要退票用户的索引" << endl;
			cin >> i;
			L->refund(i);
			break;
		case 4:
			L->showList();

		}
	}
}
