#!/bin/sh
# Finds and runs all MAKEFILES in the target directory and its subdirectories
# Usage: ./make_recurse <target directory> [make options]  

TARGET_DIR=$1
MAKEFILES=$(find "$TARGET_DIR" | grep -E 'Makefile$')
CWD=$(pwd)

for makefile in $MAKEFILES; do
    make_dir=$(echo "$makefile" | sed 's/\/Makefile$//g')
    echo "Running 'make clean' and 'make' in: $make_dir"

    make_dir="$CWD/$make_dir"
    if [ ! -d "$make_dir" ]; then
        echo "$DIRECTORY does not exist."
        exit 1
    fi
    cd "$make_dir" || exit 1

    if make clean > /dev/null; then
        echo " → 'make clean' Succeeded"
    else
        echo " → 'make clean' Failed"
        exit 1
    fi
    if make > /dev/null ; then
        echo " → 'make' Succeeded"
    else 
        echo " → 'make' Failed"
        exit 1
    fi
done
