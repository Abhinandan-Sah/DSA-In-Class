#include<iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int>pq;
    pq.push(5);
    pq.push(10);
    pq.push(15);
    cout<<pq.size()<<endl;
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }                  //-> o/p= 15 10 5
    return 0;
}