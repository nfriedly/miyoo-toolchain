# Steward's MiyooCFW Toolchain (uClibc) 
Dockerfiles to build images with the toolchain and other dependencies for compiling software for the [Miyoo Custom Firmware (CFW)](https://github.com/TriForceX/MiyooCFW). Uses the uClibc toolchain from steward. Based off of aconor's image' with some additional tools installed.

See https://github.com/TriForceX/MiyooCFW/wiki/Build-Source for more info.

## Local Usage

Requires docker - https://www.docker.com/

You have to pass in an absolute path to the source code for the first part of the `--volume` param.

```sh
docker pull nfriedly/miyoo-toolchain:steward
docker run --volume //c/users/desktop/path/to/miyoo/:/src/ -it nfriedly/miyoo-toolchain:steward
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
docker build --tag nfriedly/miyoo-toolchain:steward .
```

To publish:

```
docker push nfriedly/miyoo-toolchain:steward
```

(Obviously you'll have to change `nfriedly` to your own docker hub username if your're not me.)
