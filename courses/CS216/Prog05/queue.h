#include "ItemType.h"

const int MAX_SIZE = 10;

class Queue 
{
  public:

    void MakeEmpty();
    // Purpose: To make queue empty.
    // Input: none.
    // Pre: Queue has to be created.
    // Output: none.
    // Post: Queue is empty.
    // Note: none.

    bool IsEmpty() const;
    // Purpose: To determin if queue is empty.
    // Input: none.
    // Pre: Queue has to be created.
    // Output: none.
    // Post: Determined if queue is empty or not.
    // Note: none.

    bool IsFull() const;
    // Purpose: To determin if queue is full.
    // Input: none.
    // Pre: Queue has to be created.
    // Output: none.
    // Post: Determined if queue is full or not.
    // Note: none.

    void Enqueue(ItemType newItem );
    // Purpose: To add item to queue.
    // Input: newItem.
    // Pre: Queue has to be created, and not full.
    // Output: none.
    // Post: Item is added to queue.
    // Note: none.

    void Dequeue(ItemType& itemInQueue);
    // Purpose: To delete item from queue.
    // Input: itemInQueue.
    // Pre: Queue has to be created, and not empty.
    // Output: none.
    // Post: Item is deleted fromqueue.
    // Note: none.

    Queue();
    // Purpose: To initialize private data.
    // Input: none.
    // Pre: none.
    // Output: none.
    // Post: All private data initialized.
    // Note: none.

private:
    ItemType data[MAX_SIZE+1];
    int front;
    int rear;
};