#!/bin/sh
if [ -d $HOME/.cache/actor-framework ]; then
    cd $HOME/.cache/actor-framework
    make install
else
    cd $HOME/.cache
    git clone https://github.com/actor-framework/actor-framework.git
    cd actor-framework
    git checkout 0.15.3
    ./configure && make && make install
fi