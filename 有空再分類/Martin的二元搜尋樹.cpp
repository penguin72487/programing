#include bitsstdc++.h
using namespace std ;
struct node       //   �ŧi�`�I���c 
{
	double num ;    // �`�I�W�� 
	node lnode ;   // ���l�`�I 
	node rnode ;   // �k�l�`�I 
} ; 				// rnode  num  lnode (�������A�G���j�M�𤧩w�q)  
void search ( double obj , node ptr , node root )  //�ŧi �j�M �禡 
{
	ptr = root ;
	while ( 1 )
	{
		if ( ptr - num == obj )    //�P�_�O�_���ƭȦb�� 
		{
			cout  find it in the BST  endl ;
			break ;
		}
		else if ( ptr - num  obj && ptr - rnode != NULL )
			ptr = ptr - rnode ; // ���p ptr���W�١]num�^ �� obj �]�j�M�ȡ^�p �B rnode �D �Ť��� �h�V�k�M��  
		else if ( ptr - num  obj && ptr - rnode == NULL )
		{	// �� �p�G rnode �� �Ť��� ��� �S���� ptr�j���ƭȦb�𤤤F 
			cout  Sorry, the number is not in the tree.  endl ;
			break ;
		} 
		else if ( ptr - num  obj && ptr - lnode != NULL )
			ptr = ptr - lnode ;   // ���p ptr���W�١]num�^ �� obj �]�j�M�ȡ^�j �B lnode �D �Ť��� �h�V���M��   
		else if ( ptr - num  obj && ptr - lnode == NULL )
		{	// �� �p�G lnode �� �Ť��� ��� �S���� ptr�p���ƭȦb�𤤤F 
			cout  Sorry, the number is not in the tree.  endl ;
			break ;
		}
	 } 
}
void insert ( double obj , node ptr , node root ) // �ŧi ���J���� ���禡 
{
	node newNode = new node ; // �t�m�Ŷ� �� �ŧi newNode(�s������)     
	newNode - num = 0 ;      //  newNode ��l�� 
	newNode - rnode = NULL ;
	newNode - lnode = NULL ;
	ptr = root ;
	while ( true )
	{
		if ( ptr - num == obj )  //�P�_�Ӥ����O�_���b�𤤥X�{�F 
		{
			cout  We have it in the tree!!  endl ;
			break ;
		}
		else if ( ptr - num  obj && ptr - lnode != NULL )
			ptr = ptr - lnode ;  //���p ptr���W�١]num�^ �� obj �]�j�M�ȡ^�j �B lnode �D �Ť��� �h�V���~��V�U�����l�`�I 
		else if ( ptr - num  obj && ptr - lnode == NULL )
		{	// �� �p�G lnode �� �Ť��� ��� �S���� ptr�p���ƭȦb�𤤤F
			ptr - lnode = newNode ; // �ҥH ptr �� lnode �N�O���� �x�s�_�� 
			newNode - num = obj ; 
			break ;
		}
		else if ( ptr - num  obj && ptr - rnode != NULL )
			ptr = ptr - rnode ; 		
 //���p ptr���W�١]num�^ �� obj �]�j�M�ȡ^�p �B lnode �D �Ť��� �h�V�k�~��V�U�����l�`�I 
		else if ( ptr - num  obj && ptr - rnode == NULL )
		{     //�� �p�G rnode �� �Ť��� ��� �S���� ptr�j���ƭȦb�𤤤F
			ptr - rnode = newNode ; //�ҥH ptr �� rnode �N�O���� �x�s�_�� 
			newNode - num = obj ;
			break ;
		}
	}
}
int main ()
{
	double num ;            // �ŧi�ܼ� 
	string motion ; 
	node root = new node ; // �ŧi root �ê�l�� 
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
  

