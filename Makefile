# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -std=c++11 -Iinclude  # -Iinclude lets you include headers from ./include

# Target executable name
TARGET = solitaire

# Source and object paths
SRC_DIR = include
OBJS = Card.o CardList.o GameUtils.o main.o

# Rule to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compilation rules
Card.o: $(SRC_DIR)/Card.cpp $(SRC_DIR)/Card.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Card.cpp -o Card.o

CardList.o: $(SRC_DIR)/CardList.cpp $(SRC_DIR)/CardList.h $(SRC_DIR)/Card.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/CardList.cpp -o CardList.o

GameUtils.o: $(SRC_DIR)/GameUtils.cpp $(SRC_DIR)/GameUtils.h $(SRC_DIR)/Card.h $(SRC_DIR)/CardList.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/GameUtils.cpp -o GameUtils.o

main.o: main.cpp $(SRC_DIR)/Card.h $(SRC_DIR)/CardList.h $(SRC_DIR)/GameUtils.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)

# Run the executable
run: $(TARGET)
	./$(TARGET)
