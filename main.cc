#include "items.hh"

int main(){
    bool start=true;
    int tour = 0;
    bool choix = 0;
    int quantity = 0;
    if(tour == 0){
        printf("Bienvenue dans le jeu Fantastic Factory,\n Bonne production !\n");
        printf("Règles du jeu : Vous etes propiétaire d'une usine de production. Vous fournissez des supermarchés ayant une demande infinie !\n");
        printf("Vous devez manufacturer des produits à partir de matière première et la vente de ces produits est automatique\n");
    }
    while(start){
        printf("Tour %d\n", tour);
        printf("Vous etes actuellement au niveau : %d\n", company.getLevel());
        printf("Vous avez actuellement %d pièces magiques\n", company.getBalance());
        printf("Vous avez actuellement %d elfs employés\n", company.getNbEmployees());
        printf("Vous avez actuellement %d kg de métal\n", metal.getNbRawMaterials());
        printf("Vous avez actuellement %d kg de plastique\n", plastic.getNbRawMaterials());
        printf("-------------------------------------------------------------------\n");


        //MATIERE PREMIERE
        printf("1. Souhaitez-vous acheter des matières premières ?\n 1(OUI) ou 0(NON) ?\n");
        scanf("%d", choix);
        if(choix==1){
            printf("Quelle de matière première voulez-vous acheter ?\n");
            printf("0. Metal\n 1. Plastique\n");
            scanf("%d", choix);
            if (choix == 0){
                printf("Combien de kg de métal voulez-vous acheter ?\n");
                scanf("%d", quantity);
                metal.buyRawMaterials(quantity);
            }
            
            else{
                printf("Combien de kg de plastique voulez-vous acheter ?\n");
                scanf("%d", quantity);
                metal.buyRawMaterials(quantity);
            }
            
        }



        //PRODUCTION
        printf("2. Produire des produits\n");
        printf("Souhaitez-vous changer la production?\n  1(OUI) ou 0(NON) ?\n");
        scanf("%d", choix);
        if(choix==1){





        //ENGAGER UN EMPLOYE
        printf("3. Engager un employé\n");




        printf("-------------------------------------------------------------------\n");
        tour++;
        printf("Voulez-vous continuer ? (1/0)\n");
        scanf("%d", &start);
    }
    return 0;
}