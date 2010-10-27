#!/bin/bash

if [ ! -f atlas3.9.23.tar.bz2 ]; then
    wget http://downloads.sourceforge.net/project/math-atlas/Developer%20%28unstable%29/3.9.23/atlas3.9.23.tar.bz2
fi

if [ -d ATLAS ]; then
    rm -Rf ATLAS
fi

tar xvjf atlas3.9.23.tar.bz2

cd ATLAS

mkdir build
mkdir install

DIR=$(pwd)

cd build

../configure --shared --cflags='-fPIC' -Fa alg -fPIC --prefix=$DIR/install -b 64 -D c -DPentiumCPS=2400 -Si cputhrchk 0
make build
make check
make time

cd lib
make cshared

