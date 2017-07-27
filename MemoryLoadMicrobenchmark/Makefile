all: build-tests

DRIFT=drift
DRIFT_CODE=drift.c

build-tests: $(DRIFT_CODE)
	gcc -pthread $(DRIFT_CODE) -o $(DRIFT) -O -lrt

run-test: build-tests
	./$(DRIFT) -b 100m -w 100m -d 0b -t 20g -r 1 -R -s 100
	./$(DRIFT) -b 100m -w 100m -d 0b -t 20g -r 1 -R -s 1
	./$(DRIFT) -b 100m -w 100m -d 0b -t 20g -r 1 -R -s 2
	./$(DRIFT) -b 100m -w 100m -d 0b -t 20g -r 1 -R -s 3
	./$(DRIFT) -b 100m -w 100m -d 0b -t 20g -r 1 -R -s 4
	./$(DRIFT) -b 100m -w 100m -d 0b -t 20g -r 1 -R -s 5
	./$(DRIFT) -b 100m -w 100m -d 0b -t 20g -r 1 -R -s 6
	./$(DRIFT) -b 100m -w 100m -d 0b -t 20g -r 1 -R -s 7
	./$(DRIFT) -b 100m -w 100m -d 0b -t 20g -r 1 -R -s 8
	./$(DRIFT) -b 100m -w 100m -d 0b -t 20g -r 1 -W -s 100
	./$(DRIFT) -b 100m -w 100m -d 0b -t 20g -r 1 -W -s 1
	./$(DRIFT) -b 100m -w 100m -d 0b -t 20g -r 1 -W -s 2
	./$(DRIFT) -b 100m -w 100m -d 0b -t 20g -r 1 -W -s 3
	./$(DRIFT) -b 100m -w 100m -d 0b -t 20g -r 1 -W -s 4
	./$(DRIFT) -b 100m -w 100m -d 0b -t 20g -r 1 -W -s 5
	./$(DRIFT) -b 100m -w 100m -d 0b -t 20g -r 1 -W -s 6
	./$(DRIFT) -b 100m -w 100m -d 0b -t 20g -r 1 -W -s 7
	./$(DRIFT) -b 100m -w 100m -d 0b -t 20g -r 1 -W -s 8

guest-100-test: build-tests
	./$(DRIFT) -b 100m -w 100m -d 0b -t 1307g -r 1 -R -s 100
	./$(DRIFT) -b 100m -w 100m -d 0b -t 1145g -r 1 -R -s 1
	./$(DRIFT) -b 100m -w 100m -d 0b -t 1015g -r 1 -R -s 2
	./$(DRIFT) -b 100m -w 100m -d 0b -t 829g -r 1 -R -s 3
	./$(DRIFT) -b 100m -w 100m -d 0b -t 706g -r 1 -R -s 4
	./$(DRIFT) -b 100m -w 100m -d 0b -t 546g -r 1 -R -s 5
	./$(DRIFT) -b 100m -w 100m -d 0b -t 304g -r 1 -R -s 6
	./$(DRIFT) -b 100m -w 100m -d 0b -t 136g -r 1 -R -s 7
	./$(DRIFT) -b 100m -w 100m -d 0b -t 64g -r 1 -R -s 8
	./$(DRIFT) -b 100m -w 100m -d 0b -t 727g -r 1 -W -s 100
	./$(DRIFT) -b 100m -w 100m -d 0b -t 696g -r 1 -W -s 1
	./$(DRIFT) -b 100m -w 100m -d 0b -t 531g -r 1 -W -s 2
	./$(DRIFT) -b 100m -w 100m -d 0b -t 305g -r 1 -W -s 3
	./$(DRIFT) -b 100m -w 100m -d 0b -t 179g -r 1 -W -s 4
	./$(DRIFT) -b 100m -w 100m -d 0b -t 134g -r 1 -W -s 5
	./$(DRIFT) -b 100m -w 100m -d 0b -t 108g -r 1 -W -s 6
	./$(DRIFT) -b 100m -w 100m -d 0b -t 90g -r 1 -W -s 7
	./$(DRIFT) -b 100m -w 100m -d 0b -t 77g -r 1 -W -s 8

