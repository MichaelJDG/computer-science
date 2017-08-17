#include <iostream>
#include <fstream>
#include <vector>
#include <string> 

using namespace std; 

#ifndef Word_H
#define Word_H

class Word {
    
    private:
   string word ; 
   string def;
    
    public:
     int key ( string  key, int tableSize );
    string reWord ();
    string reDef ();
    void updateWord (string newWord); 
    void updatedef (string newDef);
    
};

#endif

