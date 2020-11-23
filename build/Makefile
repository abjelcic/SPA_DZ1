CC = gcc

LDFLAGS = -lm

OPT = -D NDEBUG -O3 -march=native

DBG = -D DEBUG -Og -g -pedantic -Wall -Wextra -Wcast-align -Wcast-qual                \
                      -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op     \
                      -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls \
                      -Wshadow -Wsign-conversion -Wstrict-overflow=5 -Wswitch-default \
                      -Wundef -Werror -Wno-unused                                     \

SRC =         \
../src/main.c \
../src/list.c \

SRCTEST =      \
../test/test.c \
../src/list.c  \

INCL = -I ../src/headers

run: $(SRC)
	$(CC) $(OPT) $(INCL) $(SRC) $(LDFLAGS) -o run

dbg: $(SRC)
	$(CC) $(DBG) $(INCL) $(SRC) $(LDFLAGS) -o dbg

test: $(SRCTEST)
	$(CC) $(DBG) $(INCL) $(SRCTEST) $(LDFLAGS) -o test

clear:
	rm -f run dbg test
