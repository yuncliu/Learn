#!/bin/bash
jdk_url="http://download.oracle.com/otn-pub/java/jdk/8u102-b14/jdk-8u102-linux-x64.tar.gz"
#jdk_url="http://download.oracle.com/otn-pub/java/jdk/8u101-b13/jdk-8u101-linux-x64.tar.gz"
cookie="Cookie: gpw_e24=http%3A%2F%2Fwww.oracle.com%2F; oraclelicense=accept-securebackup-cookie"

jdk=`basename $jdk_url`
download_dir=$HOME/Software
install_dir=$HOME/.local
if [ -d $download_dir ];then
    echo "$download_dir existed"
else
    mkdir -p $download_dir
    echo "$download_dir not existed, created"
fi

if [ -d $install_dir ];then
    echo "$install_dir existed"
else
    mkdir $install_dir
    echo "$install_dir not existed, created"
fi

#curl http://download.oracle.com/otn-pub/java/jdk/8u101-b13/jdk-8u101-linux-x64.tar.gz
if [ -f "$download_dir/$jdk" ]; then
    echo "jdk already downloaded"
else
    echo "$download_dir/$jdk"
    echo "jdk not exist"
    #wget --no-cookies --no-check-certificate --header "$cookie" $jdk_url -O $download_dir/$jdk
fi

jdk_dir=`find $install_dir -maxdepth 1 -type d -name "jdk*"`
echo $jdk_dir
if [ ! -n "$jdk_dir" ]; then
    echo "can't find jdk dir, uncompressing"
    echo "$download_dir/$jdk"
    tar -xvf "$download_dir/$jdk" -C $install_dir
    jdk_dir=`find /home/liu/Software -maxdepth 1 -type d -name "jdk*"`
fi

#TODO set java environment
