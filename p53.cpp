/*
����һ���������� nums �������ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�

������ �������е�һ���������֡�
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
