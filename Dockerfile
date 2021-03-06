FROM ubuntu:18.04

WORKDIR /opt

RUN apt update &&\
    apt install -y build-essential wget git cmake pkg-config automake autoconf libtool check

RUN wget https://github.com/libcheck/check/releases/download/0.14.0/check-0.14.0.tar.gz &&\
    tar -xvf check-0.14.0.tar.gz &&\
    cd check-0.14.0 &&\
    ./configure &&\
    make &&\
    make check &&\
    make install &&\
    cd .. && rm -rf check-0.14.0 && rm check-0.14.0.tar.gz

WORKDIR /workspace

COPY . ./

RUN ls -a && mkdir build &&\
    cd build &&\
    cmake .. && make &&\
    ./tests/check

RUN mv ./build/src/app . &&\
    rm -rf build src tests CMakeLists.txt

ENTRYPOINT ["bash", "run_app.sh"]
