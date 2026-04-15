#ifndef REQUEST_LINE_H
#define REQUEST_LINE_H

typedef struct {
    char *method;
    char *requestURI;
    char *httpVersion;
} RequestLine;

void printRequestLine(RequestLine *req);
RequestLine *createRequestLine();
void freeRequestLine (RequestLine *req);

#endif