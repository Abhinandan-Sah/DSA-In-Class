#include<iostream>
using namespace std;

void findFrequency(int* arr,int n){
    for(int round=0; round<n; round++){
        int count=1;
        int val=arr[round];
        for(int step=(round+1); step<n; step++){
            if(val==arr[step]){
                count++;
                for(int i=step; i<n; i++){
                    arr[i]=arr[i+1];
                }
                step--;
                n--;
                //counting how many times size decrease for so it 
                //can be subtract from size of arr while printing
            }

        }
        cout<<arr[round]<<" - "<<count<<" times"<<endl;
    }
}
int main(){
    int n;
    int arr[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int flag=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }

    
    
    findFrequency(arr,n);
}