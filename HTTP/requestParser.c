#include "requestParser.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int parseRequestLine(const char *rawRequestLine , RequestLine *req){

    size_t n = strlen(rawRequestLine) / sizeof(rawRequestLine[0]);

    int count = 0;
    size_t lastLetter = 0;

    // Parsear todos los espacios en blanco y mirar que espacio corresponde a que parte del request
    for(size_t i = 0 ; i < n ; i++){
        
        // Movemos el puntero i+1 veces (Ya que i es el espacio que separa entre expresiones)
        // Al hacer rawRequestLine + lastLetter estamos moviendo lastLetter veces el puntero para que apunte a la ultima letra encontrada
        if(rawRequestLine[i] == ' ' && count == 0){

            size_t length = i - lastLetter;

            req->method = malloc(sizeof(char) * length + 1);
            strncpy(req->method , rawRequestLine + lastLetter , length);
            req->method[length] = '\0';

            lastLetter = i+1;
            count++;

            continue;
        }
        
        if(rawRequestLine[i] == ' ' && count == 1){

            size_t length = i - lastLetter;

            req->requestURI = malloc(sizeof(char) * length + 1);
            strncpy(req->requestURI , rawRequestLine + lastLetter , length);
            req->requestURI[length] = '\0';

            lastLetter = i+1;
            count++;

        }

        if(rawRequestLine[i] == '\r' && count == 2){

            size_t length = i - lastLetter;

            req->httpVersion = malloc(sizeof(char) * length + 1);
            strncpy(req->httpVersion , rawRequestLine + lastLetter , length);\
            req->httpVersion[length] = '\0';

            lastLetter = i+1;
            count++;
        }
    }

    if(count != 3){
        freeRequestLine(req); // Limpiar los posibles campos que se hayan llenado
        printf("No se encontrar los 3 argumentos necesarios del request line\n");
        return -1;
    }

    return 0;
}