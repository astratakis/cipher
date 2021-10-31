all: validate_api demo_program

validate_api:
	gcc -c unit_testing.c test_functions.c simple_crypto.c
	gcc unit_testing.o test_functions.o simple_crypto.o -o validate_api.exe

demo_program:
	gcc -c main.c simple_crypto.c
	gcc main.o simple_crypto.o -o demo_program.exe

clean:
	rm *.o
	rm *.exe