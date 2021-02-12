#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "headers.h"
/** Le menu principale **/
void menu_principal(void)
{
    int choix, ret;

    do

    {
        system("COLOR 1F");                                                                                                                            /// Sa sert � colorer la fen�tre d'�xecution en bleu .
        system("cls");                                                                                                                                 /// Sa sert � effacer tout ce qu'il y a � l'�cran .
        printf("\n\n\n\n\n\n");
        printf("                   ____________________________________________________________________________");
        printf("\n                  |                                                                            |");
        printf("\n                  |                                                                            |");
        printf("\n                  |                                                                            |");
        printf("\n                  |                           MENU PRINCPAL                                    | ");
        printf("\n                  |                                                                            |");
        printf("\n                  |                                                                            |");
        printf("\n                  |____________________________________________________________________________| ");
        printf("\n                 _____________||___________________________________________________||________________\n");

        printf("\n\n                            || 1 : Gestion des adherents                         || 2 : Gestion des livres     ");
        printf("\n\n                            || 3 : gestion des emprunts                          || 4 : QUITTER");
        printf("\n\n               _____________||___________________________________________________||__________________\n");
        printf("\n  ->Entrer votre choix: ");
        ret = scanf("%d", &choix);
        if (ret != 1)                                                                                                                                  /// si on lit d'autre chose qu'un entier alors on aura Erreur de saisie .
        {
            printf("erreur de saisie\n");
            exit(EXIT_FAILURE);
        }
        switch (choix)
        {
        case 1:
            GESTION_ADHERENT();                                                                                                                        /// L'entr�e au Menu de gestion d'adh�rent .
            break;
        case 2:
            GESTION_LIVRES();                                                                                                                          /// L'entr�e au Menu de gestion de livre  .
            break;
        case 3: GESTION_EMPRUNTS();                                                                                                                    /// L'entr�e au Menu de gestion d'emprunte .
            break;
        case 4:
            QUITTER();                                                                                                                                 /// quitter l'application si on confirme par O=oui sinon on revient au menu principale .
            break;
        default:
            printf("le choix doit etre de 1 a 4");                                                                                                     /// Le choix d'entier doit �tre entre 1 et 4 sinon on refait la lecture .
        }
    } while (1);
}


