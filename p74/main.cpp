#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int num = m * n;
        bool flag =  find(0,num-1,matrix,target);
        return flag;
    }

    bool find(int start,int end,vector<vector<int>>& matrix, int target){

        int mid = (start + end) / 2;
        int x = mid / matrix[0].size();
        int y = mid % matrix[0].size();
        if(start == end){
            if(matrix[x][y]==target){
            return true;
            }
            else return false;
        }

        if(matrix[x][y]==target){
            return true;
        }
        else if(matrix[x][y]>target){
            bool re = find(start,mid,matrix,target);
            if(re == true)return true;
        }
        else if(matrix[x][y]<target){
            bool re = find(mid+1,end,matrix,target);
            if(re == true)return true;
        }
        return false;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
