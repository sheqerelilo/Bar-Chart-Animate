// barchartanimate.h
// TO DO:  add header comment here.  Also add function header comments below.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used by graders, do not remove
#include "barchart.h"
  
using namespace std;

//
// BarChartAnimate
//
class BarChartAnimate {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    //
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    map<string, string> colorMap;
    string title;
    string xlabel;
    string source;
    unsigned int colorIndex = 0;

 //Helper function for Add Frame
 void AddFrameHelper(BarChart &bc, ifstream &file, int num, string frame){
   string name, tempval, category, country;
   int value;
   while (num > 0){
     getline(file, frame, ',');
     bc.setFrame(frame);

     getline(file, name, ',');
     getline(file, country, ',');
     getline(file, tempval, ',');
     getline(file, category);

     value = stoi(tempval);
     bc.addBar(name, value, category);
     if(colorIndex >= COLORS.size()){
       colorIndex = 0;
     }
     if(colorMap.count(category) == 0){
       colorMap.emplace(category, COLORS[colorIndex]);
       colorIndex++;
     }
     num--;
   }
 }

 public:

    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
      barcharts = new BarChart[4];
      capacity = 4;
      size = 0;
      this->title = title;
      this->xlabel = xlabel;
      this->source = source;
        
    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() {
      delete [] barcharts;
        
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    void addFrame(ifstream &file) {
      if(size == capacity){
        int newcap = capacity * 2;
        BarChart * newbc = new BarChart[newcap];
        for(int i =0; i < capacity; i++){
          newbc[i] = this->barcharts[i];
        }
        delete [] this->barcharts;
        this->barcharts = newbc;
        capacity = newcap;
      }
      int num = 0;
      string frame;

      getline(file, frame);
      file >> num;
      if(num == 0){
        return;
      }
      BarChart bc(num);
      AddFrameHelper(bc, file, num, frame);
      barcharts[size] = bc;
      size++;
    }

    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000;
    //int counter = 1; 
    int sz;
    if(endIter == -1){
      sz = size;
    }
    else{
      sz = endIter;
    }
    for(int i = 0; i < sz; i++){
      usleep(3 * microsecond);
      output << CLEARCONSOLE;
      output << BLACK << title << endl << BLACK << source << endl;
      barcharts[i].graph(output, colorMap, top);
      output << BLACK << xlabel << endl << BLACK << "Frame: " << barcharts[i].getFrame() << endl;
    }
}

 //Creative Component
void animate(ostream &output, int top, int endIter, int tme, int frameP, int tmeP){  
  int sz;
  if(endIter == -1){
    sz = size;
  }
  else{
    sz = endIter;
  }
  int counter = 1;

  for(int i = 0; i < sz; i++){
    usleep(tme);
    output << CLEARCONSOLE;
    output << BLACK << title << endl << BLACK << source << endl;
    barcharts[i].graph(output, colorMap, top);
    output << BLACK << xlabel << endl << BLACK << "Frame: " << barcharts[i].getFrame() << endl;
    if (counter == frameP) {
      cout << "Frame Paused for " << tmeP << " seconds" << endl;
      usleep(1000000 * tmeP);
    }
    counter ++;
  }
}

    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize(){
        
        return size;  // TO DO:  update this, it is only here so code compiles.
        
    }

    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    //
    BarChart& operator[](int i){
       if(i >= size || i < 0){
         throw out_of_range("BarChartAnimate: i out of bonds");
       }
        
        return barcharts[i]; // TO DO:  update this, it is only here so code compiles.
    }
};
