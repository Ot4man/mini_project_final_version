  #include<stdio.h>
  #include<stdlib.h>
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
        printf("| [6] Afficher Stock                                                 |\n");
        printf("|____________________________________________________________________|\n");
        printf("| [7] Trier                                                          |\n");
        printf("|____________________________________________________________________|\n");
        printf("| [8] Quitter                                                        |\n");
        printf("+____________________________________________________________________+\n");

        printf("Votre choix: ");

        scanf("%d", &choix);
        while (getchar() != '\n');

        switch (choix)

        {
        case 1:
            Ajouter_livre();
            break;

        case 2:
            Afficher_livre();
            break;

        case 3:
           FULL_RECHERCHE();
            
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
            TRIER_STOCK();
            break;

        case 8 :
             printf(" Exit \n");
              break;

        default:
            printf("Votre choix est invalide  repet \n");
            
        }
        
    
    } while (choix!=8);
    
}
