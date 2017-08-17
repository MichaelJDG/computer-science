#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include "Word.h"



#ifndef dictionary_H
#define dictionary_H



using namespace std; 

class dictionary {
    
public:
    int tableSize; 
    vector <vector<Word> > table; 
    int N = 0;
    

   dictionary (); 
   
   void insert ( Word myWord);
   
   bool contains (string myWord); 
   
   Word Delete (string myWord);
   
   void rehash ();
   
   
   int findNextPrime(int n);
   bool isPrime(int n);
   
   int reTableSize ();
   int reN (); 
}; 

#endif
