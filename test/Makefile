CC_PREFIX=
CC=gcc
CC_FLAGS=-ansi

all: join.app cat.app
clean: clean_join.app clean_cat.app

join.app: join.c ../pzslib/pzs_join.h
	$(CC_PREFIX)$(CC) $(CC_FLAGS) -o $@ $^

clean_join.app:
	[ ! -f join.app ] || rm join.app


cat.app: cat.c ../pzslib/pzs_cat.h
	$(CC_PREFIX)$(CC) $(CC_FLAGS) -o $@ $^

clean_cat.app:
	[ ! -f cat.app ] || rm cat.app


