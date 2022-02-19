# Miyoo 1.3.3 Toolchain
Dockerfiles to build images with the toolchain and other dependencies for compiling software for the 1.3.3 release of the [Miyoo Custom Firmware (CFW)](https://github.com/TriForceX/MiyooCFW)

Miyoo 1.3.3 and older use glibc, whereas newer builds use musl libc.

See https://github.com/TriForceX/MiyooCFW/wiki/Build-Source for more info.

`legacy/steward.Dockerfile` is just `arcnor/toolchain-bittboy:steward` + a `zip` command - it works for building gmenu2x and probably other parts of MiyooCFW 1.3.3. It was published as `nfriedly/miyoo-toolchain:steward`.

`legacy/legacy.Dockerfile` uses the toolchain from the [wiki](https://github.com/TriForceX/MiyooCFW/wiki/Build-Source), but may be missing some other dependencies. It is not currently published on dockerhub.

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

Note: you'll need to [download the legacy toolchain](https://drive.google.com/file/d/1Zp6elbB3r4Hq7G7FKXNtBZMTz0H93RiY/view?usp=sharing) and extract it to the `toolchain/` folder


To build:

```sh
docker build --file legacy.Dockerfile --tag nfriedly/miyoo-toolchain:legacy .
```

Switch `legacy` to `steward` to use that version.

To publish:

```
docker push nfriedly/miyoo-toolchain:legacy
```

(Obviously you'll have to change `nfriedly` to your own docker hub username if your're not me.)
