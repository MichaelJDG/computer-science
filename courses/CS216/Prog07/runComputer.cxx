//**************************************************************************** 
// Author : Michael Gutierrez
// Course Title : Computer Programming II 
// Course Number : CS216
// Class Meets : M W / 8:30 - 10:20
// Prof Name : Moe Bidgoli
// Assignment Number : #7
// Due Date : 10-28-15
// Possible Points : 20
// Purpose :
//This Program read computer data in from a file and outputes it in a
//specified format.
//**************************************************************************** 

#include <fstream> 
#include <iostream> 
#include <string> 
#include <iomanip> 
#include "ComputerType.h"
#include "ExtComputerType.h"

using namespace std;

 int main()
 {  
    string computertype1 = "d";
    string computertype2 = "l";
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
    setw(16) << "Location" << setw(10) << "Status" << endl;
    outFile<< "--------" << setw(20) << "---------" << setw(16)
    << "--------" <<
    setw(10) << "---------" << setw(15) << "-------------" << setw(12) 
    << "----" <<
    setw(16) << "--------" << setw(10) << "------" <<endl;
    
    ExtComputerType computer;
    
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
          computer.toGOorKeep();
          
          if (computer.computerTypeIs() == computertype2)
            {
              computer.HighPriceLaptopComputer();
              computer.LowPriceLaptopComputer();
            }
          else if (computer.computerTypeIs() == computertype1)  
            {
              computer.HighPriceDesktopComputer();
              computer.LowPriceDesktopComputer();
            }
          
          computer.PrintRD(outFile);
        }
        else
        {
         computer.PrintinvalidRD(outFile);
        }
    }
    
    outFile<< endl;
    
    if (computer.gethighPriceDesktop() == 0.00)
      {
        outFile<< "Average cost of Desktop: $" << "N/A" << endl;
        outFile<< "High Price Desktop : $" << "N/A" << endl;
        outFile<< "Low Price Desktop: $" << "N/A" << endl<< endl;
      }
    else
      {
        outFile<< "Average cost of Desktop: $" << computer.avgCostOfDesktop() << endl;
        outFile<< "High Price Desktop : $" << computer.gethighPriceDesktop() << endl;
        outFile<< "Low Price Desktop: $" << computer.getlowPriceDesktop()<< endl<< endl;
      }
      
    if (computer.gethighPriceLaptop() == 0.00)
      {
        outFile<< "Average cost of Laptop: $" << "N/A" << endl;
        outFile<< "High Price Laptop: $" << "N/A" << endl;
        outFile<< "Low Price laptop: $" << "N/A" << endl << endl;
      }
    else 
      {
        outFile<< "Average cost of Laptop: $" << computer.avgCostOfLaptop()<< endl;
        outFile<< "High Price Laptop: $" << computer.gethighPriceLaptop()<< endl;
        outFile<< "Low Price laptop: $" << computer.getlowPriceLaptop()<< endl << endl;
      }
      
    outFile<< "DESKTOP" << endl;
    outFile<< "_______" << endl; 
    
    if (computer.numOfDeskTopToGois() >= 1 || computer.numOfDeskTopToKeepis() >= 1)
      {
        outFile<< "Num Of ToKeep = " << computer.numOfDeskTopToKeepis()<< endl;
        outFile<< "Num of ToGo = " << computer.numOfDeskTopToGois()<< endl<< endl;
      }
    else 
      {
        outFile << "No Desktop none ToKeep or ToGo!"<< endl << endl;
      }
    
    outFile<< "LAPTOP" << endl;
    outFile<< "______" << endl; 
    
    if (computer.numOfLapTopToGois() >= 1 || computer.numOfLapTopToKeepis() >= 1)
      {
        outFile<< "Num Of ToKeep = " << computer.numOfLapTopToKeepis()<< endl;
        outFile<< "Num of ToGo = " << computer.numOfLapTopToGois()<< endl<< endl;
      }
    else 
      {
        outFile << "No Laptop none ToKeep or ToGo!"<< endl << endl;
      }
    
    outFile << " *** " << computer.getinvalid() << " invalid record(s)"<< endl;
    outFile << endl;
    outFile<< "*< end >*" << endl;
    
   return 0;
}
