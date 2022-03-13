# our local base image
FROM ubuntu 

LABEL description="Build environment for Miyoo Custom Firmware" 

# install build dependencies
# first two lines are needed just to build the toolchain
# dosfstools and u-boot-tools are needed for main boot
# finally, run some cleanup
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y make gcc g++ \
    file wget cpio zip unzip rsync bc git \
    dosfstools u-boot-tools && \
    apt-get -y autoremove && apt-get -y clean

# it doesn't like running as root, but meh
ARG FORCE_UNSAFE_CONFIGURE=1
# Download the source, compile and "install" the toolchain, cleanup
RUN git clone https://github.com/nfriedly/buildroot.git && \
    cd buildroot && \
    make sdk && \
    mv output/host/ /opt/miyoo && \
    cd .. && \
    rm -rf buildroot

# set up some env properties (these are based on Arcnor's image)
ENV CROSS_ROOT=/opt/miyoo
ENV CROSS_TRIPLE=arm-buildroot-linux-musleabi
ENV SYSROOT="${CROSS_ROOT}/$(CROSS_TRIPLE)/sysroot"
ENV PATH=":${PATH}:${CROSS_ROOT}/bin:${SYSROOT}/usr/bin"
ENV ARCH=arm
ENV CROSS_COMPILE="$(CROSS_TRIPLE)-"
