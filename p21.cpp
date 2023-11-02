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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    	ListNode* p1=list1;
    	ListNode* p2=list2;
    	ListNode* result = new ListNode();
    	ListNode* p3=result;
    	while(p1!=NULL && p2!=NULL){
    		if(p1->val >= p2->val)
    		{
    			ListNode* Node=new ListNode();
    			Node->val = p2->val;
    			p3->next = Node;
    			p3 = Node;
    			p2 = p2->next;
			}
			else if(p1->val < p2->val){
				ListNode* Node=new ListNode();
    			Node->val = p1->val;
    			p3->next = Node;
    			p3 = Node;
    			p1 = p1->next;
			}

		}
		while(p1!=NULL){
			ListNode* Node=new ListNode();
    			Node->val = p1->val;
    			p3->next = Node;
    			p3 = Node;
    			p1 = p1->next;
		}
		while(p2!=NULL){
			ListNode* Node=new ListNode();
    			Node->val = p2->val;
    			p3->next = Node;
    			p3 = Node;
    			p2 = p2->next;
		}
        return result->next;
    }
};
