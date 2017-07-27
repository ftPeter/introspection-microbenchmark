all: test

build: setup.py _multibench.c
	python setup.py build_ext --inplace

test: build
	python python_multibench.py

clean:
	rm -rf build; rm *.so
