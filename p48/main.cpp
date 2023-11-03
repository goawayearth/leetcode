#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int temp[30][30];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[j][i]=matrix[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = temp[i][n-j-1];
            }
        }

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
