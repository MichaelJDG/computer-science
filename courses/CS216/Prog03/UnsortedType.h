#include  "ItemType.h"

const int MAX_ITEMS =5;

class  UnsortedType	
{			
 public :

   UnsortedType();
   // Purpose: To initialize unsorted list with default values.
   // Input: none.
   // Pre: none.
   // Output: none.
   // Post: length is set to a default value.
   // Note: none
    
   void MakeEmpty();
   // Purpose: To empty list..
   // Input: none.
   // Pre: List is declared with values in it.
   // Output: none.
   // Post: list is emptied.
   // Note: none
   
   bool IsFull() const; 
   // Purpose: To see if list is full or not.
   // Input: none.
   // Pre: List is declared.
   // Output: bool.
   // Post: If list is full true is returned if not false is returned.
   // Note: none
   
   int LengthIs() const;  
   // Purpose: To return length of list.
   // Input: none.
   // Pre: List is declared.
   // Output: int.
   // Post: Length is returned.
   // Note: none
   
   void RetrieveItem(ItemType& item, bool& found);
   // Purpose: To retrieve an item from a list.
   // Input: item, found.
   // Pre: List is declared and item is in list.
   // Output: item.
   // Post: Item is found and returned.
   // Note: none
   
   void InsertItem(ItemType item); 
   // Purpose: To add an item to list..
   // Input: item.
   // Pre: List is declared and isnt full..
   // Output: none.
   // Post: Item is added to list..
   // Note: none
   
   void DeleteItem(ItemType item); 
   // Purpose: To delete an item from list.
   // Input: item.
   // Pre: List is declared and item is in list.
   // Output: none.
   // Post: Item is deleted from list.
   // Note: none
   
   void ResetList();
   // Purpose: To reset current position in list.
   // Input: none.
   // Pre: List is declared.
   // Output: none.
   // Post: Current position is reset.
   // Note: none
   
   void GetNextItem(ItemType& item); 	 
   // Purpose: To iretreive next item from list.
   // Input: item.
   // Pre: List is declared and current position is not at end of list.
   // Output: item.
   // Post: Next item is retrieved.
   // Note: none
   
   void PrintList(ofstream& outFile);
   // Purpose: To print list
   // Input: outfile
   // Pre: List is declared and is not empty
   // Output: none.
   // Post: List is printed.
   // Note: none.

 private :
 
  int length ;           
  ItemType info[MAX_ITEMS] ;          
  int currentPos ;
} ;
