CC=g++
CFLAGS=-ggdb -std=c++11 -I. -Wall -Wno-sign-compare -pedantic

DEPS=VoteWriter.c Framer.h VoteProtocol.h VoteEncoding.h Common.c Common.h

all: VoteWriter-len-binary VoteWriter-len-text VoteWriter-delim-binary VoteWriter-delim-text

VoteWriter-len-binary: $(DEPS) framing/LengthFramer.c parsing/VoteEncodingBin.c
	$(CC) $(CFLAGS) -o bin/VoteWriter-len-binary VoteWriter.c Common.c framing/LengthFramer.c parsing/VoteEncodingBin.c

VoteWriter-len-text: $(DEPS) framing/LengthFramer.c parsing/VoteEncodingText.c
	$(CC) $(CFLAGS) -o bin/VoteWriter-len-text VoteWriter.c Common.c framing/LengthFramer.c parsing/VoteEncodingText.c

VoteWriter-delim-binary: $(DEPS) framing/DelimFramer.c parsing/VoteEncodingBin.c
	$(CC) $(CFLAGS) -o bin/VoteWriter-delim-binary VoteWriter.c Common.c framing/DelimFramer.c parsing/VoteEncodingBin.c

VoteWriter-delim-text: $(DEPS) framing/DelimFramer.c parsing/VoteEncodingText.c
	$(CC) $(CFLAGS) -o bin/VoteWriter-delim-text VoteWriter.c Common.c framing/DelimFramer.c parsing/VoteEncodingText.c

clean:
	rm -rf bin/VoteWriter-len-binary bin/VoteWriter-len-text bin/VoteWriter-delim-binary bin/VoteWriter-delim-text
