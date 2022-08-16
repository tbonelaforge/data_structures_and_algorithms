SortedList.o: SortedList.h SortedList.cpp ItemType.h
	g++ -c SortedList.cpp -o SortedList.o


ItemType.o: ItemType.cpp ItemType.h
	g++ -c ItemType.cpp -o ItemType.o


SortedListTest: SortedListTest.cpp SortedList.o ItemType.h ItemType.o
	g++ SortedListTest.cpp SortedList.o ItemType.o -o SortedListTest
