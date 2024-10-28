/*
Problem Statement



In a university, two student clubs, "Tech Innovators" and "Creative Designers," have decided to collaborate and work on joint projects. As part of the collaboration, they need to merge their member lists to create a unified team. You have been tasked with writing a function that merges two Grounded Header Linked Lists representing the club members, alternating their elements to create a new list.



The student club collaboration program allows the clubs to efficiently manage their member records and facilitate seamless teamwork. Each club maintains its own linked list, where each node represents a club member. The header node serves as the initial node of the list and contains no actual member data. The subsequent nodes hold the member records, with information such as student ID.



To create a unified team, your function should merge the two linked lists, alternating their elements. The merged list should include members from both clubs, with the member records from each club appearing alternatively.



Note: This is a sample question asked in TCS recruitment.

Input format :
The first line of input consists of the number of elements n in the first list.

The second line of input consists of n elements, separated by space.

The third line of input consists of the number of elements m in the second list.

The fourth line of input consists of m elements, separated by space.

Output format :
The first line of output prints the list 1 elements.

The second line of output prints the list 2 elements.

The third line of output prints the merged list, where the elements from both lists are printed alternatively.



Refer to the sample output for formatting specifications.

Sample test cases :
Input 1 :
5
1 2 3 4 5
5
6 7 8 9 10
Output 1 :
List 1: 1 2 3 4 5 
List 2: 6 7 8 9 10 
Merged List: 1 6 2 7 3 8 4 9 5 10 
Input 2 :
4
12 26 34 48
4
56 59 64 78
Output 2 :
List 1: 12 26 34 48 
List 2: 56 59 64 78 
Merged List: 12 56 26 59 34 64 48 78 
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

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    list<int> mergedList;
    auto it1 = list1.begin(), it2 = list2.begin();
    while (it1 != list1.end() || it2 != list2.end()) {
        if (it1 != list1.end()) {
            mergedList.push_back(*it1);
            ++it1;
        }
        if (it2 != list2.end()) {
            mergedList.push_back(*it2);
            ++it2;
        }
    }

    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
