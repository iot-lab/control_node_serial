FROM ubuntu:20.04

LABEL maintainer="alexandre.abadie@inria.fr"

ENV DEBIAN_FRONTEND noninteractive

ENV LC_ALL C.UTF-8
ENV LANG C.UTF-8

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        build-essential \
        autoconf \
        automake \
        ca-certificates \
        libtool \
        gcovr \
        git \
        gnulib \
        libpopt-dev \
        libxml2-dev \
        libxml2-utils \
        libsqlite3-dev \
        pkg-config \
        python \
        ruby \
        socat \
        texinfo \
        valgrind \
        && \
    apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

#liboml2 install
RUN mkdir /var/www && chown www-data:www-data /var/www

RUN git clone https://github.com/mytestbed/oml.git && \
    cd oml && \
    git checkout tags/v2.11.0 && \
    ./autogen.sh && \
    ./configure --disable-doc --disable-doxygen-doc --disable-doxygen-dot \ 
        --disable-android --disable-doxygen-html --disable-option-checking && \
    make && \
    make install && \
    cd .. && rm -rf oml

WORKDIR /shared

CMD ["/bin/bash"]
