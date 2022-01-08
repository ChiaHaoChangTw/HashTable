// Name: Chia-Hao Chang
// GitHub: ChiaHaoChangTw
// Hash Table Implementation

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>
#include <cassert>

using namespace std;

// Execute insertion operation on Table object grades.
// If the name was already present, print a message, and do not do the insert.
// PRE: grades != NULL
void executeInsert(Table*& grades){
   assert(grades != NULL);
   string arg1;
   int arg2;
   cin >> arg1 >> arg2;
   if(!grades->insert(arg1, arg2)){
      cout << arg1 << " has already been in the grade table." << endl;
   }
}

// Execute change operation on Table object grades.
// Print a message if the name is not present.
// PRE: grades != NULL
void executeChange(Table*& grades){
   assert(grades != NULL);
   string arg1;
   int arg2;
   cin >> arg1 >> arg2;
   int* currVal = grades->lookup(arg1);
   if(!currVal){
      cout << arg1 << " does not exist in the grade table." << endl;
   }
   else{
      *currVal = arg2;
   }
}

// Execute lookup operation on Table object grades.
// PRE: grades != NULL
void executeLookup(Table*& grades){
   assert(grades != NULL);
   string arg;
   cin >> arg;
   int* foundVal = grades->lookup(arg);
   if(foundVal){
      cout << arg << "'s score is " << *foundVal << "." << endl;
   }
   else{
      cout << arg << " does not exist in the grade table." << endl;
   }
}

// Execute remove operation on Table object grades.
// If the student was not in the grade table, print a message.
// PRE: grades != NULL
void executeRemove(Table*& grades){
   assert(grades != NULL);
   string arg;
   cin >> arg;
   if(!grades->remove(arg)){
      cout << arg << " does not exist in the grade table." << endl;
   }
}

// Function to execute operations according to commands input from user.
// End the function until user types in quit command.
// PRE: grades != NULL
// This function does not violate 30-line rule considering single-brace lines.
void commandHandler(Table*& grades){
   assert(grades != NULL);
   bool done = false;
   string command;
   while(!done){
      cout << "cmd> ";
      cin >> command;
      if(command == "insert"){
         executeInsert(grades);
      }
      else if(command == "change"){
         executeChange(grades);
      }
      else if(command == "lookup"){
         executeLookup(grades);
      }
      else if(command == "remove"){
         executeRemove(grades);
      }
      else if(command == "print"){
         grades->printAll();
      }
      else if(command == "size"){
         cout << grades->numEntries() << endl;
      }
      else if(command == "stats"){
         grades->hashStats(cout);
      }
      else if(command == "help"){
         cout << "Available commands are: insert [name] [score], change [name] [newscore], lookup [name], remove [name], print, size, stats, help, quit." << endl;
      }
      else if(command == "quit"){
         done = true;
      }
      else{
         cout << "ERROR: invalid command. Type \"help\" to get correct command formats." << endl;
      }
   }
}

// Main function to handle commands from user.
int main(int argc, char* argv[]){
   // gets the hash table size from the command line
   int hashSize = Table::HASH_SIZE; 
   // Table is dynamically allocated below, so we can call different constructors depending on input from the user.
   Table* grades; 
   if(argc > 1){
      // atoi converts c-string to int
      hashSize = atoi(argv[1]); 
      if(hashSize < 1){
         cout << "Command line argument (hashSize) must be a positive number" << endl;
         return 1;
      }
      grades = new Table(hashSize);
   }
   // no command line args given -- use default table size
   else{ 
      grades = new Table();
   }
   grades->hashStats(cout);
   commandHandler(grades);
   delete[] grades;
   return 0;
}