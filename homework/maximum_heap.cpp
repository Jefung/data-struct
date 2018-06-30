#include <iostream>
using namespace std;

class Maximumin_heapeap {
  private:
    int *arr_;
    int max_len_;
    int cur_len_;

  public:
    Maximumin_heapeap(int arr[], int len) {
        arr_ = new int[len + 1];
        max_len_ = len;
        cur_len_ = len;

        for(int i = 1; i < len + 1; i++) {
            arr_[i] = arr[i - 1];
        }
        init();
    }
    void init() {
        for(int i = max_len_ / 2; i > 0; i--) {
            // 保存当前操作的节点(非叶子节点)
            int save_value = arr_[i];
            // c为非叶子节点的左孩子
            int c = i * 2;
            while(c <= max_len_) {
                if(c + 1 <= max_len_ && arr_[c + 1] > arr_[c])
                    c++;
                if(save_value > arr_[c])
                    break;
                else {
                    // 将孩子节点上提
                    arr_[c / 2] = arr_[c];
                    // 移动到下一层节点
                    c = c * 2;
                }
            }
            arr_[c / 2] = save_value;
        }
    }

    void show() {
        for(int i = 1; i <= cur_len_; i++) {
            cout << arr_[i] << " ";
        }
        std::cout << endl;
    }

    void insert(int x) {
        if(cur_len_ >= max_len_)
            return;
        cur_len_++;
        arr_[cur_len_] = x;
        if(x < arr_[cur_len_ / 2])
            return;
        int c = cur_len_;
        while(c >= 1 && x > arr_[c / 2]) {
            arr_[c] = arr_[c / 2];
            c /= 2;
        }
        if(c == 0)
            c = 1;
        arr_[c] = x;
    }

    void pop(int &x) {
        if(cur_len_ == 0)
            return;
        x = arr_[1];
        arr_[1] = arr_[cur_len_];
        int last_value = arr_[cur_len_];
        cur_len_--;

        int c = 1;
        int ci = 2;
        while(ci <= cur_len_) {
            if(ci + 1 <= cur_len_ && arr_[ci] < arr_[ci + 1])
                ci++;

            if(arr_[ci] > last_value) {
                arr_[c] = arr_[ci];
                c = ci;
                ci *= 2;
            } else
                break;
        }
        arr_[c] = last_value;
    }
};

class Minimumin_heapeap {
  private:
    int *arr_;
    int max_len_;
    int cur_len_;

  public:
    Minimumin_heapeap(int arr[], int len) {
        arr_ = new int[len + 1];
        max_len_ = len;
        cur_len_ = len;

        for(int i = 1; i < len + 1; i++) {
            arr_[i] = arr[i - 1];
        }
        init();
    }
    void init() {
        for(int i = max_len_ / 2; i > 0; i--) {
            // 保存当前操作的节点(非叶子节点)
            int save_value = arr_[i];
            // c为非叶子节点的左孩子
            int c = i * 2;
            while(c <= max_len_) {
                // 左右孩子(c,c+1)中找到一个最小的
                if(c + 1 <= max_len_ && arr_[c + 1] < arr_[c])
                    c++;
                // 最小堆: 比2个孩子节点的最小值还小,不用交换
                if(save_value < arr_[c])
                    break;
                else {
                    // 将孩子节点上提
                    arr_[c / 2] = arr_[c];
                    // 移动到下一层节点
                    c = c * 2;
                }
            }
            arr_[c / 2] = save_value;
        }
    }

    void show() {
        for(int i = 1; i <= cur_len_; i++) {
            cout << arr_[i] << " ";
        }
        std::cout << endl;
    }

    void insert(int x) {
        if(cur_len_ >= max_len_)
            return;
        cur_len_++;
        arr_[cur_len_] = x;
        if(x > arr_[cur_len_ / 2])
            return;
        int c = cur_len_;
        // 从插入点一直向上,如果比父节点小,就和父节点交换
        while(c >= 1 && x < arr_[c / 2]) {
            arr_[c] = arr_[c / 2];
            c /= 2;
        }
        arr_[c] = x;
    }

    void pop(int &x) {
        if(cur_len_ == 0)
            return;
        x = arr_[1];
        arr_[1] = arr_[cur_len_];
        int last_value = arr_[cur_len_];
        cur_len_--;

        int c = 1;
        int ci = 2;
        while(ci <= cur_len_) {
            if(ci + 1 <= cur_len_ && arr_[ci] > arr_[ci + 1])
                ci++;

            if(arr_[ci] < last_value) {
                arr_[c] = arr_[ci];
                c = ci;
                ci *= 2;
            } else
                break;
        }
        arr_[c] = last_value;
    }
};
int main(int argc, char *argv[]) {
	while(1) {
		int len;
		cin >> len;
		int *arr = new int[len];
		for(int i = 0; i < len; i++) {
			cin >> arr[i];
		}
		int flag = 1;
		cin >> flag;
		if(flag != 0)
			break;
		Minimumin_heapeap min_heap = Minimumin_heapeap(arr, len);
		Maximumin_heapeap max_heap = Maximumin_heapeap(arr, len);
		int min_cost = 0;
		int max_cost = 0;

		while(1) {
			int x = 0;
			int y = 0;
			min_heap.pop(x);
			min_heap.pop(y);
			if(x == 0 || y == 0) {
				break;
				min_cost += x;
			}
			min_cost += (x + y - 1);
			min_heap.insert(x + y);

			int x1 = 0;
			int y1 = 0;
			max_heap.pop(x1);
			max_heap.pop(y1);
			if(x1 == 0 || y1 == 0) {
				break;
				max_cost += x1;
			}
			max_cost += (x1 + y1 - 1);
			max_heap.insert(x1 + y1);
		}
		std::cout << min_cost << std::endl;
		std::cout << max_cost << std::endl;
	}
}
