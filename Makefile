compile: 
	g++ *.c* *.h -o program
	
run:
	./program $(file)
# exemple: make run file=files/input3.cmm

clear:
	rm -f program	