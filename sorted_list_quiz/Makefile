TestRunner2: TestRunner2.cpp SortedList.o ItemType.o
	g++ TestRunner2.cpp SortedList.o ItemType.o -o TestRunner2

SortedListTest: SortedListTest.cpp SortedList.o ItemType.o
	g++ SortedListTest.cpp SortedList.o ItemType.o -o SortedListTest

ItemType.o: ItemType.cpp ItemType.h
	g++ -c ItemType.cpp -o ItemType.o

SortedList.o: SortedList.cpp SortedList.h ItemType.h
	g++ -c SortedList.cpp -o SortedList.o

clean:
	rm -f *.o
	rm -f SortedListTest
	rm -f TestRunner2
