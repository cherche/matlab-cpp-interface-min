# Need to compile for x86_64 because MATLAB runs on it ...
# Otherwise, MATLAB says that it's not compatible because
# it's a 32-bit library (which is at least half right, haha).
CFLAGS :=  -std=c++17 -target x86_64-apple-macos12
LDFLAGS := -Wl,-v
SOURCES=$(src/)

bin/static/%.o: src/%.cpp
	$(CXX) $(CFLAGS) -c -o $@ $^ $(LDFLAGS)

bin/static/librops.a: bin/static/adder.o bin/static/multer.o
	$(CXX) $(CFLAGS) $^ -o $@ -lginac -lcln -lgmp -Wl,-v,-dylib

bin/main.o: src/main.cpp
	$(CXX) $(CFLAGS) -c -o $@ $^ $(LDFLAGS)

all: bin/static/adder.o bin/static/multer.o bin/static/librops.a
clean:
	rm -r bin/*
	mkdir bin/static
	mkdir bin/shared
