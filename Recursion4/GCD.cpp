#include<bits/stdc++.h>
#include<math.h>
#include<algorithm>
using namespace std;

int  gcd(int a, int r){
    if(r==0){
        return a;
    }
    if(a<r){return 1;}
    int temp = r;
    r=a%r;
    a=temp;
    return gcd(a,r);
}

int main()
{
    int a=1000, b=10001;
    int divisior=min(a, b);
    int divident=max(a,b);
    int rememder=divident%divisior;
    cout<<gcd(divisior, rememder);
    return 0;
}