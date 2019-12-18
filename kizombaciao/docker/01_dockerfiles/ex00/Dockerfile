FROM alpine

RUN apk update && \
    apk upgrade && \
    apk add emacs

ENTRYPOINT emacs

# ----------------------------------------------
# From an alpine image you’ll add to your container 
# your favorite text editor, vim or emacs, 
# that will launch along with your container.

# > docker build -t ex00 .
# note, there is a period at the end !
# -t    represents tag, in this case, ex00

# > docker run -it --rm ex00
# > docker exec -it ex00 bash

# dockerfile best practices:
# https://docs.docker.com/develop/develop-images/dockerfile_best-practices/

# USEFUL !!!
# a dockerfile for emacs.
