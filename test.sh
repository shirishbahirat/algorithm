#!/bin/bash

COLOR="Red"
VALUE=10

PARA1="$1"
PARA2="$2"
PARA3="$3"

idx=10
idy=20
NUM=1113
idz=$[$idx+$idy]
NUM=$[$NUM + 1]

my_function() {
    echo "from test function: $COLOR"
    echo "parameters: $PARA1 $PARA2 $PARA3"
    echo sp{el,il,al}l
    echo $NUM
    echo ~
    echo ~/
    echo ~+
    echo `date`
    echo $[idx + 100]

    if [[ "$idx" == "11" ]]; then
        echo "if statement is true";
    else 
        echo "if statement is false";       
    fi


}

another_function() {
    echo "from another function: $VALUE"
    echo "after incrementing: $idx $idy $idz"
}

new_function() {
    echo "from new function: $VALUE"
    echo "after incrementing: $idx $idy $idz"
}

my_function
another_function
new_function
