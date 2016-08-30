#!/bin/bash
download_dir=$HOME/Software
install_dir=$HOME/.local

if [ ! -d "$download_dir/vim" ]; then
    echo "git clone https://github.com/vim/vim.git"
    git clone https://github.com/vim/vim.git $download_dir/vim
else
    cd $download_dir/vim
    echo "git pull"
    x=`git pull | wc -l`
    if [ $x -eq 1 ]; then
        echo "Alread up-to-date."
        exit 0
    fi
    cd ..
fi

if [ ! -d "/usr/include/lua5.2" ]; then
    echo "sudo apt install liblua5.2-dev"
    sudo apt install liblua5.2-dev
fi
if [ ! -f "/usr/include/curses.h" ]; then
    echo "sudo apt install libncurses5-dev"
    sudo apt install libncurses5-dev
fi

pycnf=`find /usr/lib/python3.5/ -type d -name "config*"`
if [ ! -d "$pycnf" ]; then
    echo "sudo apt install python3-dev"
    sudo apt install python3-dev
fi

cd $download_dir/vim
./configure --prefix=$install_dir --enable-luainterp --with-lua-prefix=/usr --enable-python3interp=yes --with-python3-config-dir=$pycnf

if [ -f Makefile ]; then
    make
    make install
fi

if [ ! -f ~/.vim/install.sh ];then
    bash <(curl https://raw.githubusercontent.com/yuncliu/.vim/linux/install.sh)
fi
