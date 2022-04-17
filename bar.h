/*
Project 3- Barchart Animate
bar.h
Caleb Satvedi
CS 251 Sp 2022
Description- This file is the implemenation of the Bar class, which holds primitive
data types. This file contains how to add and retrives properties of a single bar,
as well as comparison functions-(overloaded operators).
*/

#include <iostream>
#include <string>
#include "myrandom.h" 
using namespace std;

//
// Bar
//
class Bar {
 private:
   string name;
   int value;
   string category;
    // Private member variables for a Bar object
    // TO DO:  Define private member variables for this class
    // NOTE: You should not be allocating memory on the heap for this class.

 public:
    // default constructor:
    // Initalize all Private Instance variables to default values
    Bar() {
        name = "";
        category = "";
        value = 0;
    }

    //
    // a second constructor:
    //
    // Parameter passed in constructor Bar object.
    //
    //Set all Private Instance Variables to default variables
    Bar(string name, int value, string category) {
        this -> name = name;
        this-> value = value;
        this -> category = category;
    }

    // destructor: Not needed
    virtual ~Bar() {
    }

    // getName: Return name private instance variable
	string getName() {
        return name;  
	}

    // getValue: Return Value private instance variable
	int getValue() {
        return value;
    }

    // getCategory: Return category private instance variable
	string getCategory() {
        return category;
	}

	// operators
    // Return whether the current bar object's value is greater than the other
    // bar objects value
	bool operator<(const Bar &other) const {
        return this-> value < other.value;
	}

    // Return whether the current bar object's value is greater than or equal to the other
    // bar objects value
	bool operator<=(const Bar &other) const {
        return this-> value <= other.value;
	}

    // Return whether the current bar object's value is less than the other
    // bar objects value
	bool operator>(const Bar &other) const {
        return this-> value > other.value;
	}

    // Return whether the current bar object's value is less than  or equal to the other
    // bar objects value
	bool operator>=(const Bar &other) const {
    return this-> value >= other.value;
	}
};

