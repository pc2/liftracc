#!/usr/bin/env python
# -*- coding: utf-8 -*-
from matplotlib import *
use('PDF')
rcParams['text.usetex']=True
rcParams['text.latex.unicode']=True
rcParams['font.family']='serif'

from numpy import *
from matplotlib.pyplot import *
from matplotlib.mlab import *
from pylab import *

calc_ticks_per_sec = 2261000000
av_ticks_per_sec   = 2268881244

row_names = ['dim', 'count', 'min_s', 'min_ns', 'min_tks', 'max_s', 'max_ns', 'max_tks', 'av_s', 'av_ns', 'av_tks']

cblas_data    = csv2rec('profiling_dgemm_cblas_std_2-2047.log', delimiter=' ', names=row_names)
atlas_data    = csv2rec('profiling_dgemm_atlas_std_2-2047.log', delimiter=' ', names=row_names)
goto2x2_data  = csv2rec('profiling_dgemm_goto2x2_std_2-2047.log', delimiter=' ', names=row_names)
goto2x16_data = csv2rec('profiling_dgemm_goto2x16_std_2-2047.log', delimiter=' ', names=row_names)
csxl_data     = csv2rec('profiling_dgemm_csxl_std_2-2047.log', delimiter=' ', names=row_names)
cublas_data   = csv2rec('profiling_dgemm_cublas_std_2-2047.log', delimiter=' ', names=row_names)

cblas_x   = cblas_data['dim']
cblas_min = [ a+(b/1000000000.0) for a,b in zip(cblas_data['min_s'], cblas_data['min_ns']) ]
cblas_max = [ a+(b/1000000000.0) for a,b in zip(cblas_data['max_s'], cblas_data['max_ns']) ]
cblas_av  = [ a+(b/1000000000.0) for a,b in zip(cblas_data['av_s'], cblas_data['av_ns']) ]
plot(cblas_x, cblas_av, '.-', ms=5, label=r'cblas', linewidth=1)

atlas_min = map(lambda a,b: a+(b/1000000000.0), atlas_data['min_s'], atlas_data['min_ns'])
atlas_max = map(lambda a,b: a+(b/1000000000.0), atlas_data['max_s'], atlas_data['max_ns'])
atlas_av  = map(lambda a,b: a+(b/1000000000.0), atlas_data['av_s'], atlas_data['av_ns'])
plot(cblas_x, atlas_av, '.-', ms=5, label=r'atlas', linewidth=1)

goto2x2_min = map(lambda a,b: a+(b/1000000000.0), goto2x2_data['min_s'], goto2x2_data['min_ns'])
goto2x2_max = map(lambda a,b: a+(b/1000000000.0), goto2x2_data['max_s'], goto2x2_data['max_ns'])
goto2x2_av  = map(lambda a,b: a+(b/1000000000.0), goto2x2_data['av_s'], goto2x2_data['av_ns'])
plot(cblas_x, goto2x2_av, '.-', ms=5, label=r'goto2 x2', linewidth=1)

goto2x16_min = map(lambda a,b: a+(b/1000000000.0), goto2x16_data['min_s'], goto2x16_data['min_ns'])
goto2x16_max = map(lambda a,b: a+(b/1000000000.0), goto2x16_data['max_s'], goto2x16_data['max_ns'])
goto2x16_av  = map(lambda a,b: a+(b/1000000000.0), goto2x16_data['av_s'], goto2x16_data['av_ns'])
plot(cblas_x, goto2x16_av, '.-', ms=5, label=r'goto2 x16', linewidth=1)

csxl_min = map(lambda a,b: a+(b/1000000000.0), csxl_data['min_s'], csxl_data['min_ns'])
csxl_max = map(lambda a,b: a+(b/1000000000.0), csxl_data['max_s'], csxl_data['max_ns'])
csxl_av  = map(lambda a,b: a+(b/1000000000.0), csxl_data['av_s'], csxl_data['av_ns'])
plot(cblas_x, csxl_av, '.-', ms=5, label=r'csxl', linewidth=1)

cublas_min = map(lambda a,b: a+(b/1000000000.0), cublas_data['min_s'], cublas_data['min_ns'])
cublas_max = map(lambda a,b: a+(b/1000000000.0), cublas_data['max_s'], cublas_data['max_ns'])
cublas_av  = map(lambda a,b: a+(b/1000000000.0), cublas_data['av_s'], cublas_data['av_ns'])
plot(cblas_x, cublas_av, '.-', ms=5, label=r'cublas', linewidth=1)

legend(loc=0)

xlabel(r'Dimension [n]', fontsize=12)
ylabel(r'Time [s]', fontsize=12)

xlim(0, 100)
ylim(0, 0.002)

title(r"BLAS Level 3 - dgemm", fontsize=12)
grid('.')

savefig('plot')

