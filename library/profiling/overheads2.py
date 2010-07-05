#!/usr/bin/env python
# -*- coding: utf-8 -*-

import csv
import sys
from decimal import Decimal as d
from decimal import *

def d_round(d):
    return d.quantize(Decimal('.01'), rounding=ROUND_05UP)
    
def count(list):
    return d(len(list))

def calc_mean(list):
    return d(sum(list)/count(list))

def calc_confi(val, list):
    n = count(list)
    mean = calc_mean(list)
    tmp = [ d((d(x) - mean)**2) for x in list ]
    std_abw = d(d(1/n)*sum(tmp)).sqrt() # maximum like-lihood
    std_err = d(std_abw / n.sqrt())
    return val * std_err

ctks = d(2261000000)
atks = d(2268881244)

if __name__ == "__main__":
    for file in sys.argv[1:]:
        cvs_file = csv.reader(open(file), delimiter=' ')
        data_dict = {}
        for row in cvs_file:
            name = row[0]
            list = [ d(x) for x in row[3:] ]
            if len(list) == 0:
                list = [ d(x) for x in row[2:] ]
            if name in data_dict:
                data_dict[name].extend(list)
            else:
                data_dict[name] = list
        print file.split('/')[-1]
        print "%40s %15s %20s" % ("Name","Time [ns]","Time [s]")
        for elem in data_dict.keys():
            print "%40s %15.2f %20.15f" % (elem, d_round(calc_mean(data_dict[elem])), (calc_mean(data_dict[elem])/atks))
        print
