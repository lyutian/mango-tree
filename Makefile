all:
	make pixel-operation filter-operation
pixel-operation:
	g++ pixel-operation.cpp -o pixel-operation.e `pkg-config opencv --cflags --libs`
filter-operation:
	g++ filter-operation.cpp -o filter-operation.e `pkg-config opencv --cflags --libs`
clean:
	rm *.e
