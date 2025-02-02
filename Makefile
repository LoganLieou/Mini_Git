LIBS=$(pkg-config --libs openssl) $(pkg-config --libs gtest)
CFLAGS=$(pkg-config --cflags openssl) $(pkg-config --cflags gtest)

build:
	mkdir _build/
	g++ --std=c++17 $(LIBS) $(CFLAGS) -Wall -Wpedantic src/main.cpp -o _build/main

test:
	g++ --std=c++17 $(LIBS) $(CFLAGS) -Wall -Wpedantic tests/init_test.cpp -o it && ./it
	rm it
