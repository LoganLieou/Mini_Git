LIBS=$(pkg-config --libs openssl) $(pkg-config --libs gtest)
CFLAGS=$(pkg-config --cflags openssl) $(pkg-config --cflags gtest)
REFS=src/init.cpp

build:
	mkdir -p _build/
	g++ --std=c++17 $(LIBS) $(CFLAGS) -Wall -Wpedantic src/main.cpp $(REFS) -o _build/main

test:
	g++ --std=c++17 -lgtest -Wall -Wpedantic tests/init_test.cpp src/init.cpp -o it && ./it
