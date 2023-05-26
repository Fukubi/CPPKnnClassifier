CXX=g++
CXX_FLAGS=-Wall -Iincludes
LD_FLAGS=-o knn
SOURCES=main.cpp

all: $(SOURCES)
	$(CXX) $(LD_FLAGS) $^ $(CXX_FLAGS)