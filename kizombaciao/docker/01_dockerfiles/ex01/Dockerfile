FROM debian

ENV TS3SERVER_LICENSE=accept

WORKDIR /home/teamspeak

EXPOSE 9987/udp 10011 30033

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y wget bzip2
RUN wget http://dl.4players.de/ts/releases/3.7.1/teamspeak3-server_linux_amd64-3.7.1.tar.bz2
RUN tar -xvf teamspeak3-server_linux_amd64-3.7.1.tar.bz2

WORKDIR teamspeak3-server_linux_amd64

ENTRYPOINT sh ts3server_minimal_runscript.sh



# From a debian image you will add the appropriate sources 
# to create a TeamSpeak server, 
# that will launch along with your container. 
# It will be deemed valid 
# if at least one user can connect to it 
# and engage in a normal discussion (no far-fetched setup), 
# so be sure to create your Dockerfile with the right options. 
# Your program should get the sources when it builds, 
# they cannot be in your repository.

# ----------------------------------------------
# docker build -t ex01 .
# docker run --rm -p 9987:9987/udp -p 10011:10011 -p 30033:30033 ex01

# https://en.wikipedia.org/wiki/TeamSpeak
# https://www.lifewire.com/what-is-teamspeak-3426570
# https://forum.teamspeak.com/threads/132611-Install-teamspeak-3-server-on-Debian-8

# ENV specifies environment variables to set within the image
# The WORKDIR instruction sets the working directory 
# for any RUN, CMD, ENTRYPOINT, COPY and ADD instructions 
# that follow it in the Dockerfile.

# EXPOSE
# https://hub.docker.com/r/aheil/teamspeak3-server/
# docker run -d -p 9987:9987/udp -p 10011:10011 -p 30033:30033 --name=ts3-server aheil/teamspeak3-server
