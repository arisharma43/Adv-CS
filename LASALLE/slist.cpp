#include "slist.h"
#include <iostream>
#include <sstream>
using namespace std;
/*
Class Library File
*/
// Constructor

slist::slist() {
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}

slist::slist(slist *s, int i1, int i2) {
    this->head = s->get(i1);
    for(int i = i1 + 1; i < i2; i++)
        this->add(s->get(i1)->data);
    tail = get(i2 - i1 - 1);
}

// Destructor
slist::~slist(){
      Node* current = head;
      while( current != 0 ) {
        Node* next = current->next;
        delete current;
        current = next;
      }
    head = 0;
}

// add(value)				//Adds a new value to the end of this list.
void slist::add(Airport* value){
  // Node* last = this->head;

  // Node* add = new Node;   
	// add->data = value;

	// for(int i=0; i<length; i++){  
	// 	last = last->next;
	// }

	// last->next = add;

	// this->length++;
  Node *NewNode;
    NewNode=new Node;
    NewNode->data=value;
    NewNode->next=NULL;

    Node* EndNode;
    EndNode=head;

    if(EndNode == NULL)
       EndNode=NewNode;
    else
    {
        while(EndNode->next!=NULL)
            EndNode=EndNode->next;
        
        EndNode->next=NewNode;

    }
  // Node* newNode = new Node();
  //     newNode->data = value;
  //     newNode->next = NULL; 
  //     if(head == NULL) {
  //       head = newNode;
  //     } else {
  //       Node* temp = head;
  //       while(temp->next != NULL)
  //         temp = temp->next;
  //       temp->next = newNode;
  //     }    
  
}

// clear()					//Removes all elements from this list.
void slist::clear(){
	Node* current = head;
	for(int i=0; i<length; i++){ 
		Node* next = current->next;
		delete current;
		length--;
		current = next;
	}
}

// equals(list)				//Returns true if the two lists contain the same elements in the same order.

bool slist::equals(slist& list){
	Node* A = head;
	Node* B = list.head;
	
	for(int i=0; i<length; i++){
		if(A->data != B->data){
      return false;
    }

		A = A->next;
		B = B->next;
	}

	return true;
}
//get(index)				//Returns the element at the specified index in this list.
Node* slist::get(int index){
	Node* current = head;

	for(int i=0; i<length; i++){
		current = current->next;
		
		if(i == index){
			return current;
		}
	}
	cout << "Error bad input to function (get)\n	Value: " << index <<  "\n	length:" << length <<"\n";
	return NULL;
}
//insert(index, value)		//Inserts the element into this list before the specified index.
void slist::insert(int index, Airport* val){
	Node* current = head;

	for(int i=0; i<length; i++){
		current = current->next;
		
		if(i == index){
			length++;
			Node* add = new Node;
			add->data = val;
			
			add->next = current->next; 
			current->next = add;
			return;                
		}
	}
	cout << "Error bad input to function (insert)\n	Value: " << index;	
}
//exchg(index1, index2)		//Switches the payload data of specified indexex.
void slist::exchg(int index1, int index2){	
	Airport* air = get(index1)->data;
  get(index1)->data=get(index2)->data;
  get(index2)->data=air;
}
//swap(index1,index2)		//Swaps node located at index1 with node at index2
void slist::slist::swap(int index1, int index2){
    Node *n1, *n2, *p1, *p2, *t;

    if ((index1 <= 0 || index1 > this->size()) || (index2 <= 0 || index2 > this->size()))
        return;
    if (index1 == index2)
        return;

    n1 = get(index1);
    if(index1 > 0){
      p1=get(index1 - 1);
    }else{
      p1=nullptr;
    }

    if(index2>0){
      p2 = get(index2 - 1);
    }else{
      p2=nullptr;
    }
    // p1 = index1 > 0 ? get(index1 - 1) : nullptr;
    // n2 = get(index2);
    // p2 = index2 > 0 ? get(index2 - 1) : nullptr;

    if (!(n1 == nullptr || n2 == nullptr)) {
        if (p1 != nullptr){
          p1->next = n2;
        }
            
        if (p2 != nullptr){
          p2->next = n1;
        }
            
        t = n1->next;
        n1->next = n2->next;
        n2->next = t;

        if (p1 == nullptr)
            head = n2;
        else if (p2 == nullptr)
            head = n1;
    }
}

// isEmpty()				//Returns true if this list contains no elements.
bool slist::isEmpty(){
	if(length == 0){
    return true;
  }
	return false;
}
// remove(index)			//Removes the element at the specified index from this list.
void slist::remove(int index){
	Node* current = head;

	for(int i=0; i<length; i++){
		current = current->next;
		
		if(i == index){
			if(current->next != nullptr){
				current->next = current->next->next;
			}

			length--;
			delete current;

			return;
		}
	}
	cout << "Error bad input to function (remove) \n		Value: " << index;
}

// set(index, value)		//Replaces the element at the specified index in this list with a new value.
void slist::set(int index, Airport* value){
	Node* current = head;

	for(int i=0; i<length; i++){
		current = current->next;
		
		if(i == index+1){
			current->data = value;
			return;          
		}
	}
}

// size()					//Returns the number of elements in this list.
int slist::size(){
	return length;
}

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
slist slist::subList(int start, int length){
	slist* newData = new slist;

	Node* newHead = head;
	for(int i=0; i<length; i++){
		newHead = newHead->next;

		if(i == start){
			newData->head->next = newHead->next;
		}
		if(i > start && i < length){
			newData->add(newHead->data);
			remove(i);
		}
	}

	return *newData;
}


// toString()				//Converts the list to a printable string representation.
string slist::toString(){
    // if (this->length == 0)
    //       return "\n";
    // Node *current = this->head;
    // stringstream str;
    // //tried using string first but got errors with ints and string combination so using stringstream
    // int c = 1;
    // while(current!=NULL) {
    //     Airport* data = current->data;
    //     str << c << ": {" << data->code << ", (" << data->latitude << ", " << data->longitude << ")}" << endl;
    //     current = current->next;
    //     c++;
    // }
    // return str.str();
  // Node* cur = head;
	// string str = "";

	// for(int i=0; i<length; i++){
	// 	cur = cur->next;

	// 	str += cur->data->code;
  //   str += cur->data->latitude;
  //   str += cur->data->longitude;
	// }
	// return str;
  // string result = "";
  //         Node* current = head;
          
  //         while(current->next != NULL){
  //             result += current->data->code;
  //             if(current->next != NULL){
  //               result += ", ";
  //             }
  //             current = current->next;
  //         }
  //         return "List: " + result;
  //         for ( ; head; head = head->next ){
  //           cout << head->data->code << endl;
  //         }
}