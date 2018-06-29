#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]){
	int backpack_size = 12;
	int goods_num = 6;
	int w[] = {4, 6, 2, 2, 5, 1};
	int v[] = {8, 10, 6, 3, 7, 2};

	int dp[goods_num][backpack_size+1];
	for(int i = 0; i < goods_num; i++){
		for(int j = 0; j < backpack_size+1; j++){
			dp[i][j] = 0;
		}
	}
	for(int i = 1; i < backpack_size+1; i++){
		if(i < w[0])
			dp[0][i] = 0;
		else dp[0][i] = v[0];
	}

	for(int i = 1; i < goods_num; i++){
		for(int j = 1; j < backpack_size+1; j++){
			if(j < w[i])
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
		}
	}

	for(int i = 0; i < goods_num; i++){
		for(int j = 0; j < backpack_size+1; j++){
			cout << dp[i][j] << " ";
		}
		std::cout << endl;
	}

}
