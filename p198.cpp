#include<iostream>
#include<vector>
using namespace std; 

class Solution {
public:

	int money(vector<int> &nums,int start,int end){
		if(start == end){
			//���һ��������
			cout<<nums[start]<<endl;
			return nums[start]; 
		}
		else if(end-start == 1){
				int v1=0;
				int v2=0;
			//��ʣ��������䷿��
			v1 = nums[start];
			v2 = nums[end];
			if(v1>v2)cout<<v1<<endl;
			else cout<<v2<<endl;
			return v1>v2 ? v1:v2; 
		}
		else if(end-start == 2){
				int v1=0;
			int v2=0;
			//��ʣ������
			v1 = nums[start]+nums[end];
			v2 = nums[start+1];
			if(v1>v2) cout<<v1<<endl;
			else cout<<v2<<endl;
			return v1>v2 ? v1:v2; 
		}
		else{
			int v1=0;
			int v2=0;
			//��������
			v1 = nums[start] + money(nums,start+2,end);//ȥ�˵�һ�� 
			v2 = nums[start+1] + money(nums,start+3,end);//ȥ�˵ڶ��� 
			cout<<"o1:"<<money(nums,start+2,end)<<endl;
			cout<<"o2:"<<money(nums,start+3,end)<<endl;
			cout<<"start:"<<nums[start]<<" start+1:"<<nums[start+1]<<endl;
			cout<<"v1:"<<v1<<" v2:"<<v2<<endl;
			return v1>v2?v1:v2; 
		}
		return 0;
	}
	
    int rob(vector<int>& nums) {
    	//������һ�����飬ÿ�����ִ������������ֽ���
		//��������
		int num = nums.size();
		return money(nums,0,num-1);
		  
    }
};

int main(){
	Solution solu;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(9);
	nums.push_back(3);
	nums.push_back(1);
	cout<<"final:"<<solu.rob(nums)<<endl;	
	
	return 0;
} 


