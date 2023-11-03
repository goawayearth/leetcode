#include <iostream>
#include <vector>

using namespace std;
/*Ê±¼ä³¬ÏÞ
class Solution {
public:
    int recorded[300][300]={0};
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return find(matrix,target,0,0);
    }
    bool find(vector<vector<int>>& matrix, int target,int i,int j){
        recorded[i][j]=1;
        if(matrix[i][j]==target){
            return true;
        }
        else if(matrix[i][j]<target){
            if(i<matrix.size()-1 && recorded[i+1][j]==0){
                bool b1 = find(matrix,target,i+1,j);
                if(b1==true)return true;
            }
            if(j<matrix[0].size()-1 && recorded[i][j+1]==0){
                bool b2 = find(matrix,target,i,j+1);
                if(b2==true)return true;
            }
            if(i<matrix.size()-1 && j<matrix[0].size()-1  && recorded[i+1][j+1]==0){
                bool b3 = find(matrix,target,i+1,j+1);
                if(b3==true)return true;
            }

            return false;
        }
        else if(matrix[i][j]>target){
            return false;
        }

        return false;
    }
};*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix.size();
      int n = matrix[0].size();

      int row = 0;
      int col = n - 1;

      while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
              return true;
            }
            else if (matrix[row][col] > target) {
              col--;
            }
            else {
              row++;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix={{4,7,11},{7,11,16},{10,11,20},{13,13,22}};
    Solution* so = new Solution();
    cout<<so->searchMatrix(matrix,23);
    return 0;
}
