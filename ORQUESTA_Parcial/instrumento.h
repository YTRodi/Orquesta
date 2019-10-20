#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED
typedef struct
{
    int id;
    char nombre[50];
    int tipo;
    int isEmpty;
}eInstrumento;

typedef struct
{
    int id;
    char descripcion[20];
}eTipoInstru;

#endif // INSTRUMENTO_H_INCLUDED

int hardCodearInstrumento(eInstrumento vecInstru[],int tInstru);
void inicializarInstrumento(eInstrumento vecInstru[], int tInstru);
int buscarLibreInstrumento(eInstrumento vecInstru[], int tInstru);
void mostrarUnIstrumento(eInstrumento vecInstru,eTipoInstru vecTipoInstrumento[],int tamTipoInstru);
int imprimirInstrumentos(eInstrumento vecInstrumento[],int tInstru, eTipoInstru vecTipoInstrumento[],int tamTipoInstru);
int altaInstrumentoMaestra(eInstrumento vecInstrumento[],
                           int tInstru,
                           int lastId,
                           eTipoInstru vecTipoInstrumento[],
                           int tamTipoInstru);

int cargarNombreInstrumento(eInstrumento vecInstrumento[],int tInstru,int id,char descripcion[]);


/**TIPO DE ORQUESTA**/
void hardCodearTipoInstrumento(eTipoInstru vecTipoInstrumento[],int tamTipoInstru);
void mostrarTipoInstrumento(eTipoInstru vecTipoInstrumento);
void imprimirTiposInstrumentos(eTipoInstru vecTipoInstrumento[],int tamTipoInstru);
int cargarDescripcionTipoInstrumento(eTipoInstru vecTipoInstrumento[],int tamTipoInstru,int id,char descripcion[]);


