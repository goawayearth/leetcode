#include<iostream>

using namespace std;
 
//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      /*ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}*/
  };
 
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		int num = 0;
		ListNode* p = head;
		while(p)
		{
			if(p != NULL){
				num++;//������һ
				p = p->next; 
			}
		}
		//һ����num����㣬ɾ��������n��������ɾ���� num-n+1 ����� 
		//��������ƶ�num - n ��
		int time = num - n - 1;
		p = head;
		if(time > 0){
			while(time-- ){
			p = p->next;
			}
		}
		else if(time == -1){
			return p->next; 
		}
		
		if(n>=2){
			ListNode* q = p->next;
			p->next = p->next->next;
			delete q;
		}
		else{
			p->next = NULL;
		}
		return head;		
    }
};

int main(){
	return 0;
}
