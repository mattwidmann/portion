EXE = portion
SOURCES = portion.c

CC = clang
CFLAGS = -std=c11 -pedantic -Wextra -Werror

default: debug

$(EXE): portion.o

%.o: %.c %.d

.PHONY = debug release

debug: CFLAGS += -g
debug: CPPFLAGS += -DDEBUG
debug: $(EXE)

release: CPPFLAGS += -DNDEBUG
release: $(EXE)

.PHONY = clean install

clean:
	rm -f *.o *.d $(EXE)

install: release
	cp $(EXE) ~/.bin/

include $(subst .c,.d,$(SOURCES))

%.d: %.c
	$(CC) $(CPPFLAGS) -MM -MG $< | sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' > $@

