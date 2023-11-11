/*************************************************************************
        > File Name: p33.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月08日 星期三 23时52分58秒
 ************************************************************************/
#include <vector>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution{
public:
    int search(vector<int>& nums, int target){
        int n=nums.size();
        return find(nums,target,0,n-1);
            
    }
    int find(vector<int>& nums, int target, int start, int end){
        int mid = (start+end)/2;
        if(start == end && nums[start]!=target){
            return -1;
        }
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>=nums[start] && nums[mid]>=target && nums[start] <= target){
            return find(nums,target,start,mid);
        }
        else if(nums[mid]<nums[start] && target<=nums[mid]){
            return find(nums,target,start,mid);
        }
        else if(nums[mid]<nums[start] && target>=nums[start]){
            return find(nums,target,start,mid);
        }
        else{
            return find(nums,target,mid+1,end);
        }
        return -1;
        }
    


};
int main(){
    
}
