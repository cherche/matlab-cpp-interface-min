# Need to compile for x86_64 because MATLAB runs on it ...
# Otherwise, MATLAB says that it's not compatible because
# it's a 32-bit library (which is at least half right, haha).
CFLAGS :=  -std=c++17 -target x86_64-apple-macos12
LDFLAGS := -Wl,-v
SOURCES=$(src/)

bin/shared/%.o: src/%.cpp
	$(CXX) $(CFLAGS) -c -fPIC -o $@ $^ $(LDFLAGS)


bin/shared/librops.so: bin/shared/adder.o bin/shared/multer.o
	$(CXX) $(CFLAGS) -shared $^ -o $@ -lginac -lcln

all: bin/shared/adder.o bin/shared/multer.o bin/shared/librops.so
clean:
	rm -r bin/*
	mkdir bin/static
	mkdir bin/shared
#LieAlgebra.a: LieAlgebra.o
#	$(AR) $(ARFLAGS) $@ $^
# If need static, change .so to .a and remove -shared flag