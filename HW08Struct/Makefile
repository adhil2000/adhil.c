
# My Makefile

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DTEST_MAIN -DTEST_COUNTVECTOR -DTEST_READVECTOR -DTEST_COMPAREVECTOR -DTEST_WRITEVECTOR -DTESTPRINTVECTOR
SRCS = hw08.c main.c 
OBJS = $(SRCS:%.c=%.o)

hw08: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw08

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testmemory: hw08
	$(VAL) ./hw08 inputs/test3 output3
#testing only input3 and output3
	
testall: test1 test2 test3 test4 test5

test1: hw08
	./hw08 inputs/test1 > output1
	diff output1 expected/expected1

test2: hw08
	./hw08 inputs/test2 > output2
	diff output2 expected/expected2

test3: hw08
	./hw08 inputs/test3 > output3
	diff output3 expected/expected3

test4: hw08
	./hw08 inputs/test4 > output4
	diff output4 expected/expected4

test5: hw08
	./hw08 inputs/test5 > output5
	diff output5 expected/expected5

clean: # remove all machine generated files
	rm -f hw08 *.o output?
