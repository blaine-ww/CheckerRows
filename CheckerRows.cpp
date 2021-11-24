//  Created by blaine-ww

/** A class of CheckBoard coordinates
 @file CheckerRows.cpp */

#include "CheckerRows.h"


/** Constructor */
CheckerBoard::CheckerBoard(int rows, int cols)
{
    M=rows, N=cols;
    coordinates.resize(2,vector<double>(N*M));
} //END constructor



/** @param x: List of x coordinates
  * @param y: List of y coordinates
  * @return vector<vector<double>>: Sorted by row ordered coordinates
  */
vector<vector<double>> CheckerBoard::arrangeRowOrder(const vector<double> x, const vector<double> y)
{

    if (!checkValidCoordinates(x,y)) //check for invalid coodinates
        return coordinates;
    
    vector<p> CC_coord, C_coord; //to store counterclockwise and/or clockwise sorted coordinates

    for (int i=0; i<x.size(); i++)
    {
        C_coord.push_back({x[i],y[i]});
        CC_coord.push_back({y[i],x[i]});
    }

    sort(C_coord.begin(),C_coord.end());  //sort based on ascending x-values
    sort(CC_coord.begin(),CC_coord.end()); //sort based on ascending y-values

    double y0 = CC_coord[0].first, y1  = CC_coord[1].first;
    double x0 = CC_coord[0].second, x1 = CC_coord[1].second;

    double slope = (y1-y0)/ (x1-x0); 

    //determine whether slope is (+) or (-)
    // (+): counterclockwise distortion
    // (-): clockwise distortion 
    return (slope>0) ? undistortCounterclockwise(CC_coord) : undistortClockwise(C_coord);
} //END arrangeRowOrder



/** @param coord: List of coordinates sorted by ascending x-values
  * @return vector<vector<double>>: Sorted by row ordered coordinates
  */
vector<vector<double>> CheckerBoard::undistortClockwise(const vector<p> coord)
{

    set<p> cset(coord.begin(),coord.end());

    queue<p> q; //coordinates to delete from set after storing in resultant vector

    double prev_x = coord[0].first, prev_y = coord[0].second; //this will be the leftmost coordinate

    for (int i=0; i<N*M && !cset.empty();)
    {
        for (auto it:cset)
        {
            double x = it.first, y = it.second;

            if ((y<=prev_y) || cset.empty())
            {
                coordinates[0][i]=x;
                coordinates[1][i]=y;
                prev_x=x, prev_y=y;
                q.push({x,y});
                ++i;
            } //end if


            if (i%M==0) //reached end of row
            { 
                break;
            } //end if

        }//end for
        
        while (!q.empty()) // erase previous coordinates
        {
            cset.erase({q.front().first, q.front().second}); q.pop();
        } //end while

        prev_x=cset.begin()->first;  //reset to value at start of set
        prev_y=cset.begin()->second;
        
    } //end for

    return coordinates;// return new_coords;
} //END undistortClockwise



/** @param coord: List of coordinates sorted by ascending y-values
  * @return vector<vector<double>>: Sorted by row ordered coordinates
  */
 vector<vector<double>> CheckerBoard::undistortCounterclockwise(const vector<p> coord)
 {

    set<p> cset(coord.begin(),coord.end());

    queue<p> q; //coordinates to delete from set after storing in resultant vector

    double prev_x = coord[0].second, prev_y = coord[0].first; //this will be the lowest coordinate

    for (int i=0; i<N*M && !cset.empty();)
    {
        for (auto it:cset)
        {

            double x = it.second, y = it.first;

            if ((x>=prev_x) || cset.empty())
            {
                coordinates[0][i]=x;
                coordinates[1][i]=y;
                prev_x=x, prev_y=y;
                q.push({y,x});
                ++i;
            } //end if

            if (i%M==0) //reached end of row
            {     
                break;
            } //end if
        }

        while (!q.empty()) // erase previous coordinates
        {
            cset.erase({q.front().first, q.front().second}); q.pop();
        } //end while

        prev_x=cset.begin()->second; //reset to value at start of set
        prev_y=cset.begin()->first;
        
    } //end for

    return coordinates;
} //END undistortCounterclockwise



/** @param x: List of x coordinates
  * @param y: List of y coordinates
  * @return bool: True if valid coordinates, False otherwise
  */
bool CheckerBoard::checkValidCoordinates(vector<double> x, vector<double> y) const
{
    if (x.empty() || y.empty())
    {
        cout << "X or Y list is empty.\n";
        return false;
    }

    if (x.size()!=y.size())
    {
        cout << "X and Y list must be same length.\n";
        return false;
    }

    else if (x.size()!=M*N)
    {
        cout << "List must be same size as intialized rows and cols of CheckBoard.\n";
        return false;   
    }

    return true;
} //END checkValidCoordinates



/** @paran void
 *  @return void
  */
void CheckerBoard::display()
{
    for (int i=0; i<N*M; ++i)
    {
            cout << "("<< coordinates[0][i]<< ", " << coordinates[1][i] << ")\t\t";

        if ((i+1)%M==0)
            cout << "\n";
    }

    cout <<"\n\n";
} //END display



/** Destructor */
CheckerBoard::~CheckerBoard()
{

} //END destructor







