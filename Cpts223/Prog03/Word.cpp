#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include "Word.h"

using namespace std; 



 int Word:: key ( string   key, int tableSize ) {
        unsigned int hashVal = 0 ;
        
        for (char ch : key)
        {
            hashVal = 37 * hashVal +ch; 
        }
        
        return hashVal % tableSize; 
    
    }
    
 string Word:: reWord ()
 {
     return word;
 }
 
   
 string Word:: reDef ()
 {
     return def;
 }
 
 void Word:: updatedef (string newDef){
     def = newDef;
 }
 
  void Word:: updateWord (string newWord){
     word = newWord;
 }
 