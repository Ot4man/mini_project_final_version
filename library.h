#ifndef LIBRARY_H
#define LIBRARY_H

#define Max 50
  typedef struct ISBN{ 
    int Prefixe;
    int Ident_groupe;
    int code_editeur;
    int Num_artical;
    int chiffre_control;
 }ISBN ;

typedef struct livre
{
    char Titre[Max];
    char Auteur[Max];
    int Prix;
    ISBN isbn;
    int Quantite;
} Livre;


// Global variables
extern Livre L_stock[Max];
extern int Nb_livre;

// Function prototypes
void newligneremover(char titre[]);
int Ajouter_livre();
void Afficher_livre();
void FULL_RECHERCHE();

// int Recherche_livre_index(char titre[Max]);
// void Recherche();
void Mise_en_quantite();
void Supprimer_livre();
void Afficher_stock();
void TRIER_STOCK();

#endif
