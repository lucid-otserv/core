#!/bin/sh
apt-get remove cmake
apt-get purge cmake

if [ -d $HOME/.cache/cmake-3.8.2 ]; then
    echo
    echo
    echo "Using cmake from cache."
    echo
    echo
    cd $HOME/.cache/cmake-3.8.2
    make install
else
    echo
    echo
    echo "Building cmake from source."
    echo
    echo
    cd $HOME/.cache
    wget https://cmake.org/files/v3.8/cmake-3.8.2.tar.gz
    tar -zxf cmake-3.8.2.tar.gz
    cd cmake-3.8.2 && ./bootstrap && make && make install && cd ..
    rm -f cmake-3.8.2.tar.gz
fi