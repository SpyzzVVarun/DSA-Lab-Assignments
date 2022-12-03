C = gcc 
FLAGS = -O3 -pg -Wall -W
RM  = rm -f
EXEC = run

OBJECTS = \
	 main.o \

all: $(OBJECTS) compile touch 

main.o : main.c
					 $(C) $(FLAGS) -c main.c

clean:  
					 $(RM) $(OBJECTS) $(EXEC) 

compile: 
					 $(C) $(FLAGS) $(OBJECTS) -o $(EXEC) 

touch:
					 @echo " "
					 @echo "Compilation done successfully..................."
					 @echo " "