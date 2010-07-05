#!/usr/bin/env python
# -*- coding: utf-8 -*-

from matplotlib import *
use('PDF')
rcParams['text.usetex']=True
rcParams['text.latex.unicode']=True
rcParams['font.family']='serif'

import csv
import sys
import numpy as npy
import matplotlib.pyplot as plt
import matplotlib.mlab as mlab
import pylab
from math import sqrt
from decimal import Decimal as d

class tps:
    calc = d(2261000000)
    av   = d(2268881244)

class DataClass:
    def __init__(self):
        self.label     = r'no\_label'
        self.sym       = '-'
        self.xrange    = []
        self.data_tks  = []
        self.mean_tks  = []
        self.confi_tks = []
        self.data_sec  = []
        self.mean_sec  = []
        self.confi_sec = []

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

def read_data(file_name, conv_sec, sym=None, label=None):
    print "Prozessing", file_name
    csv_file = csv.reader(open(file_name), delimiter=' ')
    dc = DataClass()
    if sym: dc.sym=sym
    if label: dc.label=label
    av_error = 0
    for row in csv_file:
        if row[0].find("measuring_error") > -1:
            num_row = [ d(x) for x in row[3:] ]
            av_error = calc_mean(num_row)
            av_confi = calc_confi(d("1.96"), num_row)
            #print "Average Error:", av_error, "(", av_error-av_confi, ",", av_error+av_confi, ")"
            break
    for row in csv_file:
        if row[0].find("measuring_error") == -1:
            num_row = [ d(x) for x in row ]
            num_row[3:] = [ d(x-av_error) for x in num_row[3:]]
            num_row_sec = [ d((x-av_error)/d(conv_sec)) for x in num_row[3:]]
            dc.xrange.append(2**num_row[0])
            dc.data_tks.append(num_row[3:])
            dc.mean_tks.append(calc_mean(num_row[3:]))
            dc.confi_tks.append(calc_confi(d("1.96"), num_row[3:]))
            dc.data_sec.append(num_row_sec)
            dc.mean_sec.append(calc_mean(num_row_sec))
            dc.confi_sec.append(calc_confi(d("1.96"), num_row_sec))
    return dc

def plot_graph(filename, data, title, x_label, y_label, x_lim=None, y_lim=None):
    print "Plotting to", filename
    pylab.figure()
    for d in data:
        #pylab.plot(d.xrange, ret, d.sym, ms=5, label=d.label, linewidth=1)
        pylab.errorbar(d.xrange, d.mean_sec, d.confi_sec, label=d.label, xerr=None,
                       fmt=d.sym, elinewidth=3, ms=5, capsize=6) 
    pylab.legend(loc=0)

    pylab.xlabel(x_label, fontsize=12)
    pylab.ylabel(y_label, fontsize=12)

    pylab.xscale('log', basex=2)
    pylab.yscale('log', basey=10)

    if x_lim: pylab.xlim(x_lim)
    if y_lim: pylab.ylim(y_lim)

    pylab.title(title, fontsize=12)
    pylab.grid('.')
    pylab.savefig(filename)

if __name__ == "__main__":
    cblas_dgemm = read_data('tks_cblas_dgemm_result.log', tps.av, sym='-o', label=r'cblas')
    atlas_dgemm = read_data('tks_atlas_dgemm_result.log', tps.av, sym='->', label=r'atlas')
    clear_dgemm = read_data('tks_clear_dgemm_result.log', tps.av, sym='-s', label=r'csxl')
    cubla_dgemm = read_data('tks_cubla_dgemm_result.log', tps.av, sym='-D', label=r'cublas')
    gotx2_dgemm = read_data('tks_goto2_dgemm_resultx2.log', tps.av, sym='-v', label=r'goto2 x2')
    gox16_dgemm = read_data('tks_goto2_dgemm_resultx16.log', tps.av, sym='-^', label=r'goto2 x16')

    plot_graph('dgemm_log_scale',
               [cblas_dgemm, atlas_dgemm, clear_dgemm, cubla_dgemm, gotx2_dgemm, gox16_dgemm],
               r'Blas Level 3 - dgemm',
               r'Dimension [n]', 
               r'Time [s]', x_lim=(4,2**8), y_lim=(10**-6,10**-1)

    )
    
    cblas_ddot = read_data('tks_cblas_ddot_result.log', tps.av, sym='-o', label=r'cblas')
    atlas_ddot = read_data('tks_atlas_ddot_result.log', tps.av, sym='->', label=r'atlas')
    cubla_ddot = read_data('tks_cubla_ddot_result.log', tps.av, sym='-D', label=r'cublas')
    gotx2_ddot = read_data('tks_goto2_ddot_resultx2.log', tps.av, sym='-v', label=r'goto2 x2')
    gox16_ddot = read_data('tks_goto2_ddot_resultx16.log', tps.av, sym='-^', label=r'goto2 x16')

    plot_graph('ddot_log_scale',
               [cblas_ddot, atlas_ddot, cubla_ddot, gotx2_ddot, gox16_ddot],
               r'Blas Level 1 - ddot',
               r'Dimension [n]',
               r'Time [s]', x_lim=(1,2**26)
    )

    cblas_daxpy = read_data('tks_cblas_daxpy_result.log', tps.av, sym='-o', label=r'cblas')
    atlas_daxpy = read_data('tks_atlas_daxpy_result.log', tps.av, sym='->', label=r'atlas')
    cubla_daxpy = read_data('tks_cubla_daxpy_result.log', tps.av, sym='-D', label=r'cublas')
    gotx2_daxpy = read_data('tks_goto2_daxpy_resultx2.log', tps.av, sym='-v', label=r'goto2 x2')
    gox16_daxpy = read_data('tks_goto2_daxpy_resultx16.log', tps.av, sym='-^', label=r'goto2 x16')

    plot_graph('daxpy_log_scale',
               [cblas_daxpy, atlas_daxpy, cubla_daxpy, gotx2_daxpy, gox16_daxpy],
               r'Blas Level 1 - daxpy',
               r'Dimension [n]',
               r'Time [s]', x_lim=(1,2**26)
    )

