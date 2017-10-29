FROM nvidia/cuda:8.0-cudnn6-devel-ubuntu16.04

RUN	apt-get update
RUN	apt-get -y install firefox
RUN	apt-get -y install language-pack-ja-base language-pack-ja
RUN	apt-get -y install language-pack-gnome-ja
RUN	apt-get -y install fonts-takao-gothic
ENV	LANG=ja_JP.UTF-8
RUN	apt-get -y install gedit
RUN	apt-get -y install emacs
RUN	bash -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
RUN	apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116
RUN	apt-get update
RUN	apt-get install -y ros-kinetic-desktop-full
RUN	apt-get install -y sudo
ADD	make_user.sh /home/make_user.sh
ADD	init.sh /home/init.sh
RUN 	chmod 777 /home/make_user.sh
RUN 	chmod 777 /home/init.sh
RUN	/home/init.sh
RUN	gpasswd -a mine sudo
