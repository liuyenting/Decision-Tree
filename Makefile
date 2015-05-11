SUBJECT = a1a
EPSILON = 0

OPTIMIZE = 3

# ====================
# Envirnoment setup
# ====================
CXX = g++-4.9
CXXFLAGS += -Wall -std=c++11 -O$(OPTIMIZE)

tree: src/gen_dtree.cpp
	$(CXX) $(CXXFLAGS) src/gen_dtree.cpp -o bin/tree

forest: src/gen_dforest.cpp
	$(CXX) $(CXXFLAGS) src/gen_dforest.cpp -o bin/tree

run_tree:
	./bin/tree dat/$(SUBJECT)/$(SUBJECT).train $(EPSILON)

run_forest:
	./bin/forest dat/$(SUBJECT)/$(SUBJECT).train $(EPSILON)

migrate:
	@cp bin/tree ../hw4_ta/
	@cp bin/forest ../hw4_ta/

clean:
	@rm -rf bin/*
