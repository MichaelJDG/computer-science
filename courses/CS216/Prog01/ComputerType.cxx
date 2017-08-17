//---------------------------------------------------------------
// Implementation file ComputerType.cxx
//---------------------------------------------------------------
#include <fstream> 
#include <iostream> 
#include <string>
#include <iomanip> 
#include "ComputerType.h"

using namespace std;

    ComputerType()
    //Default constructor 
    // Purpose: Initialize data by default value. 
    // Input: none 
    // Pre: none 
    // Output: none 
    // Post: All private variables initialized and object is constructed. 
    // Note: none
    {
        idNumber = 0000;
        processor = "none";
        RAMSize  = "none"; 
        DiskSize  = "none";
        computerType = "none";
        cost = -9.99;
        labLocation = "none";
    }
    
    ComputerType(int idNumberVal, string processorVal, string RAMSizeVal, string DiskSizVal, string computerTypeVal, float costVal, string labLocationVal );
    // Purpose: To initialize data.
    // Input: idNumberVal, processorVal, RAMSizeVal, DiskSizeVal, computerTypeVal, costVal, labLocationVal 
    // Pre: none 
    // Output: none 
    // Post: Object is created and computer data is set to incoming parameters.
    // Note: none
    {
        idNumber = idNumberVal;
        processor = processorVal;
        RAMSize  = RAMSizeVal; 
        DiskSize  = DiskSizVal;
        computerType = computerTypeVal;
        cost = costVal;
        labLocation = labLocationVal; 
    }
    
    void SetComputer(int idNumberVal, string processorVal, string RAMSizeVal, string DiskSizVal, string computerTypeVal, float costVal, string labLocationVal );
    // Purpose: To set computer to new values. 
    // Input: idNumberVal, processorVal, RAMSizeVal, DiskSizeVal, computerTypeVal, costVal, labLocationVal
    // Pre: Object is constructed.  
    // Output: none 
    // Post: Computer data is set to incoming parameters.
    // Note: none
    {
        idNumber = idNumberVal;
        processor = processorVal;
        RAMSize  = RAMSizeVal; 
        DiskSize  = DiskSizVal;
        computerType = computerTypeVal;
        cost = costVal;
        labLocation = labLocationVal; 
    }
    
    string ProcessorIs() const
    // Purpose: To return processor. 
    // Input: none
    // Pre: Object is constructed, and processor is assigned a value. 
    // Output: string 
    // Post: Processor is returned.
    // Note: none
    {
        return processor;
    }
    
    string LocationIs() const
    // Purpose: To return labLocation. 
    // Input: none
    // Pre: Object is constructed, and labLocation is assigned a value. 
    // Output: string 
    // Post: labLocation is returned.
    // Note: none
    {
        return labLocation;
    }
    
    void ReadRD(ifstream& inFile)
    // Purpose: To read all the information from a file into these variables: idNumber, processor, RAMSize, DiskSize, computerType, cost, and labLocation. 
    // Input: inFile
    // Pre: inFile must be open and all variables must be declared.
    // Output: none
    // Post: The inFile has been read and all data has been read into: idNumber, processor, RAMSize, DiskSize, computerType, cost, and labLocation.
    // Note: none
    {
        inFile >> idNumber >> processor >> RAMSize >> DiskSize >> computerType >> cost >> labLocation;
    }
    
    void PrintRD(ofstream& outFile)
    // Purpose: To output all variables of the Computer type class in a specified format.
    // Input: outFile
    // Pre: outFile must be opened and all variables have to be assigned a value. 
    // Output: none
    // Post: All variables of the computer type class have been output to the outFile.
    // Note: none
    {
        if (computerType =="l") {
          computerType = Laptop;
        }
        else{
            computerType = Desktop;
        }
        
        outFile<< "*~< Computer Lab Report >~*" << endl;
        outFile<< "IdNumber" << setw(7) << "Processor" << setw(7) << "RAM Size" << setw(7) << "Disk Size" << setw(7) << "Computer Type" << setw(7) << "Cost" << setw(7) << "Location" << endl;
        outFile<< "--------" << setw(7) << "---------" << setw(7) << "--------" << setw(7) << "---------" << setw(7) << "-------------" << setw(7) << "----" << setw(7) << "--------" << endl;
        outFile<< idNumber << setw(7) << processor << setw(7) << RAMSize << setw(7) << DiskSize << setw(7) << computerType << setw(7) << cost << setw(7) << labLocation << endl;
        outFile<< "*< end  >*" << endl;

    }