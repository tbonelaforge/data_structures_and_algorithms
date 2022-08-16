fraction.o: fraction.cpp fraction.h
	g++ -c fraction.cpp -o fraction.o


test_runner: test_runner.cpp fraction.o fraction.h
	g++ test_runner.cpp fraction.o -o test_runner
