FROM ubuntu:18.04

WORKDIR /opt

RUN sudo apt update &&\
    sudo apt install -y build-essential wget git cmake pkg-config automake autoconf libtool check

RUN sudo wget https://github.com/libcheck/check/releases/download/0.14.0/check-0.14.0.tar.gz &&\
    sudo tar -xvf check-0.14.0.tar.gz &&\
    cd check-0.14.0 &&\
    sudo ./configure &&\
    sudo make &&\
    sudo make check &&\
    sudo make install &&\
    cd .. && sudo rm -rf check-0.14.0 && sudo rm check-0.14.0.tar.gz

WORKDIR /workspace

COPY ./src ./tests/ ./Dockerfile ./CMakeLists.txt ./

RUN mkdir build &&\
    cd build &&\
    cmake .. && make &&\
    ./tests/check
