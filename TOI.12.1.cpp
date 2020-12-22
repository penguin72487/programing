#include<iostream>
using namespace std;

int main ()
{
    int r , c ;
    cin >> r >> c ;
    int a[r+2][c+2] = {0} ;
    for ( int i = 1 ; i <= r ; i++ )
        for ( int j = 1 ; j <= c ; j++ )
            cin >> a[i][j] ;
    int count = 0 ;
    for ( int i = 1 ; i <= r ; i++ )
    {
        for ( int j = 1 ; j <= c ; j++ )
        {
            int u = 0 ;
            for ( int q = i-1 ; q <= i+1  ; q++ )
            {
                for ( int w = j-1 ; w <= j+1 ; w++ )
                {
                    if ( q == i && w == j )
                        continue ;
                    else
                    {
                        if ( a[i][j] == a[q][w] && a[q][w] != 0 )
                        {
                            u = -1 ;
                            break;
                        } 
                    }
                }
                if ( u == -1 )
                    break;
            }
            if ( u == 0 )
                count++ ;
        }
    }
    cout << count << '\n' ;
 }
