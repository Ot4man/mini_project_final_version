  #include<stdio.h>
  #include "library.h"
  

  
  int main()
{
    int choix;
    do
    {

        printf("######################################################################\n");
        printf("#################  SYSTEME DE GESTION DE STOCK  ######################\n");
        printf("######################################################################\n");
        printf("+____________________________________________________________________+\n");
        printf("|                                                                    |\n");
        printf("|                           Menu Principal                           |\n");
        printf("+____________________________________________________________________+\n");
        printf("| [1] Ajouter un livre                                               |\n");
        printf("|____________________________________________________________________|\n");
        printf("| [2] Afficher un livre                                              |\n");
        printf("|____________________________________________________________________|\n");
        printf("| [3] Rechercher un livre                                            |\n");
        printf("|____________________________________________________________________|\n");
        printf("| [4] Mise a jour                                                    |\n");
        printf("|____________________________________________________________________|\n");
        printf("| [5] Supprimer un livre                                             |\n");
        printf("|____________________________________________________________________|\n");
        printf("| [6] Afficher la quantite                                           |\n");
        printf("|____________________________________________________________________|\n");
        printf("| [7] Quitter                                                        |\n");
        printf("+____________________________________________________________________+\n");

        printf("Votre choix: ");

        scanf("%d", &choix);

        switch (choix)

        {
        case 1:
            Ajouter_livre();
            break;

        case 2:
            Afficher_livre();
            break;

        case 3:
            Recherche();
            break;
        case 4:
            Mise_en_quantite();

            break;

        case 5:
            Supprimer_livre();
            break;
        case 6:
            Afficher_stock();
            break;
        case 7:
            printf(" Exit \n");

        default:
            printf("Votre choix est invalide  repet \n");
        }
    } while (choix != 7);
}