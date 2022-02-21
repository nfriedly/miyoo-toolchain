# our local base image
FROM ubuntu 

LABEL description="Build environment for Miyoo Custom Firmware" 

# install build dependencies
# first two lines are needed just to build the toolchain
# libboost-all-dev is needed by gmenunx
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y make gcc g++ \
    file wget cpio zip unzip rsync bc git \
    libboost-all-dev

# Download the source
# todo: download, compile, delete all in one to reduce the size of the resulting image
RUN git clone https://github.com/MiyooCFW/buildroot.git
WORKDIR /buildroot

# it doesn't like running as root, but meh
ARG FORCE_UNSAFE_CONFIGURE=1
# compile and "install" the toolchain
RUN make sdk && mv output/host/ /opt/miyoo

# we need the boost libraries to be avaliable to the cross-compile toolchain
# todo: this seems like the wrong way to do this, figure out the correct method
RUN mv /usr/include/boost/ /opt/miyoo/arm-buildroot-linux-musleabi/sysroot/usr/include/