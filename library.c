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
    while (getchar() != '\n');
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
        while (getchar() != '\n');

        printf("Entrer le Quantite de livre %d ", i + 1);
        scanf("%d", &L_stock[Nb_livre].Quantite);
        while (getchar() != '\n');
        printf("Entrer le ISBN du livre xxx-x-xxx-xxxxx-x %d ",i+1);
        scanf("%d-%d-%d-%d-%d",&L_stock[Nb_livre].isbn.Prefixe,&L_stock[Nb_livre].isbn.Ident_groupe ,&L_stock[Nb_livre].isbn.code_editeur ,&L_stock[Nb_livre].isbn.Num_artical,&L_stock[Nb_livre].isbn.chiffre_control);
        while (getchar() != '\n');
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
        printf("  ISBN : %d-%d-%d-%d-%d\n",L_stock[i].isbn.Prefixe,L_stock[i].isbn.Ident_groupe ,L_stock[i].isbn.code_editeur ,L_stock[i].isbn.Num_artical,L_stock[i].isbn.chiffre_control);
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

// void Recherche()
// {
//     char titre[Max];
//     printf("Entrer le titre du livre a rechercher: ");
//     getchar();
//     fgets(titre, Max, stdin);
//     newligneremover(titre);
//     int index = Recherche_livre_index(titre);
//     if (index != -1)
//     {
//         printf("Livre trouve!\n");
//         printf("Titre : %s\n", L_stock[index].Titre);
//         printf("Auteur: %s\n", L_stock[index].Auteur);
//         printf("Prix  : %d DH\n", L_stock[index].Prix);
//         printf("Quantite : %d\n", L_stock[index].Quantite);
//     }
//     else
//     {
//         printf("Livre n'existe pas dans le stock.\n");
//     }
// }



void trier_quantite(){
Livre temp;
for (int i = 0; i < Nb_livre -1; i++)
{
    for (int j = i+1; j < Nb_livre; j++)
    {
        if(L_stock[i].Quantite>L_stock[j].Quantite){   
        temp = L_stock[i];
        L_stock[i]=L_stock[j];
        L_stock[j] = temp;

    }
} 
}
printf("trie par quantite avec succes\n");
}
int trier_par_titre()
{
    Livre temp;
    int swap=0;
    for (int i = 0; i < Nb_livre; i++)
    {
        for (int j = i+1; j < Nb_livre; j++)
        {
            if (_stricmp(L_stock[i].Titre, L_stock[j].Titre) > 0) //croissant ou decroissant , u choose 
            { 
                temp = L_stock[i];
                L_stock[i] = L_stock[j];
                L_stock[j] = temp;
                swap=1;
            }           
        }
    }
   if (swap == 1)
    printf("Trie avec succes \n");
else
    printf("Trie echouee\n");
return swap;
}
void TRIER_STOCK()
{
    int trie;
    printf("Appuyer sur 1 pour trier par  Quantite \n");
    printf("Appuyer sur 2 pour trier par Titre \n");
    scanf("%d", &trie);
    while (getchar() != '\n');
    switch (trie)
    {
    case 1:
        printf("Trie par Quantite \n");
        trier_quantite();
        break;
    case 2:
        printf("Trie par Titre \n");
        trier_par_titre();
        break;

    default:
        printf(" choix invalid Error\n");
        break;
    }
}



void rechercherParISBN() {
    ISBN search;
    printf("Entrer ISBN : ");
    scanf("%d-%d-%d-%d-%d", 
          &search.Prefixe, &search.Ident_groupe, 
          &search.code_editeur, &search.Num_artical, &search.chiffre_control);
          while (getchar() != '\n');
        
    for (int i = 0; i < Nb_livre; i++) {
        if (L_stock[i].isbn.Prefixe == search.Prefixe &&
            L_stock[i].isbn.Ident_groupe == search.Ident_groupe &&
            L_stock[i].isbn.code_editeur == search.code_editeur &&
            L_stock[i].isbn.Num_artical == search.Num_artical &&
            L_stock[i].isbn.chiffre_control == search.chiffre_control) {
            
            printf(" Livre trouve -> %s de %s\n", 
                   L_stock[i].Titre, L_stock[i].Auteur);
            return;
        }
    }
    printf(" Livre non trouve.\n");
}
int Recherche_binaire()
{   int debut = 0, fin = Nb_livre-1;
    int milieu ;
    char tit[50];
printf("Entrer le titre du livre a rechercher: ");
getchar();
fgets(tit, 50, stdin);
newligneremover(tit);
    while (debut <= fin)
    {
        milieu = ((debut + fin) / 2);
        if (strcmp(L_stock[milieu].Titre, tit) == 0){   
            
                    printf("Livre est exist dans position :%d  Titre : %s  \n", milieu, L_stock[milieu].Titre);
return milieu;}
        else if (strcmp(L_stock[milieu].Titre, tit) < 0)

            debut = milieu + 1;
        else
            fin = milieu - 1;
    }
    
    
        printf("Livre n'est pas exist \n");
return-1;
}
void FULL_RECHERCHE()
{
    int cherche;
    printf("Appuyer sur 1 pour cherche avec ISBN \n");
    printf("Appuyer sur 2 pour cherche avec Titre(binaire) \n");
    scanf("%d",&cherche);
    while (getchar() != '\n');
    switch (cherche)
    {
    case 1:
        printf("Recherche  avec ISBN \n");
        rechercherParISBN();
        break;
    case 2:
        printf("Recherche avec Titre(Binaire) \n");
        Recherche_binaire();
        break;
    default:
        printf("Choix invalid\n");
        break;
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
        while (getchar() != '\n');
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

    if (Nb_livre == 0) {
    printf("Le stock est vide, veuillez ajouter des livres\n");
    return;
}
}