#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
#include "disc.h"
using namespace std;

Stack::Stack()
{
  pTop=new Node;
}
/*
Stack::~Stack()
{
	// delete data;
}
*/

void Stack::push(void* inData)
{
	if (pTop == nullptr)
    pTop = new Node;
  Node *temp = new Node;
  temp->data = inData;
  temp->pNext = pTop;
  pTop = temp;
}
void* Stack::pop()
{
	struct Node* temp;
  if(pTop==nullptr){
    return nullptr;
  }
  else{
    temp = pTop;
    pTop = pTop->pNext;
    temp->pNext = nullptr;
    void *result = temp->data;
    delete temp;
    return result;
  }
}

void* Stack::top()
{
  return pTop->data;
}

bool Stack::empty()
{
  return pTop==NULL;
}

void Stack::display()
{
	// //cout<<endl;
	// Node *p1;
	// p1 = pTop;
  // //cout<<"Display!"<<endl;
	// while (p1 != NULL)
	// {
  //   //cout<<"Display!"<<endl;
	// 	cout<< ((Disc*)(p1->data))->toString()<<"\t";
	// 	p1 = p1->pNext;
  //   //cout<<"Display!"<<endl;
	// }
    cout << "[";
    Node *n = pTop;
    while (n->pNext != nullptr) {
        auto* d= static_cast<Disc*>(n->data);
        cout<<d->getSize();
        n = n->pNext;
        cout << (n->pNext == nullptr ? "" : ", ");
    }
	  cout << "]" << endl;
	//cout<<"Display!"<<endl;
}

