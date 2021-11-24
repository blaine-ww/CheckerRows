# -*- coding: utf-8 -*-
"""
@author: blaine-ww

Created on Tue Nov 23 21:24:08 2021

Visualize coordinates from 'output.py'
written during main.cpp excecution

Writes new .jpg images in directory folder
"""

import os
os.sys.path
from typing import List
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

import output

exec(open('output\output.py').read()) #read output lists from output.py



def writePlot(example, name=""):
    
    plt.title(name + " Visualization")
    plt.xlabel("X coordinates")
    plt.ylabel("Y coordinates")
    plt.plot(example[0][:],example[1][:],'-o')
    
    # only save img file if name provided
    if name:
        plt.savefig("output/"+ name + ".jpg")
    
    plt.show()



# adjust ./output_name based on object names in main.cpp and output.py
writePlot(output_0, "Example_0")
writePlot(output_1, "Example_1")
writePlot(output_2, "Example_2")
writePlot(output_3, "Example_3")