#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int  n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == val){
                nums[i]=200;
            }
        }
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i] != 200){
                ans++;
            }
            else{
                break;
            }
        }
        return ans;

    }
};