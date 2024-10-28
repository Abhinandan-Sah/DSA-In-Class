#include<iostream>
using namespace std;

int main()
{
    int arr[15];
    int n;
    cout<<"Enter the size of an array"<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int item;
    cout<<"Enter new element you want to insert"<<endl;
    cin>>item;
    int pos;
    cout<<"Enter position in which you want to insert"<<endl;
    cin>>pos;

    //Insertion algo
    
    arr[pos]=item;
    n=n+1;

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    
    


    return 0;
}