//**************************************************************************** 
// Author : Michael Gutierrez
// Course Title : Computer Programming II 
// Course Number : CS216
// Class Meets : M W / 8:30 - 10:20
// Prof Name : Moe Bidgoli
// Assignment Number : #8
// Due Date : 11-04-15
// Possible Points : 20
// Purpose :
// To input numbers in to an array and to find values from those
// numbers using recursive functions.
//**************************************************************************** 

#include <fstream> 
#include <iostream> 
#include <string> 
#include <iomanip> 

using namespace std;

void ReadToArray (int* intArray, int Max_Size, ifstream& inFile)
// Purpose: To read values into array
// Input: intArray, Max_Size, inFile
// Pre: all input has a value and inFile is open.
// Output: none
// Post: inFile is read to array.
// Note: none
{
    for(int i=0;  i != Max_Size; i++)
    {
        inFile >> intArray[i];
    }
}

void printArray (int intArray[], int first, int last,ofstream& outFile)
// Purpose: To print values of array
// Input: intArray, first , last, outFile
// Pre: all input has a value and outFile is open.
// Output: none
// Post: array is printed.
// Note: none
{
    if (first == last)
      {
        outFile << intArray[first] << endl;
      }
    else 
      {
        outFile << intArray[first] << " "; 
        printArray(intArray,first+1, last,outFile);
      }
}

void printArrayRev(int intArray[], int first, int last,ofstream& outFile)
// Purpose: To print values of array in reverse
// Input: intArray, first , last, outFile
// Pre: all input has a value and outFile is open.
// Output: none
// Post: array is printed in reverse.
// Note: none
{
    if (last == first)
      {
        outFile<< intArray[last]<< endl;
      }
    else 
      {
        outFile << intArray[last]<< " "; 
        printArrayRev(intArray,first, last-1, outFile);
      }
}

int minOfArray(int intArray[], int length)
// Purpose: To find the minimum value of array
// Input: intArray, length
// Pre: intArray and length have a value
// Output: int
// Post: min value of array is found
// Note: none
{
 

          int min = intArray[length];
          if (length > 0)
            {
              int temp = minOfArray(intArray, length -1);
              if (temp < min)
                 {
                     return temp;
                 }
              else
                 {
                     return min;
                 }
            }
}

int sumOfInt (int n)
// Purpose: To find the sum of int n
// Input: n
// Pre: n has a value
// Output: int
// Post: sum of int n is found
// Note: none
{
   if (n == 1)
     {
        return n; 
     }
   else
     {
        return n + sumOfInt(n-1);
     }
}

int fact (int n)
// Purpose: To find the Factorial of int n
// Input: n
// Pre: n has a value
// Output: int
// Post: factorial of int n is found
// Note: none
{
    if (n <= 1)
      {
          return 1;
      }
    else 
      {
          return n * fact(n-1);
      }
}

int sumOfDigits (int sum)
// Purpose: To find the sum of the digits of the array sum
// Input: sum
// Pre: sum has a value
// Output: int
// Post: sum of the digits of the array sum is found
// Note: none
{
  if (sum > 10)
    {
        return (sum%10) + sumOfDigits(sum/10);
    }
  else 
    {
      return sum;  
    }
}

void printBinary (int sum, ofstream& outFile)
// Purpose: To print the binary of the array sum
// Input: sum
// Pre: sum has a value
// Output: none
// Post: binary of the array sum is print
// Note: none
{
    if (sum > 1)
      {
         printBinary(sum / 2,outFile) ;
      }  
    outFile << (sum%2);  
      
}

 int main()
 {  
    const int Max_Size = 10;
    const int length = Max_Size -1;
    
    ifstream inFile;
    ofstream outFile;
    
    inFile.open("in.data");
    outFile.open("out.data");
    
    if(inFile.fail() || outFile.fail() )
    {
        cout << "Input file or output file opening failed" << endl;
        return 1;
    }
    
    int intArray[Max_Size];
    
    ReadToArray(intArray,Max_Size,inFile);
    
    int n = intArray[length];
    int sum = sumOfInt(n);
    
    outFile << "1) Array: ";
    printArray(intArray,0,length,outFile);
    
    outFile<< "2) Array in reverse order: ";
    printArrayRev(intArray,0,length,outFile);
    
    outFile<< "3) MIN of array: " << minOfArray(intArray, length) << endl;
    
    outFile<< "4) SUM of 1..." << intArray[length] << ": "<< sum <<endl;
    
    outFile<< "5) "<< n << "! "<< fact(n)<<endl;
    
    outFile<< "6) Summation of digits for " << sum << ": "<< sumOfDigits(sum)<< endl;
    
    outFile<< "7) Binary of "<< sum << ": "; 
    printBinary(sum,outFile);
    
    outFile<<endl << endl << "<*~ end ~*>";
    
 }    