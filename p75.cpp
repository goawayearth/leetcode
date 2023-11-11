/*************************************************************************
        > File Name: p75.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月10日 星期五 09时24分03秒
 ************************************************************************/
#include <vector>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution{
public :
    void sortColor(vector<int>& nums){
        int n = nums.size();
        int num0 = 0;
        int num1 = 0;
        int num2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)num0++;
            else if(nums[i]==1)num1++;
            else if(nums[i]==2)num2++;
        }
        int pos = 0;
        while(num0--){
            nums[pos]=0;
            pos++;
        }
        while(num1--){
            nums[pos]=1;
            pos++;
        }
        while(num2--){
            nums[pos]=2;
            pos++;
        }
    
    }
};
int main(){
    return 0;
}
