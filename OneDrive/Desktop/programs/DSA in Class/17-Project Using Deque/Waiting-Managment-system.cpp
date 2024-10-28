/*
Problem Statement



You have been assigned to develop a waitlist management system for a popular restaurant. The restaurant experiences high customer demand and often has a waitlist for customers to secure a table. Your task is to develop a program that simulates this waitlist using a double-ended queue.



The program should provide the following functionalities:



Add Customers: The program should allow the host/hostess to add customers to the waitlist. Each customer is identified by their name. The host/hostess will enter the customer's name, and the program should add the customer to the end of the waitlist.



Remove Customers: Once a table becomes available, the host/hostess can remove customers from the waitlist. The program should display the customer at the front of the waitlist and remove them from the list. The host/hostess can then seat the customer at the available table.



Move Customers: If a customer at the front of the waitlist is not ready to be seated yet, the host/hostess can move them to the end of the waitlist. This is typically done if the customer requests more time or needs to wait for additional members of their party to arrive. The program should move the customer from the front to the back of the waitlist.



Display Waitlist: At any time, the host/hostess can view the current waitlist. The program should display the names and party sizes of all customers on the waitlist, starting from the front to the back.



Your solution should utilize a double-ended queue to implement the waitlist functionality. The program should prompt the user for the required actions and perform the corresponding operations on the waitlist. It should also display appropriate messages to notify the host/hostess about the status of the waitlist and any changes made.



Note: This is a sample question asked in a HCL interview.

Input format :
The input consists of choices.

If the choice is 1, enter the customer's name.

If the option is 2, the customer is removed from the waitlist.

If the choice is 3, the customer is moved to the back of the waitlist.

If the choice is 4, the current waitlist is displayed.

If the choice is 5, exit.



Refer to the sample input for a better understanding.

Output format :
The output prints the results based on the given choices. 

If the choice is 1, display a message indicating that the customer has been added to the waitlist.

If the choice is 2, display a message indicating that the customer has been removed from the waitlist.

If the choice is 3, display a message indicating that the customer has been moved to the back of the waitlist. If there are no customers, print "Error: Waitlist is empty".

If the choice is 4, display the current waitlist. if there are no customers, print "Empty".

If the choice is 5, display the exit message.

If the choice is greater than 5, print "Invalid option!".



Refer to the sample output for the exact text and format.

Sample test cases :
Input 1 :
1
Alice
1
Bob
3
2
4
5
Output 1 :
Alice has been added to the waitlist.
Bob has been added to the waitlist.
Alice has been moved to the back of the waitlist.
Bob has been removed from the waitlist.
Current waitlist:
Alice
Exiting
Input 2 :
1
John
4
5
Output 2 :
John has been added to the waitlist.
Current waitlist:
John
Exiting
Input 3 :
1
Alice
2
3
4
5
Output 3 :
Alice has been added to the waitlist.
Alice has been removed from the waitlist.
Error: Waitlist is empty
Current waitlist:
Empty
Exiting
Input 4 :
10
5
Output 4 :
Invalid option!
Exiting
Input 5 :
1
Damon
1
Stefan
1
Elena
1
Bonnie
1
Enzo
1
Klaus
3
3
4
5
Output 5 :
Damon has been added to the waitlist.
Stefan has been added to the waitlist.
Elena has been added to the waitlist.
Bonnie has been added to the waitlist.
Enzo has been added to the waitlist.
Klaus has been added to the waitlist.
Damon has been moved to the back of the waitlist.
Stefan has been moved to the back of the waitlist.
Current waitlist:
Elena
Bonnie
Enzo
Klaus
Damon
Stefan
Exiting
*/

#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    deque<string> waitlist;
    int choice;
    string name;
    
    while (true) {
        cout << "Enter your choice:\n";
        cout << "1. Add Customers\n";
        cout << "2. Remove Customers\n";
        cout << "3. Move Customers\n";
        cout << "4. Display Waitlist\n";
        cout << "5. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer's name: ";
                cin >> name;
                waitlist.push_back(name);
                cout << name << " has been added to the waitlist.\n";
                break;
            case 2:
                if (waitlist.empty()) {
                    cout << "Error: Waitlist is empty.\n";
                } else {
                    name = waitlist.front();
                    waitlist.pop_front();
                    cout << name << " has been removed from the waitlist.\n";
                }
                break;
            case 3:
                if (waitlist.empty()) {
                    cout << "Error: Waitlist is empty.\n";
                } else {
                    name = waitlist.front();
                    waitlist.pop_front();
                    waitlist.push_back(name);
                    cout << name << " has been moved to the back of the waitlist.\n";
                }
                break;
            case 4:
                if (waitlist.empty()) {
                    cout << "Empty.\n";
                } else {
                    cout << "Current waitlist:\n";
                    for (const auto& customer : waitlist) {
                        cout << customer << endl;
                    }
                }
                break;
            case 5:
                cout << "Exiting.\n";
                return 0;
            default:
                cout << "Invalid option!\n";
        }
    } 
}


