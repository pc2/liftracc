#!/bin/bash

if [ ! -f GotoBLAS2-1.13.tar.gz ]; then
    wget http://www.tacc.utexas.edu/uploads/media/GotoBLAS2-1.13.tar.gz
fi

if [ -d GotoBLAS2 ]; then
    rm -Rf GotoBLAS2
fi

tar xvzf GotoBLAS2-1.13.tar.gz

cd GotoBLAS2

patch -p1 < ../../common/patches/goto2.patch

make BINARY=64 DYNAMIC_ARCH=1 USE_THREAD=1

