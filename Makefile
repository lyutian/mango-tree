pixel-operation:
	g++ pixel-operation.cpp -o pixel-operation.e `pkg-config opencv --cflags --libs`
clean:
	rm *.e
