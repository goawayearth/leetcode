class Solution {
public:
    int climbStairs(int n) {
    	vector<int> step;
    	step.push_back(1);
    	step.push_back(1);
    	for(int i=2;i<n+1;i++){
    		step.push_back(step[i-1] + step[i-2]);
		}
    	return step[n];
    }
   
};
