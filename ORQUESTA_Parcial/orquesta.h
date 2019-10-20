#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[50];
    char lugar[50];
    int idTipoOrquesta;
    //int tipo;
    int isEmpty;
} eOrquesta;

typedef struct
{
    int id;
    char descripcion[20];
}eTipoOrquesta;
#endif // ORQUESTA_H_INCLUDED


int hardCodearOrquestas(eOrquesta vecOrquesta[],int tOrq);
void inicializarOrquesta(eOrquesta vecOrquesta[], int tOrq);
int buscarLibreOrquesta(eOrquesta vecOrquesta[], int tOrq);

void mostrarUnaOrquesta(eOrquesta vecOrquesta,eTipoOrquesta vecTipoOrquesta[], int tamTipoOrq);

int imprimirOrquestas(eOrquesta vecOrquesta[],int tOrq,eTipoOrquesta vecTipoOrquesta[], int tamTipoOrq);

int altaOrquestaMaestra(eOrquesta vecOrquesta[],int tOrq,int lastId,eTipoOrquesta vecTipoOrquesta[],int tamTipoOrq);
int buscarOrquestaId(eOrquesta vecOrquesta[],int tOrq,int idABuscar);
int bajaOrquesta(eOrquesta vecOrquesta[],int tOrq,eTipoOrquesta vecTipoOrquesta[],int tamTipoOrq);

int cargarNombreOrquesta(eOrquesta vecOrquesta[],int tOrq,int id,char descripcion[]);


/**TIPO DE ORQUESTA**/
void hardCodearTipoOrquesta(eTipoOrquesta vecTipoOrquesta[],int tamTipoInstru);
void mostrarTipoOrquesta(eTipoOrquesta vecTipoOrquesta);
void imprimirTiposOrquestas(eTipoOrquesta vecTipoOrquesta[],int tamTipoInstru);
int cargarDescripcionTipoOrquesta(eTipoOrquesta vecTipoOrquesta[],int tamTipoInstru,int id,char descripcion[]);



