class Solution {
public:
	int num=0;
	unordered_map<int,int> col_t;//列 
    unordered_map<int,int> dp;//相剪掉 
    unordered_map<int,int> udp;//相加
	string que[10000][10];
	string fin[10000][10];
	
	
    vector<vector<string>> solveNQueens(int n) {
    	
    	for(int i=0;i<1000;i++){
    		for(int j=0;j<10;j++){
    			for(int k=0;k<n;k++){
    				que[i][j]+=".";
				}
			}
		}
		
    	int row = 0;
    	queue(0,n);
		vector<vector<string>>Queues(num);
    	for(int i=0;i<num;i++){
    		for(int j=0;j<n;j++){
    			Queues[i].push_back(fin[i][j]); 
			}	
		}

		return Queues;
    }
    
    void queue(int row,int n){
    	if(row == n){
    		for(int i=0;i<n;i++){
    			fin[num][i]=que[num][i];
    			que[num+1][i]=que[num][i];
			} 
    		num++;
			return;
		}
    	
    	for(int i=0;i<n;i++){
    		auto it1 = col_t.find(i);
    		auto it2 = dp.find(row-i+n);
    		auto it3 = udp.find(row+i);
    		if(it1==col_t.end()&&it2==dp.end()&&it3==udp.end()){
    			//同时都没找到，就是这个位置可以
				que[num][row][i]='Q'; 
				col_t[i]=1;
				dp[row-i+n]=1;
				udp[row+i]=1;
				queue(row+1,n);
				que[num][row][i]='.';
				col_t.erase(i);
				dp.erase(row-i+n);
				udp.erase(row+i);
			}
			else{
				que[num][row][i]='.';
			}
		}	
	}
};


