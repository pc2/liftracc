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

cblas_data    = csv2rec('profiling_ddot_cblas_std_2-16383.log', delimiter=' ', names=row_names)
atlas_data    = csv2rec('profiling_ddot_atlas_std_2-16383.log', delimiter=' ', names=row_names)
goto2_data    = csv2rec('profiling_ddot_goto2_std_2-16383.log', delimiter=' ', names=row_names)
cublas_data   = csv2rec('profiling_ddot_cublas_std_2-16383.log', delimiter=' ', names=row_names)

cblas_x   = cblas_data['dim']
cblas_min = [ a+(b/1000000000.0) for a,b in zip(cblas_data['min_s'], cblas_data['min_ns']) ]
cblas_max = [ a+(b/1000000000.0) for a,b in zip(cblas_data['max_s'], cblas_data['max_ns']) ]
cblas_av  = [ a+(b/1000000000.0) for a,b in zip(cblas_data['av_s'], cblas_data['av_ns']) ]
plot(cblas_x, cblas_av, '-', ms=5, label=r'cblas', linewidth=1)

atlas_min = [ a+(b/1000000000.0) for a,b in zip(atlas_data['min_s'], atlas_data['min_ns']) ]
atlas_max = [ a+(b/1000000000.0) for a,b in zip(atlas_data['max_s'], atlas_data['max_ns']) ]
atlas_av  = [ a+(b/1000000000.0) for a,b in zip(atlas_data['av_s'], atlas_data['av_ns']) ]
plot(cblas_x, atlas_av, '-', ms=5, label=r'atlas', linewidth=1)

goto2_min = [ a+(b/1000000000.0) for a,b in zip(goto2_data['min_s'], goto2_data['min_ns']) ]
goto2_max = [ a+(b/1000000000.0) for a,b in zip(goto2_data['max_s'], goto2_data['max_ns']) ]
goto2_av  = [ a+(b/1000000000.0) for a,b in zip(goto2_data['av_s'], goto2_data['av_ns']) ]
plot(cblas_x, goto2_av, '-', ms=5, label=r'goto2', linewidth=1)

cublas_min = [ a+(b/1000000000.0) for a,b in zip(cublas_data['min_s'], cublas_data['min_ns']) ]
cublas_max = [ a+(b/1000000000.0) for a,b in zip(cublas_data['max_s'], cublas_data['max_ns']) ]
cublas_av  = [ a+(b/1000000000.0) for a,b in zip(cublas_data['av_s'], cublas_data['av_ns']) ]
plot(cblas_x, cublas_av, '-', ms=5, label=r'cublas', linewidth=1)

legend(loc=0)

xlabel(r'Dimension [n]', fontsize=12)
ylabel(r'Time [s]', fontsize=12)

xlim(0, 16500)
ylim(0, 0.0005)

title(r"BLAS Level 1 - ddot", fontsize=12)
grid('.')

savefig('plot')

