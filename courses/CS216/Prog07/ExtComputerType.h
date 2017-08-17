#ifndef EXTCOMPUTERTYPE_H
#define EXTCOMPUTERTYPE_H
#include <fstream> 
#include <iostream> 
#include <string> 
#include <iomanip>

#include "ComputerType.h"

using namespace std; 

class ExtComputerType : public ComputerType 
   {
    public:
    ExtComputerType();
    //Default constructor
    // Purpose: Initialize data by default value.
    // Input: none
    // Pre: none
    // Output: none
    // Post: All private variables initialized and object is constructed.
    // Note: none
    
    void toGOorKeep();
    // Purpose: to determine to go or keep computer.
    // Input: computer
    // Pre: object is created and variables have values.
    // Output: none
    // Post: count is incremented for  either to go or to keep.
    // Note: none
    
    int returnCount (int count);
    // Purpose: to return a counter.
    // Input: count
    // Pre: object is created and variables have values.
    // Output: int
    // Post: count is returned. 
    // Note: none
    
    virtual void PrintRD(ofstream& outFile);
    // Purpose: To output all variables of the Computer type class in a specified
    // format.
    // Input: outFile
    // Pre: outFile must be opened and all variables have to be assigned a value.
    // Output: none
    // Post: All variables of the computer type class have been output to the
    // outFile.
    // Note: none
    
    int numOfLapTopToGois();
    // Purpose: to return numOfLapTopToGo.
    // Input: count
    // Pre: object is created and variable have values.
    // Output: int
    // Post: numOfLapTopToGo is returned. 
    // Note: 
    
    int numOfDeskTopToGois();
    // Purpose: to return numofdesktoptogo.
    // Input: count
    // Pre: object is created and variable have values.
    // Output: int
    // Post: numofdesktoptogo is returned. 
    // Note: none
    
    int numOfDeskTopToKeepis();
    // Purpose: to return numOfDeskTopToKeep.
    // Input: count
    // Pre: object is created and variable have values.
    // Output: int
    // Post: numOfDeskTopToKeep is returned. 
    // Note: none
    
    int numOfLapTopToKeepis();
    // Purpose: to return numOfLapTopToKeep.
    // Input: count
    // Pre: object is created and variable have values.
    // Output: int
    // Post: numOfLapTopToKeep is returned. 
    // Note: none
    
    private: 
     int numOfDeskTopToGo;
     int numOfDeskTopToKeep;
     int numOfLapTopToGo;
     int numOfLapTopToKeep;
     
     int disksize2 ;
     int disksize3 ;
     int ramsize ;
     string computertype2 ;
     string computertype1 ;
    };
    
#endif    