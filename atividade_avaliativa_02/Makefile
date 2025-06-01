CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = app_pedidos
SRCDIR = .
MENUDIR = menu
ARQUIVODIR = arquivo
PEDIDOSDIR = pedidos

SOURCES = main.c $(MENUDIR)/menu.c $(ARQUIVODIR)/arquivo.c $(PEDIDOSDIR)/pedidos.c
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET) *.dat

run: $(TARGET)
	./$(TARGET)

debug: CFLAGS += -g -DDEBUG
debug: $(TARGET)

install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

.PHONY: help
help:
	@echo "Uso:"
	@echo "  make        - Compila o projeto"
	@echo "  make run    - Compila e executa o programa"
	@echo "  make clean  - Remove arquivos compilados e dados"
	@echo "  make debug  - Compila com informações de debug"
	@echo "  make help   - Mostra esta ajuda"
