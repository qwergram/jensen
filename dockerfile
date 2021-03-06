FROM ubuntu:18.04

ENV DEBIAN_FRONTEND=noninteractive

# Prepare to install 3.7
RUN apt-get update --fix-missing
RUN apt-get install -y software-properties-common apt-utils
RUN add-apt-repository ppa:deadsnakes/ppa
RUN apt-get update --fix-missing

# Install the packages for python
RUN apt-get install python3.7 python3-pip python3.7-dev -y

# Download gcc
RUN apt-get install cmake gcc make g++ gdb -y

WORKDIR /home/project

CMD [ "/bin/bash" ]