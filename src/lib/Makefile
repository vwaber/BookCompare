.PHONY: clean make obj

make: libHash.a

obj:
	cc -c *.c -I ../include/
	mv *.o obj

libHash.a: obj
	ar rcs libHash.a obj/*.o

clean:
	rm -f obj/*.o
	rm -f *.a
