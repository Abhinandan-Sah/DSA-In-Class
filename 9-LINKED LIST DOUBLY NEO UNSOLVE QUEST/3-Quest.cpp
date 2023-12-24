/*
Problem Statement



You are working on a system that manages the inventory of a store. Each item in the inventory has a unique ID and associated information such as name, quantity, and price. The system requires a feature to search for an item by its ID. Implement a program that allows the user to create a doubly linked list of item records and perform a search operation to find a specific item by its ID.



The program should prompt the user to enter the number of items and their respective IDs. It will then create a doubly linked list with the entered item IDs. Next, the program will ask the user to enter an item ID to search for. It will perform the search operation using the searchElement function and display whether the item with the entered ID is present in the list or not.



Note: This is a sample question asked in an Amcat interview.

Input format :
The first line contains an integer n, representing the number of items in the inventory.

The next n lines contain the details of an item in the following format:

<ID>

<Name>

<Quantity>

<Price>.

The next line contains an integer searchId, representing the ID of the item to search for.

Output format :
If the item with the searched ID is present in the inventory, print "Item with ID <ID> is present in the list."

Otherwise, print "Item with ID <ID> is not found in the list."



Refer to the sample output for the exact format.

Code constraints :
The item IDs are integers and are unique within the inventory.

The item names are strings.

The item quantities are integers and represent the available quantity in stock.

The item prices are floating-point numbers.

Sample test cases :
Input 1 :
3
101
Pen
10
5.99
102
Notebook
5
12.99
103
Pencil
20
1.99
101
Output 1 :
Item with ID 101 is present in the list.
Input 2 :
2
201
Chair
8
49.99
202
Table
3
99.99
203
Output 2 :
Item with ID 203 is not found in the list.
*/