LinkedListTest:		main.o linkedlist.o memorysafety.o
					gcc -o LinkedListTest main.o memorysafety.o

main.o:				main.c linkedlist.c linkedlist.h memorysafety.c memorysafety.h 
					gcc -c main.c

linkedlist.o:		linkedlist.c linkedlist.h memorysafety.c memorysafety.h
					gcc -c linkedlist.c

memorysafety.o:		memorysafety.c memorysafety.h
					gcc -c memorysafety.c