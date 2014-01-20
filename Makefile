.PHONY: all install help test clean release

all:
	cd src; make
	#cd test; make

install: all
	mv src/compareTexts bin/;

help:
	@echo "all:\t Produces executables inside src/\n"
	@echo "install: Runs all target then puts exectuables in bin/\n"
	@echo "help:\t Prints this menu\n"
	#@echo "test:\t Runs install target then runs timing script\n"
	@echo "clean:\t Removes all files created by other targets\n"
	@echo "release: Creates a tar file of this directory\n"


test:
	cd test; make;

clean:
	cd src; make clean;
	#cd test; make clean;
	rm -r -f bin/*;
#	rm -r -f test/*png
#	rm -r -f test/*.dat

release: clean
#	cd ..; tar cvzf Waber_HW05.tgz list;

