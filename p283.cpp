class Solution{
	public:
		void moveZeroes(vector<int>& nums){
			int n = nums.size();
			int left = 0;
			int right = 0;
			int temp=0;
			while(right < n && left < n - 1){
				for(;left < n-1 && nums[left]!=0 ;left++);
				right = left + 1;
				for(;right < n && nums[right]==0;right++);
				temp = nums[left];
				nums[left] = nums[right];
				nums[right] = temp;
			} 
		}
};  
