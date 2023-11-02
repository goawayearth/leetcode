/*
c++��ϣ�� 
ͷ�ļ��� #include<unordered_map>
���壺unordered_map<int, int> hashtable; 
���ң�auto it = hashtable.find(target - nums[i]);
�ж��Ƿ��ҵ���it != hashtable.end() 
ȡԪ�أ�it->second
����Ԫ�أ�hashtable[nums[i]] = i; 
*/
#include<vector>
#include<unordered_map>

using namespace std;
class Solution{
	public:
		vector<int> twoSum(vector<int>nums, int target){
			unordered_map<int, int> hashtable;//�����ϣ�� 
			for(int i=0;i<nums.size();i++){
				auto it = hashtable.find(target - nums[i]);//�Զ��ж����� 
				if(it != hashtable.end()){//�ҵ��˾Ͳ�����end() 
					return {it->second,i};
				}
				hashtable[nums[i]] = i;//û�ҵ��Ͱ����Ԫ�ز��뵽��ϣ���� 
			}
			return {}
		}
}; 
