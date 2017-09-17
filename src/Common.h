#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>
#include <stdio.h>

// Handle error with user msg
void DieWithUserMessage(const char *msg, const char *detail);
// Handle error with sys msg
void DieWithSystemMessage(const char *msg);

enum sizeConstants {
	MAXSTRINGLENGTH = 128,
	BUFSIZE = 512,
};

#endif // COMMON_H
