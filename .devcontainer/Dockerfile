# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.194.3/containers/cpp/.devcontainer/base.Dockerfile

# [Choice] Debian / Ubuntu version: debian-11, debian-10, debian-9, ubuntu-20.04, ubuntu-18.04
# ARG VARIANT="buster"
# FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}
FROM debian:latest

RUN apt-get update --no-install-recommends -y

RUN apt-get install --no-install-recommends \
    'build-essential' \
    "valgrind" \
    "gdb" \
    'automake' \
    'make' \
    'ca-certificates' \
    'g++' \
    'libtool' \
    'pkg-config' \ 
    'manpages-dev' \
    'zip' \
    'unzip' \
    'python3' \
    'python3-pip' \
    'git' \
    'openssh-server' \
    'dialog' \
    'llvm' \
    'zsh' \
    'wget' \
    'clang' \
    'nano'  \
    'systemd'   \
    'libxext-dev'   \
    'build-base'    \
    'libx11-dev'    \
    'libbsd-dev' -y \
    && apt-get clean autoclean \
    && apt-get autoremove --yes \
    && rm -rf /var/lib/{apt,dpkg,cache,log}/ 



RUN sh -c "$(wget -O- https://github.com/deluan/zsh-in-docker/releases/download/v1.1.2/zsh-in-docker.sh)" -- \
    -t robbyrussell \
    -p git 
# clone minilibx libery to your docker 
RUN git clone https://github.com/42Paris/minilibx-linux mlx 

# install and setup 
RUN	cd mlx; ./configure && \
	cp libmlx.a /usr/local/lib/ && \
	mkdir /usr/local/include && \
	cp mlx.h /usr/local/include/mlx.h

RUN python3 -m pip install --upgrade pip setuptools
RUN python3 -m pip install norminette

MAINTAINER i99dev <Obaid.altuniji@gmail.com>
