#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows;
        vector<int> cols;
        for (int i = 0; i < matrix.size(); i++) {
           for (int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 0){
                    rows.push_back(i);
                    cols.push_back(j);
                }
           }

        }

        //处理行
        for(int i=0;i<rows.size();i++){
            int row = rows[i];
            for(int j=0;j<matrix[row].size();j++){
                matrix[row][j]=0;
            }

        }
        //处理列
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<cols.size();j++){
                matrix[i][cols[j]]=0;
            }
        }


    }
};

int main()
{

    return 0;
}
