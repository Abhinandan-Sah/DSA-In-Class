//It is just like fibonacci

#include<iostream>
using namespace std;

int stair(int n){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }

    return stair(n-1)+ stair(n-2);
}

int main()
{
    cout<<"The number of stairs are: "<<stair(5);
    return 0;
}