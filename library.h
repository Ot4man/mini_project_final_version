#ifndef LIBRARY_H
#define LIBRARY_H

#define Max 50

typedef struct livre
{
    char Titre[Max];
    char Auteur[Max];
    int Prix;
    int Quantite;
} Livre;

// Global variables
extern Livre L_stock[Max];
extern int Nb_livre;

// Function prototypes
void newligneremover(char titre[]);
int Ajouter_livre();
void Afficher_livre();
int Recherche_livre_index(char titre[Max]);
void Recherche();
void Mise_en_quantite();
void Supprimer_livre();
void Afficher_stock();

#endif
