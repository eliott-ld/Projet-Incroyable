#include "jeu.hh"
#include "items.hh"
#include "metal.hh"
#include "plastic.hh"
#include "company.hh"

void Bienvenue(){
    std::cout << "Bienvenue dans le jeu Fantastic Factory,\n Bonne production !\n";
        std::cout << "Règles du jeu : Vous etes propiétaire d'une usine de production. Vous fournissez des supermarchés ayant une demande infinie !\n";
        std::cout << "Vous devez manufacturer des produits à partir de matière première et la vente de ces produits est automatique\n";
}

int choice(std::string Phrase){
    int choix_utilisateur = -1;
    std::cout << Phrase << std::endl ;
    std::cin >> choix;
    while ( (choix_utilisateur != 0) && (choix_utilisateur !=1) ){
        std::cout << "Veuillez choisir une option valide (0 ou 1).\n" << Phrase << std::endl;
        std::cin >> choix_utilisateur;
    }
    return choix_utilisateur
}

void Tour(int tour,Company company,Metal metal,Plastic plastic){
   std::cout << "Tour " << tour << "\n";
        std::cout << "Vous etes actuellement au niveau : " << company.getLevel() << "\n";
        std::cout << "Vous avez actuellement " << company.getBalance() << " pièces magiques\n";
        std::cout << "Vous avez actuellement " << company.getNbEmployees() << " elfs employés\n";
        std::cout << "Vous avez actuellement " << metal.getNbRawMaterials() << " kg de métal\n";
        std::cout << "Vous avez actuellement " << plastic.getNbRawMaterials() << " kg de plastique\n";
        std::cout << "-------------------------------------------------------------------\n"; 
}

int quantity(std::string Phrase){
    
}