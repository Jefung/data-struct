// 问题描述: https://blog.csdn.net/amds123/article/details/60468360
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int height=0;
	
	//init trangle
	height = 5;
	int **trangle = new int*[height];
	for (int i = 0; i < height; ++i) {
		trangle[i] = new int[height];	
	}

	for (int i = 0; i < height; ++i) {
		for(int j = 0; j < height; j++)
			trangle[i][j] = -1;
	}

	trangle[0][0] = 7;
	trangle[1][0] = 3;
	trangle[1][1] = 8;
	trangle[2][0] = 8;
	trangle[2][1] = 1;
	trangle[2][2] = 0;
	trangle[3][0] = 2;
	trangle[3][1] = 7;
	trangle[3][2] = 4;
	trangle[3][3] = 4;
	trangle[4][0] = 4;
	trangle[4][1] = 5;
	trangle[4][2] = 2;
	trangle[4][3] = 6;
	trangle[4][4] = 5;
	
	// show trangle
	std::cout << "show origin trangle " << std::endl;
	for(int i = 0; i < height; i++){
		for(int j = 0; j < height; j++){
			std::cout << trangle[i][j] << " ";
		}
		std::cout << endl;	
	}
	
	int *max_trangle = new int[height];
	for (int i = 0; i < height; i++) {
		max_trangle[i] = trangle[height-1][i];
	}

	std::cout << "show recursion: " << std::endl;
	for(int i = height-2; i >= 0; i--){
		for(int j = 0; j <= i; j++){
			max_trangle[j] = max(max_trangle[j],max_trangle[j+1])+trangle[i][j];
		}
		for(int k = 0; k < height; k++){
			std::cout << max_trangle[k] << " ";
		}
		std::cout << endl;
	}

	std::cout << "max path:" << std::endl;
	std::cout << max_trangle[0] << std::endl;
}
