class Solution {
public:
    vector<vector<int>> generate(int numRows){
    	vector<vector<int>> sum(numRows);
        sum[0].push_back(1); 
        for(int i=1;i<numRows;i++){
        	for(int j=0;j<=i;j++){
                if(j==0 || j == i){
                    sum[i].push_back(1);
                }
                else{
                    sum[i].push_back(sum[i-1][j-1] + sum[i-1][j]);
                }
            }
		}
		return sum;
    }
};
