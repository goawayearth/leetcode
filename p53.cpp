/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		int vale[100000];
		vale[0] = nums[0];
		int max=vale[0];
		for(int i=1;i<n;i++){
			int v1 = vale[i-1] + nums[i];
			int v2 = nums[i];
			vale[i] = v1 > v2 ? v1:v2;
			if(vale[i]>max){
				max = vale[i];
			}
		}
		return max;
    }
};
