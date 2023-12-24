#include<iostream>
using namespace std;

void TOH(int n, char s, char a, char d){
    if(n==1){
        cout<<"Move "<<n<<" from "<<s<<" to "<<d<<endl;
        return;
    }
    TOH(n-1, s, d, a);
            cout<<"Move "<<n<<" from "<<s<<" to "<<d<<endl;
        // cout<<"Move n from "<<s<<" to "<<d<<endl;
    TOH(n-1, a, s, d);
}

int main()
{
    int n;
    cout<<"Enter no. of disk: ";
    cin>>n;
    TOH(n, 'A', 'B','C');
    return 0;
}