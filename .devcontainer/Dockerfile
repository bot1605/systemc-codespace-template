FROM ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive

RUN apt update && apt install -y build-essential wget tar git ca-certificates

# If you want to auto-build SystemC during image build, set SYSTEMC_URL as a build ARG
ARG SYSTEMC_URL="PUT_SYSTEMC_TARBALL_URL_HERE"

WORKDIR /tmp
RUN if [ "$SYSTEMC_URL" != "PUT_SYSTEMC_TARBALL_URL_HERE" ]; then \
      wget "$SYSTEMC_URL" -O systemc.tar.gz && \
      tar -xzf systemc.tar.gz && \
      cd systemc-* && mkdir build && cd build && ../configure --prefix=/usr/local/systemc && \
      make -j$(nproc) && make install ; \
    else \
      echo "No SystemC URL provided; you can build SystemC manually inside the Codespace."; \
    fi

ENV SYSTEMC_HOME=/usr/local/systemc
ENV LD_LIBRARY_PATH=$SYSTEMC_HOME/lib-linux64:$LD_LIBRARY_PATH
ENV CPLUS_INCLUDE_PATH=$SYSTEMC_HOME/include:$CPLUS_INCLUDE_PATH

WORKDIR /workspaces/${GITHUB_REPOSITORY##*/}

