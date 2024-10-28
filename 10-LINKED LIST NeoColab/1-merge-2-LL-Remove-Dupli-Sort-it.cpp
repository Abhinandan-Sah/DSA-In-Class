#include<iostream>
#include<vector>
using namespace std;

class Node{    //User defined data type
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

class LinkedList{   //user defined data structure
    public:
    Node* head;
    Node* tail;
    int size;
    LinkedList(){
        head=NULL;
        tail=NULL;
        size=0;
    }

    void insertAtEnd(int val){
        Node* temp= new Node(val);
        if(size==0){
            head=tail=temp;
        } 
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }

    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};

void removeDuplicate(int arr[], int &n){
    for(int round=0; round<n-1; round++){
        int val=arr[round];
        for(int step=(round+1); step<n; step++){
            if(val==arr[step]){
                for(int i=step; i<n; i++){
                    arr[i]=arr[i+1];
                }
                step--;
                n--;
                
            }
        }
    }
    
}

void insertionSort(int arr[], int n){
   

    for(int round=1; round<n; round++){

        //storing 2 vale of arr in val
        int val=arr[round];
        int j=round-1;
        for(; j>=0; j--){
            
            // compare
            if(arr[j]>val){
                //shift
                arr[j+1]=arr[j];
            }
            else{
                //rukna hai
                break;
            }
        }

        arr[j+1]=val;

    }
}

int main(){
    LinkedList l1 = LinkedList();
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

    insertionSort(arr1, n);
    

    cout<<"First Linked List: ";
    for(int i=0; i<n; i++){
        l1.insertAtEnd(arr1[i]);
    }

    l1.display();
    
    removeDuplicate(arr1, n);
    
    insertionSort(arr2, m);
    LinkedList l2 = LinkedList();
    cout<<"Second Linked List: ";
    for(int i=0; i<m; i++){
        l2.insertAtEnd(arr2[i]);
    }

    l2.display();

    removeDuplicate(arr2, m);

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

    

    removeDuplicate(arr3, p);
    insertionSort(arr3, p);

    
    LinkedList ll = LinkedList();
    cout<<"Union Linked List: ";
    for(int i=0; i<p; i++){
        ll.insertAtEnd(arr3[i]);
    }

    ll.display();

    
    
    
    return 0;
}


