/*
Problem Statement



Dharun is working on a program to manipulate linked lists. He wants to write a function that takes two linked lists as input, inserts nodes at the end, and deletes all the nodes from the first list that also appear in the second list. Dharun needs your help to implement this function. The function should take two linked lists, list1 and list2, as input, where each list is represented by its head node.



Note: This is a sample question asked in a Capgemini interview.

Input format :
The first line contains an integer n, denoting the number of nodes in list1.

The next line contains n space-separated integers, representing the values of the nodes in list1.

The next line contains an integer m, denoting the number of nodes in list2.

The next line contains m space-separated integers, representing the values of the nodes in list2.

Output format :
The first line of output displays the elements of the first linked list before the deletion, separated by a space.

The second line of output displays the elements of the first linked list after the deletion, separated by a space.

If all elements in the first linked list are the same after deletion, the third line will be displayed stating, "All elements in the first linked list are the same."



Refer to the sample output for formatting specifications.

Code constraints :
1 <= n,m <= 100

-50000 <= values of nodes <= 50000

Sample test cases :
Input 1 :
5
2 3 4 5 1
5
1 6 2 3 8
Output 1 :
First Linked List before deletion: 2 3 4 5 1 
First Linked List after deletion: 4 5 
Input 2 :
5
1 2 3 4 5
5
1 2 3 4 5
Output 2 :
First Linked List before deletion: 1 2 3 4 5 
First Linked List after deletion: 
All elements in the first linked list are the same.
*/


#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void printList(list<int> &lst) {
    for (int x : lst) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int n, m, val;
    list<int> list1, list2;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        list1.push_back(val);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> val;
        list2.push_back(val);
    }

    cout << "First Linked List before deletion: ";
    printList(list1);

    for (int x : list2) {
        list1.remove(x);
    }

    cout << "First Linked List after deletion: ";
    if (list1.empty()) {
        cout << "All elements in the first linked list are the same." << endl;
    } else {
        printList(list1);
    }

    return 0;
}
