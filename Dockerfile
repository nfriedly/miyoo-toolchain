# our local base image
FROM ubuntu 

LABEL description="Build environment for Miyoo Custom Firmware" 

WORKDIR /src
copy buildroot .
COPY build-toolchain.sh .
RUN chmod +x build-toolchain.sh && ./build-toolchain.sh