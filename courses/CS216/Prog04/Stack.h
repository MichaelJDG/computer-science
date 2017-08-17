#include "ItemType.h"

const int MAX_ITEMS = 5;

class StackType
{
  public:
    StackType( );
    // Purpose: To initialize private data.
    // Input: none.
    // Pre: none.
    // Output: none.
    // Post: All private data initialized.
    // Note: none.

    void MakeEmpty( );
    // Purpose: To make stack empty.
    // Input: none.
    // Pre: Object is constructed.
    // Output: none.
    // Post: Stack is empty.
    // Note: none.
    
    bool IsEmpty( ) const;
    // Purpose: To determine if stack is empty.
    // Input: none.
    // Pre: Object is constructed.
    // Output: bool.
    // Post: Bool is returned either true or false.
    // Note: none.

    bool IsFull( ) const;
    // Purpose: To determine if stack is Full.
    // Input: none.
    // Pre: Object is constructed.
    // Output: bool.
    // Post: Bool is returned either true or false.
    // Note: none.
    
    void Push(ItemType newItem);
    // Purpose: To add item to stack.
    // Input: newItem.
    // Pre: Object is constructed and stack is not full.
    // Output: none.
    // Post: Item is added to stack.
    // Note: none.
    
    void Pop(ItemType& item);
    // Purpose: To remove item from stack.
    // Input: item.
    // Pre: Object is constructed and stack is not empty.
    // Output: none.
    // Post: Item is removed from stack.
    // Note: none.

  private:
    int top;
    ItemType  items[MAX_ITEMS]; // array of ItemType
};