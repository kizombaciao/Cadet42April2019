FROM ruby

RUN apt-get update -y
RUN apt-get install -y build-essential libpq-dev nodejs sqlite3

ONBUILD COPY app /opt/app
ONBUILD WORKDIR /opt/app

ONBUILD EXPOSE 3000
ONBUILD RUN bundle install
ONBUILD RUN rake db:migrate
ONBUILD RUN rake db:seed

# ----------------------------------------------
# https://github.com/VBrazhnik/docker-1/wiki/Dockerfiles

# docker build -t ft-rails:on-build .

# https://www.learnitguide.net/2018/06/docker-onbuild-command-with-examples.html

# https://docs.docker.com/develop/develop-images/dockerfile_best-practices/
# An ONBUILD command executes after the current Dockerfile build completes. 
# ONBUILD executes in any child image derived FROM the current image. 
# Think of the ONBUILD command as an instruction 
# the parent Dockerfile gives to the child Dockerfile.
# A Docker build executes ONBUILD commands 
# before any command in a child Dockerfile.

