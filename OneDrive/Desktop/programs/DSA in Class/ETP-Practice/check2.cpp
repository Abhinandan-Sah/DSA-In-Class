#include<iostream>
using namespace std;

void countHigFreq(int arr[], int n){
    cout<<endl<<"Size of n: "<<n<<endl;
    int maxCount=0;
    int p=n;
    int cpyArr[p];
    for(int i=0; i<n; i++){
        cpyArr[i]=arr[i];
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<cpyArr[i]<<" ";
    }
    cout<<endl;
    
    for(int i=0; i<n-1; i++){
        int count =1;
        int val=arr[i];
        for(int j=i+1; j<n; j++){
            if(val==arr[j]){
                count++;
                for(int k=j; k<n; k++){
                    if((j+1)<n){
                    arr[j]=arr[j+1];
                    }
                }
                n--; 
                j--;
            }
            
        }
        
        if(count>=maxCount){
            maxCount=count;
        }
        // if(count>maxCount){
        //     maxCount=i;
        //     element=arr[i];
        //     // arr[p]=arr[i];
        //     // p++;
        // }
        
                // fStore[q]=arr[i];
                // q++;
        
                // fStore[q]=count;
                // q++;
        
        
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<endl<<"maxCount: "<<maxCount<<endl;
for(int i=0; i<p-1; i++){
        int count =1;
        int val=cpyArr[i];
        for(int j=i+1; j<p; j++){
            if(val==arr[j]){
                count++;
                for(int k=j; k<p; k++){
                    arr[j]=arr[j+1];
                }
                n--; 
                j--;
            }
            
        }
            cout<<endl<<"Count: "<<count<<endl;

        if(count==maxCount){
            cout<<cpyArr[i]<<" ";
        }
        // if(count>maxCount){
        //     maxCount=i;
        //     element=arr[i];
        //     // arr[p]=arr[i];
        //     // p++;
        // }
        
                // fStore[q]=arr[i];
                // q++;
        
                // fStore[q]=count;
                // q++;
        
        
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<cpyArr[i]<<" ";
    }
    cout<<endl;

    // int maxi=0;
    // int fStoreSize= (2*n);
    // for(int i=1; i<fStoreSize; ){
    //     if(maxi<fStore[i]){
    //         maxi=fStore[i];
    //     }
    //     i=i+2;
    // }
    // for(int i=1; i< fStoreSize; ){
    //     if(fStore[i]==maxi){
    //         cout<<fStore[i-1]<<" ";
    //     }
    //     i+=2;
    // }
    
    
    
}

int main(){
    int n; 
    cin>>n; 
    int arr1[n];
    for(int i=0; i<n; i++){
        cin>>arr1[i];
    }
    int m;
    cin>>m;
    int arr2[m];
    for(int i=0; i<m; i++){
        cin>>arr2[i];
    }
    int p=n+m;
    int arr3[p];
    for(int i=0; i<n; i++){
        arr3[i]=arr1[i];
    }
    int k=0; 
    for(int i=n; i<p; i++){
        arr3[i]=arr2[k];
        k++;
    }
    
    countHigFreq(arr3, p);
    
    return 0;
}