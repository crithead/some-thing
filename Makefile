CC = g++
CPP_FLAGS := -Wall -Werror
TEST_LIB = -lboost_unit_test_framework

ifeq ($(D),1)
GPP_FLAGS += -g
endif

ifeq ($(V),1)
E :=
else
E := @
endif

OBJ_DIR := obj
SRC_DIR := src

SOURCES := main.cpp
SOURCES += dictionary.cpp
SOURCES += exceptions.cpp
SOURCES += helpers.cpp
SOURCES += logger.cpp

TMP_SRC := $(addprefix $(SRC_DIR)/,$(SOURCES))
TMP_OBJ := $(TMP_SRC:.cpp=.o)
SOURCES := $(TMP_SRC)
OBJECTS := $(subst $(SRC_DIR),$(OBJ_DIR),$(TMP_OBJ))

TEST_SOURCES := test-main.cpp
TEST_SOURCES += test-dictionary.cpp
TEST_SOURCES += test-exceptions.cpp
TEST_SOURCES += test-helpers.cpp
TEST_SOURCES += test-logger.cpp

TMP_SRC := $(addprefix $(SRC_DIR)/,$(TEST_SOURCES))
TMP_OBJ := $(TMP_SRC:.cpp=.o)
TEST_SOURCES := $(TMP_SRC)
TEST_OBJECTS := $(subst $(SRC_DIR),$(OBJ_DIR),$(TMP_OBJ))

build: thing tester | $(OBJ_DIR)

thing: $(OBJECTS)
	$(E)$(CC) $(CPP_FLAGS) -o $@ $?

.PHONY: test
test: tester
	$(E)./tester --show-progress --log_level=unit_scope

#tester: $(filter-out $(OBJECTS)/main.o,$(OBJECTS)) $(TEST_OBJECTS)
#	$(E)$(CC) $(CPP_FLAGS) -o $@ $? $(TEST_LIB)

tester: obj/test-main.o $(filter-out $(OBJ_DIR)/main.o,$(OBJECTS))
	$(E)$(CC) $(CPP_FLAGS) -o $@ $^ $(TEST_LIB)

.PHONY: format
format:
	$(E)clang-format -i --style=file $(SRC_DIR)/*.hpp $(SRC_DIR)/*.cpp

obj/helpers.o : $(SRC_DIR)/helpers.hpp $(SRC_DIR)/helpers.cpp
obj/dictionary.o : $(SRC_DIR)/dictionary.hpp $(SRC_DIR)/dictionary.cpp
obj/exceptions.o : $(SRC_DIR)/exceptions.hpp $(SRC_DIR)/exceptions.cpp
obj/logger.o : $(SRC_DIR)/logger.hpp $(SRC_DIR)/logger.cpp
obj/main.o: $(SRC_DIR)/main.cpp

obj/%.o: src/%.cpp | $(OBJ_DIR)
	$(E)$(CC) $(CPP_FLAGS) -o $@  -c $<

$(OBJ_DIR):
	$(E)mkdir -p $(OBJ_DIR)

.PHONY: clean
clean:
	$(E)rm -rf $(OBJ_DIR)
	$(E)rm -f thing tester

.PHONY: print
print:
	@echo "SOURCES = $(SOURCES)"
	@echo "OBJECTS = $(OBJECTS)"
	@echo "TEST_SOURCES = $(TEST_SOURCES)"
	@echo "TEST_OBJECTS = $(TEST_OBJECTS)"
	@echo "filter OBJECTS = $(filter-out $(OBJ_DIR)/main.o,$(OBJECTS))"
