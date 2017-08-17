//--------------------------------------------------------------- 
// Specification file ComputerType.h 
//---------------------------------------------------------------
#include <fstream> 
#include <iostream> 
#include <string> 
#include <iomanip>

using namespace std; 

enum RelationType {LESS, EQUAL, GREATER};

class ItemType {
    public:
    
    ItemType();
    //Default constructor
    // Purpose: Initialize data by default value.
    // Input: none
    // Pre: none
    // Output: none
    // Post: All private variables initialized and object is constructed.
    // Note: none
    
    ItemType(int idNumberVal, string processorVal, int RAMSizeVal, float
    DiskSizVal, string datatypeVal, string computerTypeVal, float costVal, string labLocationVal );
    // Purpose: To initialize data.
    // Input: idNumberVal, processorVal, RAMSizeVal, DiskSizeVal, computerTypeVal,
    // costVal, labLocationVal, datatypeVal
    // Pre: none
    // Output: none
    // Post: Object is created and computer data is set to incoming parameters.
    // Note: none
    
    int getinvalid() const;
    // Purpose: To return invalid.
    // Input: none
    // Pre: invalid must have a value
    // Output: int 
    // Post: invalid is returned.
    // Note: none

    void SetComputer(int idNumberVal, string processorVal, int RAMSizeVal, float
    DiskSizVal, string datatypeVal, string computerTypeVal, float costVal, string labLocationVal );
    // Purpose: To set computer to new values.
    // Input: idNumberVal, processorVal, RAMSizeVal, DiskSizeVal, computerTypeVal,
    // costVal, labLocationVal, datatypeVal
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
    // Purpose: To read all the information from a file into these variables:
    // idNumber, processor, RAMSize, DiskSize, computerType, cost, and labLocation.
    // Input: inFile
    // Pre: inFile must be open and all variables must be declared.
    // Output: none
    // Post: The inFile has been read and all data has been read into: idNumber,
    // processor, RAMSize, DiskSize, computerType, cost, and labLocation.
    // Note: none
    
    void PrintRD(ofstream& outFile);
    // Purpose: To output all variables of the Computer type class in a specified
    // format.
    // Input: outFile
    // Pre: outFile must be opened and all variables have to be assigned a value.
    // Output: none
    // Post: All variables of the computer type class have been output to the
    // outFile.
    // Note: none
    
    void PrintinvalidRD(ofstream& outFile);
    // Purpose: To output all variables of the Computer type class in a specified
    // format when data is invalid.
    // Input: outFile
    // Pre: outFile must be opened and all variables have to be assigned a value
    // and data must be invalid.
    // Output: none
    // Post: All variables of the computer type class have been output to the
    // outFile.
    // Note: none
    
    float avgCostOfDesktop() const;
    // Purpose: To return avgCostDesktop.
    // Input: none.
    // Pre: Object is constructed, and avgCostDesktop is assigned a value.
    // Output: float.
    // Post: avgCostDesktop is returned.
    // Note: none
    
    float avgCostOfLaptop() const;
    // Purpose: To return avgCostLaptop.
    // Input: none.
    // Pre: Object is constructed, and avgCostLaptop is assigned a value.
    // Output: float.
    // Post: avgCostLaptop is returned.
    // Note: none
    
    float gethighPrice() const;
    // Purpose: To return highPrice.
    // Input: none.
    // Pre: Object is constructed, and highPrice is assigned a value.
    // Output: float.
    // Post: highPrice is returned.
    // Note: none
    
    float getlowPrice();
    // Purpose: To return lowPrice.
    // Input: none.
    // Pre: Object is constructed, and lowPrice is assigned a value.
    // Output: float.
    // Post: lowPrice is returned.
    // Note: none
    
    void FindAvgCostDesktop();
    // Purpose: To find avg cost of a dekstop.
    // Input: none.
    // Pre: desktopSum and desktopCount must have a value. desktopCount > 0.
    // Output: none.
    // Post: avgCostDesktop has an assigned value.
    // Note: none
    
    void FindAvgCostLaptop();
    // Purpose: To find avg cost of a laptop.
    // Input: none.
    // Pre: laptopSum and laptopCount must have a value. laptopCount > 0.
    // Output: none.
    // Post: avgCostLaptop has an assigned value.
    // Note: none
    
    void HighPriceComputer();
    // Purpose: To find the highest pricing computer.
    // Input: none.
    // Pre: cost must have an assigned value.
    // Output: none.
    // Post: highPrice is set with the highest value.
    // Note: none.
    
    void LowPriceComputer();
    // Purpose: To find the lowest pricing computer.
    // Input: none.
    // Pre: cost must have an assigned value.
    // Output: none.
    // Post: lowPrice is set with the lowest value.
    // Note: none.
    
    bool validData();
    // Purpose: To make sure all data is valid.
    // Input: none.
    // Pre: idNumber, processor, RAMSize, DiskSize, computerType, cost, labLocation have
    // an assigned value.
    // Output: bool.
    // Post: The bool flag is set to either true or false.
    // Note: none.
    
    string computerTypeIs() const;
    // Purpose: To return computerType.
    // Input: none.
    // Pre: Object is constructed, and computerType is assigned a value.
    // Output: string.
    // Post: computerType is returned.
    // Note: none
    
    int RamsizeIs() const;
    // Purpose: To return RAMSize.
    // Input: none.
    // Pre: Object is constructed, and RAMSize is assigned a value.
    // Output: int.
    // Post: RAMSize is returned.
    // Note: none
    
    float DiskSizeIs() const;
    // Purpose: To return DiskSize.
    // Input: none.
    // Pre: Object is constructed, and DiskSize is assigned a value.
    // Output: float.
    // Post: DiskSize is returned.
    // Note: none
    
    int IdIs() const;
    // Purpose: To return IdNumber.
    // Input: none.
    // Pre: Object is constructed, and IdNumber is assigned a value.
    // Output: int.
    // Post: IdNumber is returned.
    // Note: none
    
    RelationType ComparedTo(ItemType& info) const;
    // Purpose: To compare to items of the same type.
    // Input: info.
    // Pre: both Objects are constructed, and all values are assigned a value.
    // Output: RelationType.
    // Post: Items are compared and a bool is returned.
    // Note: nobe
    
    void ReadID (ifstream& inFile);
    // Purpose: To read id into a item.
    // Input: inFile
    // Pre:  Object is constructed, and infile is open.
    // Output: none.
    // Post: Id is read into item.
    // Note: none
    
    private:
    
   int idNumber;
   string processor;
   int RAMSize;
   float DiskSize;
   string computerType;
   float cost;
   string labLocation;
   float avgCostDesktop;
   float avgCostLaptop;
   float highPrice;
   float lowPrice;
   int desktopCount;
   float desktopSum;
   int laptopCount;
   float laptopSum;
   int invalid;
   string datatype;
   
   // Variables to change constants in validData() function.
   string diskdatatype1;
   string diskdatatype2;
   int minId;
   int maxId;
   int ramsize1;
   int ramsize2;
   int ramsize3;
   int ramsize4;
   int disksize1;
   int disksize2;
   int disksize3;
   string computertype1;
   string computertype2;
   float costmin;
   float costmax;
   string location1;
   string location2;
   string location3;
};
