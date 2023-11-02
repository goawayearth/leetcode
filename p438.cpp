#include<vector>
//#include<unordered_map>

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    	vector<int> pos;
    	unordered_map<char,int> map;
    	int s_len = s.length();
		int p_len = p.length();
		int start = 0;
		int end = p_len-1;
		for(int i=0;i<p_len;i++){
			map[p[i]]=1;
		}
		while(end<s_len){
			int flag = 0;
			for(int i=0;i<end;i++){
				auto it = map.find(s[i]);
				if(it==map.end()){
					flag=1;
				}
			}
			if(flag==0){
				pos.push_back(start);
			}
			start++;
			end++;
		}	
		return pos;	
    }
};
