#!/bin/sh

# install dependencies
export DEBIAN_FRONTEND=noninteractive
apt-get update
apt-get install -y g++ zip make

# grab the source