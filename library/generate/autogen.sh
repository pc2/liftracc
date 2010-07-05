#!/bin/bash

CBLAS_XML=cblas.xml

function usage() {
    echo "Please install 'xsltproc' in order to use this script."
    echo
}

if which xsltproc &> /dev/null; then
    echo "xsltproc found. generation started..."
    BASE_DIR=`dirname $0`
    STYLE_DIR="$BASE_DIR/stylesheets"
    for i in `cat $BASE_DIR/autogen.txt`; do
        IN_FILE="$STYLE_DIR/$i"
        OUT_FILE=`basename $IN_FILE`
        FILE_EXT=${OUT_FILE##*.}
        FILE_EXT=`echo $FILE_EXT | tr [:lower:] [:upper:]`
        OUT_FILE=${OUT_FILE%\.*}
        
        if [ "$FILE_EXT" == "XSL" ]; then
            echo "$IN_FILE -> $OUT_FILE"

            xsltproc $IN_FILE $BASE_DIR/$CBLAS_XML > $OUT_FILE
        fi
    done
    echo "done."
    exit 0
else
    usage
    exit 1
fi

