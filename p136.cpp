class Solution {
public:
    int singleNumber(vector<int>& nums) {
		int len = nums.size();
		int sum[60000]={0};
		for(int i=0;i<len;i++){
			sum[nums[i]+30000]++;
		}
		for(int i=0;i<60000;i++){
			if(sum[i]==1){
				return i-30000;
			}
		}
		return 0;
    }
};
