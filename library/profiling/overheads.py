#!/usr/bin/env python
# -*- coding: utf-8 -*-

import csv
from decimal import Decimal as d
from decimal import *

def d_round(d):
    return d.quantize(Decimal('.01'), rounding=ROUND_05UP)

ctks = d(2261000000)
atks = d(2268881244)

old = csv.reader(open('selector_old.log'), delimiter=' ', quotechar='#')
new = csv.reader(open('selector_new.log'), delimiter=' ', quotechar='#')

old_data = []
new_data = []

for row in old:
    if len(row) == 11: old_data.append(row)

for row in new:
    if len(row) == 11: new_data.append(row)

old_overheads_measuring_error = []
old_overheads_call_dynamic    = []
old_overheads_call_normal     = []
old_overheads_select_call     = []
old_libliftracc_liftracc_init   = []
old_libliftracc_liftracc_fini   = []

old_cblas_plugin_init      = []
old_cblas_plugin_fini      = []
old_atlas_plugin_init      = []
old_atlas_plugin_fini      = []
old_cublas_plugin_init     = []
old_cublas_plugin_fini     = []
old_clearspeed_plugin_init = []
old_clearspeed_plugin_fini = []
old_libgoto2_plugin_init   = []
old_libgoto2_plugin_fini   = []

for row in old_data:
    if row[0] == 'overheadsmeasuring_error':
        old_overheads_measuring_error.append(row[1:])
    if row[0] == 'overheadscall_dynamic':
        old_overheads_call_dynamic.append(row[1:])
    if row[0] == 'overheadscall_normal':
        old_overheads_call_normal.append(row[1:])
    if row[0] == 'overheadsselect_call':
        old_overheads_select_call.append(row[1:])
    if row[0] == 'libliftraccliftracc_init':
        old_libliftracc_liftracc_init.append(row[1:])
    if row[0] == 'libliftraccliftracc_fini':
        old_libliftracc_liftracc_fini.append(row[1:])
    
    if row[0] == 'liftracc_cblas_pluginliftracc_init':
        old_cblas_plugin_init.append(row[1:])
    if row[0] == 'liftracc_cblas_pluginliftracc_fini':
        old_cblas_plugin_fini.append(row[1:])
    if row[0] == 'liftracc_atlas_pluginliftracc_init':
        old_atlas_plugin_init.append(row[1:])
    if row[0] == 'liftracc_atlas_pluginliftracc_fini':
        old_atlas_plugin_fini.append(row[1:])
    if row[0] == 'liftracc_cublas_pluginliftracc_init':
        old_cublas_plugin_init.append(row[1:])
    if row[0] == 'liftracc_cublas_pluginliftracc_fini':
        old_cublas_plugin_fini.append(row[1:])
    if row[0] == 'liftracc_clearspeed_pluginliftracc_init':
        old_clearspeed_plugin_init.append(row[1:])
    if row[0] == 'liftracc_clearspeed_pluginliftracc_fini':
        old_clearspeed_plugin_fini.append(row[1:])
    if row[0] == 'liftracc_libgoto2_pluginliftracc_init':
        old_libgoto2_plugin_init.append(row[1:])
    if row[0] == 'liftracc_libgoto2_pluginliftracc_fini':
        old_libgoto2_plugin_fini.append(row[1:])

print 'Old selector:'
tmp_tks_ns = d(0)
c = 0
for row in old_overheads_measuring_error:
    count, min_s, min_ns, min_tks, max_s, max_ns, max_tks, av_s, av_ns, av_tks = row
    tmp_tks_ns += d(av_tks)/ctks*1000000000
    c += 1
old_overheads_measuring_error_ns = (tmp_tks_ns / d(c))
print '  Measuring error    :', d_round(old_overheads_measuring_error_ns), 'ns'

def output(title, data_list):
    tmp_tks_ns = d(0)
    c = 0
    for row in data_list:
        count, min_s, min_ns, min_tks, max_s, max_ns, max_tks, av_s, av_ns, av_tks = row
        tmp_tks_ns += d(av_tks)/ctks*1000000000
        c += 1
    value = (tmp_tks_ns / d(c)) - old_overheads_measuring_error_ns
    print title, d_round(value), 'ns'

output('  call through lib   :', old_overheads_call_dynamic)
output('  normal call        :', old_overheads_call_normal)
output('  Select call        :', old_overheads_select_call)
output('  libliftracc init    :', old_libliftracc_liftracc_init)
output('  libliftracc fini    :', old_libliftracc_liftracc_fini)
output('  cblas plugin init  :', old_cblas_plugin_init)
output('  cblas plugin fini  :', old_cblas_plugin_fini)
output('  atlas plugin init  :', old_atlas_plugin_init)
output('  atlas plugin fini  :', old_atlas_plugin_fini)
output('  cublas plugin init :', old_cublas_plugin_init)
output('  cublas plugin fini :', old_cublas_plugin_fini)
output('  csxl plugin init   :', old_clearspeed_plugin_init)
output('  csxl plugin fini   :', old_clearspeed_plugin_fini)
output('  goto2 plugin init  :', old_libgoto2_plugin_init)
output('  goto2 plugin fini  :', old_libgoto2_plugin_fini)


new_overheads_measuring_error = []
new_overheads_call_dynamic    = []
new_overheads_call_normal     = []
new_overheads_lut_init        = []
new_overheads_select_call     = []
new_libliftracc_liftracc_init   = []
new_libliftracc_liftracc_fini   = []

new_cblas_plugin_init      = []
new_cblas_plugin_fini      = []
new_atlas_plugin_init      = []
new_atlas_plugin_fini      = []
new_cublas_plugin_init     = []
new_cublas_plugin_fini     = []
new_clearspeed_plugin_init = []
new_clearspeed_plugin_fini = []
new_libgoto2_plugin_init   = []
new_libgoto2_plugin_fini   = []

for row in new_data:
    if row[0] == 'overheadsmeasuring_error':
        new_overheads_measuring_error.append(row[1:])
    if row[0] == 'overheadscall_dynamic':
        new_overheads_call_dynamic.append(row[1:])
    if row[0] == 'overheadscall_normal':
        new_overheads_call_normal.append(row[1:])
    if row[0] == 'overheadslut_init':
        new_overheads_lut_init.append(row[1:])
    if row[0] == 'overheadsselect_call':
        new_overheads_select_call.append(row[1:])
    if row[0] == 'libliftraccliftracc_init':
        new_libliftracc_liftracc_init.append(row[1:])
    if row[0] == 'libliftraccliftracc_fini':
        new_libliftracc_liftracc_fini.append(row[1:])
    
    if row[0] == 'liftracc_cblas_pluginliftracc_init':
        new_cblas_plugin_init.append(row[1:])
    if row[0] == 'liftracc_cblas_pluginliftracc_fini':
        new_cblas_plugin_fini.append(row[1:])
    if row[0] == 'liftracc_atlas_pluginliftracc_init':
        new_atlas_plugin_init.append(row[1:])
    if row[0] == 'liftracc_atlas_pluginliftracc_fini':
        new_atlas_plugin_fini.append(row[1:])
    if row[0] == 'liftracc_cublas_pluginliftracc_init':
        new_cublas_plugin_init.append(row[1:])
    if row[0] == 'liftracc_cublas_pluginliftracc_fini':
        new_cublas_plugin_fini.append(row[1:])
    if row[0] == 'liftracc_clearspeed_pluginliftracc_init':
        new_clearspeed_plugin_init.append(row[1:])
    if row[0] == 'liftracc_clearspeed_pluginliftracc_fini':
        new_clearspeed_plugin_fini.append(row[1:])
    if row[0] == 'liftracc_libgoto2_pluginliftracc_init':
        new_libgoto2_plugin_init.append(row[1:])
    if row[0] == 'liftracc_libgoto2_pluginliftracc_fini':
        new_libgoto2_plugin_fini.append(row[1:])

print 'New selector:'
tmp_tks_ns = d(0)
c = 0
for row in new_overheads_measuring_error:
    count, min_s, min_ns, min_tks, max_s, max_ns, max_tks, av_s, av_ns, av_tks = row
    tmp_tks_ns += d(av_tks)/ctks*1000000000
    c += 1
new_overheads_measuring_error_ns = (tmp_tks_ns / d(c))
print '  Measuring error    :', d_round(new_overheads_measuring_error_ns), 'ns'

def output(title, data_list):
    tmp_tks_ns = d(0)
    c = 0
    for row in data_list:
        count, min_s, min_ns, min_tks, max_s, max_ns, max_tks, av_s, av_ns, av_tks = row
        tmp_tks_ns += d(av_tks)/ctks*1000000000
        c += 1
    value = (tmp_tks_ns / d(c)) - new_overheads_measuring_error_ns
    print title, d_round(value), 'ns'

output('  call through lib   :', new_overheads_call_dynamic)
output('  normal call        :', new_overheads_call_normal)
output('  lut init           :', new_overheads_lut_init)
output('  Select call        :', new_overheads_select_call)
output('  libliftracc init    :', new_libliftracc_liftracc_init)
output('  libliftracc fini    :', new_libliftracc_liftracc_fini)
output('  cblas plugin init  :', new_cblas_plugin_init)
output('  cblas plugin fini  :', new_cblas_plugin_fini)
output('  atlas plugin init  :', new_atlas_plugin_init)
output('  atlas plugin fini  :', new_atlas_plugin_fini)
output('  cublas plugin init :', new_cublas_plugin_init)
output('  cublas plugin fini :', new_cublas_plugin_fini)
output('  csxl plugin init   :', new_clearspeed_plugin_init)
output('  csxl plugin fini   :', new_clearspeed_plugin_fini)
output('  goto2 plugin init  :', new_libgoto2_plugin_init)
output('  goto2 plugin fini  :', new_libgoto2_plugin_fini)

