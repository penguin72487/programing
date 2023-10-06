#include<iostream>
#include<vector>
#include<deque>
using namespace std;
class node{
public:
    int data;
    vector<node *> in_Level;
    node(int tmp)
    {
        data = tmp;
    }
};
class skip_List{
public:
    node *op=new node(-2147483648);
    node *ed=new node(2147483647);
    int max_Level=1;
    skip_List()
    {
        op->in_Level.push_back(ed);
        op->in_Level.push_back(ed);
    }
    ~skip_List()
    {
        node *tmp = op;
        for (auto it = op; it != nullptr;it=tmp)
        {
            
            tmp = it->in_Level[0];
            delete it;
        }
    }
    
    void insert(int tmp)
    {
        node *in_Node = new node(tmp);
        deque<node *> pa_Node;
        node *now = op;
        int now_Level=max_Level;
        while(now_Level>-1)
        {
            if(now->data>now->in_Level[now_Level]->data)
            {

                now = now->in_Level[0];
            }
            else
            {
                pa_Node.push_back(now);
                --now_Level;
            }
            
        }
        in_Node->in_Level[0]=now->in_Level[0];
        now->in_Level[0] = in_Node;
        ++now_Level;
        pa_Node.pop_back();
        ++now_Level;

        while(now_Level<=max_Level)
        {
            now = pa_Node.back();
            int rang_Num = 0;
            node *tmp = now;
            while(tmp->in_Level[now_Level-1]!=tmp->in_Level[now_Level])
            {
                tmp = tmp->in_Level[now_Level - 1];
                ++rang_Num;
            }
            if(rang_Num==3)
            {
                now->in_Level[now_Level - 1]->in_Level[now_Level - 1]->in_Level.push_back(now->in_Level[now_Level]);
                now->in_Level[now_Level] = now->in_Level[now_Level - 1]->in_Level[now_Level - 1];
                if(now_Level==max_Level)
                {
                    op->in_Level.push_back(ed);
                    ++max_Level;
                }
            }
        }
    }
};
int main()
{
    int n;
    cin >> n;
    skip_List ksp;
    for (int i = 0; i < n;++i)
    {
        int tmp;
        cin >> tmp;
        ksp.insert(tmp);
    }
    for (auto it = ksp.op; it != nullptr;it=it->in_Level[0])
    {
        cout << it->data << "\n";
    }
}
