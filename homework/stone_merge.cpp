#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    // int stone_num;
    // cin >> stone_num;
    // int arr[stone_num];
    // for (int i = 0; i < stone_num; ++i) {
    //     cin >> arr[i];
    // }

    int stone_num;
    while (cin >> stone_num) {
		if(stone_num == 0){
		 	break;
		}
        int arr[stone_num];
		for (int i = 0; i < stone_num; ++i) {
			cin >> arr[i];	
		}
        int dp[stone_num][stone_num];
		
        for (int i = 0; i < stone_num; ++i) {
            for (int j = 0; j < stone_num; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i < stone_num; ++i) {
            dp[0][i] = arr[i];
        }

        int min_score = 0;
        for (int i = 0; i < stone_num - 1; ++i) {
            int merger_point = 0;
            int min_merger = 0;
            for (int j = 0; j < stone_num - i; j++) {
                int cur_merger = 0;
                if (j != stone_num - 1 - i)
                    cur_merger = dp[i][j] + dp[i][j + 1];
                else
                    cur_merger = dp[i][0] + dp[i][stone_num - 1 - i];
                if (min_merger == 0){
                    min_merger = cur_merger;
                    merger_point = j;
				}
                if (cur_merger < min_merger) {
                    min_merger = cur_merger;
                    merger_point = j;
                }
            }
            int is_merger = 0;
            for (int k = 0; k < stone_num - 1 - i; k++) {
                if (k == merger_point) {
                    dp[i + 1][k] = min_merger;
                    is_merger = 1;
                    continue;
                }
                dp[i + 1][k] = dp[i][k + is_merger];
                if (merger_point == stone_num - 1 - i) {
                    dp[i + 1][0] = min_merger;
                }
            }
            min_score += min_merger;
        }
        cout << min_score << " ";

        for (int i = 0; i < stone_num; ++i) {
            for (int j = 0; j < stone_num; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i < stone_num; ++i) {
            dp[0][i] = arr[i];
        }

		cout << endl;
        int max_score = 0;
        for (int i = 0; i < stone_num - 1; ++i) {
            int merger_point = 0;
            int max_merger = 0;
            for (int j = 0; j < stone_num - i; j++) {
                int cur_merger = 0;
                if (j != stone_num - 1 - i)
                    cur_merger = dp[i][j] + dp[i][j + 1];
                else
                    cur_merger = dp[i][0] + dp[i][stone_num - 1 - i];
				// std::cout << cur_merger << "?" << max_merger<< std::endl;
                if (cur_merger > max_merger) {
                    max_merger = cur_merger;
                    merger_point = j;
                }
            }
            int is_merger = 0;
            for (int k = 0; k < stone_num - 1 - i; k++) {
                if (k == merger_point) {
                    dp[i + 1][k] = max_merger;
                    is_merger = 1;
					std::cout << dp[i+1][k] << " ";
                    continue;
                }
                dp[i + 1][k] = dp[i][k + is_merger];
                if (merger_point == stone_num - 1 - i) {
                    dp[i + 1][0] = max_merger;
                }
				std::cout << dp[i+1][k] << " ";
            }
			cout << endl;
            max_score += max_merger;
        }
        cout << max_score << endl ;

    }
}
