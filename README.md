# Miyoo Toolchain Docker
Dockerfile to build an image with the toolchain and other dependencies necessary to build software for [Miyoo Custom Firmware (CFW)](https://github.com/TriForceX/MiyooCFW)

See https://github.com/TriForceX/MiyooCFW/wiki/Build-Source for more info.

WORK IN PROGRESS: Currently both the "musl" and "steward" tags are actually builds of the legacy "steward" version, but that should change soon.

## Local Usage

Requires docker - https://www.docker.com/

You have to pass in an absolute path to the source code for the first part of the `--volume` param.

```sh
docker pull nfriedly/miyoo-toolchain:musl
docker run --volume //c/users/desktop/path/to/miyoo/:/src/ -it nfriedly/miyoo-toolchain:latest
# starting here, commands are executed inside the docker image
cd /src
make
exit
# now back to your computer
```

## GitHub Actions Usage

See this example: https://github.com/MiyooCFW/gmenunx/pull/6/files

## Development 

First make sure you have the buildroot code. Either clone with `git clone --recurse-submodules https://github.com/nfriedly/miyoo-toolchain.git` if you haven't already cloned the repo or else run `git submodule init` if you have. 

To build:

```sh
docker build --tag nfriedly/miyoo-toolchain:latest .
```

To publish:

```
docker push nfriedly/miyoo-toolchain:latest
```

