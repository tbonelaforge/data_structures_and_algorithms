hello_sqlite: hello_sqlite.cpp sqlite3.o sqlite3.h sqlite3ext.h
	g++ hello_sqlite.cpp sqlite3.o -o hello_sqlite


appointments_db_test: appointments_db_test.cpp sqlite3.o sqlite3.h sqlite3ext.h
	g++ appointments_db_test.cpp sqlite3.o -o appointments_db_test

sqlite3.o: sqlite3.c sqlite3.h sqlite3ext.h
	gcc -c sqlite3.c -o sqlite3.o


shell: shell.c sqlite3.c
	gcc -DSQLITE_THREADSAFE=0 -DSQLITE_OMIT_LOAD_EXTENSION shell.c sqlite3.c -o shell

clean:
	rm hello_sqlite
	rm sqlite3.o
	rm shell
