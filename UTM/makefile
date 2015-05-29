utm.exe 				: main.o utm_functions.h utm_rule.h utm_types.h
	g++-4.9 -std=c++11 -o utm.exe main.o -static-libgcc -static-libstdc++

main.o 					: main.cpp utm_functions.h utm_rule.h utm_types.h
	g++-4.9 -std=c++11 -c -fpermissive -fconserve-space -Wno-write-strings main.cpp


	