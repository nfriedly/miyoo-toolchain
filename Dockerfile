# our local base image
FROM ubuntu 

LABEL description="Build environment for Miyoo Custom Firmware" 

# install build dependencies
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y make gcc g++ file wget cpio zip unzip rsync bc git

# Download the source
RUN git clone https://github.com/MiyooCFW/buildroot.git
WORKDIR /buildroot

# it doesn't like running as root, but meh
ARG FORCE_UNSAFE_CONFIGURE=1
# compile and "install" the toolchain
RUN make sdk && mv output/host/ /opt/bittboy-toolchain
