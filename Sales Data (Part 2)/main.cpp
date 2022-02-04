#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

class SALESREC{
  private:
    string date;
    string region;
    string rep;
    string item;
    int units;
    float unitCost;
    float total;
  public:
    void setDate(string setD){
      date=setD;
    }
    void setRegion(string setR){
      region=setR;
    }
    void setRep(string setR){
      rep=setR;
    }
    void setItem(string setI){
      item=setI;
    }
    void setUnits(int setU){
      units=setU;
    }
    void setUnitCost(float setUC){
      unitCost=setUC;
    }
    void setTotal(float setT){
      total=setT;
    }
    void setTotal(){
      total=unitCost*units;
    }
    string getDate(){
      return date;
    }
		string getRegion(){
      return region;
    }
		string getRep(){
      return rep;
    }
		string getItem(){
      return item;
    }
		int getUnits(){
      return units;
    }
		float getUnitCost(){
      return unitCost;
    }
		float getTotal(){
      return total;
    }
};


int main()
{
	ifstream data ("SalesDataPt2.csv");
  
	SALESREC CSV_World[1000];
	int CSV_WorldSize = 0;

	string line = ""; 
	bool check = true;

	while(data.good()){ 
		getline(data, line); 

		string vals[6]; 
		string currentVal = "";
		int currentValIndex = 0;
		
		
		for(int i =0; i < line.size(); i++){ 
			if(line[i] == ','){
				vals[currentValIndex] = currentVal;
				currentValIndex++;
				currentVal = ""; 
			}
			else if(!(line[i]==' ' && line[i-1]==',')) {
				currentVal += line[i];
			}
		}

    vals[currentValIndex]=currentVal;
    currentValIndex++;
    
    if(vals[0]=="1/6/2015"){
      check=false;
    }
    if(!check){
      SALESREC loopData;
      loopData.setDate(vals[0]);  
			loopData.setRegion(vals[1]);
			loopData.setRep(vals[2]);
			loopData.setItem(vals[3]);
			loopData.setUnits((int)atoi(vals[4].c_str())); 
			loopData.setUnitCost((float)atof(vals[5].c_str())); 

			loopData.setTotal();
      CSV_World[CSV_WorldSize] = loopData;
			CSV_WorldSize++;
    }
  }
  SALESREC* CSV_Pointers[1000];
	for(int i=0; i < CSV_WorldSize-1; i++){
		CSV_Pointers[i] = &CSV_World[i];
	}

	for(int i=0; i < CSV_WorldSize ; i++){ 
		for(int j=0; j < CSV_WorldSize-i-2; j++){
      //cout << CSV_Pointers[j] -> lifeExpect[10];
			if(CSV_Pointers[j] -> getTotal() < CSV_Pointers[j+1] -> getTotal()){

        std::swap(CSV_Pointers[j], CSV_Pointers[j+1]);
				// allData* store = CSV_Pointers[j];
				// CSV_Pointers[j] = CSV_Pointers[j+1];
				// CSV_Pointers[j+1] = store;
        
			}
		}
	}
  cout << "OrderDate" << ",";
		cout << "Region" << ",";
		cout << "Rep" << ",";
		cout << "Item" << ",";
		cout << "Units" << ",";
		cout << "UnitCost" << ",";
		cout << "Total" << "\n";

	for(int i=0; i < CSV_WorldSize-1; i++){
		cout << CSV_Pointers[i] -> getDate() << ",";
		cout << CSV_Pointers[i] -> getRegion() << ",";
		cout << CSV_Pointers[i] -> getRep() << ",";
		cout << CSV_Pointers[i] -> getItem() << ",";
		cout << CSV_Pointers[i] -> getUnits() << ",";
		cout  << CSV_Pointers[i] -> getUnitCost() << ",";
		cout << CSV_Pointers[i] -> getTotal() << "\n";
	}
}

