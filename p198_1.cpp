#include<iostream>
#include<vector>
using namespace std; 

class Solution {
public:
    int rob(vector<int>& nums) {
    	int n = nums.size(); 
    	if(n==0)return 0;
    	if(n==1) return nums[0];
    	if(n==2){
    		int v1 = nums[0];
    		int v2 = nums[1];
    		return v1>v2?v1:v2;
		}
    	if(n==3){
    		int v1 = nums[0]+nums[2];
    		int v2 = nums[1];
    		return v1>v2?v1:v2;
		}
    	vector<int> value;//´æ·Å½ð¶î 
    	value.push_back(nums[0]);
    	value.push_back(nums[1]);
    	value.push_back(nums[2]+nums[0]);
    	for(int i=3;i<n;i++){
    		int v1 = nums[i] + value[i-2];
    		int v2 = nums[i] + value[i-3];
    		if(v1>v2)value.push_back(v1);
    		else value.push_back(v2);
		}

		if(value[n-1]>value[n-2]) return value[n-1];
    	else return value[n-2];
    }
};

int main(){
	Solution solu;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(9);
	nums.push_back(3);
	nums.push_back(1);
	cout<<"final:"<<solu.rob(nums)<<endl;	
	
	return 0;
} 


