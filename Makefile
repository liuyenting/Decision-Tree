SUBJECT = a4a
EPSILON = 0
TREES	= 10

OPTIMIZE = 3

# ====================
# Envirnoment setup
# ====================
CXX = g++-4.9
CXXFLAGS += -Wall -std=c++11 -O$(OPTIMIZE)

tree: src/gen_dtree.cpp
	$(CXX) $(CXXFLAGS) src/gen_dtree.cpp -o tree

forest: src/gen_dforest.cpp
	$(CXX) $(CXXFLAGS) src/gen_dforest.cpp -o forest

run_tree:
	./bin/tree dat/$(SUBJECT)/$(SUBJECT).train $(EPSILON)

run_forest:
	./bin/forest dat/$(SUBJECT)/$(SUBJECT).train $(TREES)

clean:
	@rm -rf bin/*
