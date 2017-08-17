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
        highPrice = 0 ;
        lowPrice = 99999;
        desktopCount= 0;
        desktopSum = 0;
        laptopCount = 0;
        laptopSum = 0;
        invalid =0;
        datatype = "none";
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
      << labLocation << endl;
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
    
    float ComputerType::gethighPrice() const
    // Purpose: To return highPrice.
    // Input: none.
    // Pre: Object is constructed, and highPrice is assigned a value.
    // Output: float.
    // Post: highPrice is returned.
    // Note: none
    {
        return highPrice;
    }
    
    float ComputerType::getlowPrice()
    // Purpose: To return lowPrice.
    // Input: none.
    // Pre: Object is constructed, and lowPrice is assigned a value.
    // Output: float.
    // Post: lowPrice is returned.
    // Note: none
    {
        if (lowPrice == 99999)
         {
          lowPrice = 0;
         }
        return lowPrice;
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
    
    float ComputerType::HighPriceComputer()
    // Purpose: To find the highest pricing computer.
    // Input: none.
    // Pre: cost must have an assigned value.
    // Output: float.
    // Post: highPrice is set with the highest value.
    // Note: none.
    {
        if (cost > highPrice)
        {
            highPrice = cost;
        }
     return highPrice;
    }
    
    float ComputerType::LowPriceComputer()
    // Purpose: To find the lowest pricing computer.
    // Input: none.
    // Pre: cost must have an assigned value.
    // Output: float.
    // Post: lowPrice is set with the lowest value.
    // Note: none.
    {
        if (cost < lowPrice)
        {
            lowPrice = cost;
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
      if (!(idNumber >= 1111 && idNumber <= 9999))
      {
          invalid++;
          return false;
      }
      
      if (!(RAMSize == 4 || RAMSize == 8 || RAMSize == 16 || RAMSize == 32))
      {
          invalid++;
          return false;
      }
      
      if (!((DiskSize == 500 && datatype == "GB") || (DiskSize == 1 && datatype == "TB")|| (DiskSize == 2 && datatype == "TB")))
      {
          invalid++;
          return false;
      }
      
      if (!(computerType == "d" || computerType == "l"))
      {
          invalid++;
          return false;
      }
      
      if (!(cost >= 0.00 && cost <= 1500.00))
      {
          invalid++;
          return false;
      }
      
      if (!(labLocation == "SE145" || labLocation == "SE135" || labLocation == "SE136"))
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
