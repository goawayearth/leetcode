#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int max =0;
        for(int i=0;i<n;i++)
        {
            ans[i]=1;
            int pos = i-1;
            while(pos>=0){
                if(nums[pos]<nums[i]){
                    if(ans[i]<ans[pos]+1){
                        ans[i]=ans[pos]+1;
                    }
                }
                pos--;
            }
            if(ans[i]>max){
                max=ans[i];
            }
        }
        return max;
    }
};

int main()
{
    Solution* so = new Solution();
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(3);


    cout<<so->lengthOfLIS(nums);
    return 0;
}
