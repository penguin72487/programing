#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count_Node=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            count_Node++;
            temp=temp->next;
        }
        if(count_Node==n){
            return head->next;
        }
        temp=head;
        n=count_Node-n;
        for(int i=1;i<n;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;

    }
};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    #ifdef ENABLE_TIMING
        using namespace std::chrono;
        auto start = high_resolution_clock::now();
    #endif
    Solution s;
    ListNode* head=new ListNode(1);
    ListNode* temp=head;
    temp->next=new ListNode(2);
    temp=temp->next;
    temp->next=new ListNode(3);
    temp=temp->next;
    temp->next=new ListNode(4);
    temp=temp->next;
    temp->next=new ListNode(5);
    int n=2;
    ListNode* res=s.removeNthFromEnd(head,n);
    while(res!=nullptr){
        cout<<res->val<<" ";
        res=res->next;
    }


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}