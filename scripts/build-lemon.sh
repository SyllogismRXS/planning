#!/bin/bash

if [ ! -d ../third-party-build ];
then
    mkdir ../third-party-build
fi

if [ ! -d ../third-party-build/lemon-1.3 ]; then
    echo "Downloading Lemon..."
    wget http://lemon.cs.elte.hu/pub/sources/lemon-1.3.tar.gz
    mv lemon* ../third-party-build/lemon.tar.gz
fi

pushd ../third-party-build >& /dev/null

# Extract Lemon
tar xvf lemon.tar.gz

pushd lemon* >& /dev/null

if [ ! -d build ];
then
    mkdir build
fi

pushd build

cmake ..
make $@

popd >& /dev/null # build

popd >& /dev/null # lemon

popd >& /dev/null # ../third-party-build
