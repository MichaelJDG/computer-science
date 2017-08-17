#include <fstream> #include <iostream> #include <string> #include <iomanip>using namespace std; enum RelationType {LESS, EQUAL, GREATER};class ItemType{   public:    void WriteItemToFile (ofstream& outFile) ;    // Purpose: To output an item to the file.    // Input: outFile.    // Pre: item must exist and outfile must be open.    // Output: none    // Post: item is output.    // Note: none    RelationType ComparedTo(ItemType& item) const;    // Purpose: To compare to items of the same type.    // Input: info.    // Pre: both Objects are constructed, and all values are assigned a value.    // Output: RelationType.    // Post: Items are compared and a bool is returned.    // Note: none    void setStudent(int inStudentID, char inGrade, char inMajor, char inGender);    // Purpose: To set all private variables to new data.    // Input: inStudentID, inGender, inGrade, inMajor    // Pre: item must exist and all inputs must have data.    // Output: none    // Post: all new values have been set.    // Note: none    void setID(int id);  // Purpose: To set studID to new data.  // Input: id  // Pre: item must exist and all inputs must have data.  // Output: none  // Post: new value set to studID  // Note: none    int idis() const;  // Purpose: To return studID   // Input: none  // Pre: item must exist   // Output: int  // Post: studID is returned   // Note: none      char gradeis() const;   // Purpose: To return grade  // Input: none  // Pre: item must exist   // Output: char  // Post: grade is returned   // Note: none    char majoris() const;  // Purpose: To return major  // Input: none  // Pre: item must exist   // Output: char  // Post: major is returned   // Note: none    char genderis() const;  // Purpose: To return gender  // Input: none  // Pre: item must exist   // Output: char  // Post: gender is returned   // Note: none      protected:   int studId;   char grade, major, gender;   };