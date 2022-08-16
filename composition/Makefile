Person: Person.cpp DateType.o Datetype.h Person.h RelationType.h
	g++ Person.cpp DateType.o -o Person

PersonTest: PersonTest.cpp Person.o Person.h
	g++ PersonTest.cpp Person.o -o PersonTest

DateType.o: DateType.cpp RelationType.h
	g++ -c DateType.cpp -o DateType.o


DateTypeTest: DateTypeTest.cpp DateType.h RelationType.h DateType.o
	g++ DateTypeTest.cpp DateType.o -o DateTypeTest
