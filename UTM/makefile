utm.exe 				: main.o utm_data_structures.h utm_functions.h utm_rule.h utm_types.h
	g++ -std=c++11 -o utm.exe main.o -static-libgcc -static-libstdc++

main.o 					: main.cpp utm_functions.h utm_data_structures.h utm_types.h
	g++ -std=c++11 -c -fpermissive -fconserve-space -Wno-write-strings main.cpp


	