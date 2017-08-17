
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
    
    int IdIs() const;
    // Purpose: To return Id.
    // Input: none.
    // Pre: Object is constructed, and Id is assigned a value.
    // Output: int.
    // Post: Id is returned.
    // Note: none
    
    float gpaIs() const;
    // Purpose: To return gpa.
    // Input: none.
    // Pre: Object is constructed, and gpa is assigned a value.
    // Output: float.
    // Post: gpa is returned.
    // Note: none
    
    void setID(int newid); 
    // Purpose: To set id.
    // Input: none.
    // Pre: Object is constructed
    // Output: none.
    // Post: id is set.
    // Note: none
    
    void setGPA(float newgpa);
    // Purpose: To set gpa.
    // Input: none.
    // Pre: Object is constructed
    // Output: noe.
    // Post: gpa is set.
    // Note: none
    
    
  protected:
   int id;
   float gpa;
};

