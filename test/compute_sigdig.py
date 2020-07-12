#!/usr/bin/python

import numpy as np
import sys
import math

def read_value(filename):
    fi = open(filename, 'r')
    return np.array([float.fromhex(line.strip()) for line in fi])

def sigdig(mean, std):
    if std == 0 and mean == 0:
        return 0
    elif std == 0:
        return 16
    elif mean == 0:
        return -math.log(abs(std), 10)
    else:
        return -math.log(abs(std/mean), 10)

def write_sd(sigd, func_name):
    func_, p = func_name.split('-')
    with open('sigd-{}-{}'.format(func_, p), "a+") as f:
        f.write("{}\n".format(str(sigd)))
  
if "__main__" == __name__:

    filename = sys.argv[1]
    func_name = sys.argv[2]
    values = read_value(filename)
    mean = np.mean(values)
    std = np.std(values)
    s = sigdig(mean, std)
    print("Values: {}".format(values))
    print("Mean: {mean}".format(mean=mean))
    print("Std: {std}".format(std=std))
    print("S: {s}".format(s=s))
    write_sd(s, func_name)
