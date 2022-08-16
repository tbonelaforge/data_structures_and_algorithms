all: PermutationGenerator.o ListPermutations AutoTester CheckUnique

PermutationGenerator.o: PermutationGenerator.cpp PermutationGenerator.h
	g++ -c PermutationGenerator.cpp -o PermutationGenerator.o

ListPermutations: ListPermutations.cpp PermutationGenerator.o PermutationGenerator.h
	g++ ListPermutations.cpp PermutationGenerator.o -o ListPermutations

AutoTester: AutoTester.cpp PermutationGenerator.o PermutationGenerator.h
	g++ AutoTester.cpp PermutationGenerator.o -o AutoTester

CheckUnique: CheckUnique.cpp
	g++ CheckUnique.cpp -o CheckUnique
