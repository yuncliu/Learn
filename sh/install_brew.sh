
if [ `uname` == 'Linux' ];then
    if [ ! -d $HOME/.linuxbrew ]; then
        ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Linuxbrew/install/master/install)"
    fi
else
    ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
fi

sh=`basename $SHELL`
profile="$HOME/.oh-my-zsh/custom/brew.zsh"

if [ $sh == "zsh" ];then
    if [ -d $HOME/.oh-my-zsh ]; then
        if [ -f $profile ];then
            rm $profile
        fi
        echo "export PATH=\$HOME/.linuxbrew/bin:\$PATH" >> $profile
        echo "export MANPATH=\$HOME/.linuxbrew/share/man:\$MANPATH" >> $profile
        echo "export INFOPATH=\$HOME/.linuxbrew/share/info:\$INFOPATH" >> $profile
    fi
fi

x=`grep "linuxbrew" ~/.bashrc |wc -l`
if [ $x -eq 0 ];then
    echo "export PATH=\$HOME/.linuxbrew/bin:\$PATH" >> "$HOME/.bashrc"
    echo "export MANPATH=\$HOME/.linuxbrew/share/man:\$MANPATH" >> "$HOME/.bashrc"
    echo "export INFOPATH=\$HOME/.linuxbrew/share/info:\$INFOPATH" >> "$HOME/.bashrc"
fi
