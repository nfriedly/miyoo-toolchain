# Miyoo Toolchain Docker
Dockerfile to build an image with the toolchain and other dependencies necessary to build software for [Miyoo Custom Firmware (CFW)](https://github.com/TriForceX/MiyooCFW)

See https://github.com/TriForceX/MiyooCFW/wiki/Build-Source for more info.

Docker Hub: https://hub.docker.com/r/nfriedly/miyoo-toolchain

The `:latest` tag contains a musl libc-based toolchain, and should be used for Miyoo 1.4+.

The `:steward` tag uses the older uClibc toolchain and should be used for Miyoo 1.3.3 and older.

## Local Usage

Requires docker - https://www.docker.com/

You have to pass in an absolute path to the source code for the first part of the `--volume` param.

```sh
docker pull nfriedly/miyoo-toolchain:latest
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

To build:

```sh
docker build --tag nfriedly/miyoo-toolchain .
```

To publish:

```
docker push nfriedly/miyoo-toolchain:latest
```

