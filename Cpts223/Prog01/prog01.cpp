//**************************************************************************** 
// Author : Michael Gutierrez
// Course Title : Advanced data structures in c++
// Course Number : Cpts 223
// Class Meets : M W F/ 12:10 - 1:00
// Prof Name : Aaron Crandall
// Assignment Number : #1
// Due Date : 9-22-16
// Possible Points : 100
// Purpose :
//  
//**************************************************************************** 

#include <fstream> 
#include <iostream> 
#include <iomanip> 
#include <chrono>

#include <vector> 


using namespace std;


  float do_bubblesort(vector<int> &array, int N)
  {
      int num; 
      int myArray[N];
      int temp;
      int count;
      int i,j;
      bool ordered = false;
   
	for (i = 0; i <= N; i ++)
	{    
		   num = rand() % N;
		   myArray[i] = num;
	}

	while (ordered == false ){

		for (j = 0; j < N-1; j++)
        {
            if (myArray[j] > myArray[j+1])
			{
				temp = myArray[j];
				myArray[j] = myArray[j+1];
				myArray[j+1] = temp;
				count++;
			}
        }
        
        if (count== 0){
            ordered = true; 
        }
        else {
            count =0; 
        }
        
	}
    return 0;
  }
  
  float do_bubblesortWorst(vector<int> &array, int N)
  {
      int num= N; 
      int myArray[N];
      int temp;
      int count;
      int i,j;
      bool ordered = false;
   
	for (i = 0; i <= N; i ++)
	{    
	       myArray[i] = num;
		   num = num -1;
		   
	}

	while (ordered == false ){

		for (j = 0; j < N-1; j++)
        {
            if (myArray[j] > myArray[j+1])
			{
				temp = myArray[j];
				myArray[j] = myArray[j+1];
				myArray[j+1] = temp;
				count++;
			}
        }
        
        if (count== 0){
            ordered = true; 
        }
        else {
            count =0; 
        }
        
	}
    return 0;
  }
  
  float do_bubblesortOptimal(vector<int> &array, int N)
  {
      int num =1; 
      int myArray[N];
      int temp;
      int count;
      int i,j;
      bool ordered = false;
   
	for (i = 0; i <= N; i ++)
	{      
	       myArray[i] = num;
		   num = num+1;
	}
	

	while (ordered == false ){

		for (j = 0; j < N-1; j++)
        {
            if (myArray[j] > myArray[j+1])
			{
				temp = myArray[j];
				myArray[j] = myArray[j+1];
				myArray[j+1] = temp;
				count++;
			}
        }
        
        if (count== 0){
            ordered = true; 
        }
        else {
            count =0; 
        }
        
	}
    return 0;
  }


 int main()
 {  
    
    ofstream outFile;
    int N[ ] = {10,50,100,500,1000,5000,10000,50000,100000};
    vector<int> myVector;
    int i,j;
    float avg;
    float sum;
    
    outFile.open("BSSstats.csv");
    
    if(outFile.fail() )
    {
        cout << "Output file opening failed" << endl;
        return 1;
    }
    
    outFile<< "N Size, Run #1, Run #2, Run #3, Run #4, Run #5, Optimal Time Avg, Run #1, Run #2, Run #3, Run #4, Run #5, Worst Case Time Avg, Run #1, Run #2, Run #3, Run #4, Run #5, Avg Sort Time" << endl;
    
    
    for (i =0; i<9; i++) {
        outFile << N[i] << ",";
        
        
        for (j=0; j<5; j++){
            
             chrono::time_point<chrono::system_clock> start, end;
             start = chrono::system_clock::now();
             do_bubblesortOptimal(myVector, N[i]) ;
             end = chrono::system_clock::now();
 
             chrono::duration<double> elapsed_seconds = end-start;
 
             outFile << elapsed_seconds.count() << "s,";
             sum = sum + elapsed_seconds.count();
         }
        avg = sum/5;
        outFile << avg << ",";
        
        
        
        
        
        for (j=0; j<5; j++){
            
             chrono::time_point<chrono::system_clock> start, end;
             start = chrono::system_clock::now();
             do_bubblesortWorst(myVector, N[i]) ;
             end = chrono::system_clock::now();
 
             chrono::duration<double> elapsed_seconds = end-start;
 
             outFile << elapsed_seconds.count() << "s,";
             sum = sum + elapsed_seconds.count();
         }
        avg = sum/5;
        outFile << avg << ",";
        
        
        
        
        for (j=0; j<5; j++){
            
             chrono::time_point<chrono::system_clock> start, end;
             start = chrono::system_clock::now();
             do_bubblesort(myVector, N[i]) ;
             end = chrono::system_clock::now();
 
             chrono::duration<double> elapsed_seconds = end-start;
 
             outFile << elapsed_seconds.count() << "s,";
             sum = sum + elapsed_seconds.count();
         }
        avg = sum/5;
        outFile << avg << ","<< endl;
     
    }
    
  }  
  