rodCutting: rodcut.o cut_list.o piece_values.o cache.o vec.o
	clang rodcut.o cut_list.o piece_values.o cache.o vec.o -o cacheMeIfYouCan

rodcut.o: rodcut.o
	clang -c rodcut.c

cut_list.o: cut_list.o
	clang -c cut_list.c

piece_values.o: piece_values.o
	clang -c piece_values.c

cache.o: cache.o
	clang -c cache.c

vec.o: vec.o
	clang -c vec.c

clean:
	rm *.o cacheMeIfYouCan