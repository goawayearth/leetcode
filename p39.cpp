/*************************************************************************
        > File Name: p39.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月13日 星期一 11时00分53秒
 ************************************************************************/
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using namespace std;

class Solution{
public:
    unordered_map<string,int> hashMap;
	vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<int> single;
        get(0,single,candidates,target);
        return ans;

    }
    void get(int nowsum,vector<int>single,vector<int>& candidates,int target){
        int n = candidates.size();
        int nowsum1 = nowsum;
        
        for(int i=0;i<n;i++){
            vector<int> single1 = single;
            if(nowsum1+candidates[i] == target){
                single1.push_back(candidates[i]);
                string one = "";
                sort(single1.begin(),single1.end());
                for(int k=0;k<single1.size();k++){
                    one+=(single1[k]+'0');
                }
                auto it = hashMap.find(one);
                if(it==hashMap.end()){
                    ans.push_back(single1);
                    hashMap[one]=1;
                }
                else{
                    single1.pop_back();
                }
            }
            else if(nowsum1 + candidates[i] < target){
                single1.push_back(candidates[i]);
                get(nowsum+candidates[i],single1,candidates,target);
                single1.pop_back();
            }
                
        }

    }
};
int main(){
    Solution *so = new Solution();
    vector<int> nums = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans = so->combinationSum(nums,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
