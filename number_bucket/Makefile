number_bucket.o: number_bucket.cpp number_bucket.h node.h.gch
	g++ -c number_bucket.cpp -o number_bucket.o

number_bucket_test: number_bucket_test.cpp number_bucket.h number_bucket.o node.h.gch
	g++ number_bucket_test.cpp number_bucket.o -o number_bucket_test

node.h.gch: node.h
	g++ -c node.h -o node.h.gch
