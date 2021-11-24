# CheckerRows
Sort 2D Coordinates by Row

## Description
The cross-junctions of a checkerboard are defined as the points where four adjacent squares meet (2 black, 2 white). The cross-junctions in the image below are signified with red dots.


You are given a list of 2D coordinates, corresponding to the cross-junctions of a checkerboard. Your task is to write a function that will take the list of coordinates and return them as a row-major ordered list. Row-major order will begin at the bottom row of the checkerboard, from left to right, then the second row, left to right, and so on. An example of this order is written in blue numbers on the image. 

The input to your function is a 2xN array, where each column is the x and y coordinates of a cross-junction. The output should follow the same format.


Bonus: Write a second function that visualizes the ordered-list. The goal of the visualization is to observe that the list is in row-major order.


Note:  The checkerboard may be rotated in any direction, and the image may be distorted to any degree. The only assumption that holds is that a straight line (i.e checkerboard row) remain straight after distortion. Some additional examples of possible checkerboard shapes are listed below:


## Assumptions:
* Origin, or starting point, of the checkerboard input corodinate is lower left corner.
* Input is 2D list of positive and negative float/double/int
* Output is also 2D list, same format as input
* Distortion is a combination of roation and translation, but points on each row remain collinear



## Instructions:
0. `cd CheckerRows/`
1. `g++ -o main main.cpp`
2. `./main`
3. `python WritePlot.py`


### Sample Output

![Example 0](/output/Example_0.jpg)

![Example 1](/output/Example_1.jpg)

![Example 2](/output/Example_2.jpg)

![Example 3](/output/Example_3.jpg)


## Brief Explanation
The sort is based on whether the distorted coordinates are rotated clockwise or counterclockwise. This can be determined by the slope of the minimum vertical points. The minima is calculated after sorting the coordinates based on ascending y-coordinates. If the slope calculated is positve, the coordinates are skewed counterclockwise, store coordinates in set of ascending y-coordinates. If slope is negative, the coordinates are skewed clockwise, store coordinates in set of ascending x-coordinates. Afterwards, parse through set of coordinates and if the coordinate is are collinear, add onto resultant 2D list and add coordinates onto queue to be erased from set later. If not, skip to next coordinate. Once index has reached end of row, parsing through set, and erase all values from the set that are in the queue, such that the next parse through the set, will start at the first skipped value and so forth. This ends once the set is empty or index has exceeded length of coordinate list. 