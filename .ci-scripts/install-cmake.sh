#!/bin/sh
if [ -d $HOME/.cache/cmake-3.8.2 ]; then
    cd $HOME/.cache/cmake-3.8.2
    make install
else
    cd $HOME/.cache
    wget https://cmake.org/files/v3.8/cmake-3.8.2.tar.gz
    tar -zxf cmake-3.8.2.tar.gz
    cd cmake-3.8.2 && ./bootstrap && make && make install && cd ..
    rm -f cmake-3.8.2.tar.gz
fi