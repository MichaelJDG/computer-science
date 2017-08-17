//**************************************************************************** 
// Author : Michael Gutierrez
// Course Title : Computer Programming II 
// Course Number : CS216
// Class Meets : M W / 8:30 - 10:20
// Prof Name : Moe Bidgoli
// Assignment Number : #6
// Due Date : 10-26-15
// Possible Points : 20
// Purpose : This Program reads student id and gpa from an infile and sorts the
// data in a linked list to be output in a specififc format. 
//**************************************************************************** 

#include <fstream> 
#include <iostream> 
#include <string> 
#include <iomanip> 
#include "SortedType.h"

using namespace std;

 int main()
 {
  ifstream inFile;
  ofstream outFile;
    
  inFile.open("in.data");
  outFile.open("out.data");
    
  if(inFile.fail() || outFile.fail() )
     {
       cout << "Input file or output file opening failed" << endl;
       return 1;
     }
     
  outFile << "<* Linked List Of Students *>" << endl << endl;
  
  SortedType students; 
  ItemType tempitem;
  int valid, invalid;
  valid = 0;
  invalid = 0;
  int studentID;
  float Gpa;
  char command;
  
  while(!inFile.eof())
  {
      inFile >> command; 
      
      if (inFile.eof())
        {
          break;
        }
        
      if (command == 'I')
        {
          inFile >> studentID >> Gpa; 
          
          if (students.IsFull() != true)
            {
             if (studentID>= 111 && studentID <= 999 && Gpa >= 0.00 && Gpa <= 4.00)
               {
                 valid ++;
                 tempitem.setGPA(Gpa);
                 tempitem.setID(studentID);
                 students.InsertItem(tempitem);
               }
             else 
               {
                 invalid ++;
                 outFile << studentID << "  " << Gpa << "  ~~~ Invalid data"<< endl << endl;
               }
            }
          else 
            {
              outFile << "List is full, you can not insert!" << endl << endl;
            }
        }
      else if (command == 'E')
        {
          students.MakeEmpty();
          outFile << "*List is empty!" << endl << endl;
        }
      else if (command == 'R')
        {
           bool found; 
           
           inFile >> studentID;
           tempitem.setID(studentID);
           
           if (students.LengthIs() > 0) 
             {
               students.RetrieveItem(tempitem, found);
           
               if (!found)
                 {
                   outFile << "*" << studentID << " Not Found." << endl << endl;
                 }
               else
                 {
                   outFile << "*Student " << tempitem.IdIs() << " has GPA: " << tempitem.gpaIs() << endl << endl; 
                 } 
              }
            else if (students.LengthIs() == 0)  
              {
                outFile << "List is empty, you can not search!" << endl << endl;
              }
        }
      else if (command == 'D')
        {
          inFile >> studentID ;
          tempitem.setID(studentID);
          
          if (students.LengthIs() > 0)
            {
              students.DeleteItem(tempitem);
              valid --;
            }
          else if (students.LengthIs() == 0)
            {
              outFile << "List is empty, you can not delete!" << endl << endl;
            }
        }
      else if (command == 'P')
        {
          if (students.LengthIs() == 0)
            {
              outFile << "List is empty, you can not print!" << endl << endl;
            }
          else 
            {
              students.Print(outFile);
              outFile << ">>> Number Of Item(s) In The List: " << valid << endl;
              outFile << ">>> Number Of Invalid Data: " << invalid << endl << endl;
            }
        }
    
    }    
    
    outFile << "<* end *>" << endl;
    
  }