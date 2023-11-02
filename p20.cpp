class Solution {
public:
    bool isValid(string s) {
    	char kuohao[5010];
    	int posi=0;
    	for(int i=0;i<s.length();i++){
    		if(s[i] == '(' || s[i] == '{' || s[i]=='['){
    			kuohao[posi]=s[i];
    			posi++;
			}
			else if(s[i] == ')' || s[i] == '}' || s[i]==']'){
				if(posi==0){
					return false;
				}
				if(s[i] == ')' && kuohao[posi-1] == '('){
					posi--;
				}
				else if(s[i] == '}' && kuohao[posi-1] == '{'){
					posi--;
				}
				else if(s[i] == ']' && kuohao[posi-1] == '['){
					posi--;
				}
				else {
					return false;
				}
			}
		}
		if(posi==0){
			return true;
		}
		return false;

    }
};
