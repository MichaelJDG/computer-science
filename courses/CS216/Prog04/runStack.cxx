//**************************************************************************** 
// Author : Michael Gutierrez
// Course Title : Computer Programming II 
// Course Number : CS216
// Class Meets : M W / 8:30 - 10:20
// Prof Name : Moe Bidgoli
// Assignment Number : #4
// Due Date : 10-07-15
// Possible Points : 20
// Purpose : This Program reads a fully parenthesised math 
// problem in from a file and evaluates it. 
//**************************************************************************** 

#include <fstream> 
#include <iostream> 
#include <string> 
#include <iomanip> 
#include "Stack.h"

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
   
   StackType operand, operators, parenthesis; 
   string temp; 
   char operand1, operand2, math;
   int result = 0;
   
   
   inFile >> temp; 
   outFile << "*** Fully Parenthesized Arithmetic Infix Expression ***" << endl<< endl;
   
   for (int i =0; i < temp.length(); i++)
   {
    char token = temp[i];
    
     if (token >= '0' && token <= '9' ) 
     {
      if (operand.IsFull())
      {
       outFile << temp << "  ~~~Stack Overflow!" << endl << endl;
       break;
      }
      else 
      {
       operand.Push(token-'0');
      }
     }
     
     else if(token == '+'|| token == '-'|| token == '/'|| token == '*'|| token == '%')
     {
      if (operators.IsFull())
      {
       outFile << temp << "  ~~~Stack Overflow!" << endl << endl;
       break;
      }
      else 
      {
       operators.Push(token);
      }
     }
     
     else if (token == '(')
     {
      if (parenthesis.IsFull())
      {
       outFile << temp << "  ~~~Stack Overflow!" << endl << endl;
       break;
      }
      else 
      {
       parenthesis.Push(token);
      }
     }
    
     else if (token == ')') 
       {
        if (parenthesis.IsEmpty()) 
        {
         outFile << temp << "  ~~~Stack Underflow!" << endl << endl;
         break;
        }
        else 
        {
         parenthesis.Pop(token);
         operand.Pop(operand2);
         operand.Pop(operand1);
         operators.Pop(math);
         
         if(math == '+') result = operand1 + operand2;
         else if(math == '-') result = operand1 - operand2;
         else if(math == '*') result = operand1 * operand2; 
         else if(math == '/') 
           {
            if (operand2 == 0)
             {
              outFile << temp << " Can not devide by Zero!" << endl << endl;
              break;
             }
            else result = operand1 / operand2; 
           }
         else if(math == '%')
           {
              if (operand2 == 0)
               {
                outFile << temp << " Can not Mod by zero!" << endl << endl;
                break;
               }
              else result = operand1 % operand2; 
            }
         
         operand.Push(result);

        } 
       }
       
      else if (token == ';')  
      {
        if (operators.IsEmpty() && parenthesis.IsEmpty())
        {
         if (!operand.IsEmpty())
           {
            operand.Pop(token);
            if (operand.IsEmpty())
              {
                outFile << temp << "  is OK!" << endl << endl;
                outFile << "~~ Evaluation result: "<< result << endl <<endl;
              }
            else 
              {
               outFile << temp << "  is NOT OK!" << endl << endl;
               break;
              }
           }
        }
        else 
          {
           outFile << temp << "  is NOT OK!" << endl << endl;
           break;
          }
        
      }
    
   }
   
   outFile << "< end >" << endl;
   
 }