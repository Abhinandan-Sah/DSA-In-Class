/*
Problem Statement



Imagine you are developing a program to manage a queue of incoming messages in a messaging application using a circular header linked list. Each node in the linked list represents a message, with the message content stored as data in the node. 



You have implemented the functionality to insert new messages at the beginning of the queue and display the current queue of messages. Now, you want to enhance your program by allowing users to reverse the order of all messages that were inserted at the beginning of the queue. 



Write a program that provides the functionality to reverse the order of such messages in the circular header linked list. Your code should display the original queue of messages after the reversal operation. The message content should be taken as input from the user. Consider handling cases such as an empty queue or a queue with a single message.



Note: This is a sample question asked in Capgemini recruitment.

Input format :
The first line represents the size of the list n.

The next n lines represent the values inside the list.

Output format :
The output represents the value in reverse order.



Refer to the sample output for formatting specifications.

Sample test cases :
Input 1 :
4
Hello, how are you?
Can we meet tomorrow?
Don't forget to bring the documents.
See you soon!
Output 1 :
Message Queue: 
- See you soon!
- Don't forget to bring the documents.
- Can we meet tomorrow?
- Hello, how are you?

Input 2 :
2
Hello, Hi
Let's code
Output 2 :
Message Queue: 
- Let's code
- Hello, Hi

Input 3 :
0
Output 3 :
Message queue is empty!
*/