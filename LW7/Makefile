.PHONY: build run tests clean

build:
	mkdir -p build
	cd ./build; cmake ..; make all

run:
	./build/*LW7_exe

tests:
	./build/*LW7_test

clean:
	rm -rf ./build/