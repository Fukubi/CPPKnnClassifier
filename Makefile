CXX=g++
CXX_FLAGS=-Wall -Iincludes
LD_FLAGS=-o knn
SOURCES=main.cpp knn_classifier.cpp linear_algebra.cpp

all: $(SOURCES)
	$(CXX) $(LD_FLAGS) $^ $(CXX_FLAGS)