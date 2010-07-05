#!/bin/bash

export LD_PRELOAD=libtestlib_interposer.so
exec ./test_app -v -c 41

