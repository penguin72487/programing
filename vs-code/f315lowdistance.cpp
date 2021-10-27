#include<iostream>
#include<vector>
#include<unordered_map>
#include<deque>
#include<algorithm>
using namespace std;
class node{
public:
    //int level;
    int data;
    int r_High=0;
    int l_High = 0;
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
    bool operator <(node* val2)
    {
        return (data < val2->data);
    }
    
    bool operator()(node* val,node* val2)
    {
        return (val->data < val2->data);
    }
    bool operator()(node &val,node &val2)
    {
        return (val.data < val2.data);
    }
    
};
class DC_Tree
{
public:
    node *top;
    int n;
    unordered_map<int,node*> in_Tr;
    deque<node *> r_List;
    unordered_map<int,node*> in_Map;
    long long int ans = 0;
    DC_Tree(int tmp)
    {
        top = new node(2147483647);
        r_List.push_back(top);
        n = tmp;
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
        if(r_List.size()!=1)
        {
            if(tmp<=r_List.back()->data)
            {
                r_List.back()->r_Node = new node(tmp);
                ++r_List.back()->r_High;
                r_List.push_back(r_List.back()->r_Node);
            }
            else
            {
                while(r_List.back()->data<tmp)
                {
                    r_List.pop_back();
                }
                node *in_Node=new node(tmp);
                in_Node->l_Node = r_List.back()->r_Node;
                r_List.back()->r_Node = in_Node;
                r_List.push_back(in_Node);
                
            }
        }
        else
        {
            top->r_Node = new node(tmp);
            r_List.push_back(top->r_Node);
        }
    }
    /*
    int lower_bound(int *array, int size, int key)
    {
        int first = 0, middle;
        int half, len;
        len = size;

        while(len > 0) {
            half = len >> 1;
            middle = first + half;
            if(array[middle] < key) {     
                first = middle + 1;          
                len = len-half-1;       //在右?子序列中查找
            }
            else
                len = half;            //在左?子序列（包含middle）中查找
        }
        return first;
    }
    */
   /*
    node * lower_bound(vector<node*> array, node* key)
    {
        int first=0, middle;
        int half, len;
        len = array.size();

        while(len > 0) {
            half = len >> 1;
            middle = first + half;
            if(array[middle] < key) {     
                first = middle + 1;          
                len = len-half-1;       //在右?子序列中查找
            }
            else
                len = half;            //在左?子序列（包含middle）中查找
        }
        return array[first-1];
    }*/
    void inorder_Traversal()
    {
        inorder_Traversal(top->r_Node);
        cout << "\n";
    }
    void inorder_Traversal(node *now)
    {
        if(!now)
        {
            return;
        }
        inorder_Traversal(now->l_Node);
        cout << now->data << " ";

        inorder_Traversal(now->r_Node);
    }
    void preorder_Trace()
    {
        preorder_Traversal(top->r_Node);
        cout << "\n";
    }
    void preorder_Traversal(node *now)
    {
        if(!now)
        {
            return;
        }
        cout << now->data << " ";
        preorder_Traversal(now->l_Node);
        
        preorder_Traversal(now->r_Node);
    }
    void ans_Traversal(node* now)
    {
        if(!now)
        {
            return;
        }
        ans_Traversal(now->l_Node);
        if(in_Tr.find(now->data)==in_Tr.end())
        {
            in_Tr[now->data] = now;
        }
        else
        {
            if(in_Tr[now->data]->r_Node==now)
            {
                ans += now->l_High;
            }
            else
            {
                ans += in_Tr[now->data]->r_High+now->l_High;
            }
        }
        ans_Traversal(now->r_Node);
    }
    long long int i_Distance()
    {

        i_Distance(top->r_Node);
        ans_Traversal(top->r_Node);
        return ans;
    }
    int i_Distance(node* now)
    {
        if(!now)
        {
            return 0;
        }
        now->l_High = i_Distance(now->l_Node);
        now->r_High = i_Distance(now->r_Node);
        return now->r_High+now->l_High + 1;
    }
};
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    n <<= 1;
    DC_Tree low_Distance(n);
    int tmp;
    for (int i = 0; i < n;++i)
    {
        cin >> tmp;
        low_Distance.insert(tmp);
    }
    //low_Distance.inorder_Traversal();
    cout << low_Distance.i_Distance() << "\n";
    //cout << ans;
}