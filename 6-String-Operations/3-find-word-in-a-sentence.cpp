#include<iostream>
#include<string>
using namespace std;
int main(){

    string str;
    getline(cin, str);
    string str1;
    cin>>str1;
    size_t found = str.find(str1);
        if(found!=string::npos){
            cout<<"The word '"<<str1<<"' is present in the given sentence.";
        }else{
            cout<<"The word '"<<str1<<"' is not present in the given sentence.";
        }
    
    return 0;
}