#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

Livre L_stock[Max];
int Nb_livre = 0;

void newligneremover(char titre[])
{
    for (int i = 0; titre[i] != '\0'; i++)
    {
        if (titre[i] == '\n')
        { 
            titre[i] = '\0';
            break;
        }
    }
}

int Ajouter_livre()
{
    int Nb;
    printf("--------Ajoute  livre ----------\n");
    printf("Combien de livres seront ajoutes\n ");
    scanf("%d", &Nb);
    getchar();

    for (int i = 0; i < Nb; i++)
    {
        printf("Entrer le Titre  de livre  %d \n", i + 1);

        fgets(L_stock[Nb_livre].Titre, Max, stdin);
        newligneremover(L_stock[Nb_livre].Titre);

        printf("Entrer l'autuer  de livre  %d ", i + 1);
        
        fgets(L_stock[Nb_livre].Auteur, Max, stdin);
        newligneremover(L_stock[Nb_livre].Auteur);

        printf("Entrer le Prix de livre %d ", i + 1);
        scanf("%d", &L_stock[Nb_livre].Prix);
        getchar();

        printf("Entrer le Quantite de livre %d ", i + 1);
        scanf("%d", &L_stock[Nb_livre].Quantite);
        getchar();

        Nb_livre++;
    }
    return Nb_livre;
}

void Afficher_livre()
{
    printf("--------- Affichage de Stock -----------\n");
    if(Nb_livre==0){
        printf("Le stock est vide veuillez ajoute des livres\n");
    }
    for (int i = 0; i < Nb_livre; i++)
    {
        printf("Livre %d:\n", i + 1);
        printf("  Titre : %s\n", L_stock[i].Titre);
        printf("  Auteur: %s\n", L_stock[i].Auteur);
        printf("  Prix  : %d DH\n", L_stock[i].Prix);
        printf("  Quantite : %d\n", L_stock[i].Quantite);
        printf("----------------------------------------\n");
    }
}

int Recherche_livre_index(char titre[Max])
{
    printf("---------Recherche----------\n ");
    for (int i = 0; i < Nb_livre; i++)
    {
        if (strcmp(titre, L_stock[i].Titre) == 0)
            return i;
    }
    return -1;
}

void Recherche()
{
    char titre[Max];
    printf("Entrer le titre du livre a rechercher: ");
    getchar();
    fgets(titre, Max, stdin);
    newligneremover(titre);

    int index = Recherche_livre_index(titre);
    if (index != -1)
    {
        printf("Livre trouve!\n");
        printf("Titre : %s\n", L_stock[index].Titre);
        printf("Auteur: %s\n", L_stock[index].Auteur);
        printf("Prix  : %d DH\n", L_stock[index].Prix);
        printf("Quantite : %d\n", L_stock[index].Quantite);
    }
    else
    {
        printf("Livre n'existe pas dans le stock.\n");
    }
}

void Mise_en_quantite()
{
    int index = 0, qt;
    char titre[Max];
    printf("Entrer le titre de livre a Mise a ajour la quantite\n ");
    getchar();
    fgets(titre, 50, stdin);
    newligneremover(titre);
    index = Recherche_livre_index(titre);
    if (index != -1)
    {
        printf("Donner la nouvelle quantitee \n");
        scanf("%d", &qt);
        L_stock[index].Quantite = qt;
        printf("Quanite mise a jour avec succes \n");
    }
    else
    {
        printf("Livre n'est exist pas dans le stock \n");
    }
}

void Supprimer_livre()
{
    char titre[Max];
    printf("Entrer le titre du livre a supprimer: ");
    getchar();
    fgets(titre, Max, stdin);
    newligneremover(titre);

    int exist = 0;
    for (int i = 0; i < Nb_livre; i++)
    {
        if (strcmp(L_stock[i].Titre, titre) == 0)
        {
            for (int j = i; j < Nb_livre - 1; j++)
            {
                L_stock[j] = L_stock[j + 1];
            }
            Nb_livre--;
            exist = 1;
            printf("Livre supprime avec succes!\n");
            break;
        }
    }
    if (!exist)
    {
        printf("Livre n'existe pas dans le stock.\n");
    }
}

void Afficher_stock()
{
    int total = 0;
    for (int i = 0; i < Nb_livre; i++)
    {
        total += L_stock[i].Quantite;
    }
    printf("Quantite totale en stock: %d\n", total);
}