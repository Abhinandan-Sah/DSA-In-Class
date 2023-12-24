// You are using GCC
#include<iostream>
#include<string>
using namespace std; 

int main(){
    int n;
    cin>>n;
    if(1<=n<=100){
        string str[n];
        for(int i=0; i<n; i++){
            cin>>str[i];
        }
        string arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int m=2*n;
        cout<<endl<<m<<endl;
        string str2[m];
        int k=0; 
        int l=0;
        for(int i=0; i<m; i++){
            if(i%2==0){
                str2[i]=str[k];
                k++;
            }
            else{
                str2[i]=arr[l];
                l++;
            }
        }
        
        for(int i=0; i<m; i++){
            cout<<str2[i]<<" ";
        }
    }
    return 0;
}