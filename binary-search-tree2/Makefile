Driver: Driver.cpp BinarySearchTree.o List.hpp
	g++ Driver.cpp BinarySearchTree.o -o Driver

BinarySearchTreeTest: BinarySearchTreeTest.cpp BinarySearchTree.o List.hpp
	g++ BinarySearchTreeTest.cpp BinarySearchTree.o -o BinarySearchTreeTest

BinarySearchTreeDeleteTest: BinarySearchTreeDeleteTest.cpp BinarySearchTree.o List.hpp
	g++ BinarySearchTreeDeleteTest.cpp BinarySearchTree.o -o BinarySearchTreeDeleteTest


BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h
	g++ -c BinarySearchTree.cpp -o BinarySearchTree.o


BinarySearchTreeShapeStats: BinarySearchTreeShapeStats.cpp BinarySearchTree.o PermutationGenerator.o PermutationGenerator.h PermutationGenerator.o BinarySearchTree.h

	g++ BinarySearchTreeShapeStats.cpp BinarySearchTree.o PermutationGenerator.o -o BinarySearchTreeShapeStats


PermutationGenerator.o: PermutationGenerator.cpp PermutationGenerator.h
	g++ -c PermutationGenerator.cpp -o PermutationGenerator.o


clean:
	find ./ -name '*~' | xargs rm
	rm -f *.o
	rm -f BinarySearchTreeTest
	rm -f Driver
