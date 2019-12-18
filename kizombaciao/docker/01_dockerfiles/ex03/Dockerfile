FROM ubuntu:16.04

RUN apt-get update -q \
    && DEBIAN_FRONTEND=noninteractive apt-get install -yq --no-install-recommends \
      ca-certificates \
      openssh-server \
      curl \
      postfix

WORKDIR /
RUN curl -LO https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh

RUN bash script.deb.sh

RUN apt-get update && EXTERNAL_URL="http://gitlab.example.com" apt-get install -yq gitlab-ce

RUN apt update && apt install -y tzdata && \
  apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

EXPOSE 22 80

ADD https://gist.githubusercontent.com/rizkyario/bc236974f3b0c9ce60cdb722bf12a702/raw/634df1395ab9c4187250b81d1c4a38e7e0934779/gitlab-entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

CMD [ "bash", "/entrypoint.sh" ]

# Docker can be useful to test an application 
# that’s still being developed without polluting your libraries. 
# You will have to design a Dockerfile 
# that gets the development version of Gitlab - Community Edition 
# installs it with all the dependencies 
# and the necessary configurations, 
# and launches the application, all as it builds. 
# The container will be deemed valid 
# if you can access the web client, 
# create users and interact via GIT 
# with this container (HTTPS and SSH). 
# Obviously, you are not allowed to use the official container 
# from Gitlab, it would be a shame...

# ----------------------------------------------
# docker build -t ex03 .
# docker run -it --rm -p 80:80 -p 21:22 --privileged ex03

# difference between entrypoint and cmd:
# https://stackoverflow.com/questions/21553353/what-is-the-difference-between-cmd-and-entrypoint-in-a-dockerfile

# EXPOSE
# https://docs.docker.com/engine/reference/builder/
# The EXPOSE instruction informs Docker 
# that the container listens on the specified network ports at runtime. 
# You can specify whether the port listens on TCP or UDP, 
# and the default is TCP if the protocol is not specified.

