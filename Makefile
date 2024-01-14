all:
	g++ -I src/include -L src/lib -o draw draw.cpp -l mingw32 -l SDL2main -l SDL2