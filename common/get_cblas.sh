#!/bin/bash

if [ ! -f cblas.tgz ]; then
    wget http://www.netlib.org/blas/blast-forum/cblas.tgz
fi

if [ -d CBLAS ]; then
    rm -Rf CBLAS
fi

tar xvzf cblas.tgz

cd CBLAS

patch -p1 < ../patches/cblas_complete.patch

ln -s Makefile.LINUX Makefile.in

make alllib

