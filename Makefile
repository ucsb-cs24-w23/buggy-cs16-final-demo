CXX = g++

CXXFLAGS = -Wall -Wno-uninitialized -std=c++11 -g -O0

BINARIES= test_tallyTheVote test_countVotes test_votedOut

COMMON_OBJECT_FILES = survivor.o tddFuncs.o 

all: ${BINARIES}

tests: ${BINARIES}
	./test_countVotes 1
	./test_countVotes 2
	./test_countVotes 3
	./test_countVotes 4
	./test_votedOut 1
	./test_votedOut 2
	./test_votedOut 3
	./test_tallyTheVote 1
	./test_tallyTheVote 2
	./test_tallyTheVote 3
	

test_countVotes: test_countVotes.o ${COMMON_OBJECT_FILES}
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

test_votedOut: test_votedOut.o ${COMMON_OBJECT_FILES}
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

test_tallyTheVote: test_tallyTheVote.o ${COMMON_OBJECT_FILES}
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@


clean:
	/bin/rm -f ${BINARIES} *.o
