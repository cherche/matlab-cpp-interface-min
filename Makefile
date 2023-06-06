# Need to compile for x86_64 because MATLAB runs on it ...
# Otherwise, MATLAB says that it's not compatible because
# it's a 32-bit library (which is at least half right, haha).
CFLAGS :=  -std=c++17 -arch x86_64
LDFLAGS := -Wl,-v
SOURCES=$(src/)

bin/static/%.o: src/rops/%.cpp
	$(CXX) $(CFLAGS) -c -o $@ $^ $(LDFLAGS)

# Static library doesn't seem to work ...
# so we'll be stuck with shared.
# However, this might not be too big a deal since
# we can still statically link stuff into it.
# (No idea how that works.)
bin/librops.dylib: bin/static/adder.o bin/static/multer.o bin/static/lin_alg.o
#	ar rcs $@ $^
	$(CXX) $(CFLAGS) $^ -o $@ -lginac -lcln -lgmp -Wl,-v,-dylib
# Note that macOS's `ld` has no -Bstatic option,
# so the only way to force a static link is by
# removing all the shared versions of the libraries,
# wherever they might appear in the PATH

bin/main.o: src/main.cpp
	$(CXX) $(CFLAGS) -c -o $@ $^ $(LDFLAGS)

bin/main: bin/main.o
	$(CXX) $(CFLAGS) -Lbin -lrops -o $@ $^

test: bin/librops.dylib bin/main.o bin/main
all: bin/static/adder.o bin/static/multer.o bin/librops.dylib
clean:
	rm -r bin/*
	mkdir bin/static
	mkdir bin/shared
