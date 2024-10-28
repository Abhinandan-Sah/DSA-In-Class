#include<iostream>
using namespace std;

int powLog(int x, int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return x;
    }
    int val;
    if(n%2==0){
        val=powLog(x, n/2);
    }
    else{
        val =x*powLog(x, n/2);
    }
    
    return val*val;
}

int main()
{
    // cout<<powLog(3, 5);
    // cout<<3*3*3*3*3;
    return 0;
}




//This code have greater T.C=O(n)
/*
#include<iostream>
using namespace std;

int powLog(int x, int n){
    if(n==1)
    return x;
    if(n==0)
    return 1;

    return x*powLog(x, n-1);
}
int main()
{
    cout<<powLog(2, 4);
    return 0;
}
*/
