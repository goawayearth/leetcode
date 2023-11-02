#include <iostream>
#include <vector>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;


class Solution {
public:
    unordered_map<int, int> preSum;
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();// 数据的大小
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];

            if(sum==k){
                count++;
            }
            if(preSum.find(sum-k)!=preSum.end()){
                count=count+preSum[sum-k];
            }

            preSum[sum]++;
        }
        return count;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
