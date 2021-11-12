#!/bin/bash

COLOR="Red"
VALUE=10

PARA1="$1"
PARA2="$2"
PARA3="$3"

idx=10
idy=20
idz=($idx+$idy)

my_function() {
	echo "from test function: $COLOR"
	echo "parameters: $PARA1 $PARA2 $PARA3"
	echo sp{el,il,al}l
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

my_function
another_function
