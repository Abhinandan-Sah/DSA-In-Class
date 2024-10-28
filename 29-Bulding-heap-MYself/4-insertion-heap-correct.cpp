/*
In an online gaming platform, players have individual scores that determine their ranking on a leaderboard. The platform needs a program to manage and display the leaderboard efficiently using a max heap. The player with the highest score should be at the top of the leaderboard.



Write a program that assists the gaming platform in maintaining a leaderboard of players' scores using a max heap.

Input format :
The input consists of a series of space-separated integers, each representing the score of a player.

Output format :
The output displays the player scores on the leaderboard, positioning the player with the highest score at the top.

Code constraints :
The maximum number of players that can be displayed on the leaderboard is 100, as the max heap has a maximum capacity of 100.

Sample test cases :
Input 1 :
10 20 5 15 25
Output 1 :
25 20 5 10 15 
Input 2 :
30 12 18
Output 2 :
30 12 18 
*/

// You are using GCC

#include <iostream>
using namespace std;

struct Player {
  int score;
};

void swap(Player& a, Player& b) {
  Player temp = a;
  a = b;
  b = temp;
}

void insertPlayer(Player heap[], int& heapSize, Player newPlayer) {
  // Increase the heap size by 1.
  heapSize++;

  // Insert the new player at the end of the heap.
  heap[heapSize - 1] = newPlayer;

  // Percolate up the new player to maintain the max heap property.
  int childIndex = heapSize - 1;
  while (childIndex > 0 && heap[childIndex].score > heap[(childIndex - 1) / 2].score) {
    swap(heap[childIndex], heap[(childIndex - 1) / 2]);
    childIndex = (childIndex - 1) / 2;
  }
}

void printHeap(Player heap[], int heapSize) {
  for (int i = 0; i < heapSize; i++) {
    cout << heap[i].score << " ";
  }
  cout << endl;
}

int main() {
  Player maxHeap[100];
  int heapSize = 0;

  // Read the player scores from the input.
  while (true) {
    Player newPlayer;
    if (!(cin >> newPlayer.score)) {
      break;
    }

    insertPlayer(maxHeap, heapSize, newPlayer);
  }

  // Print the leaderboard.
  printHeap(maxHeap, heapSize);

  return 0;
}
