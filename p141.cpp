/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
    	int zero[10000];
    	int pos1=0;
    	int flag[10000];
    	int pos2=0;
    	ListNode* p=head;
    	while(p!=NULL){
    		if(p->val == 100001 ){
    			return true;
			}
    		p->val = 100001;
    		p = p->next;
		}
		return false;
        
    }
};
