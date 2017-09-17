#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include "Common.h"
#include "VoteProtocol.h"
#include "Framer.h"
#include "VoteEncoding.h"

int main(int argc, char *argv[]) {
  if (argc < 3 || argc > 4)  // Test for correct # of args
    DieWithUserMessage("Parameter(s)", "<OutputFile> <Candidate> [I]");

  char *outfile = argv[1];
  int candi = atoi(argv[2]);
  if (candi < 0 || candi > MAX_CANDIDATE)
    DieWithUserMessage("Candidate # not valid", argv[2]);

  bool inq = argc > 3 && strcmp(argv[3], "I") == 0;

  // Create the output file
  FILE *str = fopen(outfile, "wb"); // Wrap for stream I/O
  if (str == NULL)
    DieWithSystemMessage("fopen() failed");

  // Set up info for a request
  VoteInfo vi;
  memset(&vi, 0, sizeof(vi));

  vi.isInquiry = inq;
  vi.candidate = candi;

  // Encode for transmission
  uint8_t outbuf[MAX_WIRE_SIZE];
  size_t reqSize = Encode(&vi, outbuf, MAX_WIRE_SIZE);

  // Print info
  printf("Writing out a %ld-byte %s for candidate %d...\n", reqSize,
	 (inq ? "inquiry" : "vote"), candi);

  // Frame and write
  if (PutMsg(outbuf, reqSize, str) < 0)
    DieWithSystemMessage("PutMsg() failed");

  // Close the stream
  fclose(str);

  exit(0);
}
