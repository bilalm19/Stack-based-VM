FROM ubuntu:18.04

ENV DEBIAN_FRONTEND=noninteractive

ARG USERNAME=vsdev
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && apt-get update \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME



USER $USERNAME
ENV DEBIAN_FRONTEND=

WORKDIR /opt

RUN sudo apt update &&\
    sudo apt install -y build-essential wget git

RUN sudo apt install -y cmake

RUN sudo apt install -y pkg-config automake autoconf libtool check

# RUN sudo wget https://github.com/libcheck/check/releases/download/0.14.0/check-0.14.0.tar.gz &&\
#     sudo tar -xvf check-0.14.0.tar.gz &&\
#     cd check-0.14.0 &&\
#     sudo ./configure &&\
#     sudo make &&\
#     sudo make check &&\
#     sudo make install