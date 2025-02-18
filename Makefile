rodCutting: cacheMeIfYouCan.o
	clang cacheMeIfYouCan.o -o cacheMeIfYouCan

main.o: cacheMeIfYouCan.o
	clang -c cacheMeIfYouCan.c

clean:
	rm *.o cacheMeIfYouCan