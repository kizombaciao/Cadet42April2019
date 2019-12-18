FROM ubuntu:latest

RUN apt-get update
RUN apt-get install -y python python-pip wget
#RUN pip install Flask

ADD hello.py /home/hello.py
# add our code file 
#COPY . /home/hello.py
WORKDIR /home

# default directory when the container starts

# docker build -t "flask:dockerfile" .
# docker run -p 5000:5000 flask:dockerfile python hello.py
# we run the Flask app directly with container start
# rather than with a running bash shell.

# -t flag means add a tag to the image,
# in order to get a repository name and tag.

# 'docker history' will show the effect of each command 
# on the overall size of the file.

# https://odewahn.github.io/docker-jumpstart/building-images-with-dockerfiles.html


