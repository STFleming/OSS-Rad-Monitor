cd tests;
for t in  *_test.cpp; do
	rm -rf ./obj_dir/
	#echo $t
	module_name=${t%_test.cpp}
	echo $module_name

	#echo "$module_name Build"
	verilator -Wall -cc --trace --exe --build -j -I../modules $module_name $t > /dev/null
	#echo "\n$module_name Run\n\n"
	./obj_dir/V$module_name +trace
	rm -rf ./obj_dir/

done
