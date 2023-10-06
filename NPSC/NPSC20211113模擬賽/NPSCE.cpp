#include<iostream>
#include<deque>
using namespace std;
class node{
public:
    
    int data;
    int r_Num = 0;
    node ()
    {

    }

    node(int tmp)
    {
        data = tmp;


    }
    //node* min_Node = this;
    //int i_Max = -2147483648;
    node *l_Node = nullptr;
    node *r_Node = nullptr;
    
};
class DC_Tree
{
public:
    node *top;
    node *end;
    deque<node *> r_List;

    DC_Tree()
    {
        top = new node(0);
        r_List.push_back(top);
    }
    ~DC_Tree()
    {
        dis_Node();
    }
    void dis_Node()
    {
        dis_Node(top);
    }
    void dis_Node(node* now)
    {
        if(!now)
        {
            return;
            
            
        }
        dis_Node(now->l_Node);
        dis_Node(now->r_Node);
        delete now;
    }
    void insert(int tmp)
    {
            if(tmp==r_List.back()->data)
            {
                r_List.back()->r_Node = new node(tmp);
                r_List.push_back(r_List.back()->r_Node);
            }
            else
            {
                
                node *in_Node=new node(tmp);
                in_Node->l_Node = *r_List.begin();
                (*r_List.begin())->r_Num = r_List.size();
                r_List.clear();
                end = in_Node;
                r_List.push_back(in_Node);
            }
    }
    void insert_End()
    {
        end->r_Num = r_List.size();
        r_List.clear();
    }
    int longSam()
    {
        int ans = 0;
        node *now = end;
        while(now->l_Node!=top)
        {
            
            int i_Sum=now->r_Num;
            if(now->l_Node->r_Num==1&&now->l_Node->l_Node->data==now->data)
            {
                i_Sum += 1 + now->l_Node->l_Node->r_Num;
            }
            else
            {
                ++i_Sum;
            }



            ans = max(ans, i_Sum);
            now = now->l_Node;
        }
        ans = max(now->r_Num, ans);
        return ans;
    }
    
};
int main()
{
    int n;
    cin >> n;
    DC_Tree tmp;
    for (int i = 0; i < n;++i)
    {
        int a;
        cin >> a;
        tmp.insert(a);
    }
    tmp.insert_End();
    cout << tmp.longSam() << "\n";

}