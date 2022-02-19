# Miyoo Toolchain
Toolchain and dockerfile to build the [Miyoo Custom Firmware (CFW)](https://github.com/TriForceX/MiyooCFW)

See https://github.com/TriForceX/MiyooCFW/wiki/Build-Source for more info.

Currently both the "latest" and "steward" tags are actually building the legacy "steward" version, but that should change soon.

## Local Usage

Requires docker - https://www.docker.com/

You have to pass in an absolute path to the source code for the first part of the `--volume` param.
# Legacy Miyoo 1.3.3 Toolchain
Toolchain and dockerfile to build the 1.3.3 release of the  [Miyoo Custom Firmware (CFW)](https://github.com/TriForceX/MiyooCFW)

See https://github.com/TriForceX/MiyooCFW/wiki/Build-Source for more info.

Currently both the "musl" and "steward" tags are actually building the legacy "steward" version, but that should change soon.

`legacy/alt.Dockerfile` is just `arcnor/toolchain-bittboy:steward` + a `zip` command - it works for building gmenu2x and probably other parts ov MiyooCFW 1.3.3. It was published as `nfriedly/miyoo-toolchain:steward`.

`legacy/Dockerfile` uses the toolchain from the [wiki](https://github.com/TriForceX/MiyooCFW/wiki/Build-Source), but may be missing some other dependencies. It was published as `nfriedly/miyoo-toolchain:musl` (which turned out to be incorrect - that toolchain is actually the 1.3.3 one that predates the move to musl libc)

## Local Usage

Requires docker - https://www.docker.com/

You have to pass in an absolute path to the source code for the first part of the `--volume` param.

Note: you'll need to [download the legacy toolchain](https://drive.google.com/file/d/1Zp6elbB3r4Hq7G7FKXNtBZMTz0H93RiY/view?usp=sharing) and extract it to the `toolchain/` folder

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

