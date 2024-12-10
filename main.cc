#include "items.hh"

int main(){
    bool start=true;
    int tour = 0;
    if(tour == 0){
        printf("Bienvenue dans le jeu Fantastic Factory,\n Bonne production !\n");
        printf("Règles du jeu : Vous etes propiétaire d'une usine de production. Vous fournissez des supermarchés ayant une demande infinie !\n");
        printf("Vous devez manufacturer des produits à partir de matière première et la vente de ces produits est automatique\n");
    }
    while(start){
        printf("Tour %d\n", tour);
        printf("Vous etes actuellement au niveau : %d\n", company.getLevel());
        printf("Vous avez actuellement %d euros\n", company.getBalance());
        printf("Vous avez actuellement %d employés\n", company.getNbEmployees());
        printf("Vous avez actuellement %d matières premières\n", company.getNbRawMaterials());
        printf("-------------------------------------------------------------------\n");
        printf("1. Acheter des matières premières\n");
        printf("2. Produire des produits\n");
        printf("3. Engager un employé\n");




        printf("-------------------------------------------------------------------\n");
        tour++;
        printf("Voulez-vous continuer ? (1/0)\n");
        scanf("%d", &start);
    }
    return 0;
}