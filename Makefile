all:
	g++ -I src/include -L src/lib -o 3Drenderer launcher.cpp -l mingw32 -l SDL2main -l SDL2