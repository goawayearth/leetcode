class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	unordered_map<char,int> map; 
    	//������� 
    	if(s.size()==0)return 0;
    	if(s.size()==1)return 1;
    	
		int start=0;
		int end=1;
		int max=1;
		int length=1;
		int n = s.size();
		map[s[start]] = 1;
		while(end<n){
			auto it = map.find(s[end]);
			if(it == map.end()){
				//����û�ҵ�
				map[s[end]] = 1; 
				end++;
				length++; 
			}
			else{
				//�����Ѿ�����
				if(max<length)max=length;
				map.erase(s[start]);
				start++;
				length--;
				 
			}
		}
		if(length>max){
			max=length;
		}
		return max;
    }
};
