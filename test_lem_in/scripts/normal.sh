	#!/bin/bash
	rm -rf normal.txt
	list_file=`find ./valid_map/ -type f -name "valid*"`
	echo "\n\033[0;35mBegin of valid map\033[0m\n\n" >> leaks
	for file in $list_file
	do
		RETVAL=`valgrind --log-fd=1 ../lem-in < valid_map/valid_map01 | grep "definitely lost"`
		LEAK=`echo $RETVAL | cut -d : -f 2 | awk '{print $1}'`
		../lem-in < $file | ./normal $file
		if [ "$LEAK" != "0" ]
		then
			echo "Leaks in $file\n$RETVAL\n" >> leaks
		fi
	done
	../lem-in < ./valid_map/big_map00 | ./normal ./valid_map/big_map00
	echo "\n"