compile: 
	g++ -w *.c* *.h -o program
	
run:
	./program $(file)
# exemple: make run file=files/input3.cmm

clear:
	rm -f program	