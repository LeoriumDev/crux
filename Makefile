./build/crux: ./src/main.c ./src/lexer.c
	mkdir -p build
	gcc ./src/main.c ./src/lexer.c -o ./build/crux

run: ./build/crux
	./build/crux --lex ./tests/test.c

clean:
	rm -rf build
