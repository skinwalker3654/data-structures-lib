SRC = test.c src/vector.c
CC = gcc
TARGET =  test


test: $(SRC)
	@echo "compiling the test..."
	$(CC) $^ -o $(TARGET)
	@echo "executing the test..."
	./$(TARGET)

clean:
	@echo "deleting test executable..."
	rm -rf $(TARGET)
