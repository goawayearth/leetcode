#include <iostream>

using namespace std;

typedef struct Node {
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
}Node;


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* priPos = head;//ָ��ԭ�����ָ��
        Node* head1 = new Node(0);//������ͷ�ڵ�
        Node* nowPos = head1;//��ͷ�ڵ�ָ��
        if(head==NULL)return NULL;
        nowPos->val = priPos->val;
        priPos = priPos->next;
        while(priPos!=NULL){
            Node* node = new Node(priPos->val);
            nowPos->next = node;
            nowPos = node;
            priPos=priPos->next;
        }
        //�Ѿ���next��������
        priPos = head;
        nowPos = head1;
        Node* p1=head;//��ԭ����������
        Node* p2=head1;//����������
        Node* rand1=head;
        while(priPos!=NULL){
            rand1 = priPos->random;
            while(p1 != rand1){
                p1 = p1->next;
                p2 = p2->next;
            }
            nowPos->random = p2;
            //��һ��
            priPos = priPos->next;
            nowPos = nowPos->next;
            p1=head;
            p2=head1;
        }



        return head1;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
