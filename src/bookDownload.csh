#!/bin/csh

make clean
make

set books = `cat bookList.dat`

foreach book1 ( $books )
	echo retrieving $book1:t
	wget $book1
end

