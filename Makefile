SRCV = test/vectortest.c src/vector.c
SRCL = test/linkedlisttest.c src/linked_list.c
TARGET1 = testvector
TARGET2 = testlinkedlist
CC = gcc

testvector: $(SRCV)
	@echo "compiling the vector test..."
	$(CC) $^ -o $(TARGET1)
	@echo "executing the vector test..."
	./$(TARGET1)

testlinkedlist: $(SRCL)
	@echo "compiling the linkedlist test..."
	$(CC) $^ -o $(TARGET2)
	@echo "executing the linkedlist test..."
	./$(TARGET2)

clean:
	@echo "deleting test executable..."
	rm -rf $(TARGET1) $(TARGET2)

.PHONY: clean testvector testlinkedlist
