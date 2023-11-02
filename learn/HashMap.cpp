/*
c++哈希表 
头文件： #include<unordered_map>
定义：unordered_map<int, int> hashtable; 
查找：auto it = hashtable.find(target - nums[i]);
判断是否找到：it != hashtable.end() 
取元素：it->second
增加元素：hashtable[nums[i]] = i; 
*/
#include<vector>
#include<unordered_map>

using namespace std;
class Solution{
	public:
		vector<int> twoSum(vector<int>nums, int target){
			unordered_map<int, int> hashtable;//定义哈希表 
			for(int i=0;i<nums.size();i++){
				auto it = hashtable.find(target - nums[i]);//自动判断类型 
				if(it != hashtable.end()){//找到了就不会是end() 
					return {it->second,i};
				}
				hashtable[nums[i]] = i;//没找到就把这个元素插入到哈希表中 
			}
			return {}
		}
}; 
