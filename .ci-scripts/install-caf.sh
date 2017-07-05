#!/bin/sh
if [ -d $HOME/.cache/actor-framework ]; then
    echo "Using CAF from cache"
    cd $HOME/.cache/actor-framework
    make install
else
    echo "Building CAF from source"
    cd $HOME/.cache
    git clone https://github.com/actor-framework/actor-framework.git
    cd actor-framework
    git checkout 0.15.3
    ./configure && make && make install
fi