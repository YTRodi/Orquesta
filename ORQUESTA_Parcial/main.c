#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "Musico.h"
#include "Orquesta.h"
#include "Instrumento.h"

#define TAMORQ 11
#define TAMMUSIC 11
#define TAMINSTRU 8
#define TAMTIPOORQ 3
#define TAMTIPOINSTRU 4


int menuGeneralTeatro();

int main()
{
    eOrquesta arrayOrquesta[TAMORQ];
    eTipoOrquesta arrayTipoOrquesta[TAMTIPOORQ];
    eMusico arrayMusico[TAMMUSIC];
    eInstrumento arrayInstrumento[TAMINSTRU];
    eTipoInstru arrayTipoInstrumento[TAMTIPOINSTRU];

    char exit = 'n';

    int idOrquesta = 1;
    int idMusico = 1000;
    int idInstrumento = 100;

    inicializarOrquesta(arrayOrquesta,TAMORQ);
    inicializarMusico(arrayMusico,TAMMUSIC);
    inicializarInstrumento(arrayInstrumento,TAMINSTRU);

    idOrquesta = idOrquesta + hardCodearOrquestas(arrayOrquesta,TAMORQ);
    hardCodearTipoOrquesta(arrayTipoOrquesta,TAMTIPOORQ);
    idMusico = idMusico + hardCodearMusicos(arrayMusico,TAMMUSIC);
    idInstrumento = idInstrumento + hardCodearInstrumento(arrayInstrumento,TAMINSTRU);
    hardCodearTipoInstrumento(arrayTipoInstrumento,TAMTIPOINSTRU);

    do
    {
        switch(menuGeneralTeatro())
        {
            case 1:
                if(altaOrquestaMaestra(arrayOrquesta,TAMORQ,idOrquesta,arrayTipoOrquesta,TAMTIPOORQ))
                {
                    idOrquesta++;
                }
                break;

            case 2:
                bajaOrquesta(arrayOrquesta,TAMORQ,arrayTipoOrquesta,TAMTIPOORQ);
                break;

            case 3:
                imprimirOrquestas(arrayOrquesta,TAMORQ,arrayTipoOrquesta,TAMTIPOORQ);
                break;

            case 4:
                if(altaMusicoMaestra(arrayMusico,TAMMUSIC,idMusico,arrayOrquesta,TAMORQ,arrayTipoOrquesta,TAMTIPOORQ,arrayInstrumento,TAMINSTRU,arrayTipoInstrumento,TAMTIPOINSTRU))
                {
                    idMusico++;
                }
                break;

            case 5:
                modificarMusico(arrayMusico,TAMMUSIC,arrayOrquesta,TAMORQ,arrayInstrumento,TAMINSTRU);
                break;

            case 6:
                bajaMusico(arrayMusico,TAMMUSIC,arrayOrquesta,TAMORQ,arrayInstrumento,TAMINSTRU);
                break;

            case 7:
                imprimirMusicos(arrayMusico,TAMMUSIC,arrayOrquesta,TAMORQ,arrayInstrumento,TAMINSTRU);
                break;

            case 8:
                if(altaInstrumentoMaestra(arrayInstrumento,TAMINSTRU,idInstrumento,arrayTipoInstrumento,TAMTIPOINSTRU))
                {
                    idInstrumento++;
                }
                break;

            case 9:
                imprimirInstrumentos(arrayInstrumento,TAMINSTRU,arrayTipoInstrumento,TAMTIPOINSTRU);
                break;

            case 11:
                printf("Confirma salir? <s/n>: ");
                fflush(stdin);
                exit = getche();
                printf("\n\n");
                break;

            case 20:
                imprimirTiposOrquestas(arrayTipoOrquesta,TAMTIPOORQ);
                break;

            default:
                printf("\n\n...Usted no ingreso una opcion valida...");
                printf("\n\n...--Redireccionando al menu--...\n\n");
        }
        system("pause");

    }
    while(exit == 'n');

    return 0;
}

int menuGeneralTeatro()
{
    int option;
    system("cls");
    printf("..::Bienvenido al menu de teatro::..\n\n");
    printf("1 - Alta Orquesta\n");
    printf("2 - Eliminar Orquesta\n");
    printf("3 - Imprimir Orquestas\n");
    printf("4 - Alta Musico\n");
    printf("5 - Modificar Musico\n");
    printf("6 - Baja Musico\n");
    printf("7 - Imprimir Musicos\n");
    printf("8 - Alta Instrumento\n");
    printf("9 - Imprimir Instrumentos\n");
    printf("11 - Salir\n");
    printf("20 - Imprimir tipo de orquesta\n");
    getInt(&option,"\nIngrese opcion: ","\nError.Opcion no valida",1,99,2);
    return option;
}

