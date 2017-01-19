NOERR_FLAGS = $(subst -Werror,,$(subst -Wall,,$(CFLAGS)))

%.o: %.y
	yacc -d -o$*.c $<
	$(CC) -c $(NOERR_CFLAGS) $(_LIBINCPATHS) $*.c

%.o: %.l
	flex -o$*.c $<
	$(CC) -c $(NOERR_CFLAGS) $(_LIBINCPATHS) $*.c
