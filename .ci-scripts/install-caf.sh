#!/bin/sh
if [ -d $HOME/.cache/$CACHE_KEY/actor-framework ]; then
    echo
    echo
    echo "Using CAF from cache."
    echo
    echo
    cd $HOME/.cache/$CACHE_KEY/actor-framework
    make install
else
    echo
    echo
    echo "Building CAF from source."
    echo
    echo
    cd $HOME/.cache/$CACHE_KEY
    git clone https://github.com/actor-framework/actor-framework.git
    cd actor-framework
    git checkout 0.15.3
    ./configure --build-static
    make && make install
fi
