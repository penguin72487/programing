# matrix 矩陣  

```cpp
template <class T>
class matrix
{
public:
    vector<vector<T>> val;
    unsigned long long row;
    unsigned long long column;
    ......
}
```  

## Member functions

### (constructor)  

demo  

```cpp
matrix<int> A(2,2);// default initialize 0 {{0,0},{0,0}}
matrix<int> B(2,2,{1,1,1,0});
matrix<int> C=B;
```  


### operator =

1. ```operator = (matrix\<T>);```
2. ```operator = (initializer_list<T>);```使用必須確認數量一致。
3. ```operator = (initializer_list<initializer_list<T>> )```


```cpp
matrix<int> A(2,2);// default initialize 0 {{0,0},{0,0}}
matrix<int> B(2,2,{1,1,1,0});
A=B;// A == {1,1,1,0}
matrix<long long> C(2,2,{{2, 1}, {3, 9}});
    //C = {{2, 1}, {3, 9}};
```

### operator []  

```operator [](unsigned long long i)```

```cpp
cout<<A[1][1]<<"\n";
```


### operator *=  

```operator *=(matrix<T>)```  

```cpp  
A*=B;
B*=B;
```

### friend ostream &operator  
```friend istream& operator<<(istream&s, matrix ob)```
```friend ostream &operator<<(ostream &s, matrix &ob)```


```cpp
cout<<A; 
/*
1 1
1 0
*/
```

