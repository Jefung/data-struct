#include <iostream>
#include <algorithm>
using namespace std;

int get_longest_commom_subsequence_lenth(char *str1,int str1_len, char *str2, int str2_len){
	if(str1_len == 0 || str2_len == 0)
		return 0;
	if(str1[str1_len-1] == str2[str2_len])
		return get_longest_commom_subsequence_lenth(str1,str1_len-1,str2,str2_len-1) + 1;
	else
		return max(get_longest_commom_subsequence_lenth(str1,str1_len-1,str2,str2_len),\
				get_longest_commom_subsequence_lenth(str1,str1_len,str2,str2_len-1));

}
int main(int argc, char *argv[]){
	int str1_len = 10;
	int str2_len = 12;
	char str1[] = "1A2C3D4B56";
	char str2[] = "B1D23CA45B6A";
	
	std::cout << "longest common subsequence: ";
	std::cout << get_longest_commom_subsequence_lenth(str1,str1_len,str2,str2_len) << std::endl;

}
