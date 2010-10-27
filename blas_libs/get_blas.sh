#!/bin/bash

if [ ! -f blas.tgz ]; then
    wget http://www.netlib.org/blas/blas.tgz
fi

if [ -d BLAS ]; then
    rm -Rf BLAS
fi

tar xvzf blas.tgz

cd BLAS

patch -p1 < ../../common/patches/blas.patch

make

