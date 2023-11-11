/*************************************************************************
        > File Name: 153.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月10日 星期五 21时19分53秒
 ************************************************************************/
#include <vector>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution{
public:
    int ans;
    int findMin(vector<int>& nums){
        if(nums[nums.size()-1]>nums[0]){
            return nums[0];
        }
        find(nums,0,nums.size()-1);
        return ans;
    }
    void find(vector<int>& nums,int start, int end){
        if(start == end){
            ans = nums[start];
        }
        if(start - end == -1){
            ans = nums[end];
        }
        int mid = (start + end) / 2;
        if(nums[mid]>nums[start]){

            find(nums,mid,end);
        }
        else if(nums[mid]<nums[start]){
            find(nums,start,mid);
        }
    }

};
