//*****************************************************************
//  LinkedList.cpp
//  HashTable

//
//  This header file contains the Linked List class declaration.
//  Hash Table array elements consist of Linked List objects.
//*****************************************************************

#include "LinkedList.h"

// Constructs the empty linked list object.
// Creates the head node and sets length to zero.
LinkedList::LinkedList()
{
    head = NULL;
    length = 0;
}

// Inserts an item at the end of the list.
void LinkedList::insert( Element * newElement )
{
  
  if(head==NULL){
    head = newElement;
  }else{
    Element *current = head;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = newElement;
  }
  length++;
}

// Removes an item from the list by item key.
// Returns true if the operation is successful.
bool LinkedList::remove( string Key )
{
  if(head==NULL){
    return false;
  }
  

  if (head->key.compare(Key) == 0)
  {
    Element *temp = head;
    head = head->next;
    delete temp;
    length--;
    return true;
  }

  Element *current = head;
  while (current->next != NULL && current->next->key.compare(Key) !=0){
    current= current->next;
  }if (current->next == NULL){
    return false;
  }
  Element* temp =current->next;
  current->next =current->next->next;
  delete temp;
  length--;
  return true;
}

// Searches for an item by its key.
// Returns a reference to first match.
// Returns a NULL pointer if no match is found.
Element * LinkedList::get( string Key )
{


  if (head == NULL)
  {
    return NULL;
  }
  Element* current = head;
  while (current->key.compare(Key) != 0){
    if (current->next != NULL)
    {  
      current = current->next;
    }
    else
    {
      return NULL;
    }
  }
  return current;
}

// Displays list contents to the console window.
void LinkedList::printList()
{
    if (length == 0)
    {
        cout << "\n{ }\n";
        return;
    }
    Element * p = head;
    Element * q = head;
    cout << "\n{ ";
    while (q)
    {
        p = q;
        //if (p != head)
        if (p != nullptr)
        {
            cout << p -> key;
            if (p -> next) cout << ", ";
            else cout << " ";
        }
        q = p -> next;
    }
    cout << "}\n";
}

// Returns the length of the list.
int LinkedList::getLength()
{
    return length;
}

// De-allocates list memory when the program terminates.
LinkedList::~LinkedList()
{
  Element* current = head;
      while( current != 0 ) {
        Element* next = current->next;
        delete current;
        current = next;
      }
    head = 0;
}

//*****************************************************************
// End of File
//*****************************************************************