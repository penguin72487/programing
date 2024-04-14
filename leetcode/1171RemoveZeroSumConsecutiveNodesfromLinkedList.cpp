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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* front=head;
        ListNode *prev=new ListNode(0);
        prev->next=head;

        int sum=front->val;//front to back
        ListNode* back=head->next;
        while(back!=NULL){
            if(back->val<0)
            {
                while(sum+ back->val>0)
                {
                    sum-=front->val;
                    front=front->next;
                }
                // front->next=back->next;
                prev->next=back->next;
                front=prev->next->next;
                back=front->next;
                sum=front->val;
            }
            else
            {
                sum+=back->val;
                back=back->next;
            }
        }
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
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(-3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(1);
    ListNode* res = s.removeZeroSumSublists(head);
    while(res!=NULL){
        cout<<res->val<<" ";
        res=res->next;
    }
    cout<<endl;
    


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}