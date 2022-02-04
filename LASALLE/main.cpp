// /*
//  *
//  *	Linked List lab.
//  *	- Build a library for singly linked list.
//  *	- Replace the airport array in main with a Linked List.
//  *  - sort the array. 
//  *	
//  */

#include <iostream>
#include <fstream>
#include "slist.h"
#include <cmath>
#include <istream>
#include <bits/stdc++.h>
using namespace std;


#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

//This function converts decimal degrees to radians
 double deg2rad(double deg) {
   return (deg * pi / 180);
 }

//This function converts radians to decimal degrees
 double rad2deg(double rad) {
   return (rad * 180 / pi);
 }


 /**
  * Returns the distance between two points on the Earth.
  * Direct translation from http:en.wikipedia.org/wiki/Haversine_formula
  * @param lat1d Latitude of the first point in degrees
  * @param lon1d Longitude of the first point in degrees
  * @param lat2d Latitude of the second point in degrees
  * @param lon2d Longitude of the second point in degrees
  * @return The distance between the two points in kilometers
  */
 double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
   double lat1r, lon1r, lat2r, lon2r, u, v;
   lat1r = deg2rad(lat1d);
   lon1r = deg2rad(lon1d);
   lat2r = deg2rad(lat2d);
   lon2r = deg2rad(lon2d);
   u = sin((lat2r - lat1r)/2);
   v = sin((lon2r - lon1r)/2);
   return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
 }

double distToAUS(Airport* arr) {
  // cout<<"code:"<<arr->code<<" lat:"<<arr->latitude<<" long:"<<arr->longitude;
  return distanceEarth(arr->latitude, arr->longitude, -97.66989899, 30.19449997);
}

void simpleSortTotal(slist * s) {
    // for (int i=0; i < s->size(); i++) {
    //     for (int j = i; j < s->size(); j++)
    //         if (distToAUS(s->get(i)->data) > distToAUS(s->get(j)->data))
    //             s->swap(i, j);
    // }
    int i, j, n;
    n=s->size();
    for (i = 0; i < n-1; i++)    
     
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (distToAUS(s->get(i)->data) > distToAUS(s->get(j)->data))
            s->swap(j, j+1);
}

int main() {
    ifstream infile;
    char cNum[200];
    char type[200];
    char name[200];
    auto* airportArr = new slist();

    infile.open ("airport-codes_US.csv", ifstream::in);
    auto* farApt = new Airport("TST", 30, 98);
    if (infile.is_open()) {
      //cout <<"open good, infile maybe"<<endl;

      Airport* air=new Airport();
        while (infile.good()) {
          //cout <<"open good, infile good"<<endl;
            
            
            infile.getline(air->code,256, ',');
            //cNum[0]=0;
            //cout <<"1st getline good"<<endl;
            infile.getline(type,256, ',');
            infile.getline(name,256, ',');
            infile.getline(cNum,256, ',');
            //cout <<"2nd getline good"<<endl;
            //cout<<"cNum:"<<cNum<<endl;
            air->latitude = atof(cNum);
            //cout <<"1st atof good"<<endl;
            infile.getline(cNum,256, '\n');
            //cout <<"3rd getline good"<<endl;
            air->longitude = atof(cNum);
            //cout <<"2nd atof good"<<endl;
            //air=new Airport();

            // cout<<"code:"<<air->code<<" lat:"<<air->latitude<<" long:"<<air->longitude;
            
            if (distToAUS(air)>distToAUS(farApt))
                //farApt=air;

              swap(farApt,air);
                // strcpy(air->code,farApt->code);
                // air->latitude=farApt->latitude;
                // air->longitude=farApt->longitude;
            if(distToAUS(air) <= 100.0*1.609){
              airportArr->add(air);
              //cout<<"something less than 100.0 m"<<endl;
            }
            
            cout<<airportArr->size()<<endl;
                
            //cout<<distToAUS(air)<<endl;
            //cout<<airportArr->toString();
        }
        infile.close();
    }
    else cout << "Error opening file";

    //vector<Node*> temp;



    simpleSortTotal(airportArr);
    
    
    
    // for(int i=0; i<airportArr->size(); i++){  
    //   cout << i << ": ";
    //   cout << airportArr->head->data->code<< "|";

    //   cout << airportArr->head->data->latitude;
    //   cout << airportArr->head->data->longitude;
		// }
    cout << "Airport farthest from AUS is: " << farApt->code << " at " << distToAUS(farApt) << endl;
    cout << "All airports within a 100 miles of the reference point: " << airportArr->toString()<<endl;
}
