#include <fstream> 
#include <iostream> 
#include <string> 
#include <iomanip> 
#include "ItemType.h"

using namespace std;


void setStudent(int inStudentID, char inGrade, char inMajor, char inGender)
{
    studId = inStudentID;
    grade = inGrade;
    major = inMajor;
    gender = inGender;
}

int idis() const
{
    return studId;
}
    
char gradeis() const
{
    return grade;
}
  
char majoris() const
{
    return major;
}
  
char genderis() const
{
    return gender;
}

RelationType ItemType::ComparedTo(ItemType& item) const
    // Purpose: To compare to items of the same type.
    // Input: info.
    // Pre: both Objects are constructed, and all values are assigned a value.
    // Output: bool.
    // Post: Items are compared and a bool is returned.
    // Note: none
    {
      if(id < item.IdIs())
        return LESS;
      else if (id > item.IdIs())
        return GREATER;
      else 
        return EQUAL;    
    }