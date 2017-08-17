//---------------------------------------------------------------
// Specification file ComputerType.h
//---------------------------------------------------------------
#include <fstream> 
#include <iostream> 
#include <string>
#include <iomanip> 

using namespace std;

class ComputerType
{
    public:
    
    ComputerType()
    //Default constructor 
    // Purpose: Initialize data by default value. 
    // Input: none 
    // Pre: none 
    // Output: none 
    // Post: All private variables initialized and object is constructed. 
    // Note: none
    
    ComputerType(int idNumberVal, string processorVal, string RAMSizeVal, string DiskSizVal, string computerTypeVal, float costVal, string labLocationVal );
    // Purpose: To initialize data.
    // Input: idNumberVal, processorVal, RAMSizeVal, DiskSizeVal, computerTypeVal, costVal, labLocationVal 
    // Pre: none 
    // Output: none 
    // Post: Object is created and computer data is set to incoming parameters.
    // Note: none
    
    void SetComputer(int idNumberVal, string processorVal, string RAMSizeVal, string DiskSizVal, string computerTypeVal, float costVal, string labLocationVal );
    // Purpose: To set computer to new values. 
    // Input: idNumberVal, processorVal, RAMSizeVal, DiskSizeVal, computerTypeVal, costVal, labLocationVal
    // Pre: Object is constructed.  
    // Output: none 
    // Post: Computer data is set to incoming parameters.
    // Note: none
    
    string ProcessorIs() const;
    // Purpose: To return processor. 
    // Input: none
    // Pre: Object is constructed, and processor is assigned a value. 
    // Output: string 
    // Post: Processor is returned.
    // Note: none
    
    string LocationIs() const;
    // Purpose: To return labLocation. 
    // Input: none
    // Pre: Object is constructed, and labLocation is assigned a value. 
    // Output: string 
    // Post: labLocation is returned.
    // Note: none
    
    void ReadRD(ifstream& inFile);
    // Purpose: To read all the information from a file into these variables: idNumber, processor, RAMSize, DiskSize, computerType, cost, and labLocation. 
    // Input: inFile
    // Pre: inFile must be open and all variables must be declared.
    // Output: none
    // Post: The inFile has been read and all data has been read into: idNumber, processor, RAMSize, DiskSize, computerType, cost, and labLocation.
    // Note: none
    
    void PrintRD(ofstream& outFile);
    // Purpose: To output all variables of the Computer type class in a specified format.
    // Input: outFile
    // Pre: outFile must be opened and all variables have to be assigned a value. 
    // Output: none
    // Post: All variables of the computer type class have been output to the outFile.
    // Note: none
    
    private: 
    
   int idNumber;
   string processor;
   string RAMSize;
   string DiskSize;
   string computerType;
   float cost;
   string labLocation;
}