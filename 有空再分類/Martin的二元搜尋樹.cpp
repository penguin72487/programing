#include bitsstdc++.h
using namespace std ;
struct node       //   宣告節點結構 
{
	double num ;    // 節點名稱 
	node lnode ;   // 左子節點 
	node rnode ;   // 右子節點 
} ; 				// rnode  num  lnode (恆不等式，二分搜尋樹之定義)  
void search ( double obj , node ptr , node root )  //宣告 搜尋 函式 
{
	ptr = root ;
	while ( 1 )
	{
		if ( ptr - num == obj )    //判斷是否找到數值在樹中 
		{
			cout  find it in the BST  endl ;
			break ;
		}
		else if ( ptr - num  obj && ptr - rnode != NULL )
			ptr = ptr - rnode ; // 假如 ptr的名稱（num） 比 obj （搜尋值）小 且 rnode 非 空元素 則向右尋找  
		else if ( ptr - num  obj && ptr - rnode == NULL )
		{	// 但 如果 rnode 為 空元素 表示 沒有比 ptr大的數值在樹中了 
			cout  Sorry, the number is not in the tree.  endl ;
			break ;
		} 
		else if ( ptr - num  obj && ptr - lnode != NULL )
			ptr = ptr - lnode ;   // 假如 ptr的名稱（num） 比 obj （搜尋值）大 且 lnode 非 空元素 則向左尋找   
		else if ( ptr - num  obj && ptr - lnode == NULL )
		{	// 但 如果 lnode 為 空元素 表示 沒有比 ptr小的數值在樹中了 
			cout  Sorry, the number is not in the tree.  endl ;
			break ;
		}
	 } 
}
void insert ( double obj , node ptr , node root ) // 宣告 插入元素 的函式 
{
	node newNode = new node ; // 配置空間 並 宣告 newNode(新的元素)     
	newNode - num = 0 ;      //  newNode 初始化 
	newNode - rnode = NULL ;
	newNode - lnode = NULL ;
	ptr = root ;
	while ( true )
	{
		if ( ptr - num == obj )  //判斷該元素是否早在樹中出現了 
		{
			cout  We have it in the tree!!  endl ;
			break ;
		}
		else if ( ptr - num  obj && ptr - lnode != NULL )
			ptr = ptr - lnode ;  //假如 ptr的名稱（num） 比 obj （搜尋值）大 且 lnode 非 空元素 則向左繼續向下延伸子節點 
		else if ( ptr - num  obj && ptr - lnode == NULL )
		{	// 但 如果 lnode 為 空元素 表示 沒有比 ptr小的數值在樹中了
			ptr - lnode = newNode ; // 所以 ptr 的 lnode 就是此數 儲存起來 
			newNode - num = obj ; 
			break ;
		}
		else if ( ptr - num  obj && ptr - rnode != NULL )
			ptr = ptr - rnode ; 		
 //假如 ptr的名稱（num） 比 obj （搜尋值）小 且 lnode 非 空元素 則向右繼續向下延伸子節點 
		else if ( ptr - num  obj && ptr - rnode == NULL )
		{     //但 如果 rnode 為 空元素 表示 沒有比 ptr大的數值在樹中了
			ptr - rnode = newNode ; //所以 ptr 的 rnode 就是此數 儲存起來 
			newNode - num = obj ;
			break ;
		}
	}
}
int main ()
{
	double num ;            // 宣告變數 
	string motion ; 
	node root = new node ; // 宣告 root 並初始化 
	root - num = 1000 ;
	root - lnode = NULL ;
	root - rnode = NULL ;
	node ptr ;
	ptr = root ;
	while ( true )
	{
		cout  enter 1 to insert   endl ;
		cout  enter 2 to search   endl ;
		cout  enter 3 to exit   endl ;
		cout  Your Action  ;
		cin  motion ;
		if ( motion == 1 )
		{
			cout  number to insert  ;
			cin  num ;
			insert( num , ptr , root ) ;
		} 
		if ( motion == 2 )
		{
			cout  number to search  ;
			cin  num ;
			search( num , ptr , root ) ; 
		}
		if ( motion == 3 )
			break ;
		else
			//cout  you enter wrong. please entering again.;
		cout  endl ;
	}
	return 0 ; 
}
  

