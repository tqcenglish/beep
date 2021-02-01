OS:=$(shell uname)
ifeq ($(OS),Darwin)
	LDFLAGS=-framework AudioUnit
endif

ifeq ($(OS),Linux)
	LDFLAGS=-lasound
endif

beep: beep.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

js: 
	cd quickjs && $(CC) lib.c libquickjs.a  -fPIC -shared -o lib.so $(LDFLAGS)
js_run: js
	cd quickjs && qjs index.js
clean:
	rm -f beep beep.exe beep.o
