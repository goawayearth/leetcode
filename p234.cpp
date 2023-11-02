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
    bool isPalindrome(ListNode* head) {
		int arr[100000];
		int posi=0;
		ListNode* p=head;
		while(1){
			if(p!=NULL){
				arr[posi] = p->val;
				posi++;
				p=p->next;
			}
			else break;
		}
		int start = 0;
		int end = posi-1;
		while(arr[start] == arr[end] && end>start){
			start++;
			end--;
		}
		if(end<=start)return true;
		else return false;
		
    }
};
