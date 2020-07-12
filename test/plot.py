#!/usr/bin/python

import sys
import matplotlib.pyplot as plt
import numpy as np

def read_values(file_):
    with open(file_, 'r') as f:
        x = []
        for line in f.readlines():
            x.append(float(line))
        return x

if '__main__' == __name__:
    points = sys.argv[1]
    #sigd_log_16 = sys.argv[2]
    #sigd_log_23 = sys.argv[3]
    sigd_cosf_53 = sys.argv[2]
    
    #sigd_tanf_53 = sys.argv[3]
    #sigd_sin_23 = sys.argv[6]
    sigd_sinf_53 = sys.argv[3]
    x = read_values(points)
    #y_log_16 = read_values(sigd_log_16)
    #y_log_23 = read_values(sigd_log_23)
    y_cosf_53 = read_values(sigd_cosf_53)
    #y_sin_16 = read_values(sigd_sin_16)
    #y_tanf_53 = read_values(sigd_tanf_53)
    y_sinf_53 = read_values(sigd_sinf_53)

    #plt.plot(x, y_log_16, '.', label='log-p16')
    #plt.plot(x, y_log_23, '.', label='log-p23')
    plt.plot(x, y_cosf_53, '.', label='cosf-mca')
    #plt.plot(x, y_sin_16, '_', label='sinf-p16')
    #plt.plot(x, y_tanf_53, '_', label='tanf-p53')
    plt.plot(x, y_sinf_53, '.', alpha=.8, label='sinf-mca')

    #plt.xticks(np.arange(min(x), max(x)+1, 10))
    #plt.xticks(np.arange(-100, 100, step=20))
    #plt.yticks(np.arange(-20, 20, step=5))
    plt.legend(loc='center right')
    plt.xlabel("Input points")
    plt.ylabel("Number of significant digits")
    #plt.title('Accuracy of fuzzy OpenLibm (mode RR)')
    plt.savefig('sinfcosf-wrapper-mca.pdf', bbox_inches='tight')

