#!/bin/sh
apt-get remove cmake
apt-get purge cmake

ls $HOME
ls $HOME/.cache

if [ -d $HOME/.cache/cmake-3.8.2 ]; then
    echo -n "\n########################################"
    echo "# Using cmake from cache               #"
    echo -n "########################################\n"
    cd $HOME/.cache/cmake-3.8.2
    make install
else
    echo -n "\n########################################"
    echo "# Building cmake from source           #"
    echo -n "########################################\n"
    cd $HOME/.cache
    wget https://cmake.org/files/v3.8/cmake-3.8.2.tar.gz
    tar -zxf cmake-3.8.2.tar.gz
    cd cmake-3.8.2 && ./bootstrap && make && make install && cd ..
    rm -f cmake-3.8.2.tar.gz
fi