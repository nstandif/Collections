LL_TEST_BIN=binaries/LinkedList-Test
BST_TEST_BIN=binaries/bst-test

LL_TEST_OBJ=obj/LinkedList-Test.o obj/LinkedList.o
BST_TEST_OBJ=obj/bst-test.o obj/BST.o
FLAGS=-Wall -c -o
CHKS=~/Projects/CppCheckStyle/CppCheckStyle

all : clean testbin


checkstyle : 
	$(CHKS) include/*.h
	$(CHKS) source/*.cpp

testbin : $(LL_TEST_BIN) $(BST_TEST_BIN)

$(LL_TEST_BIN) : $(LL_TEST_OBJ)
	g++ -Wall -o $(LL_TEST_BIN) $(LL_TEST_OBJ)
	chmod ugo+x $(LL_TEST_BIN)

$(BST_TEST_BIN) : $(BST_TEST_OBJ)
	g++ -Wall -o $(BST_TEST_BIN) $(BST_TEST_OBJ)
	chmod ugo+x $(BST_TEST_BIN)

obj/LinkedList-Test.o : source/LinkedList-Test.cpp libraries/utils/inc/UnitTest.h \
\include/LinkedList-Test.h
	g++ $(FLAGS) obj/LinkedList-Test.o -I libraries/utils/inc \
\-I include source/LinkedList-Test.cpp

obj/bst-test.o : source/bst-test.cpp libraries/utils/inc/UnitTest.h\
\include/bst-test.h
	g++ $(FLAGS) obj/bst-test.o -I libraries/utils/inc -I include source/bst-test.cpp

obj/LinkedList.o : source/LinkedList.cpp include/LinkedList.h
	g++ $(FLAGS) obj/LinkedList.o -I include source/LinkedList.cpp

obj/BST.o : source/BST.cpp include/BST.h
	g++ $(FLAGS) obj/BST.o -I include source/BST.cpp

runtests : testbin
	$(LL_TEST_BIN)
	$(BST_TEST_BIN)
clean :
	- echo "Removing generated files"
	- rm -f obj/*
	- rm -f binaries/*

