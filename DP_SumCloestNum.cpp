#include<stdio.h>
#include<memory.h>
#include<string>
#include<iostream>

using namespace std;

int GetCloestNum(int *a,int n,int sum);

int main()
{
    int a[] = {1,3,4,6,2,5};
    GetCloestNum(a,sizeof(a)/sizeof(int),11);
    return 1;
}

int GetCloestNum(int *a,int n,int sum){
    int **p ;
    p = new int*[n];
    for(int i = 0 ; i < n; ++i)
        p[i] = new int[n];
    memset(p,0,n*n);
    cout<<"n:"<<n<<"\tsum:"<<sum<<endl; 

    for(int i = 0; i < n; ++i)
        delete[] p[i];
    delete[] p;
}

