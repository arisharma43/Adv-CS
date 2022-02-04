//using namespace std;
#include <string.h>
#include <cstring>
#include <string>
using namespace std;

struct Airport{
    char code[5];
    double longitude;
    double latitude;


		//string toString();
	  Airport()=default;
    Airport(const char* code2, double lat, double lon) {
      //copy the code2 to code
        strcpy(code,code2);
        latitude = lat;
        longitude = lon;
    }
    // void dsp() {
    // cout << "{" << code << ", (" << latitude << ", " << longitude << ")}" << endl;
    // }
};

struct Node{
  Airport* data;
  Node* next;
};

class slist{
	public:
		Node* head;
    Node* tail;
		int length;

    
		slist();
    slist(slist* s, int i1, int i2);
    ~slist();
    void add(Airport* a);
    
    void clear();
    bool equals (slist& s);
    Node* get(int index);
    void insert(int index, Airport* a);
    void exchg(int i1, int i2);
    void swap(int i1, int i2);
    bool isEmpty();
    void remove(int index);
    void set(int index, Airport* a);
    int size();
    slist subList(int s, int e);
    string toString();
};

