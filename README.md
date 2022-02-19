# Miyoo Toolchain
Toolchain and dockerfile to build the [Miyoo Custom Firmware (CFW)](https://github.com/TriForceX/MiyooCFW)

See https://github.com/TriForceX/MiyooCFW/wiki/Build-Source for more info.

Currently both the "latest" and "steward" tags are actually building the legacy "steward" version, but that should change soon.

## Local Usage

Requires docker - https://www.docker.com/

You have to pass in an absolute path to the source code for the first part of the `--volume` param.

```sh
docker pull nfriedly/miyoo-toolchain:musl
docker run --volume //c/users/desktop/path/to/miyoo/:/src/ -it nfriedly/miyoo-toolchain:musl
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
docker build --tag nfriedly/miyoo-toolchain:musl .
```

To publish:

```
docker push nfriedly/miyoo-toolchain:musl
```

