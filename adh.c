#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "headers.h"


/** Le menu de gestion d'adh�rent **/
void GESTION_ADHERENT(void)
{
    int choix, ret;
     system("COLOR 1F");                                                                                                                                          /// Sa sert � colorer la fen�tre d'�xecution en bleu .
    do
    {
        system("cls");                                                                                                                                            /// Sa sert � effacer tout ce qu'il y a � l'�cran .
        printf("\n\n\n\n\n\n");
        printf("              ________________________________________________________________________________________________");
        printf("\n            |                                                                                                 |");
        printf("\n            |                                                                                                 |");
        printf("\n            |                                     GESTION DES ADHERENTS                                       | ");
        printf("\n            |                                                                                                 |");
        printf("\n            |_________________________________________________________________________________________________| ");
        printf("\n           _____________________________||___________________________________________________||_______________________\n");
        printf("\n\n             |*| 1 : ajouter                                           |*| 2 :modifier");
        printf("\n\n             |*| 3 : supprimer                                         |*| 4: recherche adherent ");
        printf("\n\n             |*| 5 : retour au menu                                                ");
        printf("\n\n\n           ___________________________________________________________________________________________________________\n");
        printf("\n\n                             *|->Entrer votre choix: ");
        ret = scanf("%d", &choix);
        if (ret != 1)                                                                                                                                            /// si on lit d'autre chose qu'un entier alors on aura Erreur de saisie .
        {
            printf("erreur de saisie\n");
            exit(EXIT_FAILURE);
        }
        switch (choix)
        {
        case 1:
            ajout_adh();
            break;
        case 2:
            modifier_adh();
            break;
        case 3:
            supprimer_adh();
            break;
        case 4:
            recherche_adh();
            break;
        case 5:
            QUITTER_menu();
            break;
        default:
            printf("le choix doit etre entre 1 et 5 ");                                                                                                          /// Le choix d'entier doit �tre entre 1 et 5 sinon on refait la lecture .
        }

    } while (1);
}
/** Le r�le de cet fonction est d�ajouter un adh�rent dans le fichier adherent **/
void ajout_adh(void)
{
    system("cls");                                                                       /// Sa sert � effacer tout ce qu'il y a � l'�cran .

    printf("veillez remplir ce formulaire\n");
    int id, nbr, ret;
    do{
    printf("\nnumero de l'adherent:");                                                   /// saisir le num�ro de l'adhrent (entier>0) sinon on refait la lecture
    ret = scanf("%d", &id);
    if (ret != 1)
    {
        printf("erreur de saisie\n");
        exit(EXIT_FAILURE);
    }
    if (id<0 || id==0) printf("numero doit etre strictement positif!");
    }while(id<0 || id==0);

    while (exist_adh(id) == 1)                                                           /// La fonction exist_adh si le num�ro saisie existe dans le fichier adherent t'affirme que ce num�ro est d�ja exist� dans le fichier .
    {
        printf("ce numero est deja pris!");
    do{
    printf("\nnumero de l'adherent:");
    ret = scanf("%d", &id);
    if (ret != 1)
    {
        printf("erreur de saisie\n");
        exit(EXIT_FAILURE);
    }
    if (id<0 || id==0) printf("numero doit etre strictement positif!");
    }while(id<0 || id==0);
    }

    printf("\nnombres de livres emprunt%cs :",130);                                     /// saisir le nombre de livre emprunt� par l'adh�rent
    ret = scanf("%d", &nbr);
    if (ret != 1)
    {
        printf("erreur de saisie\n");
        exit(EXIT_FAILURE);
    }
    adh.nbre_emprunts_adh = nbr;
    adh.num_adh = id;
    printf("\nnom :");

    scanf("%s", &adh.nom_adh);                                                          /// ajouter tout les informations dans une structure "adh"

    printf("\nprenom :");
    scanf("%s", &adh.prenom_adh);

    printf("\nadresse mail :");
    scanf("%s", &adh.email_adh);

    printf("\nadresse personelle :");
    scanf("%s", &adh.adress_adh);


    f_adh = fopen("adherent.txt", "a");
    if (f_adh == NULL)                                                                  /// Gestion d'erreur du fichier
    {
        fprintf(stderr, "\nErreur: Impossible de lire le fichier \n");
        exit(EXIT_FAILURE);
    }
    fseek(f_adh, 0, SEEK_END);
    fwrite(&adh, sizeof(struct adherent), 1, f_adh);                                    /// ajouter la structure dans le fichier adherent .
    fclose(f_adh);
   printf("\n\n\n\n\n                                 ");
   printf("ajout effectu%c avec succes!",130);
   printf("\n                            _______________________________________");
   getch();
    return;                                                                             /// apr�s l'ajout on revient au menu de gestion d'adh�rent
}
/** Le r�le est de chercher si un tel num�ro d�ja existe dans le fichier adherent ou non **/
int exist_adh(int id)
{
    FILE *a;
    a = fopen("adherent.txt", "ab");
    if (a == NULL)                                                                     /// Gestion d'erreur du fichier .
    {
        fprintf(stderr, "\nErreur: Impossible de lire le fichier\n");
        exit(EXIT_FAILURE);
    }
    fclose(a);

    a = fopen("adherent.txt", "rb");
    if (a == NULL)                                                                     /// Gestion d'erreur du fichier
    {
        fprintf(stderr, "\nErreur: Impossible de lire le fichier\n");
        exit(EXIT_FAILURE);
    }
    while (!feof(a))
    {
        if (fread(&ad, sizeof(struct adherent), 1, a) == 1)
            if (ad.num_adh == id)
            {
                fclose(a);
                return 1;
            }
    }

    return 0;
}
/** Le r�le de cet fonction est de modifier un adh�rent qui existe dans le fichier adherent **/

void modifier_adh(void)
{

    system("cls");                                                                            /// Sa sert � effacer tout ce qu'il y a � l'�cran .
    FILE *tmp;
    int id, choix, ret, pos;
    printf("inserer le numero de ladherent :");
    ret = scanf("%d", &id);                                                                   /// la lecture de num�ro d'adh�rent qu'on souhaite � modifier .
    if (ret != 1)
    {
        printf("erreur de saisie\n");
        exit(EXIT_FAILURE);
    }
    if (exist_adh(id) == 1)                                                                   /// tester l'existance du num�ro .
    {
        f_adh = fopen("adherent.txt", "rb");
        tmp = fopen("tmp.txt", "wb");

        while (1)
        {
            fread(&adh, sizeof(struct adherent), 1, f_adh);
            if (feof(f_adh))
                break;
            if (adh.num_adh == id)
            {

                printf("saisir le numero de la donn%ce %c modifier:\n",130,160);
            printf("       _______________________________________________________________________________\n");
            printf("      |                                    |                                          |\n");
            printf("      |  ->numero                :   1            ->adresse mail               :  4   |\n");
            printf("      |  ->prenom                :   2     |      ->adresse personelle         :  5   |\n");
            printf("      |  ->nom                   :   3            ->nombbre de livres emprunte :  6   |\n");
            printf("      |____________________________________|__________________________________________|");
            printf("\n                                           |->votre choix: ");
                ret = scanf("%d", &choix);
                if (ret != 1)
                {
                    printf("erreur de saisie\n");
                    exit(EXIT_FAILURE);
                }
                switch (choix)
                {
                case 1:
                    printf("\n numero :");
                    ret = scanf("%d", &id);
                    if (ret != 1)
                    {
                        printf("erreur de saisie\n");
                        exit(EXIT_FAILURE);
                    }
                    adh.num_adh = id;
                    break;
                case 2:
                    printf("\n  prenom :");

                    scanf("%s", &adh.prenom_adh);

                    break;
                case 3:
                    printf("\n nom :");

                    scanf("%s", &adh.nom_adh);

                    break;
                case 4:
                    printf("\n adresse mail:");
                    scanf("%s", &adh.email_adh);
                    break;
                case 5:
                    printf("\n adresse personelle :");
                    scanf("%s", &adh.adress_adh);
                    break;
                case 6:
                    printf("\n nombbre de livres emprunte :");
                    ret = scanf("%d", &id);
                    if (ret != 1)
                    {
                        printf("erreur de saisie\n");
                        exit(EXIT_FAILURE);
                    }
                    adh.nbre_emprunts_adh = id;
                    break;
                default:
                    break;
                }
            }
            fwrite(&adh, sizeof(struct adherent), 1, tmp);
        }
        fclose(f_adh);
        fclose(tmp);
        f_adh = fopen("adherent.txt", "wb");
        tmp = fopen("tmp.txt", "rb");
        while (1)
        {
            fread(&adh, sizeof(struct adherent), 1, tmp);
            if (feof(tmp))
                break;
            fwrite(&adh, sizeof(struct adherent), 1, f_adh);
        }
        fclose(f_adh);
        fclose(tmp);
         printf("\n\n\n\n\n                                 ");
          printf("\Modifications enregistr%cs!!\n",130);
         printf("\n                            _______________________________________");
         getch();
         return;
    }

    else{
        printf("\n\n\n\n\n                                 ");
          printf("\nnumero d'adherent INVALID!\n");
         printf("\n                            _______________________________________");
    }
    getch();
    return;
}
/** Le r�le de cet fonction est de rechercher un adh�rent qui existe dans le fichier adherent **/
void recherche_adh()
{
    system("cls");                                                                                 /// Sa sert � effacer tout ce qu'il y a � l'�cran .
    char nom[30];
    int trouve = 0;
    int lettre;

    printf("donner le nom de l'adherent recherche: ");

    scanf("%s", &nom);
    f_adh = fopen("adherent.txt", "rb");
    if (f_adh == NULL)
    {
        fprintf(stderr, "\nErreur: Impossible de lire le fichier \n");
        return;
    }

    while (!feof(f_adh))
    {
        if(fread(&adh, sizeof(struct adherent), 1, f_adh)==1){


        if (strcmp(adh.nom_adh, nom) == 0)
        {
            trouve = 1;
            //affichage des informations
            printf("numero: %d\nnom: %s\nprenom: %s\nadresse mail: %s\nadresse personelle:%s\nnombre des livres emprunte:%d\n", adh.num_adh, adh.nom_adh, adh.prenom_adh, adh.email_adh, adh.adress_adh, adh.nbre_emprunts_adh);
        }
    }
    }
    fclose(f_adh);
    if (trouve == 0)
        printf("\npersonne ne porte ce nom vous serez redirige au menu\n");

    getch();
    return;
}
/** Le r�le de cet fonction est de supprimer un adh�rent qui existe dans le fichier adherent **/
void supprimer_adh()
{
    system("cls");                                                                                          /// Sa sert � effacer tout ce qu'il y a � l'�cran .
    FILE *tmp;
    int id, choix, ret, pos;
    printf("inserer le numero de ladherent :");
    ret = scanf("%d", &id);
    if (ret != 1)
    {
        printf("erreur de saisie\n");
        exit(EXIT_FAILURE);
    }
    if (exist_adh(id) == 1)
    {
        f_adh = fopen("adherent.txt", "rb");
        tmp = fopen("tmp.txt", "wb");

        while (1)
        {
            fread(&adh, sizeof(struct adherent), 1, f_adh);
            if (feof(f_adh))
                break;
            if (adh.num_adh != id)
                fwrite(&adh, sizeof(struct adherent), 1, tmp);
        }
        fclose(f_adh);
        fclose(tmp);
        f_adh = fopen("adherent.txt", "wb");
        tmp = fopen("tmp.txt", "rb");
        while (1)
        {
            fread(&adh, sizeof(struct adherent), 1, tmp);
            if (feof(tmp))
                break;
            fwrite(&adh, sizeof(struct adherent), 1, f_adh);
        }

        fclose(f_adh);
        fclose(tmp);

        printf("\n\n\n\n\n                                 ");
        printf("\suppression effect%c avec succes!!\n",130);
         printf("\n                            _______________________________________");
         getch();
         return;
    }
        printf("\n\n\n\n\n                                 ");
        printf("\nnumero d'adheren INVALID!!\n");
         printf("\n                            _______________________________________");
        getch();
        return;

}



