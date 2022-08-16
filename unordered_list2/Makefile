
ItemType.o: ItemType.cpp ItemType.h
	g++ -c ItemType.cpp -o ItemType.o


UnorderedList.o: UnorderedList.cpp UnorderedList.h ItemType.o ItemType.h
	g++ -c UnorderedList.cpp -o UnorderedList.o

TestRunner: TestRunner.cpp UnorderedList.o UnorderedList.h ItemType.o ItemType.h
	g++ TestRunner.cpp UnorderedList.o ItemType.o -o TestRunner
