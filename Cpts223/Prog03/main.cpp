#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string> 
#include "dictionary.h"
#include "Word.h"


using namespace std; 

int main(int argc, char* argv[]) {
    
 ifstream inFile;
  
 inFile.open(argv[1]);

    
  if(inFile.fail() )
     {
       cout << " Please includ a dictionary file. EX: ./a.out dictionary.json" << endl;
       return 1;
     }

    
dictionary myDictionary;

while(!inFile.eof())
    {
        int i =0;
        Word temp;
        string newWord, newDef;
        inFile >> newWord >> newDef;     
        
        if (inFile.eof())
        {
          break;
        }
        
        temp.updateWord(newWord);
        temp.updatedef(newDef);
        
        myDictionary.insert(temp);
        
       i++;    
    }
 string temp;   
 cout << "Words in dictionary: " << myDictionary.reN() << endl; 
 cout << "Table size: " << myDictionary.reTableSize() << endl; 
 cout << "Load Factor: " << (myDictionary.reN()/myDictionary.reTableSize()) << endl;
 cout << "What word are you looking for?" << endl;
 cin >> temp;
 
 transform(temp.begin(), temp.end(), temp.begin(), ::toupper);

 bool found =myDictionary.contains(temp); 
 if (!found) {
     cout <<temp << " is not in dictionary" << endl;
 }

    
    
return 0;    
}