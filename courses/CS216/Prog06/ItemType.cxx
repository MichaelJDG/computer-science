#include <fstream> 
#include <iostream> 
#include <string> 
#include <iomanip> 
#include "ItemType.h"

using namespace std;


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
    
int ItemType::IdIs() const
    // Purpose: To return idNumber.
    // Input: none.
    // Pre: Object is constructed, and id is assigned a value.
    // Output: int.
    // Post: idNumber is returned.
    // Note: none
    {
        return id;
    }    
    
float ItemType::gpaIs() const
    // Purpose: To return gpa.
    // Input: none.
    // Pre: Object is constructed, and gpa is assigned a value.
    // Output: float.
    // Post: gpa is returned.
    // Note: none
    {
        return gpa;
    }     
    
void ItemType::setID(int newid) 
// Purpose: To set id.
// Input: none.
// Pre: Object is constructed
// Output: none.
// Post: id is set.
// Note: none
{
  id = newid;
}
    
void ItemType::setGPA(float newgpa)
// Purpose: To set gpa.
// Input: none.
// Pre: Object is constructed
// Output: noe.
// Post: gpa is set.
// Note: none  
{
  gpa = newgpa;
}