CXX:=g++
BINDIR:=bin
OBJ:=obj
SRC:=src
INCLUDES:=$(SRC)/includes
SRCS:=$(wildcard $(SRC)/*.cpp)
DEFS:=$(wildcard $(INCLUDES)/*.cpp)
SRCOBJS:=$(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SRCS))
DEFOBJS:=$(patsubst $(INCLUDES)/%.cpp,$(OBJ)/%.o,$(DEFS))
HDRS:=$(patsubst $(INCLUDES)/%.cpp,$(INCLUDES)/%.h,$(DEFS))
OBJS:=$(SRCOBJS) $(DEFOBJS)
CXXFLAGS:=-I $(INCLUDES)
DEPS:=$(INCLUDES)/doubly-linked-list.h
TARGET:=$(BINDIR)/out

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ && ./$(TARGET)

$(OBJ)/%.o: $(INCLUDES)/%.cpp $(INCLUDES)/%.h $(DEPS)
	$(CXX) -c -o $@ $<

$(OBJ)/%.o: $(SRC)/%.cpp $(HDRS) $(DEPS)
	$(CXX) -c -o $@ $<

clean:
	rm $(BINDIR)/* $(OBJ)/*

run:
	./$(TARGET)