#!/bin/sh
# Finds and runs all MAKEFILES in the target directory and its subdirectories
# Usage: ./make_recurse <target directory> [make options]  

TARGET_DIR=$1
MAKE_ARG=$2
MAKEFILES=$(find "$TARGET_DIR" | grep -E 'Makefile$')
CWD=$(pwd)

for makefile in $MAKEFILES; do
    make_dir=$(echo "$makefile" | sed 's/\/Makefile$//g')
    echo "Running 'make $MAKE_ARG' in: $make_dir"

    make_dir="$CWD/$make_dir"
    if [ ! -d "$make_dir" ]; then
        echo "$DIRECTORY does not exist."
        exit 1
    fi
    cd "$make_dir" || exit 1

    if make "$MAKE_ARG" > /dev/null 2> /dev/null; then
        echo " → Succeeded"
    else 
        echo " → Failed"
    fi
done
