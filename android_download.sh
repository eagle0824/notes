#!/bin/bash

echo "======start repo sync======"

/work/tools/repo/repo sync

while [ $? == 1 ]; do

    echo "======sync failed, re-sync again======"

    sleep 3

    /work/tools/repo/repo sync

done
