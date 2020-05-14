build: cJensen
	python3.7 setup.py build_ext --inplace

test: build
	cp ./*.so tests/
	python3.7 tests

clean:
	rm -rf *.so
	rm cJensen/*.cpp
	rm tests/*.so