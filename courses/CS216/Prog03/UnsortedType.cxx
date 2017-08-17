#include  "UnsortedType.h"

UnsortedType::UnsortedType()
// Purpose: To initialize unsorted list with default values.
// Input: none.
// Pre: none.
// Output: none.
// Post: length is set to a default value.
// Note: none
{
  length = 0;
}   	

void UnsortedType::MakeEmpty ( ) 
// Purpose: To empty list.
// Input: none.
// Pre: List is declared with values in it.
// Output: none.
// Post: list is emptied.
// Note: none
{    
   length = 0 ;
}

bool UnsortedType::IsFull () const
// Purpose: To see if list is full or not.
// Input: none.
// Pre: List is declared.
// Output: bool.
// Post: If list is full true is returned if not false is returned.
// Note: none
{
   return (length == MAX_ITEMS);
}

int UnsortedType::LengthIs() const
// Purpose: To return length of list.
// Input: none.
// Pre: List is declared.
// Output: int.
// Post: Length is returned.
// Note: none
{    
   return length ;
}

void UnsortedType::RetrieveItem(ItemType& item, bool& found)  
// Purpose: To retrieve an item from a list.
// Input: item, found.
// Pre: List is declared and item is in list.
// Output: item.
// Post: Item is found and returned.
// Note: none
{    bool moreToSearch;
     int location = 0;

     found = false;
	moreToSearch = (location < length);
	while (moreToSearch  &&  !found)
	{ switch (item.ComparedTo(info[location]))
    	  {       
    	    case  LESS	:
		    case  GREATER : location++;
				  moreToSearch = (location < length);
                                  break ;
		    case  EQUAL	: found = true;
				  item = info[location] ;
				  break ;
   	       }
    }
}

void UnsortedType::InsertItem(ItemType item)
// Purpose: To add an item to list.
// Input: item.
// Pre: List is declared and isnt full.
// Output: none.
// Post: Item is added to list.
// Note: none
{
	info[length] = item ;
	length++ ;
}


void UnsortedType::DeleteItem(ItemType item) 
// Purpose: To delete an item from list.
// Input: item.
// Pre: List is declared and item is in list.
// Output: none.
// Post: Item is deleted from list.
// Note: none
{    
     int location = 0;
    
     while (item.ComparedTo(info[location]) != EQUAL)
      location++;

	info[location] = info[length - 1] ;
	length-- ;
}


void UnsortedType::ResetList()  
// Purpose: To reset current position in list.
// Input: none.
// Pre: List is declared.
// Output: none.
// Post: Current position is reset.
// Note: none
{    
   currentPos = -1;
}

void  UnsortedType::GetNextItem(ItemType& item)  
// Purpose: To iretreive next item from list.
// Input: item.
// Pre: List is declared and current position is not at end of list.
// Output: item.
// Post: Next item is retrieved.
// Note: none
{
   currentPos++;
   item = info[currentPos];
}

void UnsortedType::PrintList(ofstream& outFile)
// Purpose: To print list
// Input: outfile
// Pre: List is declared and is not empty
// Output: none.
// Post: List is printed.
// Note: none.
{
  outFile<< "IdNumber" << setw(20) << "Processor" << setw(16) << "RAM Size" <<
  setw(10) << "Disk Size" << setw(15) << "Computer Type" << setw(12)
  << "Cost" <<
  setw(16) << "Location" << endl;
  outFile<< "--------" << setw(20) << "---------" << setw(16)
  << "--------" <<
  setw(10) << "---------" << setw(15) << "-------------" << setw(12) 
  << "----" <<
  setw(16) << "--------" << endl;
  
  ItemType item;
  ResetList();
  for(int i = 0; i<length; i++)
  {
     GetNextItem(item);
     item.PrintRD(outFile);
  }
  
  outFile << endl;
}
