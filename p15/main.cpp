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

        unordered_map<int,vector<int>> myHash;
        int n=nums.size();

        for(int i=0;i<n;i++){
            myHash[nums[i]].push_back(i);
        }


        for(int i=0;nums[i]<=0 && i<n-2;i++){
            for(int j=i+1;j<n-1;j++){

                    if(nums[i] == 0 && nums[j]==0&& nums[j+1]==0){
                        vector<int>one;
                        one.push_back(nums[i]);
                        one.push_back(nums[j]);
                        one.push_back(nums[j]);
                        ans.push_back(one);
                        break;
                    }
                    else if(nums[i]+nums[j]<0){

                        auto it = myHash.find(-nums[i]-nums[j]);

                        if(it != myHash.end()){


                            for(int k=0;k<(it->second).size();k++){
                                if(it->second[k]>j){
                                    vector<int>one;
                                    one.push_back(nums[i]);
                                    one.push_back(nums[j]);
                                    one.push_back(nums[it->second[k]]);
                                    ans.push_back(one);
                                    break;
                                }
                            }
                        }
                        while(j+1<n-1 && nums[j+1]==nums[j]){
                            j++;
                        }
                    }

                else{
                    break;
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
    vector<int> nums;
    vector<vector<int>> ans;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(-1);
    nums.push_back(4);

    Solution* s =new Solution();
    ans = s->threeSum(nums);
    cout<<"ans:"<<endl;
     for (int i = 0; i < ans.size(); i++) {
       for (int j = 0; j < ans[i].size(); j++) {
           cout << ans[i][j] << " ";
       }
       cout << endl;
   }

    return 0;
}
