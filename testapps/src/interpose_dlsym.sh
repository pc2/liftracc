#!/bin/bash

export LD_LIBRARY_PATH="/home-e/niekma/diplomarbeit/sourcecode/test_app/build"
export LD_PRELOAD=libtestlib_interposer.so
exec ./test_app_sym -v -c 41

