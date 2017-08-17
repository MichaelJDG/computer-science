#include <iostream> #include "queue.h"using namespace std; const int VEC_SIZE = MAX_SIZE + 1; void Queue::MakeEmpty() // Purpose: To make queue empty. // Input: none. // Pre: Queue has to be created. // Output: none. // Post: Queue is empty. // Note: none. {  front = rear = VEC_SIZE - 1;}   Queue::Queue() // Purpose: To initialize private data. // Input: none. // Pre: none. // Output: none. // Post: All private data initialized. // Note: none. {  front = rear = VEC_SIZE - 1;}bool Queue::IsEmpty() const // Purpose: To determin if queue is empty. // Input: none. // Pre: Queue has to be created. // Output: none. // Post: Determined if queue is empty or not. // Note: none. {  return (rear == front);}bool Queue::IsFull() const // Purpose: To determin if queue is full. // Input: none. // Pre: Queue has to be created. // Output: none. // Post: Determined if queue is full or not. // Note: none. {  return ((rear + 1) % VEC_SIZE == front);}void Queue::Enqueue(ItemType newItem) // Purpose: To add item to queue. // Input: newItem. // Pre: Queue has to be created, and not full. // Output: none. // Post: Item is added to queue. // Note: none. {  rear = (rear + 1) % VEC_SIZE;  data[rear] = newItem;}void Queue::Dequeue(ItemType& itemInQueue) // Purpose: To delete item from queue. // Input: itemInQueue. // Pre: Queue has to be created, and not empty. // Output: none. // Post: Item is deleted fromqueue. // Note: none. {  front = (front + 1) % VEC_SIZE;  itemInQueue = data[front];}