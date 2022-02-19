LABEL description="Build environment for legacy (steward) Miyoo Custom Firmware based on arcnor image" 


FROM arcnor/toolchain-bittboy:steward
RUN apt-get update
RUN apt-get install -y zip
