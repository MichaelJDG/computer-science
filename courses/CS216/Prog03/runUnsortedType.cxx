//**************************************************************************** 
// Author : Michael Gutierrez
// Course Title : Computer Programming II 
// Course Number : CS216
// Class Meets : M W / 8:30 - 10:20
// Prof Name : Moe Bidgoli
// Assignment Number : #3
// Due Date : 09-30-15
// Possible Points : 20
// Purpose :
//This Program reads computer data in from a file and outputes it in a
//specified format using an unsorted list and command keys. 

#include <fstream> 
#include <iostream> 
#include <string> 
#include <iomanip> 
#include "UnsortedType.h"

using namespace std;

 int main()
 {
   // Variables to remove constants. 
   bool valid;
   int minramsize;
   int mindisksize;
   string lablocation1;
   string lablocation2;
   string lablocation3;
   string computertype;
   lablocation1 = "SE135";
   lablocation2 = "SE136";
   lablocation3 = "SE145";
   computertype = "l";
   minramsize = 16;
   mindisksize = 2;
   
   string command;
   bool found;
   int tempID;
   int se136count;
   int se145count;
   int se135count;
   int lowdisk;
   int highram;
   int lowram;
   int trash;
   se135count = 0;
   se145count = 0;
   se136count = 0;
   lowdisk = 2;
   highram = 33;
   lowram = 15;
   
   ifstream inFile;
   ofstream outFile;
    
   inFile.open("in.data");
   outFile.open("out.data");
    
   if(inFile.fail() || outFile.fail() )
     {
       cout << "Input file or output file opening failed" << endl;
       return 1;
     }
     
   ItemType computer;
   UnsortedType computerList, laptopsList, desktopsList, highRAMandDiskList;
   
   outFile<< "*~< Lab Report >~*"<< endl << endl;
   
    while(!inFile.eof())
    {
      inFile >> command ;
      
      if (inFile.eof())
        {
          break;
        }
   
           if (command == "A")  
    	     {
    	         computer.ReadRD(inFile);
    	         valid = computer.validData();
    	         
    	         if (valid == false)
    	         {computer.PrintinvalidRD(outFile);}
    	         
    	         if (computerList.IsFull())
    	           {outFile << "List is full cannot add item!" << endl<< endl;}
    	         else
    	           {
    	             if (valid == true)
    	               {
    	                 computerList.InsertItem(computer);
    	                 
    	                 if(computer.RamsizeIs() >= minramsize && computer.DiskSizeIs()
    	                 >= mindisksize)
    	                   {highRAMandDiskList.InsertItem(computer);}
    	                   
    	                 if(computer.computerTypeIs() == computertype)
    	                   {laptopsList.InsertItem(computer);}
    	                 else
    	                   {desktopsList.InsertItem(computer);}
    	                   
    	                 if(computer.LocationIs() == lablocation1)
    	                   {se135count++;}
    	                 else if (computer.LocationIs() == lablocation2)
    	                   {se136count++;}
    	                 else 
    	                   {se145count++;}
    	               }
    	           }
    	      }
    	    else if (command == "D")  
		       {
		         if(computerList.LengthIs() != 0)
		           {
		             ItemType temp;
		             
		             temp.ReadID(inFile);
		             
		             computerList.RetrieveItem(temp, found);
		             computerList.DeleteItem(temp);
		             if(temp.computerTypeIs() == "l")
		               {laptopsList.DeleteItem(temp);}
		             if(temp.computerTypeIs() == "d")  
		               {desktopsList.DeleteItem(temp);}
		             if(temp.RamsizeIs() > lowram && temp.RamsizeIs()< highram
		             && temp.DiskSizeIs()>= lowdisk) 
		               {highRAMandDiskList.DeleteItem(temp);}
		             
		             if (temp.LocationIs() == "SE136")  
		               {se136count--;}
		             if (temp.LocationIs() == "SE135") 
		               {se135count--;}
		             if (temp.LocationIs() == "SE145")  
		               {se145count--;}
		               
		           }
		         else
		          { 
		             inFile >> trash; 
		             outFile << "List is empty not able to delete!"<< endl<< endl;
		              
		          }     
		       }
		     else if(command == "P")               
		       {
		         if(computerList.LengthIs() != 0)
		           {
		             computerList.PrintList(outFile);
		             
		             float total = computerList.LengthIs()/ 100.0f;
		             
		             if (se135count == 0)
		               {
		                 outFile << "No computers in Lab SE135"<<endl; 
		               }
		            else
		              {
		                outFile << "SE135:	%" << (se135count/total)<<endl;
		              }
		              
		             if (se136count == 0) 
		               {
		                 outFile << "No computers in Lab SE136" << endl;
		               }
		             else
		               {
		                 outFile << "SE136:	%" << (se136count/total)<<endl;  
		               }
		             if (se145count == 0) 
		               {
		                 outFile << "No computers in Lab SE145"<< endl; 
		               }
		             else
		               {
		                 outFile << "SE145:	%" << (se145count/total)<<endl;
		               }
		               
		             outFile << endl << "*** " << computer.getinvalid() << " invalid record(s)"
		             << endl << endl;
		           }
		         else 
		           {outFile << "List is empty not able to print!" << endl << endl;}    
		       }     
		     else if (command == "L")
		       {
		         if(laptopsList.LengthIs() != 0)
		           {
		             outFile << "List of Laptop(s)"<< endl;
		             outFile << "-----------------"<< endl;
		             laptopsList.PrintList(outFile);
		           }
		         else
		           {outFile << "Laptop list is empty not able to print!"<< endl<< endl;}
		       }
		     else if (command == "K")     
		       {
		         if(desktopsList.LengthIs() != 0)
		           {
		             outFile << "List of Desktop(s)"<< endl;
		             outFile << "------------------"<< endl;
		             desktopsList.PrintList(outFile);
		           }
		         else
		           {outFile << "Desktop list is empty not able to print!"<< endl<< endl;}
		       }
		     else if (command == "M")     
		       {
		         if(highRAMandDiskList.LengthIs() != 0)
		           {
		             outFile << "List of High RAM & Disk computers"<< endl;
		             outFile << "---------------------------------"<< endl;
		             highRAMandDiskList.PrintList(outFile);
		           }
		         else
		           {outFile << "High RAM & Disk computers list is empty not able to print!"<< endl<< endl;}
		       }
		     else 
		     {outFile << "Command not recognized!" << endl<< endl;}
   	          
       
    }
    
    outFile<< "*< end  >*"<< endl << endl;
  }