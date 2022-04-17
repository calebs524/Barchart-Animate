// Bar Chart Animation
//
// This application uses BarChartAnimate (which uses BarChart, which uses Bar)
// to produce an animated bar chart.
//
// Once your three class/abstraction files are completed and tested, run with
// this application to see your final creation.
//
// TO DO: Nothing for the standard application, just compile and run! However,
// before submitting you need to add your creative component.
//
// Shanon Reckinger
// U. of Illinois, Chicago
// CS 251: Fall 2021
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "barchartanimate.h"
using namespace std;

void textFileSelection(){
  cout<<"Here are the available text files:"<<endl;
  cout<<"baby-names.txt"<<endl<<"brands.txt"<<endl<<"cities-usa.txt"<<"cities.txt"<<endl<<"countries.txt"<<endl<<"endgame.txt"<<endl<<"football.txt"<<endl<<"game-of-thrones.txt"<<endl<<"infinity-war.txt"<<endl<<"movies.txt"<<endl<<"patents.txt"<<endl<<"trademarks.txt"<<endl;
}

void creativeComponenet(){
  cout<<"Welcome to the Animated Bar Chart"<<endl;
    textFileSelection();
  cout<<"Please enter the text file you want to use:"<<endl;
  string fileName;
  cin>> fileName;
  cout<<"How much faster do you want the funtion to go?"<<endl;
  cout<<"Please enter an integer: ";
  int faster=0;
  cin>>faster;
  cout<<"How many inputs do you want to see?"<<endl;
  cout<<"Please enter an integer: ";
  int numInputs=0;
  cin >> numInputs;
	ifstream inFile(fileName);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);
	
	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}
	
	bca.animate(cout, numInputs, -1, faster);
}


int main() {
	string filename = "cities.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);
	
	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}
	
	bca.animate(cout, 12, -1);
	//Creative component used in bharchartanimte.h
  	creativeComponenet();
    return 0;
  
}
