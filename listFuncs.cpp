// Name: Chia-Hao Chang
// GitHub: ChiaHaoChangTw
// Hash Table Implementation

#include <iostream>
#include <cassert>

#include "listFuncs.h"

using namespace std;

// Construct a new node with theKey as its key, and theValue as its value.
Node::Node(const string &theKey, int theValue){
   key = theKey;
   value = theValue;
   next = NULL;
}

// Construct a new node with theKey as its key, theValue as its value, and n as its next node.
Node::Node(const string &theKey, int theValue, Node *n) {
   key = theKey;
   value = theValue;
   next = n;
}

// Print out keys and values of all the nodes in the list, one per line.
// Sample output:
//   zhou 283
//   sam 84
//   babs 99
void printList(ListType listHead){
   while(listHead){
      cout << listHead->key << " " << listHead->value << endl;
      listHead = listHead->next;
   }
}

// Return the length of the list.
int listLength(ListType listHead){
   int count = 0;
   while(listHead){
      ++count;
      listHead = listHead->next;
   }
   return count;
}

// Search node with theKey as its key, return NULL if the node does not exist in the list.
ListType searchNode(ListType listHead, const string &theKey){
   while(listHead && listHead->key != theKey){
      listHead = listHead->next;
   }
   return listHead;
}

// Insert a new node with theKey and theValue in front of the list.
void insertFront(ListType& listHead, const string &theKey, int theValue){
   listHead = new Node(theKey, theValue, listHead);
}

// Remove a node with theKey as its key, return false if the node does not exist in the list.
bool removeNode(ListType& listHead, const string &theKey){
   if(!listHead){
      return false;
   }
   if(listHead->key == theKey){
      Node* temp = listHead;
      listHead = listHead->next;
      delete temp;
      return true;
   }
   ListType preNode = listHead;
   ListType currNode = listHead->next;
   while(currNode && currNode->key != theKey){
      preNode = currNode;
      currNode = currNode->next;
   }
   if(!currNode){
      return false;
   }
   preNode->next = currNode->next;
   delete currNode;
   return true;
}