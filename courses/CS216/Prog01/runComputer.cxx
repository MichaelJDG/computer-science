//******************************************************************************
// Author                : Michael Gutierrez
// Course Title          : Computer Programming II
// Course Number         : CS216 
// Class Meets           : M W / 8:30 - 10:20
// Prof Name             : Moe Bidgoli 
// Assignment Number     : #1 
// Due Date              : 09-16-15
// Possible Points       : 20
// Purpose               : 
//This Program read computer data in from a file and outputes it in a specified 
//format. 

#include <fstream> 
#include <iostream> 
#include <string>
#include <iomanip> 
#include "ComputerType.h"

using namespace std;

int main()
{
    ifstream inFile;
    ofstream outFile;
    
    inFile.open("in.data");
    outFile.open("out.data");
    
    if(inFile.fail() || outFile.fail() )
    {
        cout << "Input file or output file opening failed" << endl;
        exit(1);
    }
    
    ComputerType computer ;
    
    computer.ReadRD(inFile);
    computer.PrintRD(outFile);
    
}