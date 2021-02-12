#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "headers.h"

/** Le r�le de cet fonction est de revenir au menu principale **/
void QUITTER_menu(void)
{
    system("cls");                                                           /// Sa sert � effacer tout ce qu'il y a � l'�cran .
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\t\t\t    voulez-vous vraiment quitter ?(O/N) : ");
    char ch;
    int ret;
    ret = scanf(" %c", &ch);
    if (ret != 1)                                                            /// si on lit d'autre chose qu'une caract�re alors on aura Erreur de saisie .
    {
        printf("erreur de saisie\n");
        exit(EXIT_FAILURE);
    }
    if (ch == 'o' || ch == 'O')                                              /// si on saisie O=oui alors on revient au menu principale sinon on return au menu ou on �tait d�ja .
        menu_principal();
    return;
}


/** Le r�le de cet fonction est de quitter le programme **/
void QUITTER(void)
{
    system("cls");                                                           /// Sa sert � effacer tout ce qu'il y a � l'�cran .
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\t\t\t      voulez-vous vraiment quitter ?(O/N) : ");
    char ch;
    int ret;
    ret = scanf(" %c", &ch);
    if (ret != 1)                                                            /// si on lit d'autre chose qu'une caract�re alors on aura Erreur de saisie .
    {
        printf("erreur de saisie\n");
        exit(EXIT_FAILURE);
    }
    if (ch == 'o' || ch == 'O')                                              /// si on saisie O=oui alors on quitte l'�xecution sinon on reste au menu principale .
        exit(1);
    return;
}



