#!/bin/sh

if [ "$#" -ne 2 ]; then
    echo "Usage: sh `basename $0` <abs_path_to_dir> <text_to_find>"
    exit 1
fi

SEARCH_DIR=$1
SEARCH_TEXT=$2

if [ -d "$SEARCH_DIR" ]; then
    cd "$SEARCH_DIR"
    GREP_RESULT=`grep -RHn "$SEARCH_TEXT"`
    if [ -z "$GREP_RESULT" ]; then
        echo "No matches"
    else
        echo "$GREP_RESULT" | awk -F":" '{ print $1 "\t\t" $2 "\t\t" $3 }'
    fi
else
    echo "Error: folder '"$SEARCH_DIR"' doesn't exist!"
    exit 1
fi

