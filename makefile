# Top level makefile, the real shit is at src/makefile

TARGETS=noopt 32bit

all:
	cd src && $(MAKE) $@

install:
	cd src && $(MAKE) $@

$(TARGETS):
	cd src && $(MAKE) $@

doc:
	cd doc && $(MAKE)

test:
	cd test && $(MAKE)

capi_test:
	gcc -g -c -I./src/ ./capi_tests/test.c -o ./capi_tests/bin/test.o
	gcc -g -I./src/ ./capi_tests/main.c -o ./capi_tests/main -L./src/ -lzlog \
		-lpthread ./capi_tests/bin/*.o

TAGS:
	find . -type f -name "*.[ch]" | xargs etags -

clean:
	cd src && $(MAKE) $@
	cd test && $(MAKE) $@
	cd doc && $(MAKE) $@
	rm -f TAGS

distclean: clean

dummy:

.PHONY: doc install test TAGS
