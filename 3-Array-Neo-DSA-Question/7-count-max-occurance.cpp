#include<iostream>
using namespace std;

int main()
{
    int arr[100];
    int n;
    cout<<"Enter size: "<<endl;
    cin>>n;
    int p=n;
    int arr1[100];
    // cout<<"Value of n: "<<n;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    for(int i=0; i<n; i++){
        arr1[i]=arr[i];
    }
    int count=0; 
    int maxCount=0;
    // int i, j, k;
    int i;
    for( i=0; i<n; i++){
        count =1;
        for(int j=i+1; j<n; j++){
            if(arr[i]==arr[j]){
                count++;
                for(int k=j; k<n; k++){
                    arr[k]=arr[k+1];
                }
                n=n-1; 
            j=j-1;
            }
            
            //  cout<<"n: "<<maxCount<<endl;

        }
                            cout<<"Count: "<<arr[i]<<" : "<<count<<endl;

        if(count>=maxCount){
               maxCount=count;
        }
    }

    cout<<"MaxCount: "<<maxCount<<endl;

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
    int x;
    int c=0;
    for( x=0; x<p; x++){
        c =1;
        for(int y=x+1; y<p; y++){
            if(arr1[x]==arr1[y]){
                c++;
                for(int z=y; z<p; z++){
                    arr1[z]=arr1[z+1];
                }
                p=p-1;
                y=y-1;
            }
            //  cout<<"n: "<<maxCount<<endl;

        }
                    // cout<<"Count: "<<arr1[x]<<" : "<<c<<endl;

        if(c==maxCount){
               cout<<arr1[x]<<" ";
        }
    }

    return 0;
}