.PHONY: build run tests clean

build:
	mkdir -p build
	cd ./build; cmake ..; make all

run:
	./build/*LW6_exe

tests:
	./build/*LW6_test

clean:
	rm -rf ./build/