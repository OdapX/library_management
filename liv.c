#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "headers.h"
/** Le menu de gestion du livre **/
void GESTION_LIVRES(void)
{
    int choix,ret;
     system("COLOR 1F");                                                                                                                                        /// Sa sert � colorer la fen�tre d'�xecution en bleu .
    do
    {
        system("cls");                                                                                                                                          /// Sa sert � effacer tout ce qu'il y a � l'�cran .
         printf("\n\n\n\n\n\n");
        printf("            ________________________________________________________________________________________________");
        printf("\n          |                                                                                                 |");
        printf("\n          |                                                                                                 |");
        printf("\n          |                                       GESTION DES LIVRES :                                      | ");
        printf("\n          |                                                                                                 |");
        printf("\n          |_________________________________________________________________________________________________| ");
        printf("\n           _____________________________||_______________________________________________||______________________\n");

        printf("\n\n             |*| 1 : ajouter                                                          |*| 2 :modifier");

        printf("\n\n             |*| 3 : supprimer                                                        |*| 4: ordonner par categorie ",130);

        printf("\n\n             |*| 5: Recherche par *Cat%cgorie/titre*                                   |*| 6:retour au menu ",130);
        printf("\n\n\n           ______________________________________________________________________________________________________\n");

        printf("\n\n                             |->Entrer votre choix: ");
        ret=scanf("%d", &choix);
        if (ret != 1)
    {
        printf("erreur de saisie\n");
        exit(EXIT_FAILURE);
    }
        switch (choix)
        {
        case 1:
            ajout_lvr();
            break;
        case 2:
            modifier_lvr();
            break;
        case 3:
            supprimer_lvr();
            break;
        case 4:
            ordonner_lvr();
            break;
        case 5:
            recherche_lvr();
            break;
        case 6:
            QUITTER_menu();
            break;

        default:
            printf("le choix est invalide \n");
        }

    } while (1);
}
/** le role de cet fonction est de chercher si un livre existe deja ou non **/
int exist_lvr(int id)
{
    f_liv=fopen("livres.txt","ab");
    if (f_liv == NULL)
    {
        fprintf(stderr, "\nErreur: Impossible de lire le fichier\n");
        exit(EXIT_FAILURE);
    }
    fclose(f_liv);
    f_liv = fopen("livres.txt", "rb");
    if (f_liv == NULL)
    {
        fprintf(stderr, "\nErreur: Impossible de lire le fichier\n");
        exit(EXIT_FAILURE);
    }
    while (!feof(f_liv))
    {
        fread(&lvr, sizeof(struct livre), 1, f_liv);
        if (lvr.num_liv == id)
        {
            fclose(f_liv);
            return 1;
        }
    }
    fclose(f_liv);
    return 0;
}
/** Le r�le de cet fonction est d�ajouter un livre  dans le fichier livre **/
void ajout_lvr()
{
    system("cls");                                                                                                             /// Sa sert � effacer tout ce qu'il y a � l'�cran .
    int id, ret;
    printf("\nremplir ce formulaire:");
    do{

    printf("\ndonner le numero du livre:");
    ret = scanf("%d", &id);
    if (ret != 1)
    {
        printf("erreur de saisie\n");
        exit(EXIT_FAILURE);
    }
    if (id<0 || id==0) printf("numero doit etre strictement positif!");
    }while(id<0 || id==0);
    while (exist_lvr(id) == 1)
    {
        printf("\nce numero est deja pris!");
        printf("\ndonner le numero du livre:");
        ret = scanf("%d", &id);
        if (ret != 1)
        {
            printf("erreur de saisie\n");
            exit(EXIT_FAILURE);
        }
    }
    lvr.num_liv = id;
    printf("\ntitre du  livre: ");
    fflush(stdin);
    scanf("%s", &lvr.titre_liv);
    fflush(stdin);
    printf("\nla categorie du  livre: ");

    scanf("%s", &lvr.categ_liv);

    printf(" -> si ce livre n'a pas ete emprunte affecte 0 au numero d'emprunteur. <- ");
    printf("\nnumero d'emprunteur du livre: ");
    ret = scanf("%d", &id);
    if (ret != 1)
    {
        printf("erreur de saisie\n");
        exit(EXIT_FAILURE);
    }
    lvr.emprunteur_liv = id;

    printf("\nnom de  l auteur: ");

    scanf("%s", &lvr.nom_aut);

    printf("\nprenom de  l auteur: ");

    scanf("%s", &lvr.prenom_aut);


    printf("\nle livre est enregistre!\n ");


    f_liv = fopen("livres.txt", "a");
    if (f_liv == NULL)
    {
        fprintf(stderr, "\nErreur: Impossible de lire le fichier \n");
        exit(EXIT_FAILURE);
    }
    fwrite(&lvr, sizeof(struct livre), 1, f_liv);
    fclose(f_liv);
    printf("\n\n\n\n\n                                 ");
    printf("\ajout effect%c avec succes!!\n",130);
    printf("\n                            _______________________________________");
    getch();
     return;
}
/** Le r�le de cet fonction est d�ordonner les livres  qui existe dans le fichier livre de m�me cat�gorie **/
void ordonner_lvr(void)
{
   system("cls");                                                                                                                                        /// Sa sert � effacer tout ce qu'il y a � l'�cran .
    int id, trouve, lettre;
    char categ[30];
    printf("\n->donner la categorie recherche:");
    scanf("%s", &categ);
    f_liv = fopen("livres.txt", "r");
    if (f_liv == NULL)
    {
        fprintf(stderr, "\nErreur: Impossible de lire le fichier \n");
        return;
    }
    rewind(f_liv);
    printf("\n-------------------livres de la categorie %s-----------------  \n", categ);
    while (1)
    {
         if(feof(f_liv)) break;
        if(fread(&lvr, sizeof(struct livre), 1, f_liv)==1){
        if (strcmp(lvr.categ_liv, categ) == 0)
        {
            trouve = 1;

            printf("\n    Titre:%s", lvr.titre_liv);
            printf("\n    Numero:%d", lvr.num_liv);
            printf("\n    Nom de l'auteur:%s", lvr.nom_aut);
            printf("\n    Prenom de l'auteur:%s", lvr.prenom_aut);
            printf("\n    Numero de l'emprunteur:%d\n", lvr.emprunteur_liv);
        }
        }
    }
    fclose(f_liv);
    if (trouve == 0){
         printf("\n\n\n\n\n                                 ");
        printf("\n **cette cat%cgorie est vide! ",130);
         printf("\n                            _______________________________________");

    }

    getch();
    return;
}
/** Le r�le de cet fonction est de modifier  un livre qui existe dans le fichier livre **/
void modifier_lvr(void)
{
    system("cls");                                                                                                           /// Sa sert � effacer tout ce qu'il y a � l'�cran .
    FILE *tmp;
    int id, choix, ret, pos;
    printf("inserer le numero de livre :");
    ret = scanf("%d", &id);
    if (ret != 1)
    {
        printf("erreur de saisie\n");
        exit(EXIT_FAILURE);
    }
    if (exist_lvr(id) == 1)
    {
        f_liv = fopen("livres.txt", "rb");
        tmp = fopen("tmp.txt", "wb");

        while (1)
        {
            fread(&lvr, sizeof(struct livre), 1, f_liv);
            if (feof(f_liv))
                break;
            if (lvr.num_liv == id)
            {
            system("cls");
            printf("saisir le numero de la donn%ce � modifier:\n",130);
            printf("       __________________________________________________________________________\n");
            printf("      |                                    |                                     |\n");
            printf("      |  ->numero                :   1            ->categorie             :  4   |\n");
            printf("      |                                    |                                     |\n");
            printf("      |  ->titre                 :   2     |      ->nom d'auteur          :  5   |\n");
            printf("      |                                    |                                     |\n");
            printf("      |  ->numero d'emprunteur   :   3            ->prenom d'auteur       :  6   |\n");
            printf("      |____________________________________|_____________________________________|");
            printf("\n\n    |->votre choix: ");
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

            lvr.num_liv = id;
            break;
        case 2:
            printf("\n  ttitre :");
            scanf("%s", &lvr.titre_liv);
            break;
        case 3:
            printf("\n numero d'emprunteur :");
            ret = scanf("%d", &id);
            if (ret != 1)
            {
                printf("erreur de saisie\n");
                exit(EXIT_FAILURE);
            }
            lvr.emprunteur_liv = id;
            break;
        case 4:
            printf("\n categorie :");
            scanf("%s", &lvr.categ_liv);
            break;
        case 5:
            printf("\n nom auteur :");
            scanf("%s", &lvr.nom_aut);
            break;
        case 6:
            printf("\n prenom auteur :");
            scanf("%s", &lvr.prenom_aut);
            break;
        default:
            break;
        }
            }
            fwrite(&lvr, sizeof(struct livre), 1, tmp);
        }
        fclose(f_liv);
        fclose(tmp);
        f_liv = fopen("livres.txt", "wb");
        tmp = fopen("tmp.txt", "rb");
        while (1)
        {
            fread(&lvr, sizeof(struct livre), 1, tmp);
            if (feof(tmp))
                break;
            fwrite(&lvr, sizeof(struct livre), 1, f_liv);
        }
        fclose(f_liv);
        fclose(tmp);
         printf("\n\n\n\n\n                                 ");
       printf("modifications enregistr%cs avec succes!",130);
         printf("\n                        _______________________________________");

    }

    else{
       printf("\n\n\n\n\n                                 ");
       printf("\nnumero d'adhrent INVALID!!\n");
       printf("\n                     _______________________________________");
    }
    getch();
    return;
}
/** Le r�le de cet fonction est de rechercher un livre  qui existe dans le fichier livre par nom titre et cat�gorie de livre **/
void recherche_lvr()
{
    system("cls");                                                                                                          /// Sa sert � effacer tout ce qu'il y a � l'�cran .
    char categ[30], titre[30];
    int trouve = 0;

    printf("donner le titre: ");
    scanf("%s", &titre);
    printf("donner la categorie: ");
    scanf("%s", &categ);
    fflush(stdin);
    f_liv = fopen("livres.txt", "r");
    if (f_liv == NULL)
    {
        fprintf(stderr, "\nErreur: Impossible de lire le fichier \n");
        return;
    }
    ;

    while (1) {

        if(feof(f_liv)) break;
        if(fread(&lv, sizeof(struct livre), 1, f_liv)==1){
        if (strcmp(lv.titre_liv, titre) == 0 && strcmp(lv.categ_liv, categ) == 0)
        {
            trouve = 1;
            //affichage des informations
            printf("  ______________________________________\n");
            printf("*                                    *\n");
            printf("|     ->numero                :   %d     \n",lv.num_liv);
            printf("|     ->titre                 :   %s     \n",lv.titre_liv);
            printf("|     ->categorie             :   %s     \n",lv.categ_liv);
            printf("|     ->nnom d'auteur         :   %s     \n",lv.nom_aut);
            printf("|     ->prenom d'auteur       :   %s     \n",lv.prenom_aut);
            printf("|     ->numero de l'emprunteur:   %d     \n",lv.emprunteur_liv);
            printf("*______________________________________*\n");
        }
        }

    }
    fclose(f_liv);

    if (trouve == 0){
       printf("\n\n\n\n\n                                 ");
        printf("\nce livre n'existe pas!\n");
         printf("\n                            _______________________________________");
    }

   getch();
    return;
}
/** Le r�le de cet fonction est de supprimer  un livre qui existe dans le fichier livre  **/
void supprimer_lvr()
{
    system("cls");                                                                                                    /// Sa sert � effacer tout ce qu'il y a � l'�cran .
    FILE *tmp;
    int id, choix, ret, pos;
    printf("inserer le numero de livre :");
    ret = scanf("%d", &id);
    if (ret != 1)
    {
        printf("erreur de saisie\n");
        exit(EXIT_FAILURE);
    }
    if (exist_lvr(id) == 1)
    {
        f_liv = fopen("livres.txt", "rb");
        tmp = fopen("tmp.txt", "wb");

        while (1)
        {
            fread(&lvr, sizeof(struct livre), 1, f_liv);
            if (feof(f_liv))
                break;
            if (lvr.num_liv != id)
                fwrite(&lvr, sizeof(struct livre), 1, tmp);
        }
        fclose(f_liv);
        fclose(tmp);
        f_liv = fopen("livres.txt", "wb");
        tmp = fopen("tmp.txt", "rb");
        while (1)
        {
            fread(&lvr, sizeof(struct livre), 1, tmp);
            if (feof(tmp))
                break;
            fwrite(&lvr, sizeof(struct livre), 1, f_liv);
        }
        fclose(f_liv);
        fclose(tmp);
         printf("\n\n\n\n\n                                 ");
        printf("suppression effectu%c avec succes!",130);
         printf("\n                            _______________________________________");

    }

    else{
         printf("\n\n\n\n\n                                 ");
          printf("\n\nNumero INVALID!!\n");
         printf("\n                            _______________________________________");

    }

    getch();
    return;
}


