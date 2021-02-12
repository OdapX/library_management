/******************infos d un adherent***********************************/
struct adherent
{
    int num_adh;
    char nom_adh[30];
    char prenom_adh[30];
    char email_adh[80];
    char adress_adh[80];
    int nbre_emprunts_adh;
} ad, adh;

/******************infos sur les livres***********************************/
struct livre
{
    int num_liv;
    char titre_liv[30];
    char categ_liv[30];
    int emprunteur_liv;
    char nom_aut[30];
    char prenom_aut[30];
} lv, lvr;



/**********************************LES FICHIERS DE STOCKAGE D'INFOS****************************************************/
FILE *f_adh, *f_liv, *f_categ;
/*********************************PROTOTYPE DE TOUTES LES FONCTIONS UTILISABLES***************************************/
void menu_principal(void);
void GESTION_ADHERENT(void);
void GESTION_LIVRES(void);
void GESTION_EMPRUNTS(void);
void QUITTER(void);
void ajout_adh(void);
void supprimer_adh(void);
void modifier_adh(void);
void recherche_adh(void);
void ajout_lvr(void);
void supprimer_lvr(void);
void modifier_lvr(void);
void ordonner_lvr(void);
void recherche_lvr(void);
int exist_lvr(int);
int exist_adh(int);
void emprunter(void);
void affich_lvr_empr(void);
void affich_adh_empr(void);
void rendre(void);
void QUITTER_menu(void);






