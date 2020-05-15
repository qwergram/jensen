pip:
	python3.7 -m pip install -r requirements.txt

build: jensen/cJensen
	cd jensen && python3.7 setup.py build_ext --inplace

test: build
	cd jensen && cp ./*.so tests/
	cd jensen && python3.7 tests

clean:
	cd jensen && rm -rf *.so
	cd jensen && rm cJensen/*.cpp
	cd jensen && rm tests/*.so

docs:
	mkdocs serve -a 0.0.0.0:8080