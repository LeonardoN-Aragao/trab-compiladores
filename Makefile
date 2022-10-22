compile: 
	g++ *.c* *.h -o program
run:
	./program $(file)
clear:
	rm -f program