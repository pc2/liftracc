#!/bin/bash

if [ ! -f cblas.tgz ]; then
    wget http://www.netlib.org/blas/blast-forum/cblas.tgz
fi

if [ -d CBLAS ]; then
    rm -Rf CBLAS
fi

tar xvzf cblas.tgz

cd CBLAS

patch -p1 < ../../common/patches/cblas_makefile.patch

# cblas_makefile_inner.patch
# cblas_makefile.patch
# cblas_rename.patch

ln -s Makefile.LINUX Makefile.in

make alllib

patch -p1 < ../../common/patches/cblas_makefile_inner.patch
patch -p1 < ../../common/patches/cblas_rename.patch

rm -f src/*.o

make alllib

