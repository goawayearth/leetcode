/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	int array[5000];
    	int posi=0;//存放数据
    	ListNode* p = head;
    	ListNode* result = new ListNode();
    	ListNode* pp=result;
		while(1){
			if(p!=NULL){
				array[posi] = p->val;
				p = p->next;
				posi++;
			}
			else{
				break;
			}
		} 
		if(posi==0) return NULL;
		if(posi>0){
			//说明至少有一个
			pp->val = array[posi-1]; 
		}
		for(int i=posi-2;i>=0;i--){
			ListNode* Node=new ListNode();
			Node->val = array[i];
			pp->next = Node;
			pp = Node; 
		}
		return result;

    }
};
