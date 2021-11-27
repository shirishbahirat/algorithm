reverse: reverse.cpp
	g++ reverse.cpp -o reverse

reverse.o: reverse.cpp
	g++ -c reverse.cpp

.PHONY: clean
clean:
	rm -f reverse reverse.o

.PHONY: build_msg
build_msg:
	@printf "Building Program\n"


































