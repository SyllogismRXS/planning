#!/bin/bash

# Script usage display function
usage()
{
cat << EOF
usage: $0 [options]

This script installs all dependencies.

OPTIONS:
 [TODO]-h Show this message
EOF
}

# Require the script to be run as root
if [[ $(/usr/bin/id -u) -ne 0 ]]; then
    echo 
    echo "This script must be run as root because libraries will be installed."
    usage
    exit
fi

# Grab username of caller for later
ORIGINAL_USER=$(who am i | awk '{print $1}')

if [ ! -d ../third-party-build ];
then
su $ORIGINAL_USER -m -c 'mkdir ../third-party-build'
fi

##################################################
# Build and install LEMON
##################################################
su $ORIGINAL_USER -m -c './build-lemon.sh'
./build-lemon.sh install
ldconfig
