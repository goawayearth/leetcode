class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        return find(nums,0,len,target);
    }
    
    int find(vector<int>& nums, int start, int end,int target){
    	int mid = (start + end)/2;
    	if(start == mid){
    		if(nums[start]>=target)return start;
    		if(nums[start]<target)return start+1; 
		}
    	if(nums[mid] >= target){
    		return find(nums,start,mid,target);
		}

		else if(nums[mid]<target ){
			return find(nums,mid,end,target);
		}
		return start;
	}
};
