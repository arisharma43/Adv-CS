/*
 * LaQueue
 * 
 * 
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *  
 * (c) copyright 2018, James Shockey - all rights reserved
 * 
 * */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"



/*
 * Class Priority Queue
 */

		
/*
* Insert into Priority Queue
*/
void PQueue::push(void *item, int priority)
{
  node* temp=new node;
  temp->data=item;
  temp->priority=priority;
  if(front==nullptr){
    front=temp;
  }else if(front->priority>priority){
    temp->link=front;
    front=temp;
  }else{
    // while(front->link==""&&front->link->priority>priority)
    while(front->link!=nullptr&&front->link->priority<=priority){ //use nullptr to find next nodes
      front=front->link;
      temp->link=front->link;
      front->link=temp;
    }
  }

}

/*
 * Delete from Priority Queue
 */
void* PQueue::top()
{
  if(front==nullptr){
    return nullptr; 
  }else{
    return front->data;
  }
}
/*
 * Delete from Priority Queue
 */
void PQueue::pop()
{
  if(front==nullptr){
    return;
  }else{
    std::cout<<front->data<<std::endl;
    front=front->link;
  }
}

/*
 * Print Priority Queue
 */
void PQueue::display()
{
	/* Your code here */
	node* temp=front;
  while(temp!=nullptr){
    	std::cout<<temp->priority<<" "<<(char*)temp->data<<std::endl;

  }
	/* Use the following out command for the data */
  //std::cout<<ptr->priority<<" "<<(char*)ptr->data<<std::endl;

}
	
