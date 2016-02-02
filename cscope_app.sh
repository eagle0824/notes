#!/bin/sh

find ./ ../../../frameworks/base ../../../libcore/luni/src/main -type f -a \( -name "*.h" -o -name "*.c" -o -name "*.java" -o -name "*.mk" -o -name "*.xml" -o -name "*.cpp" -o -name "*.sh" \) -print > cscope.files
cscope -bq
