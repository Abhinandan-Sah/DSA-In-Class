/*
Problem Statement



You are developing a web analytics tool that tracks user engagement on a website. The tool requires functionality to determine the number of unique user interactions recorded in a log file. Each user interaction is represented by a unique session ID. Implement a program that allows the user to input a log file containing session IDs representing user interactions. The program should create a doubly linked list using the session IDs from the log file and calculate the total count of unique user interactions in the list.



The program should read the log file, which consists of one session ID per line. It will then create a doubly linked list using the session IDs as the data. Next, the program will traverse the list and count the number of unique session IDs present. Finally, it will display the count as the output.



The web analytics tool will provide valuable insights to website administrators by accurately determining the number of unique user interactions, enabling them to analyze user engagement and make data-driven decisions to enhance the user experience.



Note: This is a sample question asked in an Amazon interview.

Input format :
The input begins with an integer N, representing the number of session IDs in the log file.

This is followed by N lines of strings, each containing a session ID.

Output format :
The program should output a single line containing the number of unique user interactions.

Code constraints :
The program assumes the input log file is formatted with one session ID per line.

The session IDs are alphanumeric strings.

The log file may contain duplicate session IDs.

The maximum length of a session ID is 100 characters.

The maximum number of session IDs in the log file is 1000.

Sample test cases :
Input 1 :
3
ABC123
DEF456
GHI789
Output 1 :
Number of unique user interactions: 3
Input 2 :
5
ABC123
DEF456
ABC123
JKL987
DEF456
Output 2 :
Number of unique user interactions: 3
Input 3 :
2
XYZ789
XYZ789
Output 3 :
Number of unique user interactions: 1
*/