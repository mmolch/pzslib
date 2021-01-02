CC_PREFIX=
CC=gcc
CC_FLAGS=-ansi

all: join cat
clean: clean_join clean_cat

join: join.c ../pzslib/pzs_join.h
	$(CC_PREFIX)$(CC) $(CC_FLAGS) -o $@ $^

clean_join:
	[ ! -f join ] || rm join


cat: cat.c ../pzslib/pzs_cat.h
	$(CC_PREFIX)$(CC) $(CC_FLAGS) -o $@ $^

clean_cat:
	[ ! -f cat ] || rm cat


