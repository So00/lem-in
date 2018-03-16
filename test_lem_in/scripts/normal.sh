	#!/bin/bash
	rm -rf normal.txt
	list_file=`find ./valid_map/ -type f -name "valid*"`
	for file in $list_file
	do
		../lem-in < $file | ./normal $file
	done
	../lem-in < ./valid_map/big_map00 | ./normal ./valid_map/big_map00
	echo "\nThanks for using that script, good luck ;)"
