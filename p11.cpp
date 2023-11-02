class Solution {
public:
    int maxArea(vector<int>& height) {
    	int start = 0;
    	int end = height.size()-1;
    	int max = 0;
    	while(start<end){
    		int min;
    		if(height[start]>height[end])min=height[end];
    		else min = height[start];
    		
    		int size = min*(end-start);
    		if(max < size){
    			max = size;
			}
			if(height[start]>height[end])end--;
    		else start++;
			
		}
    	return max;
	}
};
