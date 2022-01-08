// Name: Chia-Hao Chang
// GitHub: ChiaHaoChangTw
// Hash Table Implementation

#ifndef TABLE_H
#define TABLE_H

// Table class
// stores a collection of (string, int) entries
// such that each key (the string) is unique
// with efficient (O(1)) lookup, insert, and removal of entries

#include <iostream>
#include <string>

// the following line of code is a forward declaration of Node struct.
// allows us to use Node* (or ListType because of typedef) in private 
// section of Table below. (Complete Node definition is in listFuncs.h)
struct Node;

typedef Node* ListType;

class Table{
 public:
   
   // a prime number
   static const int HASH_SIZE = 9973;  

   // create an empty table, i.e., one where numEntries() is 0
   // (Underlying hash table is HASH_SIZE.)
   Table();

   // create an empty table, i.e., one where numEntries() is 0
   // such that the underlying hash table is hSize
   Table(unsigned int hSize);

   // insert a new pair into the table
   // return false iff this key was already present 
   // (and no change made to table)
   bool insert(const std::string &key, int value);

   // returns the address of the value that goes with this key
   // or NULL if key is not present.
   // Thus, this method can be used to either lookup the value or
   // update the value that goes with this key.
   int* lookup(const std::string &key);

   // remove a pair given its key
   // return false iff key wasn't present
   // (and no change made to table)
   bool remove(const std::string &key);

   // print out all the entries in the table, one per line.
   // Sample output:
   //   zhou 283
   //   sam 84
   //   babs 99
   void printAll() const;

   // number of entries in the table
   int numEntries() const;      

   // hashStats: for diagnostic purposes only
   // prints out info to let us know if we're getting a good distribution
   // of values in the hash table.
   // Sample output from this function
   //   number of buckets: 997
   //   number of entries: 10
   //   number of non-empty buckets: 9
   //   longest chain: 2
   void hashStats(std::ostream &out) const;

 private:

   // making these private disallows copying of tables  
   Table &operator =(const Table &);
   Table(const Table &);

   unsigned int hashCode(const std::string &word) const;

   // add private data and private method headers here
   /**
     * Representation invariants:
     * 
     * a) listLen[i] >= 0, 0 <= i < hashSize
     * b) numEntry >= 0
     * c) hashSize > 0
     * 
     */
   ListType* hashTable;
   int* listLen;
   int numEntry;
   
   // size of the hash table (NOTE: YOU MUST USE THIS INSTANCE VARIABLE BECAUSE THE
   // HASHCODE METHOD ABOVE USES IT)
   unsigned int hashSize;
   
   // Returns true iff the Table data is in a valid state.
   // (See representation invariant comment for details.)
   bool isValidTable() const;
};

#endif