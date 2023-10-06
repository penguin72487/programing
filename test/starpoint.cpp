#include<iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int a[] = {10, 11, 12, 13, 14, 15, 16};
    int *tp = &a[0];
    int **ttp = &tp;
    int ***tttp = &ttp;
    int ****ttttp = &tttp;
    cout << &a <<" "<< tp <<" "<< ttp <<" "<< tttp <<" "<<ttttp<< "\n";
    cout << &a+1 <<" "<< tp+1 <<" "<< ttp+1 <<" "<< tttp+1 <<" "<<ttttp+1<< "\n";
    cout << (&a+1) <<" "<< (tp+1) <<" "<< *(ttp+1) <<" "<< *(tttp+1) <<" "<<*   (ttttp+1)<< "\n";


    return 0;
}
