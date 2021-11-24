//  Created by blaine-ww

/** @file CheckerRows.h */

#ifndef _CHECKER_ROWS
#define _CHECKER_ROWS

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <iterator>


using namespace std;

template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) //overload ostream operator to ease writing output file
{ 
    os << "["; 
    for (int i = 0; i < v.size(); ++i) { 
        os << v[i]; 
        if (i != v.size() - 1) 
            os << ", "; 
    } 
    os << "]\n"; 
    return os; 
} 

class CheckerBoard {
    private:
        typedef pair<double,double> p; //abbreviated for readability
        int M, N;  //row and columns
        vector<vector<double>> coordinates; // final sorted coordinates

    public:

        //Initalize CheckBoard with rows and columns
        CheckerBoard(const int rows=0, const int cols=0);
        
        // Sorts coordinates by row order depending on clockwise or counterclockwise distortion
        vector<vector<double>> arrangeRowOrder(const vector<double> x, const vector<double> y);
        vector<vector<double>> undistortClockwise(const vector<p> coord);
        vector<vector<double>> undistortCounterclockwise(const vector<p> coord);

        // Affirms input is valid
        bool checkValidCoordinates(const vector<double> x, const vector<double> y) const;

        // Prints resultant sorted coordinates
        void display();

        ~CheckerBoard();

}; // END CheckerBoard

#include "CheckerRows.cpp"
#endif