#include <fstream> 
#include <iostream> 
#include <string> 
#include <iomanip> 
#include "ExtComputerType.h"

using namespace std;


    ExtComputerType::ExtComputerType()
    //Default constructor
    // Purpose: Initialize data by default value.
    // Input: none
    // Pre: none
    // Output: none
    // Post: All private variables initialized and object is constructed.
    // Note: none
    {
        numOfDeskTopToGo = 0;
        numOfDeskTopToKeep = 0;
        numOfLapTopToGo = 0;
        numOfLapTopToKeep = 0;
        
        disksize2 = 1;
        disksize3 = 2;
        ramsize = 16;
        computertype2 = "l";
        computertype1 = "d";
    }
    
    void ExtComputerType::toGOorKeep()
    // Purpose: to determine to go or keep computer.
    // Input: computer
    // Pre: object is created and variables have values.
    // Output: none
    // Post: count is incremented for  either to go or to keep.
    // Note: none
    {
        if (computerType == computertype2)
          {
             if (RAMSize == ramsize3 || RAMSize == ramsize4)
               {
                   if (DiskSize == disksize3 || DiskSize == disksize2)
                     {
                       numOfLapTopToKeep++;
                     } 
                   else numOfLapTopToGo++;     
               }
             else numOfLapTopToGo++;  
          }
        else if (computerType == computertype1)
          {
            if (RAMSize == ramsize3 || RAMSize == ramsize4)
               {
                   if (DiskSize == disksize3 || DiskSize == disksize2)
                     {
                      numOfDeskTopToKeep++;
                     } 
                   else numOfDeskTopToGo++;    
               }
             else numOfDeskTopToGo++;    
          }
    }
    
    int ExtComputerType::numOfDeskTopToGois()
    // Purpose: to return numofdesktoptogo.
    // Input: count
    // Pre: object is created and variable have values.
    // Output: int
    // Post: numofdesktoptogo is returned. 
    // Note: none
    {
        return numOfDeskTopToGo; 
    }
    
    int ExtComputerType::numOfLapTopToGois()
    // Purpose: to return numOfLapTopToGo.
    // Input: count
    // Pre: object is created and variable have values.
    // Output: int
    // Post: numOfLapTopToGo is returned. 
    // Note: none
    {
        return numOfLapTopToGo; 
    }
    
    int ExtComputerType::numOfLapTopToKeepis()
    // Purpose: to return numOfLapTopToKeep.
    // Input: count
    // Pre: object is created and variable have values.
    // Output: int
    // Post: numOfLapTopToKeep is returned. 
    // Note: none
    {
        return numOfLapTopToKeep; 
    }
    
    int ExtComputerType::numOfDeskTopToKeepis()
    // Purpose: to return numOfDeskTopToKeep.
    // Input: count
    // Pre: object is created and variable have values.
    // Output: int
    // Post: numOfDeskTopToKeep is returned. 
    // Note: none
    {
        return numOfDeskTopToKeep; 
    }
    
    void ExtComputerType::PrintRD(ofstream& outFile)
    // Purpose: To output all variables of the Computer type class in a specified
    // format.
    // Input: outFile
    // Pre: outFile must be opened and all variables have to be assigned a value.
    // Output: none
    // Post: All variables of the computer type class have been output to the
    // outFile.
    // Note: none
    {
        ComputerType::PrintRD(outFile);
        
             if (RAMSize >= ramsize )
               {
                  if (DiskSize == disksize3 || DiskSize == disksize2) 
                    {
                        outFile << setw(10) << "ToKeep!" << endl;
                    }
                  else outFile << setw(10) << "ToGo!" << endl;
               }  
             else outFile << setw(10) << "ToGo!" << endl;
        
        
    }