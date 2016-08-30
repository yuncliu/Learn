#!/bin/bash
#install JDK
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
    echo "$jdk already downloaded"
else
    echo "$download_dir/$jdk"
    echo "jdk not exist"
    #wget --no-cookies --no-check-certificate --header "$cookie" $jdk_url -O $download_dir/$jdk
fi

jdk_home=`find $install_dir -maxdepth 1 -type d -name "jdk*"`
if [ ! -n "$jdk_home" ]; then
    echo "can't find jdk dir, uncompressing $download_dir/$jdk"
    tar -xvf "$download_dir/$jdk" -C $install_dir
fi
jdk_home=`find $install_dir -maxdepth 1 -type d -name "jdk*"`
echo "JAVA_HOME is [$jdk_home]"

#set Java environment
omzjavaenv="$HOME/.oh-my-zsh/custom/java.zsh"
if [ -d ~/.oh-my-zsh ] && [ ! -f $omzjavaenv ];then
    echo "oh-my-zsh is installed, setting java environment to $omzjavaenv"
    echo "export JAVA_HOME=$jdk_home" >> $omzjavaenv
    echo "export PATH=\$JAVA_HOME/bin:\$PATH" >> $omzjavaenv
    echo "export CLASSPATH=\$JAVA_HOME/jre/lib:." >> $omzjavaenv
fi

if [ ! -d ~/.oh-my-zsh ] && [ -f ~/.zshrc ];then
    if [ `grep JAVA_HOME ~/.zshrc|wc -l` -eq 0 ];then
        echo "zshrc is found, but oh-my-zsh is not installed"
        echo "export JAVA_HOME=$jdk_home" >> ~/.zshrc
        echo "export PATH=\$JAVA_HOME/bin:\$PATH" >> ~/.zshrc
        echo "export CLASSPATH=\$JAVA_HOME/jre/lib:." >> ~/.zshrc
    fi
fi

if [ `grep JAVA_HOME ~/.bashrc|wc -l` -eq 0 ];then
    echo "setting environment for bash"
    echo "#Java environment start" >> ~/.bashrc
    echo "export JAVA_HOME=$jdk_home" >> ~/.bashrc
    echo "export PATH=\$JAVA_HOME/bin:\$PATH" >> ~/.bashrc
    echo "export CLASSPATH=\$JAVA_HOME/jre/lib:." >> ~/.bashrc
    echo "#Java environment end" >> ~/.bashrc
fi

echo "JDK install complete"
