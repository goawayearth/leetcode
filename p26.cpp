/*************************************************************************
        > File Name: p26.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月15日 星期三 20时25分36秒
 ************************************************************************/
#include <vector>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        int n = nums.size();
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size();
    }
};
