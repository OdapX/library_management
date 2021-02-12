#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "headers.h"

/** L'entrée au menu principale **/
int main(void)
{

    system("cls");                                                                                                       /// Sa sert à effacer tout ce qu'il y a à l'écran .
    system("COLOR 1F");                                                                                                  /// Sa sert à colorer la fenêtre d'éxecution en bleu .
    printf("\n\n\n\n\n\n");
    printf("                     ____________________________________________________________________________");
    printf("\n                    |*                                                                          *|");
    printf("\n                    |                                                                            |");
    printf("\n                    |                                                                            |");
    printf("\n                    |                                                                            |");
    printf("\n                    |                         Gestion de librairie                               | ");
    printf("\n                    |                                                                            |");
    printf("\n                    |                                                                            |");
    printf("\n                    |                                                                            |");
    printf("\n                    |____________________________________________________________________________| ");
    printf(" \n\n                           *cliquez sur n'importe quelle touche pour continuer\n");
    getch();
    menu_principal();                                                                                                    /// Menu principale .
    return 0;
}
