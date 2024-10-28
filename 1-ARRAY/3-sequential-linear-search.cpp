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
    cout<<"Enter element you want to Find"<<endl;
    cin>>item;

    //linear search
    bool ind=false;
    int i;
    for( i=0; i<n; i++){
        if(arr[i]==item){
            ind=true;
            break;
        }
        
    }
    if(ind){
        cout<<"Element is found at index "<<i;
    }
    else{
        cout<<"Element isn't present in an array";

    }

    return 0;
}