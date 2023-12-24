/*
pow(a, b);
*/

#include<iostream>
using namespace std;

int power(int a, int b){
    if(a==0 && b==0){
        cout<<"0 to the power 0 is not defined";
        return -100;
    }
    if(b==0){
        return 1;
    }
    return a*power(a, b-1);
}

int main()
{
    int p=1;
    cout<<power(3, 3);
    return 0;
}