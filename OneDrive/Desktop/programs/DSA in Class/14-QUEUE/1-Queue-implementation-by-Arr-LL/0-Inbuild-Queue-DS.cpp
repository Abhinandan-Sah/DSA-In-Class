#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int>q;
    q.push(5);
    q.push(6);
    cout<<q.front()<<endl;
    q.emplace(10);
    return 0;
}