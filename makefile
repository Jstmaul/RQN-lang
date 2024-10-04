default :
	gcc -o app compiler.c lexer.c
test :
	./app test.txt
