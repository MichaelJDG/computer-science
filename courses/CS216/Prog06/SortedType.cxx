#include <iostream>
#include "SortedType.h"

using namespace std;

SortedType::SortedType()  // Class constructor
// Purpose: To construct object
// Input: none
// Pre: none
// Output: none
// Post: object is created
// Note: none
{
  length = 0;
  listData = NULL;
}

SortedType::~SortedType() 
// Purpose: To deconstruct object
// Input: none
// Pre: object is created
// Output: none
// Post: object is deconstructed
// Note: none
{
  MakeEmpty();
}

SortedType::SortedType(const SortedType& otherList)
// Purpose: To copy an object
// Input: otherlist
// Pre: otherlist must be created
// Output: SortedType
// Post: a deep copy is made of other list
// Note: none
{
    NodeType* fromPtr;	// Pointer into list being copied from
    NodeType* toPtr;   	// Pointer into new list being built
    if(otherList.listData == NULL)
    {
        listData = NULL;
        return;
    }
    // Copy first node
    fromPtr = otherList.listData;
    listData = new NodeType;
    listData->info = fromPtr->info;

    // Copy remaining nodes
   
    toPtr = listData;
    fromPtr = fromPtr->next;
    while (fromPtr != NULL)
    {
        toPtr->next = new NodeType;
        toPtr = toPtr->next;
        toPtr->info = fromPtr->info;
        fromPtr = fromPtr->next;
    }
    toPtr->next = NULL;
}

bool SortedType::IsFull() const
// Purpose: To determin if list is full
// Input: none 
// Pre: object must be created
// Output: bool 
// Post: bool is returned 
// Note: none
{
  NodeType* ptr;

  ptr = new NodeType;
  if (ptr == NULL)
    return true;
  else
  {
    delete ptr;
    return false;
  }
}

int SortedType::LengthIs() const
// Purpose: To determin length os list
// Input: none
// Pre: object is created
// Output: int
// Post: length is returned
// Note: none
{
  return length;
}


void SortedType::MakeEmpty()
// Purpose: To make list empty
// Input: none
// Pre: object is created
// Output: none
// Post: list is empty
// Note: none
{
  NodeType* tempPtr;
  while (listData != NULL) // traverse list, deallocating each node in turn
  {
    tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
  }
  length = 0; 
}


void SortedType::DeleteItem(ItemType item)
// Purpose: To delete item 
// Input: item
// Pre: object is created and list is not empty
// Output: none
// Post: item is deleated
// Note: none
{
  NodeType* location = listData;
  NodeType* tempLocation;

  // Locate node to be deleted.
  if (item.ComparedTo(listData->info)== EQUAL)
  {
    tempLocation = location;
    listData = listData->next;		// Delete first node.
  }
  else
  {
    while (!((item.ComparedTo((location->next)->info))== EQUAL))
      location = location->next;
    
    tempLocation = location->next;
    location->next = (location->next)->next;
  }
  delete tempLocation;
  length--;
}

void SortedType::ResetList()
// Purpose: To set current position to front of list
// Input: none
// Pre: object is created
// Output: none
// Post: current possition is reset
// Note: none
{
  currentPos = NULL;
}
 

void SortedType::RetrieveItem(ItemType& item, bool& found)
// Purpose: To retrieve item
// Input: item , found
// Pre: object is created and list is not empty
// Output: none
// Post: Item is found or message is output
// Note: none
{
  bool moreToSearch;
  NodeType* location;

  location = listData;
  found = false;
  moreToSearch = (location != NULL);

  while (moreToSearch && !found)
  {
    switch(item.ComparedTo(location->info))
    {
      case GREATER:
        location = location->next;
        moreToSearch = (location != NULL);
        break;
  
      case EQUAL:
        found = true;
        item = location->info;
        break;
  
      case LESS:
        moreToSearch = false;
        break;
    }
  }
}

void SortedType::InsertItem(ItemType item)
// Purpose: To insert item
// Input: item
// Pre: object is created and list is not full
// Output: none
// Post: object is inserted
// Note: none
{
  NodeType* newNode;  // pointer to node being inserted
  NodeType* predLoc;  // trailing pointer
  NodeType* location; // traveling pointer
  bool moreToSearch;

  location = listData;
  predLoc = NULL;
  moreToSearch = (location != NULL);

  // Find insertion point.
  while (moreToSearch)
  {
    if(item.ComparedTo(location->info) == GREATER)
    {
      predLoc = location;
      location = location->next;
      moreToSearch = (location != NULL);
    }
    else
      moreToSearch = false;
  }

  // Prepare node for insertion
  newNode = new NodeType;
  newNode->info = item;

  // Insert node into list.
  if (predLoc == NULL)         // Insert as first
  {
    newNode->next = listData;
    listData = newNode;
  }
  else
  {
    newNode->next = location;
    predLoc->next = newNode;
  }
  length++;
}


void SortedType::GetNextItem(ItemType& item)
// Purpose: To get next item in list
// Input: item
// Pre: object is created 
// Output: none
// Post: next item is retrieved 
// Note: none
{
  if (currentPos == NULL) //Wrap at end of list
    currentPos = listData; 

  item = currentPos->info;
  currentPos = currentPos->next;
} 

void SortedType::Print(ofstream& outFile)
// Purpose: To print list
// Input: outFile
// Pre: object is created and list is not empty
// Output: none
// Post: list is printed
// Note: none
{
   currentPos = listData;
   bool skipfront = false;
   while(currentPos != NULL)
   {
      if (!skipfront)
      {
        outFile << "*";
      }
      skipfront = true;
      outFile << currentPos->info.IdIs()<<"("<<currentPos->info.gpaIs()<< ")";
      currentPos = currentPos->next;
      
      if (currentPos != NULL)
       {
         outFile << " → ";
       }
   }
   
   outFile << endl; 
}
