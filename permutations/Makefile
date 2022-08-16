PermutationGeneratorTest: PermutationGeneratorTest.cpp PermutationGenerator.o PermutationGenerator.h
	g++ PermutationGeneratorTest.cpp PermutationGenerator.o -o PermutationGeneratorTest

PermutationGenerator.o: PermutationGenerator.cpp PermutationGenerator.h
	g++ -c PermutationGenerator.cpp -o PermutationGenerator.o

ListPermutations: ListPermutations.cpp PermutationGenerator.o PermutationGenerator.h
	g++ ListPermutations.cpp PermutationGenerator.o -o ListPermutations

CheckUnique: CheckUnique.cpp
	g++ CheckUnique.cpp -o CheckUnique
