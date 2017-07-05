#!/bin/sh
apt-get remove cmake
apt-get purge cmake

if [ -d $HOME/.cache/actor-framework ]; then
    cd $HOME/.cache/actor-framework
    make install
else
    cd $HOME/.cache
    git clone https://github.com/actor-framework/actor-framework.git
    git checkout 0.15.3
    cd actor-framework
    ./configure && make && make install
fi