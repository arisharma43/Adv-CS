//*****************************************************************
//  HashTable.cpp
//  HashTable
//
//  This header file contains the Hash Table class definition.
//  Hash Table array elements consist of Linked List objects.
//*****************************************************************

#include "HashTable.h"

// Constructs the empty Hash Table object.
// Array length is set to 13 by default.
HashTable::HashTable( int tableLength )
{
    if (tableLength <= 0) tableLength = 16;
    array = new LinkedList[ tableLength ];
    length = tableLength;
}

// Returns an array location for a given item key.
int HashTable::hFunc( string Key )
{
    int value = 0;
    for ( int i = 0; i < Key.length(); i++ )
        value += Key[i];
    return (value * Key.length() ) % length;
}

// Adds an item to the Hash Table.
void HashTable::insert( Element * newElement )
{

  array[hFunc(newElement->key)].insert(newElement);
}

// Deletes an Element by key from the Hash Table.
// Returns true if the operation is successful.
bool HashTable::erase( string Key )
{
  return array[hFunc(Key)].remove(Key); 
}

// Returns an Element from the Hash Table by key.
// If the Element isn't found, a null pointer is returned.
Element * HashTable::get( string Key )
{
  cout << "\n\nHash Table:\n";
  for(int i=0;i<length;i++){
    cout<<"Bucket "<<i+1<<": ";
    array[i].printList();
  }
  
}

// Display the contents of the Hash Table to console window.
void HashTable::printTable()
{
    cout << "\n\nHash Table:\n";
    for ( int i = 0; i < length; i++ )
    {
        cout << "Bucket " << i + 1 << ": ";
        array[i].printList();
    }
}

// Prints a histogram illustrating the Item distribution.
void HashTable::printHistogram()
{
    cout << "\n\nHash Table Contains ";
    cout << getNumberOfElements() << " Items total\n";
    for ( int i = 0; i < length; i++ )
    {
        cout << i + 1 << ":\t";
        for ( int j = 0; j < array[i].getLength(); j++ )
            cout << " X";
        cout << "\n";
    }
}

// Returns the number of locations in the Hash Table.
int HashTable::getLength()
{
    return length;
}

// Returns the number of Items in the Hash Table.
int HashTable::getNumberOfElements()
{
    int itemCount = 0;
    for ( int i = 0; i < length; i++ )
    {
        itemCount += array[i].getLength();
    }
    return itemCount;
}

// De-allocates all memory used for the Hash Table.
HashTable::~HashTable()
{
    delete [] array;
}

//*****************************************************************
// End of File
//*****************************************************************