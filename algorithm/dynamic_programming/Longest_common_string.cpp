//最小子串问题
//问题参考链接:https://blog.csdn.net/mc695192383/article/details/70146579
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
	int str1_len = 9;
	int str2_len = 7;
	char str1[] = "1AB2345CD";
	char str2[] = "12345EF";
	int longest_len = 0;

	int **dp = new int *[str1_len];
	for(int i = 0; i < str1_len; i++){
		dp[i] = new int[str2_len];
	}

	for(int i = 0; i < str1_len; i++){
		for(int j = 0; j < str2_len; j++){
			dp[i][j] = 0;
		}
	}

	for(int i = 0; i < str2_len; i++){
		dp[0][i] = str1[0] == str2[i]?1:0;
	}

	for(int i = 0; i < str1_len; i++){
		dp[i][0] = str1[i] == str2[0]?1:0;
	}


	for(int i = 1; i < str1_len ; i++){
		for(int j = 1; j < str2_len; j++){
			if(str1[i] == str2[j]){
				dp[i][j] = dp[i-1][j-1] + 1;
				if(longest_len < dp[i][j])
					longest_len = dp[i][j];
			}
		}
	}

	// for(int i = 0; i < str1_len; i++){
	//     for(int j = 0; j < str2_len; j++){
	//         std::cout << dp[i][j] << " ";
	//     }
	//     std::cout << endl;
	// }
	std::cout << "longest common string length: " << longest_len << std::endl;
}
