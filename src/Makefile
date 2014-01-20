.PHONY: clean make libBST

make: libHash compareTexts

libHash:
	cd lib; make

compareTexts: compareTexts.c libHash
	cc -g -lm compareTexts.c -Llib -lHash -I include/ -o compareTexts


clean:
	cd lib; make clean
	rm -f compareTexts
	rm -f C_*.txt
	rm -f *o5*
	#rm -f *.txt
	#rm -f *Compare.dat
	#find . -type f ! -name "edge*" -name "*.ps" -execdir rm {} +
