SUBJECT = htlin
EPSILON = 0

# ====================
# Envirnoment setup
# ====================
CXX = g++-4.9

# Directories
SRC_DIR := src/
OBJ_DIR := obj/
BIN_DIR := bin/
DAT_DIR := dat/

#CXXFLAGS += -Wall -O3 -std=c++11 -fopenmp -DMMF
CXXFLAGS += -Wall -O0 -std=c++11

# Create directories if not exist
$(OBJ_DIR):
	@echo "Create OBJ_DIR at '$(OBJ_DIR)'."
	@mkdir $@

$(BIN_DIR):
	@echo "Create BIN_DIR at '$(BIN_DIR)'."
	@mkdir $@

# Source files in sequence
SRC_FILES := $(addprefix $(SRC_DIR), $(wildcard $(SRC_DIR)*.cpp))
OBJ_FILES := $(addprefix $(OBJ_DIR), $(notdir $(SRC_FILES:.cpp=.o)))

# Main executable
MAIN = tree


.DEFAULT_GOAL := all


# If the first argument is "run"...
ifeq (run, $(firstword $(MAKECMDGOALS)))
    # use the rest as arguments for "run"
    RUN_ARGS := $(wordlist 2, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))
	# ...and turn them into do-nothing targets
    $(eval $(RUN_ARGS):;@:)
endif


all: clean build

debug: CXXFLAGS += -DDEBUG -g3
debug: clean build
	@mv $(BIN_DIR)$(MAIN) $(BIN_DIR)$(MAIN)_debug

build: $(BIN_DIR) $(OBJ_DIR) $(MAIN)
	@echo "Compile complete."

$(MAIN): $(OBJ_FILES)
	@echo "Linking all the object files..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(BIN_DIR)$@ $^ $(LFLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@echo "Compiling $<..." 
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

run:
ifneq ($(wildcard $(BIN_DIR)$(MAIN)),)
	@./$(BIN_DIR)$(MAIN) $(DAT_DIR)$(SUBJECT)/$(SUBJECT).train $(EPSILON)
else ifneq ($(wildcard $(BIN_DIR)$(MAIN)_debug),)
	@./$(BIN_DIR)$(MAIN)_debug $(DAT_DIR)$(SUBJECT)/$(SUBJECT).train $(EPSILON)
else
	@echo "Please execute 'make all', 'make build' or 'make debug' first."
endif

test: migrate
test:
	@echo "Executing TA's Makefile..."
	@cd ../hw4_ta && make run_tree && \
	echo "====================" && \
	cat tree_prediction.txt
	@echo "===================="

migrate:
	@echo "Copy binary into TA's project..."
	@cp ./$(BIN_DIR)$(MAIN) ../hw4_ta/

clean:
	@rm -rf $(OBJ_DIR)*
	@echo "'$(OBJ_DIR)' wiped..."
	@rm -rf $(BIN_DIR)*
	@echo "'$(BIN_DIR)' wiped..."
