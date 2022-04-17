/*
Project 3- Barchart Animate
barchartanimate.h
Caleb Satvedi
CS 251 SP 2022
Description- This file is the implemenation of the barchart animate class,
which holds the array of barcharts. Thhis holds an array of barcharts, as well as
a map of colors that relate to each category. This will also be able to help with 
the animations of each frame. 
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <unistd.h>
#include "myrandom.h"  // used in autograder, do not remove
#include "barchart.h"

using namespace std;


// Constants used for bar chart animation.  You will primarily
// use these in barchartanimate.h, but you might find some useful here.


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
    int colorIndex;
 
public:
    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
        capacity = 4;
        barcharts = new BarChart[capacity];
        size = 0;
        this -> title = title;
        this -> xlabel = xlabel;
        this -> source = source;
      colorIndex = 0;
    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() {
      if (barcharts != nullptr) {
        delete [] barcharts;
      }
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    void addFrame(ifstream &file) {
      string full;
      string iter;
      getline(file, iter);
      // if line is blank, leave the function
      if (iter.size() == 0) {
        return;}
      // read in how many lines to parse through
      int numIter = 0;
      numIter = stoi(iter);
      // create temp barchart to hold bars variables
      BarChart temp(numIter);
      for (int i = 0; i < numIter; i++) {
      string tempName;
      string tempValue;
      string tempCategory;
      string tempFrame;
        // read in one line of the file
      getline(file, full);
        // use stringstream to break line up
        // put line inforamtion into correct variables
      stringstream s(full);
      getline(s, tempFrame, ',');
      string tName1;
      string tName2;
      getline(s, tName1, ',');
      getline(s, tName2, ',');
      tempName += tName1;
      getline(s, tempValue, ',');
      int tValue = 0;
      tValue = stoi(tempValue);
      getline(s, tempCategory);
        // make new bar 
      temp.addBar(tempName, tValue, tempCategory);
      temp.setFrame(tempFrame);
        // add color for category to colorMap if not already added
      if (colorMap.count(tempCategory) == 0) {
        colorMap[tempCategory] = COLORS[colorIndex];
        if (colorIndex  == 6) {
          colorIndex = 0;        }
        else
        colorIndex++;         
        }
              }
      // add temp barchart to barcharts array
       barcharts[size] = temp;
      size++;
      // allocate more space for barchart if needed
      if (size == capacity) {
      int newCapacity = capacity * 2;
      BarChart*  barcharts2 = new BarChart[newCapacity];
      for (int m = 0; m < size; m++) {
        barcharts2[m] = barcharts[m];      }
      delete [] barcharts;
      barcharts = barcharts2;
      capacity = newCapacity;
      }    }

    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000;
    if (endIter == -1) {
      endIter = size;
    }
        for (int i = 0; i < endIter; i++) {
          usleep(3 * microsecond);
          output << CLEARCONSOLE;
          output << BLACK << title << endl << source << endl;
          barcharts[i].graph(output, colorMap, top);
          output << BLACK << xlabel << endl;
          output << "Frame: " << barcharts[i].getFrame() << endl;
        }
	}

// CREATIVE COMPONENT
// The only difference is that this takes in integer faster
// faster is used here to make the frames go by quicker
	void animate(ostream &output, int top, int endIter, int faster) {
		unsigned int microsecond = 50000;
    if (endIter == -1) {
      endIter = size;
    }
        for (int i = 0; i < endIter; i++) {
          // use faster parameter to make the frames go by quicker
          usleep((3 * microsecond)/faster);
          output << CLEARCONSOLE;
          output << BLACK << title << endl << source << endl;
          barcharts[i].graph(output, colorMap, top);
          output << BLACK << xlabel << endl;
          output << "Frame: " << barcharts[i].getFrame() << endl;
        }
	}

    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize() {
        return size;
    }

    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    //
    BarChart& operator[](int i){
        if (i > size) {
          throw out_of_range("BarChartAnimate: i out of bounds");
        }
        return barcharts[i];
    }
};
