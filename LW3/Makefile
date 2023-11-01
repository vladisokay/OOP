.PHONY: build run point-tests pentagon-tests hexagon-tests octagon-tests vector-tests clean

build:
	mkdir -p build
	cd ./build; cmake ..; make all

run:
	./build/lw3

point-tests:
	./build/*pointTest

pentagon-tests:
	./build/*pentagonTest

hexagon-tests:
	./build/*hexagonTest

octagon-tests:
	./build/*octagonTest

vector-tests:
	./build/*vectorTest

clean:
	rm -rf ./build/