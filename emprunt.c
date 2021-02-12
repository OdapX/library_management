#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "headers.h"

/** Le menu de gestion d'emprunte **/
void GESTION_EMPRUNTS()
{    system("COLOR 1F");                                                                                                                          /// Sa sert � colorer la fen�tre d'�xecution en bleu .
    int choix, ret;
    system("cls");                                                                                                                                /// Sa sert � effacer tout ce qu'il y a � l'�cran .
    do
    {   system("cls");
        system("COLOR 1F");
        printf("\n\n\n\n\n\n");
        printf("       _________________________________________________________________________________________________");
        printf("\n      |                                                                                                 |");
        printf("\n      |                                                                                                 |");
        printf("\n      |                                          GESTION DES EMPRUNTS :                                 | ");
        printf("\n      |                                                                                                 |");
        printf("\n      |_________________________________________________________________________________________________| ");
        printf("\n                                   ||                                                   ||");
        printf("\n      _____________________________||___________________________________________________||_____________________\n");

        printf("\n\n        |*| 1 : emprunter                                           |*| 2 :affichage  des livres emprunt%cs",130);

        printf("\n\n        |*| 3 : affichage des adh%crents emprunteurs de livre        |*| 4: Rendre un livre ",130);

        printf("\n\n        |*| 5 : retour au menu                     ");
        printf("\n\n      _________________________________________________________________________________________________________\n");

        printf("\n\n                             *|->Entrer votre choix: ");
        ret = scanf("%d", &choix);
        if (ret != 1)
        {
            printf("erreur de saisie\n");
            exit(EXIT_FAILURE);
        }
        switch (choix)
        {
        case 1:
            emprunter();
            break;
        case 2:
             affich_lvr_empr();
            break;
        case 3:
            affich_adh_empr();
            break;
        case 4:
           rendre();
            break;
        case 5:
            QUITTER_menu();
            break;
        default:printf("choix invalide");
            break;
        }

    } while (1);
}
/** C�est une fonction pour emprunt�s un livre par cat�gorie et par titre du livre **/
void emprunter(void)
{
    system("cls");                                                                                                                /// Sa sert � effacer tout ce qu'il y a � l'�cran .
    char titre[30];int trouve=0,id;
    printf("\ndonner le titre du  livre:");
    fflush(stdin);
    scanf("%s",&titre);
    fflush(stdin);
    f_liv=fopen("livres.txt","rb");
    while(!feof(f_liv)){
        fread(&lv,sizeof(struct livre),1,f_liv);
        if( strcmp(lv.titre_liv,titre)==0 && lv.emprunteur_liv==0) {trouve=1;break;}
    }
    fclose(f_liv);
    if(trouve==1){
        printf("\ndonner le numero de l'adherent qui veut emprunter:");
        scanf("%d",&id);
        f_adh=fopen("adherent.txt","rb");
        while(!feof(f_adh)){
            fread(&ad,sizeof(struct adherent),1,f_adh);
            if(ad.num_adh==id){


                if(ad.nbre_emprunts_adh>=3) {
                    printf("\ncet adherent doit rendre un livre avant d'emprunter\n");
                    return;
                }
                else {
                    ad.nbre_emprunts_adh=ad.nbre_emprunts_adh+1;
                    lv.emprunteur_liv=id;
                    break;
                }

                }
            }
             fclose(f_adh);
        FILE* tmp;
        f_adh = fopen("adherent.txt","rb");
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
            fread(&adh, sizeof(struct adherent),1,tmp);
            if (feof(tmp))
                break;
            fwrite(&adh, sizeof(struct adherent),1,f_adh);
        }
        fclose(f_adh);
        fclose(tmp);
        f_adh=fopen("adherent.txt","ab");
        fwrite(&ad, sizeof(struct adherent), 1,f_adh);
        fclose(f_adh);
         f_liv=fopen("livres.txt","rb");
        tmp = fopen("tmp.txt", "wb");
        while (1)
        {
            fread(&lvr, sizeof(struct livre), 1, f_liv);
            if (feof(f_liv))
                break;
            if (lvr.emprunteur_liv != id)
                fwrite(&lvr, sizeof(struct livre), 1, tmp);
        }
        fclose(f_liv);
        fclose(tmp);
        f_liv = fopen("livres.txt", "wb");
        tmp = fopen("tmp.txt", "rb");
        while (1)
        {
            fread(&lvr, sizeof(struct livre),1,tmp);
            if (feof(tmp))
                break;
            fwrite(&lvr, sizeof(struct livre),1,f_liv);
        }
        fclose(f_liv);
        fclose(tmp);
        f_liv=fopen("livres.txt","ab");
        fwrite(&lv, sizeof(struct livre), 1,f_liv);
        fclose(f_liv);
        printf("\n\n\n\n\n                                 ");
           printf("emprunt effectu%c avec succes!",130);
         printf("\n                            _______________________________________");

        getch();
        }
        else{
        printf("\n\n\n\n\n                                 ");
        printf("\nce livre n'est pas en stock\n");
         printf("\n                            _______________________________________");
        }
        getch();
    return;
}

/** Le r�le de cet fonction est d�afficher la liste des livres emprunt�s **/
void affich_lvr_empr(){
    system("cls");                                                                                                                   /// Sa sert � effacer tout ce qu'il y a � l'�cran .
    f_liv=fopen("livres.txt","rb");
    printf("\nLISTE DES LIVRES EMPRUNTES:\n");
    while(!feof(f_liv)) {
        if(fread(&lv,sizeof(struct livre), 1,f_liv)==1){
        if(lv.emprunteur_liv!=0){
            printf(" ____________________________________\n");
            printf("|numero                :   %d       \n",lv.num_liv);
            printf("|titre                 :   %s       \n",lv.titre_liv);
            printf("|categorie             :   %s       \n",lv.categ_liv);
            printf("|nnom d'auteur         :   %s       \n",lv.nom_aut);
            printf("|prenom d'auteur       :   %s      \n",lv.prenom_aut);
            printf("|numero de l'emprunteur:   %d      \n",lv.emprunteur_liv);


        }

        }
    }
    fclose(f_liv);
    printf("\n\n\n\n\n\n\n\n");
    printf("                                       Affichage termin%c!",130);
    printf("\n                                _____________________________________");
    getch();
    return;
}
/**  Le r�le de cet fonction est d�afficher les adh�rents qui ont emprunt�s un livre par cat�gorie **/
void affich_adh_empr(){
    system("cls");                                                                                                           /// Sa sert � effacer tout ce qu'il y a � l'�cran .
    char titre[30];int id,trouve=0;
    printf("\ndonner le titre du livre:");
    scanf("%s",&titre);
    f_liv=fopen("livres.txt","rb");
     printf("\n                                    LISTE DES ADHERENT EMPRUNTEUR DU LIVRE  %s:\n",titre);
    while(!feof(f_liv)){
        if(fread(&lvr,sizeof(struct livre),1,f_liv)==1){
        if(strcmp(lvr.titre_liv,titre)==0){
            trouve=1;
            id=lvr.emprunteur_liv;
            f_adh=fopen("adherent.txt","rb");
              while(!feof(f_adh)){
                   if(fread(&ad,sizeof(struct adherent), 1,f_adh)==1){
                    if(ad.num_adh==id){
                     trouve=2;
            printf("     _______________________________________\n");
            printf("    |numero                :    %d        \n",ad.num_adh);
            printf("    |nom adherent          :    %s        \n",ad.nom_adh);
            printf("    |prenom adherent       :    %s        \n",ad.prenom_adh);
            printf("    |adresse_email         :    %s        \n",ad.email_adh);
            printf("    |adresse_personnelle   :    %s        \n",ad.adress_adh);
            printf("    |numero de l'emprunteur:    %d        \n",ad.nbre_emprunts_adh);

                    }

      }

    }

        }
        }
    }
    fclose(f_liv);
  fclose(f_adh);

    if(trouve==0) {
            printf("\n\n\n\n\n\n\n                      ce livre n'est pas en stock!\n");
           printf("\n                                     ______________________________");
    }
    if(trouve==1){
            printf("\n\n\n\n\n\n\n                      -> personne n'a emprunt%c ce livre <-\n",130);
            printf("\n                                             ____________________________________");
    }
    getch();
    return;
}
/** Le r�le de cet fonction est de faire rendre un livre **/
void rendre(){
    system("cls");                                                                                                                                /// Sa sert � effacer tout ce qu'il y a � l'�cran .
    int id,ret;
    printf("donner le numero de l'adherent souhaitant rendre:");
     ret=scanf("%d",&id);
    if(ret!=1){
        printf("erreur du saisi!");
        exit(EXIT_FAILURE);
    }
   if(exist_adh(id)!=1){printf("\n\n\n\n\n\n\n\n                   ce numero d'adherent est INVALID"); getch();}

  else{
         f_adh= fopen("adherent.txt","rb");
         while(!feof(f_adh)){
            if(fread(&adh,sizeof(struct adherent),1,f_adh)==1) {
                if(adh.num_adh==id) {
                        if(adh.nbre_emprunts_adh==0){
                            printf("\n\n\n\n\n\n  cet adherent n'a rien %c  rendre",160);
                            getch();
                            return;
                        }
                        else{
                            adh.nbre_emprunts_adh--;
                            f_liv=fopen("livres.txt","rb");
                            while(!feof(f_liv)){
                                if(fread(&lvr,sizeof(struct livre),1,f_liv)==1) {
                                        if(lvr.emprunteur_liv==id){
                                            lvr.emprunteur_liv=0;

                                            break;
                                        }
                            }

                        }
            }

         }



    }
         }
         fclose(f_adh);fclose(f_liv);
         FILE *tmp;
        f_adh = fopen("adherent.txt", "rb");
        tmp = fopen("tmp.txt", "wb");

        while (!feof(f_adh))
        {
            if(fread(&ad, sizeof(struct adherent), 1, f_adh)==1){
            if (adh.num_adh != id)
                fwrite(&ad, sizeof(struct adherent), 1, tmp);
            }
        }
        fclose(f_adh);
        fclose(tmp);
        f_adh = fopen("adherent.txt", "wb");
        tmp = fopen("tmp.txt", "rb");
        while (!feof(tmp))
        {
           if(fread(&ad,sizeof(struct adherent), 1, tmp)==1)  fwrite(&ad, sizeof(struct adherent), 1, f_adh);
        }

        fclose(f_adh);
        fclose(tmp);
        f_liv=fopen("livres.txt","rb");
        tmp = fopen("tmp.txt", "wb");
        while (!feof(f_liv))
        {
            if(fread(&lv, sizeof(struct livre), 1, f_liv)==1){
            if (lv.emprunteur_liv != id)
                fwrite(&lv, sizeof(struct livre), 1, tmp);
            }
        }
        fclose(f_liv);
        fclose(tmp);
        f_liv = fopen("livres.txt", "wb");
        tmp = fopen("tmp.txt", "rb");
        while (!feof(tmp))
        {
            if(fread(&lv,sizeof(struct livre), 1, tmp)==1)  fwrite(&lv, sizeof(struct livre), 1, f_liv);


        }

        fclose(f_adh);
        fclose(tmp);

        f_adh=fopen("adherent.txt","ab");
        fwrite(&adh,sizeof(struct adherent), 1, f_adh);
        fclose(f_adh);

        f_liv=fopen("livres.txt","ab");
        fwrite(&lvr,sizeof(struct livre), 1, f_liv);
        fclose(f_liv);
        printf("\n\n\n\n\n\n\n\n\n\n\n                                    livre rendu avec succes!!");
        printf("\n                         _________________________________");
      getch();
  }

    return;
}


