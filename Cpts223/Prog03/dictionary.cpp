#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include "dictionary.h"

using namespace std; 


 dictionary :: dictionary ()
{
    tableSize = 101;
    table.resize(tableSize);
    for (int i =0 ; i<101 ; i++){
       vector<Word> myChain; 
        table.push_back (myChain) ;
    }
    
}

void dictionary :: insert(Word myWord) {
    
bool found = false; 
  int index = Word:: key(myWord.reWord(),tableSize);

       for(vector<vector<Word> >::iterator it = table.begin(); it != table.end(); ++it)
            if(this.begin(),this.end(), index) != this.end()) 
            {
                
                 found = true;
                  myChain.updatedef(  myWord.reDef());
                 break;
            }
             if (found == false) {
            myChain[i].push_back(myWord);
            N++;
        }
                
       }
        
       
     if (table.sizeof() > (N/tableSize) )   {
         rehash();
     }
}

bool dictionary :: contains (string myWord) {
    bool found = false; 
    int index = Word:: key(myWord,tableSize);
  
        for(vector<vector<Word> >::iterator it = table.begin(); it != table.end(); ++it)
            if(myChain.begin(),myChain.end(), index) != myChain.end()) 
            {
                 cout << myWord << "means :" << this.def << endl;
                 break;
            }
                
        }
    return found;    
        
}

Word dictionary :: Delete (string myWord) {
    bool found = false; 
    Word temp;
    int index = Word:: key(myWord,tableSize);
  
        for(vector<vector<Word> >::iterator it = table.begin(); it != table.end(); ++it)
            if(myChain.begin(),myChain.end(), index) != myChain.end()) 
            {
                 found = true;
                 temp = this;
                 myChain.erase(table[this]);
                 break;
            }
                
        }
    return temp;
    
} 

void dictionary ::  rehash () {
    tableSize = tableSize *2 ;
    tableSize = findNextPrime(tableSize);
    vector<chain> oldtable = table; 
    table.resize(tableSize);
    table = oldtable; 
    
}
    



int dictionary ::  findNextPrime(int tableSize)
{
    int nextPrime = tableSize;
    bool found = false;

    while (!found)
    {
        nextPrime++;
        if (isPrime(nextPrime))
            found = true;
    }

    return nextPrime;
}



bool dictionary ::  isPrime(int n)
{
    for (int i = 2; i <= n/2; i++)
    {
        if (n % i == 0)    
            return false;
    }

    return true;
}

int dictionary:: reTableSize () {
    return  tableSize; 
}

int dictionary:: reN () {
    return N;
}
