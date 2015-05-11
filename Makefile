SUBJECT = a1a
EPSILON = 0

OPTIMIZE = 3

# ====================
# Envirnoment setup
# ====================
CXX = g++-4.9

# Directories
SRC_DIR = src/
TREE_SRC_DIR := $(SRC_DIR)tree/
FOREST_SRC_DIR := $(SRC_DIR)forest/
OBJ_DIR = obj/
TREE_OBJ_DIR := $(OBJ_DIR)tree/
FOREST_OBJ_DIR := $(OBJ_DIR)forest/
BIN_DIR = bin/
DAT_DIR = dat/

CXXFLAGS += -Wall -std=c++11 -O$(OPTIMIZE)

# Create directories if not exist
$(TREE_OBJ_DIR):
	@echo "Create OBJ_DIR at '$(TREE_OBJ_DIR)'."
	@mkdir -p $@

$(FOREST_OBJ_DIR):
	@echo "Create OBJ_DIR at '$(FOREST_OBJ_DIR)'."
	@mkdir -p $@

$(BIN_DIR):
	@echo "Create BIN_DIR at '$(BIN_DIR)'."
	@mkdir $@

# Source files in sequence
TREE_SRC_FILES := $(addprefix $(TREE_SRC_DIR), $(wildcard $(TREE_SRC_DIR)*.cpp))
FOREST_SRC_FILES := $(addprefix $(FOREST_SRC_DIR), $(wildcard $(FOREST_SRC_DIR)*.cpp))

TREE_OBJ_FILES := $(addprefix $(TREE_OBJ_DIR), $(notdir $(TREE_SRC_DIR:.cpp=.o)))
FOREST_OBJ_FILES := $(addprefix $(FOREST_OBJ_DIR), $(notdir $(FOREST_SRC_DIR:.cpp=.o)))

# Main executable
TREE_MAIN = tree
FOREST_MAIN = forest


.DEFAULT_GOAL := all


# If the first argument is "run"...
ifeq (run, $(firstword $(MAKECMDGOALS)))
    # use the rest as arguments for "run"
    RUN_ARGS := $(wordlist 2, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))
	# ...and turn them into do-nothing targets
    $(eval $(RUN_ARGS):;@:)
endif


all: clean tree forest

#debug: CXXFLAGS := $(filter-out -O$(OPTIMIZE), $(CXXFLAGS))
#debug: CXXFLAGS += -DDEBUG -O0 -g3 -pg
#debug: clean build
#	@mv $(BIN_DIR)$(TREE_MAIN) $(BIN_DIR)$(TREE_MAIN)_debug

$(TREE_MAIN): $(TREE_OBJ_FILES)
	@echo "Linking all the object files for tree..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(BIN_DIR)$@ $^ $(LFLAGS)

$(FOREST_MAIN): $(FOREST_OBJ_FILES)
	@echo "Linking all the object files for forest..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(BIN_DIR)$@ $^ $(LFLAGS)

$(TREE_OBJ_DIR)%.o: $(TREE_SRC_DIR)%.cpp
	@echo "Compiling $<..." 
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

$(FOREST_OBJ_DIR)%.o: $(FOREST_SRC_DIR)%.cpp
	@echo "Compiling $<..." 
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

tree: $(BIN_DIR) $(TREE_OBJ_DIR) $(TREE_MAIN)
	@echo "Compile complete. Built with CXXFLAGS = $(CXXFLAGS)"

run_tree:
ifneq ($(wildcard $(BIN_DIR)$(TREE_MAIN)),)
	@./$(BIN_DIR)$(TREE_MAIN) $(DAT_DIR)$(SUBJECT)/$(SUBJECT).train $(EPSILON)
else ifneq ($(wildcard $(BIN_DIR)$(TREE_MAIN)_debug),)
	@./$(BIN_DIR)$(TREE_MAIN)_debug $(DAT_DIR)$(SUBJECT)/$(SUBJECT).train $(EPSILON)
else
	@echo "Please execute 'make all', 'make build' or 'make debug' first."
endif

forest: $(BIN_DIR) $(FOREST_OBJ_DIR) $(FOREST_MAIN)
	@echo "Compile complete. Built with CXXFLAGS = $(CXXFLAGS)"

run_forest:
ifneq ($(wildcard $(BIN_DIR)$(FOREST_MAIN)),)
	@./$(BIN_DIR)$(FOREST_MAIN) $(DAT_DIR)$(SUBJECT)/$(SUBJECT).train $(EPSILON)
else ifneq ($(wildcard $(BIN_DIR)$(FOREST_MAIN)_debug),)
	@./$(BIN_DIR)$(FOREST_MAIN)_debug $(DAT_DIR)$(SUBJECT)/$(SUBJECT).train $(EPSILON)
else
	@echo "Please execute 'make all', 'make build' or 'make debug' first."
endif

migrate:
	@echo "Copy binaries into TA's project..."
	@cp ./$(BIN_DIR)$(TREE_MAIN) ../hw4_ta/
	@cp ./$(BIN_DIR)$(FOREST_MAIN) ../hw4_ta/

clean:
	@rm -rf $(OBJ_DIR)*
	@echo "'$(OBJ_DIR)' wiped..."
	@rm -rf $(BIN_DIR)*
	@echo "'$(BIN_DIR)' wiped..."
