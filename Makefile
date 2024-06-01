CC = g++
CFLAGS = -g -Wall -pedantic -Wextra -Werror -std=c++17

TARGET = bindecimal

all: $(TARGET)

rc: $(TARGET) run clean

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

clean:
	@rm -rf $(TARGET) $(TARGET).dSYM

run:
	./$(TARGET)
