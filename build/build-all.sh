#!/bin/bash

if [[ "$#" -lt 1 ]]; then
	echo "Usage:   ./build-all.sh <path-to-qt-cmake>"
	echo "Example: ./build-all.sh ~/Qt5.5.0/5.5/gcc_64/lib/cmake/"
	exit 1
fi

cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PREFIX_PATH=$1

make -j4
