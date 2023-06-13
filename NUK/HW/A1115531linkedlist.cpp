#include<bits/stdc++.h>
using namespace std;
class linklist{
public:
    class node{  // All data structure in one class
    private:
        int data;
        node* next;
        node(int data){
            this->data=data;
            next=nullptr;
        }
        friend class linklist;// authorized linklist to use private data
    };
    node* head;//linklist has head and last
    node* last;
    int size=0;// obviously linklist has size
    linklist(){
        head = nullptr;
        last = nullptr;
    }
    void push_back(int data){
        node* newnode = new node(data);
        if(head==nullptr){
            head=newnode;
            last=newnode;
        }
        else{
            last->next=newnode;
            last=newnode;
        }
        size++;
    }
    void pop_back()
    {
        if(head==nullptr)
        {
            return;
        }
        else if(head==last)
        {
            delete head;
            head=nullptr;
            last=nullptr;
        }
        else
        {
            node* temp=head;
            while(temp->next!=last) // find the second last node
            {
                temp=temp->next;
            }
            delete last;
            last=temp;
            last->next=nullptr;
        }
        size--;
    }
    void insert(int index,int data)
    {
        if(index==0)
        {
            node* newnode=new node(data);
            newnode->next=head;
            head=newnode;
            size++;
        }
        else if(index==size)
        {
            push_back(data);
        }
        else
        {
            node* temp=head;
            for(int i=0;i<index-1;++i)// find the node before the index
            {
                temp=temp->next;
            }
            node* newnode=new node(data);
            newnode->next=temp->next;
            temp->next=newnode;
            size++;
        }
    }
    void remove(int index)
    {
        if(index==0)
        {
            node* temp=head;
            head=head->next;
            delete temp;
            size--;
        }
        else if(index==size-1)
        {
            pop_back();
        }
        else
        {
            node* temp=head;
            for(int i=0;i<index-1;++i)// find the node before the index
            {
                temp=temp->next;
            }
            node* temp2=temp->next;
            temp->next=temp2->next;
            delete temp2;
            size--;
        }
    }
    friend ostream& operator<<(ostream& os,linklist& l) //cout<<linklist
    {
        node* temp=l.head;
        while(temp!=nullptr)
        {
            os<<temp->data<<" ";
            temp=temp->next;
        }
        return os;
    }
    void reverse()
    {
        node* temp=head;
        node* prev=nullptr;
        node* next=nullptr;
        while(temp!=nullptr)// temp->next alternate to prev
        {
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        last=head;
        head=prev;
    }
    
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    linklist l;
    l.push_back(1);
    cout<<l<<"\n";
    l.push_back(2);
    cout<<l<<"\n";
    l.push_back(3);
    cout<<l<<"\n";
    l.insert(0,0);
    cout<<l<<"\n";
    l.insert(4,4);
    cout<<l<<"\n";
    l.insert(2,5);
    cout<<l<<"\n";
    l.remove(0);
    cout<<l<<"\n";
    l.remove(4);
    cout<<l<<"\n";
    l.pop_back();
    cout<<l<<"\n";
    l.reverse();
    cout<<l<<"\n";
    l.pop_back();
    cout<<l<<"\n";
    return 0;
}