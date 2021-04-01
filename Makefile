CC = gcc
LD = gcc

CFLAGS = -g -std=c99 -pedantic -Wall -Wextra   
OBJLIB = htab_bucket_count.o htab_clear.o htab_erase.o htab_find.o htab_for_each.o htab_free.o \
htab_hash_function.o htab_init.o htab_lookup_adc.o htab_move.o htab_size.o 
all: tail wordcount wordcount-dynamic
#$< jmeno první závislosti		#$@ jmeno cile 		#$^ jmena vsech zavislosti

##############	TAIL ###############
tail: tail.o
	gcc $(CFLAGS) $< -o $@
tail.o: tail.c tail.h
	gcc $(CFLAGS) -c $< -o $@ 
#####################################

########### WORDCOUNT #############

wordcount: wordcount.o libhtab.a
	gcc $(CFLAGS) -o $@ $< -L . libhtab.a
wordcount-dynamic: wordcount.o libhtab.so
	gcc $(CFLAGS) -o $@ $< libhtab.so
wordcount.o: wordcount.c
	gcc $(CFLAGS) -c $< -o $@

# static library
libhtab.a: $(OBJLIB)
	ar -rcs libhtab.a $<
# shared library (dynamicly linked)
libhtab.so: $(OBJLIB)
	gcc $(CFLAGS) -shared -fPIC -o libhtab.so $(OBJLIB)

## object files 
htab_bucket_count.o: htab_bucket_count.c
	gcc $(CFLAGS) -fPIC -c $< -o $@ 
htab_clear.o: htab_clear.c
	gcc $(CFLAGS) -fPIC -c $< -o $@ 
htab_erase.o: htab_erase.c
	gcc $(CFLAGS) -fPIC -c $< -o $@ 
htab_find.o: htab_find.c
	gcc $(CFLAGS) -fPIC -c $< -o $@ 
htab_for_each.o: htab_for_each.c
	gcc $(CFLAGS) -fPIC -c $< -o $@ 
htab_free.o: htab_free.c
	gcc $(CFLAGS) -fPIC -c $< -o $@ 
htab_hash_function.o: htab_hash_function.c
	gcc $(CFLAGS) -fPIC -c $< -o $@ 
htab_init.o: htab_init.c
	gcc $(CFLAGS) -fPIC -c $< -o $@ 
htab_lookup_adc.o: htab_lookup_adc.c
	gcc $(CFLAGS) -fPIC -c $< -o $@ 
htab_move.o: htab_move.c
	gcc $(CFLAGS) -fPIC -c $< -o $@ 
htab_size.o: htab_size.c
	gcc $(CFLAGS) -fPIC -c $< -o $@ 
###################################


clean:
	rm *.o tail wordcount
run: tail 
	./tail
zip:
	zip xkuzni04.zip *.c *.cc *.h Makefile

