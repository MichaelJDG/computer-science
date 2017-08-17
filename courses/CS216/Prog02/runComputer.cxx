//**************************************************************************** 
// Author : Michael Gutierrez
// Course Title : Computer Programming II 
// Course Number : CS216
// Class Meets : M W / 8:30 - 10:20
// Prof Name : Moe Bidgoli
// Assignment Number : #2
// Due Date : 09-23-15
// Possible Points : 20
// Purpose :
//This Program read computer data in from a file and outputes it in a
//specified format.

#include <fstream> 
#include <iostream> 
#include <string> 
#include <iomanip> 
#include "ComputerType.h"

using namespace std;

 int main()
 {  
    bool valid; 
    ifstream inFile;
    ofstream outFile;
    
    inFile.open("in.data");
    outFile.open("out.data");
    
    if(inFile.fail() || outFile.fail() )
    {
        cout << "Input file or output file opening failed" << endl;
        return 1;
    }
    
    outFile<< "*~< Computer Lab Report >~*" << endl;
    outFile<< "IdNumber" << setw(20) << "Processor" << setw(16) << "RAM Size" <<
    setw(10) << "Disk Size" << setw(15) << "Computer Type" << setw(12)
    << "Cost" <<
    setw(16) << "Location" << endl;
    outFile<< "--------" << setw(20) << "---------" << setw(16)
    << "--------" <<
    setw(10) << "---------" << setw(15) << "-------------" << setw(12) 
    << "----" <<
    setw(16) << "--------" << endl;
    
    ComputerType computer ;
    
    while(!inFile.eof())
    {
      computer.ReadRD(inFile);     
        
        if (inFile.eof())
        {
          break;
        }

        valid = computer.validData();
        if(valid == true)
        {
          computer.FindAvgCostDesktop();
          computer.FindAvgCostLaptop();
          computer.HighPriceComputer();
          computer.LowPriceComputer();
          computer.PrintRD(outFile);
        }
        else
        {
         computer.PrintinvalidRD(outFile);
        }
    }
    
    outFile<< endl;
    outFile<< "Average cost of Desktop: $" << computer.avgCostOfDesktop() 
    << endl;
    outFile<< "Average cost of Laptop: $" << computer.avgCostOfLaptop()
    << endl;
    outFile<< "High Price: $" << computer.gethighPrice() << endl;
    outFile<< "Low Price: $" << computer.getlowPrice() << endl;
    outFile << " *** " << computer.getinvalid() << " invalid record(s)"<< endl;
    outFile << endl;
    outFile<< "*< end >*" << endl;
    
   return 0;
}