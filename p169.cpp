class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	int n = nums.size();
    	unordered_map<long,int> map;
    	for(int i=0;i<n;i++){
    		auto it = map.find(nums[i]);
    		if(it == map.end()){//就是说本来不存在的 
    			map.insert({nums[i], 1});
    			if(map[nums[i]] > n/2){
					return nums[i];
				}
			}
			else if(it != map.end()){
				map[nums[i]] = map[nums[i]]+1;
				if(map[nums[i]] > n/2){
					return nums[i];
				}
			}
    		
		}
    	return 0;

    }
};
