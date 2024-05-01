# sudo docker build -t skipskipandaway .
# sudo docker run -p 1337:1337 skipskipandaway:lastest
FROM ubuntu:22.04

RUN groupadd -r ctf && useradd -r -g ctf ctf
WORKDIR /home/chall

COPY ./skipskipandaway .
COPY ./flag.txt .

RUN chown -R root:ctf /home/chall
RUN chmod 750 /home/chall/skipskipandaway
RUN chmod 440 /home/chall/flag.txt

USER ctf

EXPOSE 1337


