#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "headers.h"

/** L'entr�e au menu principale **/
int main(void)
{

    system("cls");                                                                                                       /// Sa sert � effacer tout ce qu'il y a � l'�cran .
    system("COLOR 1F");                                                                                                  /// Sa sert � colorer la fen�tre d'�xecution en bleu .
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
