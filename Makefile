flag = -Wall -Werror -Wextra
all: main_executable_module.o data_io.o data_stat.o data_process.o decision.o
	gcc $(flag) main_executable_module.o data_io.o data_stat.o data_process.o decision.o -o ../../build/Quest_3
	rm -f *.o

main_executable_module.o: 
	gcc $(flag) -c main_executable_module.c

data_io.o: 
	gcc $(flag) -c ../data_libs/data_io.c

data_stat.o: 
	gcc $(flag) -c ../data_libs/data_stat.c

data_process.o: 
	gcc $(flag) -c ../data_module/data_process.c

decision.o: 
	gcc $(flag) -c ../yet_another_decision_module/decision.c

clear:
	rm -f *.o
	rm -f *.a
	rm -f *.so

data_stat.a: data_stat.o
	ar r data_stat.a data_stat.o
	rm *.o

build_with_static: data_stat.a main_executable_module.o data_io.o data_process.o decision.o
	gcc $(flag) data_stat.a main_executable_module.o data_io.o data_process.o decision.o -o ../../build/Quest_5 -L../data_libs -data_stat
	rm -f *.o

data_process.so: data_process.o
	gcc -c -fPIC ../data_module/data_process.c ../data_libs/data_stat.c
	gcc -shared -o data_process.so data_process.o data_stat.o
	rm *.o

build_with_dynamic: data_process.so data_stat.o main_executable_module.o data_io.o decision.o
	gcc $(flag) data_process.so main_executable_module.o data_io.o data_stat.o decision.o -o ../../build/Quest_6 -L../data_module -data_process -Wl,-rpath,../data_module/
	rm -f *.o
