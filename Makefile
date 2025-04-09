# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Target executable name
TARGET = solitaire

# Object files
OBJS = Card.o CardList.o GameUtils.o main.o

# Rule to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compilation rules
Card.o: Card.cpp Card.h
	$(CXX) $(CXXFLAGS) -c Card.cpp

CardList.o: CardList.cpp CardList.h Card.h
	$(CXX) $(CXXFLAGS) -c CardList.cpp

GameUtils.o: GameUtils.cpp GameUtils.h Card.h CardList.h
	$(CXX) $(CXXFLAGS) -c GameUtils.cpp

main.o: main.cpp Card.h CardList.h GameUtils.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)

# Run the executable
run: $(TARGET)
	./$(TARGET)