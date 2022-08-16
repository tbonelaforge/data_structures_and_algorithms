Driver: Driver.cpp BinarySearchTree.o List.hpp
	g++ Driver.cpp BinarySearchTree.o -o Driver

BinarySearchTreeTest: BinarySearchTreeTest.cpp BinarySearchTree.o List.hpp
	g++ BinarySearchTreeTest.cpp BinarySearchTree.o -o BinarySearchTreeTest

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h
	g++ -c BinarySearchTree.cpp -o BinarySearchTree.o

clean:
	find ./ -name '*~' | xargs rm
	rm -f *.o
	rm -f BinarySearchTreeTest
	rm -f Driver
