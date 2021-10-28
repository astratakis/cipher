validate_api.exe:
	gcc -c unit_testing.c test_functions.c simple_crypto.c
	gcc unit_testing.o test_functions.o simple_crypto.o -o validate_api.exe

clean:
	rm *.o
	rm *.exe
	rm *.out