______________________________________________________________________
How to build the project using make and g++ (Tested on mac osx 10.9.5)

make all



________________
ListPermutations

A command-line program that takes a single integer 'n' as an argument, echoes it back, and then lists all the permutations of the numbers 1..n

Example: 

./ListPermutations 4


__________
AutoTester

An interactive testing program which prompts the user for a single integer 'n'.
If n is valid, it constructs a new PermutationGenerator(n).
If n is exactly 3, it will check that the order of the permutations given by the generator is correct (according to Johnson-Trotter algorithm)

Example:

./AutoTester 


___________
CheckUnique

Another command-line program, which takes the output of 'ListPermutations' above, and checks that each one is unique.
It also checks that the total number of permutations is correct.

Example:

./ListPermutations 9 | ./CheckUnique


__________
Source Files

PermutationGenerator.h - Header file defining the interface to the permutation generator class

PermutationGenerator.cpp - Implementation file, containing the algorithm for "next permutation" and associated data structures

AutoTester.cpp - Implementation of the AutoTester program.

ListPermutations.cpp - Implementation file for ListPermutations

CheckUnique.cpp - Implementation file for CheckUnique
