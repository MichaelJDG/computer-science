//--------------------------------------------------------------- 
// Implementation file ComputerType.cxx 
//---------------------------------------------------------------
#include <fstream> 
#include <iostream> 
#include <string> 
#include <iomanip> 
#include "ComputerType.h"

using namespace std;

    ComputerType::ComputerType()
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
        RAMSize = 0;
        DiskSize = 0;
        computerType = "none";
        cost = -9.99;
        labLocation = "none";
        avgCostDesktop = 0;
        avgCostLaptop = 0;
        highPriceLaptop = 0 ;
        lowPriceLaptop = 99999;
        highPriceDesktop = 0 ;
        lowPriceDesktop = 99999;
        desktopCount= 0;
        desktopSum = 0;
        laptopCount = 0;
        laptopSum = 0;
        invalid =0;
        datatype = "none";
        
        // Variables for changing constants in validData() function.
        diskdatatype1 = "GB";
        diskdatatype2 = "TB";
        minId = 1111;
        maxId = 9999;
        ramsize1 = 4;
        ramsize2 = 8;
        ramsize3 = 16;
        ramsize4 = 32;
        disksize1 = 500;
        disksize2 = 1;
        disksize3 = 2;
        computertype1 = "d";
        computertype2 = "l";
        costmin = 0.00;
        costmax = 1500.00;
        location1 = "SE145";
        location2 = "SE135";
        location3 = "SE136";
    }
    
    ComputerType::ComputerType(int idNumberVal, string processorVal, int 
                               RAMSizeVal, float DiskSizVal ,string datatypeVal,
                               string computerTypeVal, float costVal, string
                               labLocationVal )
    // Purpose: To initialize data.
    // Input: idNumberVal, processorVal, RAMSizeVal, DiskSizeVal, 
    // computerTypeVal, costVal, labLocationVal, datatypeVal
    // Pre: none
    // Output: none
    // Post: Object is created and computer data is set to incoming 
    // parameters.
    // Note: none
    {
        idNumber = idNumberVal;
        processor = processorVal;
        RAMSize = RAMSizeVal;
        DiskSize = DiskSizVal;
        datatype = datatypeVal;
        computerType = computerTypeVal;
        cost = costVal;
        labLocation = labLocationVal;
    }
    
    void ComputerType::SetComputer(int idNumberVal, string processorVal, 
                                   int RAMSizeVal, float DiskSizVal, string datatypeVal,
                                   string computerTypeVal, float costVal, string 
                                   labLocationVal )
    // Purpose: To set computer to new values.
    // Input: idNumberVal, processorVal, RAMSizeVal, DiskSizeVal, 
    // computerTypeVal, costVal, labLocationVal, datatypeVal
    // Pre: Object is constructed.
    // Output: none
    // Post: Computer data is set to incoming parameters.
    // Note: none
    {
        idNumber = idNumberVal;
        processor = processorVal;
        RAMSize = RAMSizeVal;
        DiskSize = DiskSizVal;
        datatype = datatypeVal;
        computerType = computerTypeVal;
        cost = costVal;
        labLocation = labLocationVal;
    }
 
    int ComputerType::getinvalid()  const 
    // Purpose: To return invalid.
    // Input: none
    // Pre: invalid must be assigned a value
    // Output: int
    // Post: invalid is returned.
    // Note: none.
    {
        return invalid;
    }

    string ComputerType::ProcessorIs() const
    // Purpose: To return processor.
    // Input: none
    // Pre: Object is constructed, and processor is assigned a value.
    // Output: string
    // Post: Processor is returned.
    // Note: none
    {
        return processor;
    }
    
    string ComputerType::LocationIs() const
    // Purpose: To return labLocation.
    // Input: none
    // Pre: Object is constructed, and labLocation is assigned a value.
    // Output: string
    // Post: labLocation is returned.
    // Note: none
    {
        return labLocation;
    }
    
    void ComputerType::ReadRD(ifstream& inFile)
    // Purpose: To read all the information from a file into these variables:
    // idNumber, processor, RAMSize, DiskSize, computerType, cost, and 
    // labLocation.
    // Input: inFile
    // Pre: inFile must be open and all variables must be declared.
    // Output: none
    // Post: The inFile has been read and all data has been read into: idNumber,
    // processor, RAMSize, DiskSize, computerType, cost, and labLocation.
    // Note: none
    {
        inFile >> idNumber >> processor >> RAMSize;
        inFile.ignore(4);
        inFile >> DiskSize >> datatype;
        inFile >> computerType >> cost >> labLocation;
        
        
    }
    
    void ComputerType::PrintRD(ofstream& outFile)
    // Purpose: To output all variables of the Computer type class in a 
    // specified format.
    // Input: outFile
    // Pre: outFile must be opened and all variables have to be assigned a
    // value.
    // Output: none
    // Post: All variables of the computer type class have been output to the
    // outFile.
    // Note: none
    {
      if (computerType =="l") {
          computerType = "Laptop";
        }
      if (computerType =="d") {
            computerType = "Desktop";
        }
        
      outFile << fixed << showpoint;
      outFile << setprecision(2);
      
      outFile<< idNumber << setw(25) << processor << setw(11) << RAMSize 
      << "GB" << setw(10)
      << DiskSize << datatype << setw(12) << computerType << setw(10)
      << "$"<< cost << setw(14)
      << labLocation;
    }
    
    float ComputerType::avgCostOfDesktop() const
    // Purpose: To return avgCostDesktop.
    // Input: none.
    // Pre: Object is constructed, and avgCostDesktop is assigned a value.
    // Output: float.
    // Post: avgCostDesktop is returned.
    // Note: none
    {  
        return avgCostDesktop;
    }
    
    float ComputerType::avgCostOfLaptop() const
    // Purpose: To return avgCostLaptop.
    // Input: none.
    // Pre: Object is constructed, and avgCostLaptop is assigned a value.
    // Output: float.
    // Post: avgCostLaptop is returned.
    // Note: none
    {  
         
        return avgCostLaptop;
    }
    
    float ComputerType::gethighPriceLaptop() const
    // Purpose: To return highPrice.
    // Input: none.
    // Pre: Object is constructed, and highPrice is assigned a value.
    // Output: float.
    // Post: highPrice is returned.
    // Note: none
    {   
        return highPriceLaptop;
    }
    
    float ComputerType::gethighPriceDesktop() const
    // Purpose: To return highPriceDesktop.
    // Input: none.
    // Pre: Object is constructed, and highPriceDesktop is assigned a value.
    // Output: float.
    // Post: highPriceDesktop is returned.
    // Note: none
    {   
        return highPriceDesktop;
    }
    
    float ComputerType::getlowPriceLaptop() 
    // Purpose: To return lowPrice.
    // Input: none.
    // Pre: Object is constructed, and lowPriceLaptop is assigned a value.
    // Output: float.
    // Post: lowPrice is returned.
    // Note: none
    {
        if (lowPriceLaptop == 99999)
         {
          lowPriceLaptop = 0;
         }
        return lowPriceLaptop;
    }
    
    float ComputerType::getlowPriceDesktop()
    // Purpose: To return lowPriceDesktop.
    // Input: none.
    // Pre: Object is constructed, and lowPriceDesktop is assigned a value.
    // Output: float.
    // Post: lowPriceDesktop is returned.
    // Note: none
    {
        if (lowPriceDesktop == 99999)
         {
          lowPriceDesktop = 0;
         }
        return lowPriceDesktop;
    }
    
    void ComputerType::FindAvgCostDesktop()
    // Purpose: To find avg cost of a dekstop.
    // Input: none.
    // Pre: desktopSum and desktopCount must have a value. desktopCount > 0.
    // Output: none.
    // Post: avgCostDesktop has an assigned value.
    // Note: none
    {
        if (computerType =="d") {
          desktopSum = desktopSum + cost;
          desktopCount++;
        }
        avgCostDesktop = (desktopSum/desktopCount);
    }
    
    void ComputerType::FindAvgCostLaptop()
    // Purpose: To find avg cost of a laptop.
    // Input: none.
    // Pre: laptopSum and laptopCount must have a value. laptopCount > 0.
    // Output: none.
    // Post: avgCostLaptop has an assigned value.
    // Note: none
    {
        if (computerType =="l") {
          laptopSum = laptopSum + cost;
          laptopCount++;
        }
        
        avgCostLaptop = (laptopSum/laptopCount);
    }
    
    void ComputerType::HighPriceLaptopComputer()
    // Purpose: To find the highest pricing laptop computer.
    // Input: none.
    // Pre: cost must have an assigned value.
    // Output: none.
    // Post: highPricelaptop is set with the highest value.
    // Note: none.
    {
        if (cost > highPriceLaptop)
        {
            highPriceLaptop = cost;
        }
     
    }
    
    void ComputerType::LowPriceLaptopComputer()
    // Purpose: To find the lowest pricing laptop computer.
    // Input: none.
    // Pre: cost must have an assigned value.
    // Output: none.
    // Post: lowPricelaptop is set with the lowest value laptop price.
    // Note: none.
    {
        if (cost < lowPriceLaptop)
        {
            lowPriceLaptop = cost;
        }
    }
    
    void ComputerType::HighPriceDesktopComputer()
    // Purpose: To find the highest pricing desktopcomputer.
    // Input: none.
    // Pre: cost must have an assigned value.
    // Output: float.
    // Post: highPricedesktop is set with the highest value.
    // Note: none.
    {
        if (cost > highPriceDesktop)
        {
            highPriceDesktop = cost;
        }
     
    }
    
    void ComputerType::LowPriceDesktopComputer()
    // Purpose: To find the lowest pricing desktop computer .
    // Input: none.
    // Pre: cost must have an assigned value.
    // Output: float.
    // Post: lowPricedesktop is set with the lowest value desktop value.
    // Note: none.
    {
        if (cost < lowPriceDesktop)
        {
            lowPriceDesktop = cost;
        }
    }
    
    bool ComputerType::validData()
    // Purpose: To make sure all data is valid.
    // Input: none.
    // Pre: idNumber, processor, RAMSize, DiskSize, computerType, cost, 
    // labLocation have an assigned value.
    // Output: bool.
    // Post: The bool flag is set to either true or false.
    // Note: none.
    {
      if (!(idNumber >= minId && idNumber <= maxId))
      {
          invalid++;
          return false;
      }
      
      if (!(RAMSize == ramsize1 || RAMSize == ramsize2 || RAMSize == ramsize3 || RAMSize == ramsize4))
      {
          invalid++;
          return false;
      }
      
      if (!((DiskSize == disksize1 && datatype == diskdatatype1) || (DiskSize == disksize2 && datatype == diskdatatype2)|| 
      (DiskSize == disksize3 && datatype == diskdatatype2)))
      {
          invalid++;
          return false;
      }
      
      if (!(computerType == computertype1 || computerType == computertype2))
      {
          invalid++;
          return false;
      }
      
      if (!(cost >= costmin && cost <= costmax))
      {
          invalid++;
          return false;
      }
      
      if (!(labLocation == location1 || labLocation == location2 || labLocation == location3))
      {
          invalid++;
          return false;
      }
      
      return true;
    }

 void ComputerType::PrintinvalidRD(ofstream& outFile)
    // Purpose: To output all variables of the Computer type class in a specified
    // format when data is invalid.
    // Input: outFile
    // Pre: outFile must be opened and all variables have to be assigned a value
    // and data must be invalid.
    // Output: none
    // Post: All variables of the computer type class have been output to the
    // outFile.
    // Note: none
    {
        if (computerType =="l") {
          computerType = "Laptop";
        }
      if (computerType =="d") {
            computerType = "Desktop";
        }
        
      outFile << fixed << showpoint;
      outFile << setprecision(2);
      
      outFile<< idNumber << setw(25) << processor << setw(11) << RAMSize << "GB" << setw(10)
      << DiskSize << datatype << setw(12) << computerType << setw(10) << "$" <<  cost << setw(14)
      << labLocation << "*** Invalid data" << endl;
    }
    
    string ComputerType::computerTypeIs() const
    // Purpose: To return computerType.
    // Input: none.
    // Pre: Object is constructed, and computerType is assigned a value.
    // Output: string.
    // Post: computerType is returned.
    // Note: none
    {
        return computerType;
    }
    
    int ComputerType::RamsizeIs() const
    // Purpose: To return RAMSize.
    // Input: none.
    // Pre: Object is constructed, and RAMSize is assigned a value.
    // Output: string.
    // Post: RAMSize is returned.
    // Note: none
    {
        return RAMSize;
    }
    
     float ComputerType::DiskSizeIs() const
    // Purpose: To return DiskSize.
    // Input: none.
    // Pre: Object is constructed, and DiskSize is assigned a value.
    // Output: string.
    // Post: DiskSize is returned.
    // Note: none
    {
        return DiskSize;
    }
    
    int ComputerType::IdIs() const
    // Purpose: To return idNumber.
    // Input: none.
    // Pre: Object is constructed, and idNumber is assigned a value.
    // Output: int.
    // Post: idNumber is returned.
    // Note: none
    {
        return idNumber;
    }
    
    RelationType ComputerType::ComparedTo(ComputerType& info) const
    // Purpose: To compare to items of the same type.
    // Input: info.
    // Pre: both Objects are constructed, and all values are assigned a value.
    // Output: bool.
    // Post: Items are compared and a bool is returned.
    // Note: none
    {
      if(idNumber < info.IdIs())
        return LESS;
      else if (idNumber > info.IdIs())
        return GREATER;
      else 
        return EQUAL;    
    }
    
    void ComputerType::ReadID (ifstream& inFile)
    // Purpose: To read id into a item.
    // Input: inFile
    // Pre:  Object is constructed, and infile is open.
    // Output: none.
    // Post: Id is read into item.
    // Note: none
    {
        inFile >> idNumber;
    }
    
    