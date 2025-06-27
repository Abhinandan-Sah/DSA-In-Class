#include<bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
    string s= "hello world";
    // cin>>s;
    stringstream ss(s);
    string word;
    string result;
    while(ss >>  word){
        reverse(word.begin(), word.end());
        result += word+ " ";
    }
    cout<<result;
    // for(string ss)
    return 0;
}