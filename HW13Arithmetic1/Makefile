# My Makefile

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DTEST_CALCULATE -DTEST_READLIST -DTEST_DELETELIST -DTEST_ADDNODE -DTEST_DELETENODE -DDEBUG
SRCS = calculate.c list.c main.c
OBJS = $(SRCS:%.c=%.o)

hw13: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw13

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testmemory: hw13
	$(VAL) ./hw13 inputs/input1 output1
#testing only input1 and output1

testall: test3 test4 test6

test1: hw13
	./hw13 inputs/test1 > output1
	diff output1 expected/expected1

test2: hw13
	./hw13 inputs/test2 > output2
	diff output2 expected/expected2

test3: hw13
	./hw13 inputs/test3 > output3
	diff output3 expected/expected3

test4: hw13
	./hw13 inputs/test4 > output4
	diff output4 expected/expected4

test5: hw13
	./hw13 inputs/test5 > output5
	diff output5 expected/expected5

test6: hw13
	./hw13 inputs/test6 > output6
	diff output6 expected/expected6
	
clean: # remove all machine generated files
	rm -f hw13 *.o output? 
