#include <fstream> 
#include <iostream> 
#include <string> 
#include <iomanip>

using namespace std; 

enum RelationType {LESS, EQUAL, GREATER};

class ItemType
{ 
  public:
  
  RelationType ComparedTo(ItemType& item) const;
    // Purpose: To compare to items of the same type.
    // Input: info.
    // Pre: both Objects are constructed, and all values are assigned a value.
    // Output: RelationType.
    // Post: Items are compared and a bool is returned.
    // Note: none
  
  void setStudent(int inStudentID, char inGrade, char inMajor, char inGender);
  
  int idis() const;
    
  char gradeis() const; 
  
  char majoris() const;
  
  char genderis() const;
    
  protected:
   int studId;
   char grade, major, gender;

   
};