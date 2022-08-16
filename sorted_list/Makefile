ItemType.o: ItemType.cpp ItemType.h
	g++ -c ItemType.cpp -o ItemType.o

SortedList.o: SortedList.cpp SortedList.h ItemType.h
	g++ -c SortedList.cpp -o SortedList.o


SortedListTest: SortedListTest.cpp SortedList.o ItemType.o
	g++ SortedListTest.cpp SortedList.o ItemType.o -o SortedListTest
