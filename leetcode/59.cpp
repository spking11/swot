#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, -1));
        int state = 0;
        for (int counter = 0, i = 0, j = 0; counter < n * n; counter++) {
            result[i][j] = counter + 1;
            switch (state) {
            case 0:
                if (j + 1 < n && result[i][j + 1] == -1) {
                    j += 1;
                } else {
                    state = 1;
                    i += 1;
                }
                break;
            case 1:
                if (i + 1 < n && result[i + 1][j] == -1) {
                    i += 1;
                } else {
                    state = 2;
                    j -= 1;
                }
                break;
            case 2:
                if (j - 1 >= 0 && result[i][j - 1] == -1) {
                    j -= 1;
                } else {
                    state = 3;
                    i -= 1;
                }
                break;
            case 3:
                if (i - 1 >= 0 && result[i - 1][j] == -1) {
                    i -= 1;
                } else {
                    state = 0;
                    j += 1;
                }
                break;
            }
        }
        return result;
    }
};

int main() {
    for (auto row : Solution().generateMatrix(3)) {
        for (auto item : row) {
            cout << item << " ";
        }
        cout << endl;
    }

    return 0;
}