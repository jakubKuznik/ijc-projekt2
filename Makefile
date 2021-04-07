CC = gcc
LD = gcc

CFLAGS = -g -std=c99 -pedantic -Wall -Wextra   
OBJLIB = htab_bucket_count.o htab_clear.o htab_erase.o htab_find.o htab_for_each.o htab_free.o \
		 htab_hash_function.o htab_init.o htab_lookup_add.o htab_move.o htab_size.o

LD_LIBRARY_PATH="."

all: tail wordcount wordcount-dynamic libhtab.so libhtab.a
#$< jmeno první závislosti		#$@ jmeno cile 		#$^ jmena vsech zavislosti

##############	TAIL ###############
tail: tail.o
	$(CC) $(CFLAGS) $< -o $@
tail.o: tail.c tail.h
	$(CC) $(CFLAGS) -c $< -o $@ 
#####################################

########### WORDCOUNT #############

wordcount: wordcount.o io.o libhtab.a
	$(CC) $(CFLAGS) -o $@ $^ -L $(LD_LIBRARY_PATH)
wordcount-dynamic: wordcount.o io.o libhtab.so
	$(CC) $(CFLAGS) -o $@ $^
wordcount.o: wordcount.c
	$(CC) $(CFLAGS) -c $< -o $@


io.o: io.c 
	$(CC) $(CFLAGS) -c $< -o $@

# static library
libhtab.a: $(OBJLIB)
	ar -rcs libhtab.a $^
# shared library (dynamicly linked)
libhtab.so: $(OBJLIB)
	$(CC) $(CFLAGS) -shared -fPIC -o libhtab.so $(OBJLIB)

## object files 
htab_bucket_count.o: htab_bucket_count.c htab.h htab_struct.h
	$(CC) -fPIC -c $<
htab_clear.o: htab_clear.c htab.h htab_struct.h
	$(CC) -fPIC -c $<
htab_erase.o: htab_erase.c htab.h htab_struct.h
	$(CC) -fPIC -c $<
htab_find.o: htab_find.c htab.h htab_struct.h
	$(CC) -fPIC -c $<
htab_for_each.o: htab_for_each.c htab.h htab_struct.h
	$(CC) -fPIC -c $<
htab_free.o: htab_free.c htab.h htab_struct.h
	$(CC) -fPIC -c $<
htab_hash_function.o: htab_hash_function.c htab.h htab_struct.h
	$(CC) -fPIC -c $<
htab_init.o: htab_init.c htab.h htab_struct.h
	$(CC) -fPIC -c $<
htab_lookup_add.o: htab_lookup_add.c htab.h htab_struct.h
	$(CC) -fPIC -c $<
htab_move.o: htab_move.c htab.h htab_struct.h
	$(CC) -fPIC -c $<
htab_size.o: htab_size.c htab.h htab_struct.h
	$(CC) -fPIC -c $<
###################################

clean:
	rm *.o tail wordcount
run: tail 
	./tail
zip:
	zip xkuzni04.zip *.c *.h Makefile
git:
	sudo git add *.c *.h Makefile
	sudo git commit -m "Update."
	sudo git push

