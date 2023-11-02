#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> result={0,0};
    	int n = nums.size();
    	int find;
    	int j,i;
    	for(i=0;i<n-1;i++){
    		find = target - nums[i];
    		for(j = i+1;j<n && nums[j]!=find;j++);
    		if(j!=n){
    			result[0] = i;
    			result[1] = j;
			}
		}
        return result;
    }
};
int main(){
	return 0;
}
