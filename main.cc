#include "items.hh"
#include <iostream>

int main(){
    bool start = true;
    int tour = 0;
    bool choix = 0;
    int quantity = 0;
    if(tour == 0){
        std::cout << "Bienvenue dans le jeu Fantastic Factory,\n Bonne production !\n";
        std::cout << "Règles du jeu : Vous etes propiétaire d'une usine de production. Vous fournissez des supermarchés ayant une demande infinie !\n";
        std::cout << "Vous devez manufacturer des produits à partir de matière première et la vente de ces produits est automatique\n";
    }
    while(start){
        std::cout << "Tour " << tour << "\n";
        std::cout << "Vous etes actuellement au niveau : " << company.getLevel() << "\n";
        std::cout << "Vous avez actuellement " << company.getBalance() << " pièces magiques\n";
        std::cout << "Vous avez actuellement " << company.getNbEmployees() << " elfs employés\n";
        std::cout << "Vous avez actuellement " << metal.getNbRawMaterials() << " kg de métal\n";
        std::cout << "Vous avez actuellement " << plastic.getNbRawMaterials() << " kg de plastique\n";
        std::cout << "-------------------------------------------------------------------\n";

        //MATIERE PREMIERE
        std::cout << "1. Souhaitez-vous acheter des matières premières ?\n 1(OUI) ou 0(NON) ?\n";
        std::cin >> choix;
        //Si l'utilisateur saisit autre chose que 0 ou 1
        while ( (choix != 0) && (choix !=1) ){
            std::cout << "Veuillez choisir une option valide (0 ou 1).\nSouhaitez-vous acheter des matières premières ?\n";
            std::cin >> choix;
        }
        if(choix == 1){
            std::cout << "Quelle de matière première voulez-vous acheter ?\n";
            std::cout << "0. Metal\n1. Plastique\n";
            std::cin >> choix;
            //Si l'utilisateur saisit autre chose que 0 ou 1
            while ( (choix != 0) && (choix !=1) ){
                std::cout << "Veuillez choisir une option valide (0 ou 1).\nQuelle de matière première voulez-vous acheter ?\n0. Metal\n1. Plastique\n";
                std::cin >> choix;
            }
            if (choix == 0){
                std::cout << "Combien de kg de métal voulez-vous acheter ?\n";
                std::cin >> quantity;
                metal.buyRawMaterials(quantity);
            }
            
            if (choix == 1){
                std::cout << "Combien de kg de plastique voulez-vous acheter ?\n";
                std::cin >> quantity;
                plastic.buyRawMaterials(quantity);
            }
            else{
                std::cout << "Veuillez choisir une option valide (0 ou 1)\n";
            }
        }

        //PRODUCTION
        std::cout << "2. Produire des produits\n";
        std::cout << "Souhaitez-vous changer la production?\n  1(OUI) ou 0(NON) ?\n";
        std::cin >> choix;
        if(choix == 1){
            // Ajoutez ici le code pour changer la production
        }

        //ENGAGER UN EMPLOYE
        std::cout << "3. Engager un employé\n";

        std::cout << "-------------------------------------------------------------------\n";
        tour++;
        std::cout << "Voulez-vous continuer ? (1/0)\n";
        std::cin >> start;
    }
    return 0;
}
