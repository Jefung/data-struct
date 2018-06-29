// 参考链接:https://blog.csdn.net/rock_joker/article/details/68953786

#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
	int str_len = 7;
	int arr[7] = {1,7,3,5,9,4,8};
	int longest[7] = {1,1,1,1,1,1,1};
	longest[0] = 1;
	for(int i = 1; i < str_len; i++){
		for(int j = 0; j < i; j++){
			if(arr[i] > arr[j] && longest[j] >= longest[i])
				longest[i] = longest[j]+1;
		}
	}
	int longest_len = 0;
	for(int i = 0; i < str_len; i++){
		if(longest[i] > longest_len)
			longest_len = longest[i];
	}
	std::cout << "longest increasing subsequence length: " << std::endl;
	std::cout <<  longest_len << std::endl;
}
