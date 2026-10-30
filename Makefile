INPUT = entrada.in

build:
	@g++ -o programa src/*.cpp src/operacoes/*.cpp

run: build
	@./programa < "$(INPUT)"