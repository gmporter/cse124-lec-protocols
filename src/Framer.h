#ifndef FRAMER_H
#define FRAMER_H

int GetNextMsg(FILE *in, uint8_t *buf, size_t bufSize);
int PutMsg(uint8_t buf[], size_t msgSize, FILE *out);

#endif // FRAMER_H
