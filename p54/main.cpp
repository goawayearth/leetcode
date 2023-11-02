#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int direction = 0;//01 2 3 ср об вС ио
        int total_elements = 0;

        for (const auto& row : matrix) {
            total_elements += row.size();
        }
        int row=0;
        int col=0;
        ans.push_back(matrix[0][0]);
        matrix[0][0]=200;
        total_elements--;
        while(total_elements--){

            if(direction==0 && col==matrix[0].size()-1 || direction==1 && row==matrix.size()-1
                || direction==2&&col == 0 || direction==3 && row==0){
                    direction = (direction+1)%4;
                }
            switch(direction){
                case 0:{
                    int i = row;
                    int j = col+1;
                    if(matrix[i][j]==200)direction = 1;
                    break;
                }
                case 1:{
                    int i = row+1;
                    int j = col;
                    if(matrix[i][j]==200)direction = 2;
                    break;
                }
                case 2:{
                    int i = row;
                    int j = col-1;
                    if(matrix[i][j]==200)direction = 3;
                    break;
                }
                case 3:{
                    int i = row-1;
                    int j = col;
                    if(matrix[i][j]==200)direction = 0;
                    break;
                }
            }
            switch(direction){
                case 0:{
                    col++;break;
                }
                case 1:{
                    row++;break;
                }
                case 2:{
                    col--;break;
                }
                case 3:{
                    row--;break;
                }
            }
            ans.push_back(matrix[row][col]);
            matrix[row][col] = 200;

        }
        return ans;

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
