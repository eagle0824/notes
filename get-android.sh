#!/bin/bash
#FileName get_android.sh

PATH=./bin:$PATH
repo init -u git://android.git.kernel.org/platform/manifest.git -b master
repo sync
while [ $? = 1 ];
do
    echo "======== sync failed, re-sync again ========"
    sleep 3
    repo sync
done
