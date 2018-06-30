#include <algorithm>
#include <iostream>
using namespace std;
	
int main( int argc, char *argv[] ) {
    int str1_len = 3;
    int str2_len = 3;
    char str1[] = "abc";
    char str2[] = "adc";

    int del_cost = 3;
    int insert_cost = 5;
    int modify_cost = 100;

    int dp[str1_len][str2_len];

    // 初始化dp
    for( int i = 0; i < str1_len; i++ ) {
        for( int j = 0; j < str2_len; j++ ) {
            dp[i][j] = 0;
        }
    }

    // 初始化第一行
    for( int i = 1; i < str2_len; i++ ) {
        dp[0][i] = insert_cost * i;
    }

    // 初始化第一列
    for( int i = 1; i < str1_len; i++ ) {
        dp[i][0] = del_cost * i;
    }

    for( int i = 1; i < str1_len; i++ ) {
        for( int j = 1; j < str2_len; j++ ) {
            if( str1[i] == str2[j] )
                dp[i][j] = dp[i - 1][j - 1];
            else {
                dp[i][j] =
                    min( min( dp[i - 1][j - 1] + modify_cost, dp[i - 1][j] + del_cost ),
                         dp[i][j - 1] + insert_cost );
            }
        }
    }

    std::cout << "minimum edit cost: " << dp[str1_len - 1][str2_len - 1]
              << std::endl;
}
