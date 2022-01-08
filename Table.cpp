// Name: Chia-Hao Chang
// GitHub: ChiaHaoChangTw
// Hash Table Implementation

// Table.cpp Table class implementation

#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

// for hash function called in private hashCode method defined below
#include <functional>

using namespace std;

#include "listFuncs.h"

//*************************************************************************

// create an empty table, i.e., one where numEntries() is 0
// (Underlying hash table is HASH_SIZE.)
Table::Table(){
   hashSize = HASH_SIZE;
   hashTable = new ListType[hashSize]();
   listLen = new int[hashSize]();
   numEntry = 0;
   assert(isValidTable());
}

// create an empty table, i.e., one where numEntries() is 0
// such that the underlying hash table is hSize
// PRE: hSize > 0
Table::Table(unsigned int hSize){
   assert(hSize > 0);
   hashSize = hSize;
   hashTable = new ListType[hashSize]();
   listLen = new int[hashSize]();
   numEntry = 0;
   assert(isValidTable());
}

// returns the address of the value that goes with this key
// or NULL if key is not present.
// Thus, this method can be used to either lookup the value or
// update the value that goes with this key.
int* Table::lookup(const string &key){
   int currCode = hashCode(key);
   ListType currNode = searchNode(hashTable[currCode], key);
   if(!currNode){
      assert(isValidTable());
      return NULL;
   }
   assert(isValidTable());
   return &currNode->value;
}

// remove a pair given its key
// return false iff key wasn't present
// (and no change made to table)
bool Table::remove(const string &key){
   int currCode = hashCode(key);
   bool removed = removeNode(hashTable[currCode], key);
   if(removed){
      --listLen[currCode];
      --numEntry;
   }
   assert(isValidTable());
   return removed;
}

// insert a new pair into the table
// return false iff this key was already present 
// (and no change made to table)
bool Table::insert(const string &key, int value){
   int currCode = hashCode(key);
   if(searchNode(hashTable[currCode], key)){
      assert(isValidTable());
      return false;
   }
   insertFront(hashTable[currCode], key, value);
   ++listLen[currCode];
   ++numEntry;
   assert(isValidTable());
   return true;
}

// number of entries in the table
int Table::numEntries() const{
   assert(isValidTable());
   return numEntry;
}

// print out all the entries in the table, one per line.
void Table::printAll() const{
   for(int i = 0; i < hashSize; ++i){
      printList(hashTable[i]);
   }
   assert(isValidTable());
}

// hashStats: for diagnostic purposes only
// prints out info to let us know if we're getting a good distribution
// of values in the hash table.
void Table::hashStats(ostream &out) const{
   out << "number of buckets: " << hashSize << endl;
   out << "number of entries: " << numEntry << endl;
   int numFilled = 0;
   int maxLen = 0;
   for(int i = 0; i < hashSize; ++i){
      if(listLen[i] > 0){
         ++numFilled;
      }
      maxLen = max(listLen[i], maxLen);
   }
   out << "number of non-empty buckets: " << numFilled << endl;
   out << "longest chain: " << maxLen << endl;
   assert(isValidTable());
}

// hash function for a string
// (we defined it for you)
// returns a value in the range [0, hashSize)
unsigned int Table::hashCode(const string &word) const{
   // Note: calls a std library hash function for string (it uses the good hash
   // algorithm for strings that we discussed in lecture).
   return hash<string>()(word) % hashSize;
}

// Returns true iff the Table data is in a valid state.
// (See representation invariant comment for details.)
bool Table::isValidTable() const{
   for(int i = 0; i < hashSize; ++i){
      if(listLen[i] < 0){
         return false;
      }
   }
   return numEntry >= 0 && hashSize > 0;
};