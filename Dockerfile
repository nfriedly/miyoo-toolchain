# our local base image
FROM ubuntu 

LABEL description="Build environment for Miyoo Custom Firmware" 

# install build dependencies
# first two lines are needed just to build the toolchain
# libboost-all-dev is needed by gmenunx
# finally, run some cleanup
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y make gcc g++ \
    file wget cpio zip unzip rsync bc git \
    libboost-all-dev && \
    apt-get -y autoremove && apt-get -y clean

# it doesn't like running as root, but meh
ARG FORCE_UNSAFE_CONFIGURE=1
# Download the source, compile and "install" the toolchain, cleanup
RUN git clone https://github.com/MiyooCFW/buildroot.git && \
    cd buildroot && \
    make sdk && \
    mv output/host/ /opt/miyoo && \
    cd .. \
    rm -rf buildroot

# we need the boost libraries to be avaliable to the cross-compile toolchain
# todo: this seems like the wrong way to do this, figure out the correct method
RUN mv /usr/include/boost/ /opt/miyoo/arm-buildroot-linux-musleabi/sysroot/usr/include/