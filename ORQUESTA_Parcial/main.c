#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "Musico.h"
#include "Orquesta.h"
#include "Instrumento.h"
#include "informes.h"

#define TAMORQ 11
#define TAMMUSIC 28
#define TAMINSTRU 15
#define TAMTIPOORQ 3
#define TAMTIPOINSTRU 4


int menuGeneralTeatro();



void totalMusicos(eMusico vecMusico[],int tMusic);

int main()
{
    eOrquesta arrayOrquesta[TAMORQ];
    eTipoOrquesta arrayTipoOrquesta[TAMTIPOORQ];
    eMusico arrayMusico[TAMMUSIC];
    eInstrumento arrayInstrumento[TAMINSTRU];
    eTipoInstru arrayTipoInstrumento[TAMTIPOINSTRU];

    char exit = 'n';
    char exitInforme = 'n';

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
            modificarMusico(arrayMusico,TAMMUSIC,arrayOrquesta,TAMORQ,arrayTipoOrquesta,TAMTIPOORQ,arrayInstrumento,TAMINSTRU);
            break;

        case 6:
            bajaMusico(arrayMusico,TAMMUSIC,arrayOrquesta,TAMORQ,arrayInstrumento,TAMINSTRU);
            break;

        case 7:
            ordenarPorIdOrquesta(arrayMusico,TAMMUSIC);
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

        case 10:
            do
            {
                switch(menuInformes())
                {
                case 1:
                    listarOrquestasConMasDe5Musicos(arrayOrquesta,TAMORQ,arrayTipoOrquesta,TAMORQ,arrayMusico,TAMMUSIC);
                    break;

                case 2:
                    listarMusicosMayoresA30(arrayOrquesta,TAMORQ,arrayMusico,TAMMUSIC,arrayInstrumento,TAMINSTRU);
                    break;

                case 3:
                    listarOrquestaLugarSeleccionado(arrayOrquesta,TAMORQ,arrayTipoOrquesta,TAMTIPOORQ);
                    break;

                case 4:
                    listarOrquestasCompletas(arrayOrquesta,TAMORQ,arrayTipoOrquesta,TAMTIPOORQ,arrayMusico,TAMMUSIC,arrayInstrumento,TAMINSTRU,arrayTipoInstrumento,TAMTIPOINSTRU);
                    break;

                case 5:
                    listarMusicosDeUnaOrquestaSeleccionada(arrayOrquesta,TAMORQ,arrayTipoOrquesta,TAMTIPOORQ,arrayMusico,TAMMUSIC,arrayInstrumento,TAMINSTRU,arrayTipoInstrumento,TAMTIPOINSTRU);
                    break;

                case 6:
                    orquestaConMasMusicos(arrayOrquesta,TAMORQ,arrayTipoOrquesta,TAMTIPOORQ,arrayMusico,TAMMUSIC,arrayInstrumento,TAMINSTRU,arrayTipoInstrumento,TAMTIPOINSTRU);
                    break;

                case 7:
                    listarMusicosCuerdas(arrayMusico,TAMMUSIC,arrayOrquesta,TAMORQ,arrayInstrumento,TAMINSTRU,arrayTipoInstrumento,TAMTIPOINSTRU);
                    break;

                case 8:
                    imprimirPromedioDeMusicosPorOrquesta(arrayMusico,TAMMUSIC,arrayOrquesta,TAMORQ);
                    break;

                case 9:
                    imprimirTiposOrquestas(arrayTipoOrquesta,TAMTIPOORQ);
                    break;

                case 10:
                    printf("Confirma salir? <s/n>: ");
                    fflush(stdin);
                    exitInforme = getche();
                    printf("\n\n");
                    break;

                default:
                    printf("\n\n...Usted no ingreso una opcion valida...");
                    printf("\n\n...--Redireccionando al menu--...\n\n");

                }
                system("pause");

            }
            while(exitInforme == 'n');
            break;

        case 11:
            printf("Confirma salir? <s/n>: ");
            fflush(stdin);
            exit = getche();
            printf("\n\n");
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
    printf("10 - Informes\n");
    printf("11 - Salir\n");
    getInt(&option,"\nIngrese opcion: ","\nError.Opcion no valida",1,11,2);
    return option;
}



