
unit_testing.o:
	gcc -c unit_testing.c test_functions.c

validate_api:
	gcc -o unit_testing.o


clean:
	rm *.o
	rm *.exe