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

exec(open('output.py').read()) #read output lists from output.py


def writePlot(example, name=""):
    
    plt.title(name + " Visualization")
    plt.plot(example[0][:],example[1][:],'-o')
    
    # only save img file if name provided
    if name:
        plt.savefig(name)
    
    plt.show()

# adjust ./output_name based on object names in main.cpp and output.py
writePlot(output_0, "Example_0.jpg")
writePlot(output_1, "Example_1.jpg")
writePlot(output_2, "Example_2.jpg")
writePlot(output_3, "Example_3.jpg")