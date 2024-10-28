#include<iostream>
using namespace std;

int toh(int n, char s, char h, char d, int& cnt){
    if(n==0){
        return cnt;
    }

    toh(n-1, s, d, h, cnt=cnt+1);
    cout<<s<<"->"<<d<<endl;
    toh(n-1, h, s, d, cnt);
}

int main()
{
    int n;
    cin>>n;
    int count=0;
    cout<<toh(n, 'A', 'B', 'C', count);
    return 0;
}