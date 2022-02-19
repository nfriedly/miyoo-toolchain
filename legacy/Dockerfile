# our local base image
FROM ubuntu 

LABEL description="Build environment for Miyoo Custom Firmware" 

# install build dependencies
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y g++ zip make

# Copy over the toolchain & add it to the path
ADD toolchain /opt/miyoo 
ENV PATH=$PATH:/opt/miyoobin
