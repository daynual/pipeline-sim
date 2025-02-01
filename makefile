CXX = g++
CXXFLAGS = -Wall -g -pthread

SRCS = main.cpp

TARGET = sim

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
