#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int first = 100000;//最小位置
    int end = -1;//最大位置
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        if(n==0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        findElement(0,n-1,target,nums);
        if(first==100000)first=-1;
        ans.push_back(first);
        ans.push_back(end);
        return ans;

    }

    void findElement(int start,int last,int target,vector<int>& nums){
        if(nums[start]>target)return;
        if(nums[last]<target)return;
        if(start==last){
            if(nums[start]==target ){
                if(start>end){
                    end=start;
                }
                if(start<first){
                    first=start;
                }
            }
        }
        else{
            int mid = (start+last)/2;
            if(nums[mid]>target){
                findElement(start,mid,target,nums);
            }
            if(nums[mid]<target){
                findElement(mid+1,last,target,nums);
            }
            if(nums[mid]==target){
                if(mid>end){
                    end=mid;
                }
                if(mid<first){
                    first=mid;
                }
                findElement(start,mid,target,nums);
                findElement(mid+1,last,target,nums);
            }

        }
    }
};

int main()
{
    Solution* so = new Solution();
    vector<int> vec;
    vector<int> ans;
    /*vec.push_back(5);
    vec.push_back(7);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(8);
    vec.push_back(10);*/
    ans = so->searchRange(vec,6);
    cout<<ans[0]<<endl;
    cout<<ans[1]<<endl;

    cout << "Hello world!" << endl;
    return 0;
}
