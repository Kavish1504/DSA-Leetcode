/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void solve(Node* &curr,Node* temp){
        if(!temp) return;
        Node* newNode=new Node(temp->val);
        curr->next=newNode;
        newNode->prev=curr;
        newNode->child=nullptr;
        curr=newNode;
        solve(curr,temp->child);
        solve(curr,temp->next);
    }
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        Node* dummy=new Node(-1);
        dummy->prev=nullptr;
        Node* curr=dummy;
        Node* temp=head;
        solve(curr,temp);
        Node* ans = dummy->next;
        ans->prev = nullptr;
        delete dummy;

        return ans;
    }
};