FROM ubuntu
MAINTAINER Romin Irani
RUN apt-get update
RUN apt-get install -y nginx
COPY index.html /usr/share/nginx/html/
ENTRYPOINT [“/usr/sbin/nginx”,”-g”,”daemon off;”]
EXPOSE 80

# https://stackoverflow.com/c/42network/questions/487

