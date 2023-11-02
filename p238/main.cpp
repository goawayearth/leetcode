#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> left;
        vector<int> right(n);

        for(int i=0;i<n;i++){
            if(i == 0){
                left.push_back(nums[0]);
                continue;
            }
            left.push_back(left[i-1] * nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            if(i == n-1){
                right[i] = nums[i];
                continue;
            }
            right[i] = right[i+1] * nums[i];
        }
        for(int i=0;i<n;i++){
            if(i == 0){
                ans[i] = right[i+1];
            }
            else if(i == n-1){
                ans[i] = left[i-1];
            }
            else{
                ans[i] = left[i-1] * right[i+1];
            }
        }
        return ans;

    }
};

int main()
{
    vector<int> nums;
    vector<int> ans;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    Solution* s= new Solution();
    ans = s->productExceptSelf(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}
