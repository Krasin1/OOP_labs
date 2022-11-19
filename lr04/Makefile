all: main.cpp 
	g++ main.cpp -o main -fsanitize=address,leak,undefined -g -std=c++2b -Wall -Wextra -Wpedantic -Wconversion

clean:
	rm main 
