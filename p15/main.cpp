#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int> one;
                        one.push_back(nums[i]);
                        one.push_back(nums[j]);
                        one.push_back(nums[k]);
                        ans.push_back(one);
                    }
                    while(k+1<n && nums[k+1]==nums[k]){
                        k++;
                    }
                }
                while(j+1<n-1 && nums[j+1]==nums[j]){
                    j++;
                }
            }
            while(i+1<n-2 && nums[i+1]==nums[i]){
                i++;
            }
        }
    return ans;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
