// Name: Chia-Hao Chang
// GitHub: ChiaHaoChangTw
// Hash Table Implementation

//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

#include <string>
  
// Define Node data structure which stores a key, a value, and a next pointer.
struct Node{
   std::string key;
   int value;
   Node *next;
   
   // Construct a new node with theKey as its key, and theValue as its value.
   Node(const std::string &theKey, int theValue);
   // Construct a new node with theKey as its key, theValue as its value, and n as its next node.
   Node(const std::string &theKey, int theValue, Node *n);
};

typedef Node * ListType;

// Print out keys and values of all the nodes in the list, one per line.
// Sample output:
//   zhou 283
//   sam 84
//   babs 99
void printList(ListType listHead);

// Return the length of the list.
int listLength(ListType listHead);

// Search node with theKey as its key, return NULL if the node does not exist in the list.
ListType searchNode(ListType listHead, const std::string &theKey);

// Insert a new node with theKey and theValue in front of the list.
void insertFront(ListType& listHead, const std::string &theKey, int theValue);

// Remove a node with theKey as its key, return false if the node does not exist in the list.
bool removeNode(ListType& listHead, const std::string &theKey);

// keep the following line at the end of the file
#endif