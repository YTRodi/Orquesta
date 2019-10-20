#include "Orquesta.h"
#include "Instrumento.h"
#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    int edad;
    int idOrquesta;
    int idInstrumento;
    int isEmpty;
}eMusico;

#endif // MUSICO_H_INCLUDED

int hardCodearMusicos(eMusico vecMusico[],int tMusic);
void inicializarMusico(eMusico vecMusico[], int tMusic);
int buscarLibreMusico(eMusico vecMusico[], int tMusic);

void mostrarUnMusico(eMusico vecMusico,
                     eOrquesta vecOrquesta[],
                     int tOrq,
                     eInstrumento vecInstrumento[],
                     int tInstru);

int imprimirMusicos(eMusico vecMusico[],
                    int tMusic,
                    eOrquesta vecOrquesta[],
                    int tOrq,
                    eInstrumento vecInstrumento[],
                    int tInstru);

int altaMusicoMaestra(eMusico vecMusico[],
                      int tMusic,
                      int lastId,
                      eOrquesta vecOrquesta[],
                      int tOrq,
                      eTipoOrquesta vecTipoOrquesta[],
                      int tamTipoOrq,
                      eInstrumento vecInstrumento[],
                      int tInstru,
                      eTipoInstru vecTipoInstrumento[],
                      int tamTipoInstru);

int buscarMusicoId(eMusico vecMusico[],int tMusic,int idABuscar);

int menuModificacion();

int modificarMusico(eMusico vecMusico[],
                    int tMusic,
                    eOrquesta vecOrquesta[],
                    int tOrq,
                    eTipoOrquesta vecTipoOrquesta[],
                    int tamTipoOrq,
                    eInstrumento vecInstrumento[],
                    int tInstru);

int bajaMusico(eMusico vecMusico[],
               int tMusic,
               eOrquesta vecOrquesta[],
               int tOrq,
               eInstrumento vecInstrumento[],
               int tInstru);
