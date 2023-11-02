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
        		//֮ǰ�����ֵ�����������ˣ���Ҫ���������ֵ
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
				//֮ǰ�����ֵ���ڣ��Ƚ����ֵ�����һ��ֵ�ͺ�
				if(nums[pos] <= nums[end]){
					pos = end;
				}
			
			}
			maxVal.push_back(nums[pos]);
		}
		return maxVal;

    }
};
