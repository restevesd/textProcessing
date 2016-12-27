CC=gcc

test: test_compile test_run

test_compile:
	$(CC) hashString.c testHashString.c -o testHashString -g -Wall
	$(CC) hashString.c gram.c testGram.c -o testGram -g -Wall	

test_run:
	./testHashString
	./testGram

compile: 
	$(CC) -pg hashString.c gram.c gramBT.c readFile.c findMax.c -o findMax -g -Wall 

run: 
	./findMax

get_data:
	wget https://d396qusza40orc.cloudfront.net/dsscapstone/dataset/Coursera-SwiftKey.zip -P data
	unzip data/Coursera-SwiftKey.zip -d data
	rm data/Coursera-SwiftKey.zip

create_test_file:
	head -n 10000  data/final/en_US/en_US.twitter.txt > data/final/en_US/en_US.test.txt

clean_txt_files:
	./cleanTextFile.sh < data/final/en_US/en_US.twitter.txt > data/en_US.twitter.clean.txt
	./cleanTextFile.sh < data/final/en_US/en_US.blogs.txt > data/en_US.blogs.clean.txt  	
	./cleanTextFile.sh < data/final/en_US/en_US.news.txt > data/en_US.news.clean.txt  	
