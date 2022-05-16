// Skip to content
// Search or jump to
// Pull requests
// Issues
// Marketplace
// Explore
 
// @js-aisd 
// LASA-ACP-2021
// /
// Towers-of-Hanoi
// Private
// Code
// Issues
// Pull requests
// Actions
// Projects
// Security
// Insights
// Settings
// Towers-of-Hanoi/Main.cpp
// @js-aisd
// js-aisd Create Main.cpp
// Latest commit 356ba3c yesterday
//  History
//  1 contributor
// 38 lines (31 sloc)  526 Bytes
   
#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
#include "disc.h"

using namespace std;
int moveNum=0;

static void displayTowers(Stack* t1, Stack* t2, Stack* t3) {
    cout << "T1" << ": ";
    t1->display();
    //cout<<"passed t1"<<endl;
    cout << "T2" << ": ";
    t2->display();

    cout << "T3" << ": ";
    t3->display();

}

void moveDisks(int n, Stack *from, Stack *to, Stack *spare) {
    if (n <= 0)
        return;

    moveDisks(n - 1, from, spare, to);

    moveNum++;
    printf("MOVE #%d:\n\n", moveNum);
    //printf("");

    void *temp = from->pop();
    to->push(temp); 
    
    displayTowers(from,spare,to);

    moveDisks(n - 1, spare, to, from);
}

void toh(int n)
{
    int i, x;
	  Disc* a;
	  Disc* b;
	  Stack* t1 = new Stack();
	  Stack* t2 = new Stack();
	  Stack* t3 = new Stack();
	

    for (i = n; i >= 1; i--)
    {
		  Disc* d = new Disc(i);
		  cout << d->toString()<<endl;
      t1->push(d);
      //cout<<t3->empty()<<endl;
    }

  moveDisks(n, t1, t3, t2);

  delete t1;
  delete t2;
  delete t3;
	// ****  Your Tower of Hanoi solution!


}
int main()
{
    int n;
    cout<<"enter the number of disks";
    cin>>n;
    toh(n);
    return 0;
}
// © 2022 GitHub, Inc.
// Terms
// Privacy
// Security
// Status
// Docs
// Contact GitHub
// Pricing
// API
// Training
// Blog
// About
// Loading complete
