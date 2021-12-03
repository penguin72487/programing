#include<iostream>
#include<vector>
#include<deque>
#include <iterator>
#include<algorithm>
using namespace std;
class node{
public:
    long long i_Sum = 0;
    int data;

    node ()
    {

    }

    node(int &tmp)
    {
        data = tmp;
        i_Sum = data;

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
    deque<node *> r_List;

    DC_Tree()
    {
        int zero = 0;
        top = new node(zero);
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
    void dis_Node(node*& now)
    {
        if(!now)
        {
            return;
            
            
        }
        dis_Node(now->l_Node);
        dis_Node(now->r_Node);
        delete now;
    }
    void insert(int &tmp)
    {
        if(r_List.size()!=1)
        {
            if(tmp>r_List.back()->data)
            {
                r_List.back()->r_Node = new node(tmp);
                r_List.push_back(r_List.back()->r_Node);
            }
            else
            {
                while(r_List.back()->data>tmp)
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
                len = len-half-1;       //�b�k?�l�ǦC���d��
            }
            else
                len = half;            //�b��?�l�ǦC�]�]�tmiddle�^���d��
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
                len = len-half-1;       //�b�k?�l�ǦC���d��
            }
            else
                len = half;            //�b��?�l�ǦC�]�]�tmiddle�^���d��
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

    int i_Licky()
    {
        i_Sum();
        node *now = top->r_Node;
        while(now->i_Sum!=now->data)
        {
            if(!now->l_Node)
            {
                now = now->r_Node;
            }
            else if(!now->r_Node)
            {
                now = now->l_Node;
            }
            else if(now->l_Node->i_Sum>now->r_Node->i_Sum)
            {
                now = now->l_Node;
            }
            else
            {
                now = now->r_Node;
            }
        }
        return now->data;
    }
    void i_Sum()
    {
        i_Sum(top->r_Node);
    }
    long long i_Sum(node*& now)
    {
        if(!now)
        {
            return 0;
        }
        now->i_Sum = i_Sum(now->l_Node) + i_Sum(now->r_Node)+now->data;
        return now->i_Sum;
    }
};
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    DC_Tree Licky;
    for (int i = 0; i < n;++i)
    {
        int tmp;
        cin >> tmp;
        Licky.insert(tmp);
    }
    //Licky.inorder_Traversal();
    cout << Licky.i_Licky() << "\n";
}