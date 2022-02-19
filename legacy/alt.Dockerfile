FROM arcnor/toolchain-bittboy:steward
RUN apt-get update
RUN apt-get install -y zip
