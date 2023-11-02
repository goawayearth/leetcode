class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxVal;
        int pos = -1;
        int n = nums.size();
        int endPos = n - k + 1;
        int max;
        int start,end;
        for(int i=0;i<endPos;i++){
        	 start = i;
        	 end = i+k-1;
        	if(!(pos>=start&&pos<=end)){
        		//之前的最大值不在这里面了，需要从新找最大值
        		 max=nums[start];
        		 pos=start;
        		for(int j=start;j<=end;j++){
        			if(max < nums[j]){
        				max = nums[j];
        				pos = j;
					}
				}
			}
			else{
				//之前的最大值还在，比较最大值和最后一个值就好
				if(nums[pos] <= nums[end]){
					pos = end;
				}
			
			}
			maxVal.push_back(nums[pos]);
		}
		return maxVal;

    }
};
