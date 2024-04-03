#
# /etc/bash.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

[[ $DISPLAY ]] && shopt -s checkwinsize

case ${TERM} in
  Eterm*|alacritty*|aterm*|foot*|gnome*|konsole*|kterm*|putty*|rxvt*|tmux*|xterm*)
    PROMPT_COMMAND+=('printf "\033]0;%s@%s:%s\007" "${USER}" "${HOSTNAME%%.*}" "${PWD/#$HOME/\~}"')

    ;;
  screen*)
    PROMPT_COMMAND+=('printf "\033_%s@%s:%s\033\\" "${USER}" "${HOSTNAME%%.*}" "${PWD/#$HOME/\~}"')
    ;;
esac

if [[ -r /usr/share/bash-completion/bash_completion ]]; then
  . /usr/share/bash-completion/bash_completion
fi

#
# Edits start here
#

PS1='[\u@\h \W]\$ '

[[ $- != *i* ]] && return

alias ls='ls --color=auto'
alias grep='grep --color=auto'
alias ll='ls -la --color=auto'
alias p='echo $PATH | tr ":" "\n"'

# adds $1 to path, iterates over all sub directories and adds to path if not already there...
source /scripts/path_add_directory_recurse /scripts

HISTFILE=500000
HISTFILESIZE=10000000

# if not ssh and wm not already running (i.e. first login), launch wm and exit terminal. Getty TTY will act as our "login screen"? i3lock for lockscreen
# systemd?
# or or or 
#  get dm-tool working, continue using lightdm and don't use i3lock.......... monitor dbus to see what's happneing (blank screen)?
#
# gdm is a mess if not using gnome... afaik... sesssion selction not trivial (dbus config?), dm-tool not configured properly... gnome lock not modular... 
#
#
# 
