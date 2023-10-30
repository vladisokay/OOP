.PHONY: build run point-tests rectangle-tests square-tests trapeze-tests vector-tests clean

build:
	mkdir -p build
	cd ./build; cmake ..; make all

run:
	./build/lw3

point-tests:
	./build/*testPoint

rectangle-tests:
	./build/*testPentagon

square-tests:
	./build/*testHexagon

trapeze-tests:
	./build/*testOctagon

vector-tests:
	./build/*testVector

clean:
	rm -rf ./build/