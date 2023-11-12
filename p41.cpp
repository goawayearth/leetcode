/*************************************************************************
        > File Name: p41.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月12日 星期日 09时01分33秒
 ************************************************************************/
#include <unordered_map>
#include <vector>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution{
public:
    unordered_map<int ,int> map;
    int min = 1;
    int firstMissingPosition(vector<int>& nums){
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == min){
                min++;
                auto it = map.find(min);
                while(it!=map.end()){
                    min++;
                    it = map.find(min);
                }
            }
            else{
                map[nums[i]]=1;
            }
        }
        return min;
    }

};

int main(){
    vector<int>nums = {3,4,-1,1};
    Solution* so = new Solution();
    cout<<so->firstMissingPosition(nums)<<endl;
}


