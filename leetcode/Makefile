CPP=${CXX}
CC=${CC}
CFLAGS=-std=c++11 -Wall -g  -DDEBUG
LINKS	=  -lgtest -lpthread -lstdc++ -lm


SRCS	= IntegerToRoman.cpp \
		ListNode.cpp \
		StringToInteger.cpp \
		ZigZagConversion.cpp \
		RegularExpressionMatching.cpp \
		reverseInteger.cpp \
		MedianOfTwoSortedArrays.cpp \
		isPalindrome.cpp \
		ContainerWithMostWater.cpp \
		LongestPalindromicSubstring.cpp \
		LongestSubstringWithoutRepeatingCharacters.cpp \
		LongestCommonPrefix.cpp \
		3Sum.cpp \
		3SumClosest.cpp \
		4Sum.cpp \
		LetterCombinationsOfPhoneNumber.cpp \
		RemoveNthNodeFromEndOfList.cpp \
		ValidParentheses.cpp \
		MergeTwoSortedList.cpp \
		generateParentheses.cpp \
		MergeKSortedList.cpp \
		SwapNodesInPairs.cpp \
		ReverseNodesInKGroup.cpp \
		main.cpp

OBJS := $(SRCS:%.cpp=%.o)

TEST=a.out

VPATH		 = ./

INC=-I. \
	-I./c++ \
	-I./googletest/googletest/include

LIB=-L. \
	-L./googletest/build/googlemock/gtest

all: $(TEST)

gtest:
	git submodule init
	git submodule update
	mkdir googletest/build
	cd googletest/build;cmake ..;make



$(TEST):$(OBJS)
	 $(CPP) $(CFLAGS) $(LIB) $(OBJS) -o $@ $(LINKS)

%.o:%.cpp
	 $(CPP) $(CFLAGS) $(INC) -c $< -o $@

%.o:%.c
	 $(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(OBJS)
	rm -rf $(TEST)
	rm -rf core
