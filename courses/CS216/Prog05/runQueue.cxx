//**************************************************************************** 
// Author : Michael Gutierrez
// Course Title : Computer Programming II 
// Course Number : CS216
// Class Meets : M W / 8:30 - 10:20
// Prof Name : Moe Bidgoli
// Assignment Number : #5
// Due Date : 10-19-15
// Possible Points : 20
// Purpose : This Program reads male and female partners into two stacks and 
// evaluates the dance partners. . 
//**************************************************************************** 

#include <fstream> 
#include <iostream> 
#include <string> 
#include <iomanip> 
#include "queue.h"

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
  string gender, name;
  bool womenDone = false;
  bool menDone = false;
  bool skip = false;
  Queue men, women;
   
  outFile << "~<* ACM dancing partners *>~"<< endl << endl; 
   
  while(!inFile.eof())
  {
   
   inFile >> gender >> name ;
   
   if (inFile.eof())
        {
          break;
        }
   
   if (gender == "M")
     {
      if (!men.IsFull())
        {
         men.Enqueue(name);
        }
      else if (men.IsFull() && !menDone)
        {
         outFile << "~~~Queue Overflow! No Enqueue for Men!" << endl << endl;
         menDone = true;
        }  
     }
   else if (gender == "F") 
     {
      if (!women.IsFull())
        {
          women.Enqueue(name);
        }
     else if (women.IsFull() && !womenDone )
        {
         outFile << "~~~Queue Overflow! No Enqueue for Women!" << endl << endl;
         womenDone = true;
        }   
     }
     
    if (womenDone && menDone) break;
    
  }   
     
   if (men.IsEmpty() && women.IsEmpty())
     {
       outFile << "~** Dance cannot be start! No male or female show up so far! **~ " << endl;
       skip = true;
     }
   else if (men.IsEmpty() && !women.IsEmpty())  
     {
      outFile << "*** No male! No dance!" << endl;
      skip = true;
     }
   else if (!men.IsEmpty() && women.IsEmpty())  
     {
      outFile << "*** No female! No dance!" << endl;
      skip = true;
     } 
     
   while (!men.IsEmpty() && !women.IsEmpty()) 
     {
      string tempGuy, tempGirl; 
      men.Dequeue(tempGuy); 
      women.Dequeue(tempGirl);
      
      outFile <<tempGuy << " + " << tempGirl << endl;
     }
   
   if (!men.IsEmpty() && !skip)
     {
      string nextMale; 
      int menLeft = 0; 
      
      while(!men.IsEmpty())
        {
         men.Dequeue(nextMale); 
         menLeft ++;
        }
      
      outFile << endl;
      outFile << "*** There are " << menLeft << " men waiting for the next round." << endl;
      outFile << "*** " << nextMale << " will be the first to get a partner." << endl;
     }
   else if (!women.IsEmpty() && !skip) 
     {
      string nextFemale; 
      int womenLeft = 0; 
      
      while(!women.IsEmpty())
        {
         women.Dequeue(nextFemale); 
         womenLeft ++;
        }
      
      outFile << endl;
      outFile << "*** There are " << womenLeft << " women waiting for the next round." << endl;
      outFile << "*** " << nextFemale << " will be the first to get a partner." << endl;
     }
    
  outFile << endl << "<~* end *~>" << endl;
 }     