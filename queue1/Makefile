TestRunner: TestRunner.cpp IntegerQueue.o IntegerQueue.h
	g++ TestRunner.cpp IntegerQueue.o -o TestRunner

TestRunner2: TestRunner2.cpp CountedIntegerQueue.o CountedIntegerQueue.h IntegerQueue.o IntegerQueue.h
	g++ TestRunner2.cpp CountedIntegerQueue.o IntegerQueue.o -o TestRunner2

IntegerQueue.o: IntegerQueue.cpp IntegerQueue.h
	g++ -c IntegerQueue.cpp -o IntegerQueue.o

CountedIntegerQueue.o: CountedIntegerQueue.cpp CountedIntegerQueue.h
	g++ -c CountedIntegerQueue.cpp -o CountedIntegerQueue.o

IntegerQueueTest: IntegerQueueTest.cpp IntegerQueue.o IntegerQueue.h
	g++ IntegerQueueTest.cpp IntegerQueue.o -o IntegerQueueTest

QueueTest: QueueTest.cpp Queue.hpp
	g++ QueueTest.cpp -o QueueTest
