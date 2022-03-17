FROM arcnor/toolchain-bittboy:steward

LABEL description="Legacy (uClibc/steward) build environment Miyoo Custom Firmware based on arcnor's image" 

# install build dependencies
# first two lines are needed just to build the toolchain
# dosfstools & u-boot-tools are for mainboot generation scripts
# python-dev & swig are needed to build uboot
# finally, run some cleanup
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y make gcc g++ \
    file wget cpio zip unzip rsync bc git \
    dosfstools u-boot-tools \
    python-dev swig && \
    apt-get -y autoremove && apt-get -y clean