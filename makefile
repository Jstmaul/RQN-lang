default : 
	gcc -o app compiler.c lexer.c
test : default
	./app test.rqn
