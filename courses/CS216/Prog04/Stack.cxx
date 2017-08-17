#include "Stack.h"

StackType::StackType( )
// Purpose: To initialize private data.
// Input: none.
// Pre: none.
// Output: none.
// Post: All private data initialized.
// Note: none.
{
  top = -1;
}

void StackType::MakeEmpty( )
// Purpose: To make stack empty.
// Input: none.
// Pre: Object is constructed.
// Output: none.
// Post: Stack is empty.
// Note: none.
{
  top = -1;
}

bool StackType::IsEmpty( ) const
// Purpose: To determine if stack is empty.
// Input: none.
// Pre: Object is constructed.
// Output: bool.
// Post: Bool is returned either true or false.
// Note: none.
{
  return ( top == -1 );
}

bool StackType::IsFull( ) const
// Purpose: To determine if stack is Full.
// Input: none.
// Pre: Object is constructed.
// Output: bool.
// Post: Bool is returned either true or false.
// Note: none.
{
  return  ( top == MAX_ITEMS-1);
}

void StackType::Push(ItemType newItem)
// Purpose: To add item to stack.
// Input: newItem.
// Pre: Object is constructed and stack is not full.
// Output: none.
// Post: Item is added to stack.
// Note: none.
{
  top++;
  items[top] = newItem;
}

void StackType::Pop(ItemType& item)
// Purpose: To remove item from stack.
// Input: item.
// Pre: Object is constructed and stack is not empty.
// Output: none.
// Post: Item is removed from stack.
// Note: none.
{
  item = items[top];
  top--;
}