FROM ubuntu:14.04

RUN apt-get update && apt-get install -y make gcc check git

VOLUME ["/development"]
WORKDIR /development

CMD 'bash'
