# our local base image
FROM ubuntu 

LABEL description="Build environment for legacy (steward) Miyoo Custom Firmware based on Ubuntu" 

# install build dependencies
ARG DEBIAN_FRONTEND=noninteractive
# note: I think there are some other dependencies that are needed to compile everything...
RUN apt-get update && apt-get install -y g++ zip make

# Copy over the toolchain & add it to the path
ADD toolchain /opt/miyoo 
ENV PATH=$PATH:/opt/miyoobin
