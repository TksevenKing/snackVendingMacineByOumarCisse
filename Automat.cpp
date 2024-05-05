#include<iostream>
#include<vector>
#include"Automat.h"


using namespace std;

Automat::Automat(int numSlots = 0,int numProductsPerSlot = 0){
	this->numSlots = numSlots;
	this->numProductsPerSlot = numProductsPerSlot;
	// Pas la peine de faire la resevation dynamique ici car vector<Slot> est un tableau dynamique et j'ajouterai avec addSlot()
    slots.reserve(numSlots);
};
Automat::~Automat(){
	cout<<"-- Automat "<<endl;
	// Liberation Automatique avec Vector
	    // Nettoyage des ressources allou�es dynamiquement
    for (Slot* slot : slots) {
        delete slot;
    }
};

bool Automat::addSlot(string productName,int price, int slotId, int motor1Id, int motor2Id) {
    // V�rifie si le slot avec cet ID existe d�j�
    for ( Slot* slot : slots) {
        if (slot->getId() == slotId) {
            cout << "Le slot avec l'ID " << slotId << " existe deja." << endl;
            return false;
        }
    }

    // Cr�e un nouveau slot et l'ajoute au vector
    Slot* newSlot = new WideSlot(slotId, productName, price, motor1Id, motor2Id);
    slots.push_back(newSlot);
    return true;
};
bool Automat::addSlot(string productName,int price, int slotId, int motor1Id){
    // V�rifie si le slot avec cet ID existe d�j�
    for ( Slot* slot : slots) {
        if (slot->getId() == slotId) {
            cout << "Le slot avec l'ID " << slotId << " existe deja." << endl;
            return false;
        }
    }

    // Cr�e un nouveau slot et l'ajoute au vector
    Slot* newSlot = new SmallSlot(slotId, productName, price, motor1Id);
    slots.push_back(newSlot);
    return true;
}
Slot* Automat::searchSlot(int slotId) {
    // V�rifie si le slot recherch� est d�j� mis en cache
    if (cached != nullptr && cached->getId() == slotId) {
       // cout << "Le slot avec l'ID " << slotId << " a ete trouve dans le cache." << endl;
        return cached;
    }

    // Recherche le slot dans le vector
    for (Slot* slot : slots) {
        if (slot->getId() == slotId) {
            // Met � jour le slot en cache
            cached = slot;
        //    cout << "Le slot avec l'ID " << slotId << " a ete trouve." << endl;
            return slot;
        }
    }

    // Aucun slot correspondant n'a �t� trouv�, r�initialise le cache
    cached = nullptr;
    cout << "Le slot avec l'ID " << slotId << " n'a pas ete trouve." << endl;
    // Retourner un Slot par d�faut si aucun slot correspondant n'a �t� trouv�
    return nullptr;
}

void Automat::changeSlot(int slotId, string name, int price) {
    for (Slot* slot : slots) {
        if (slot->getId() == slotId) {
            // Modifie le nom du produit si le param�tre 'name' n'est pas une cha�ne vide
            if (!name.empty()) {
                slot->setProductName(name);
            }
            // Modifie le prix du produit si le param�tre 'price' est sup�rieur � z�ro
            if (price > 0) {
                slot->setPrice(price);
            }
            cout << "Le produit dans le slot avec l'ID " << slotId << " a ete modifie." << endl;
            return;
        }
    }
    cout << "Le slot avec l'ID " << slotId << " n'a pas  ete trouve." << endl;
}
int Automat::getPieces(int slotId) {
    for ( Slot* slot : slots) {
       if (slot->getId() == slotId){
            cout << "Le nombre de produits dans le slot avec l'ID " << slotId << " est " << slot->getNumProduct() << "." << endl;
            return slot->getNumProduct();
        }
    }
    cout << "Le slot avec l'ID " << slotId << " n'a pas  ete trouve." << endl;
    return 0; // Retourne 0 si le slot n'a pas �t� trouv�
}
int Automat::getPrice(int slotId) {
    for ( Slot* slot : slots) {
        if (slot->getId() == slotId) {
            //cout << "Le prix du produit dans le slot avec l'ID " << slotId << " est " << slot->getPrice() << "." << endl;
            return slot->getPrice();
        }
    }
    cout << "Le slot avec l'ID " << slotId << " n'a pas ete trouve." << endl;
    return 0; // Retourne 0 si le slot n'a pas �t� trouv�
}
bool Automat::isAvailable(int slotId) {
    for ( Slot* slot : slots) {
        if (slot->getId() == slotId) {
            int numProducts = slot->getNumProduct();
            if (numProducts > 0) {
                ///**<  */cout << "Le produit dans le slot avec l'ID " << slotId << " est disponible." << endl;
                return true;
            } else {
                cout << "Le produit dans le slot avec l'ID " << slotId << " n'est pas disponible." << endl;
                return false;
            }
        }
    }
    cout << "Le slot avec l'ID " << slotId << " n'a pas  ete trouve." << endl;
    return false; // Retourne false si le slot n'a pas �t� trouv�
}
bool Automat::dropSlot(int slotId) {
    for ( Slot* slot : slots) {
        if (slot->getId() == slotId) {
            slot->drop();
            return true; // Retourne true si le slot a �t� trouv� et le produit a �t� �ject�
        }
    }


    cout << "Le slot avec l'ID " << slotId << " n'a pas  ete trouve." << endl;
    return false; // Retourne false si le slot n'a pas �t� trouv�
}
void Automat::fillAll() {
    for ( Slot* slot : slots) {
        slot->setNumProduct(numProductsPerSlot);
    }
    cout << "Tous les emplacements ont ete remplis avec le nombre maximal de produits." << endl;
}
void Automat::remplir(int slotId, int numProducts) {
    for ( Slot* slot : slots) {
        if (slot->getId() == slotId) {
            slot->setNumProduct(numProducts);
            cout << "Le slot avec l'ID " << slotId << " a ete rempli avec " << numProducts << " produits." << endl;
            return;
        }
    }
    cout << "Le slot avec l'ID " << slotId << " n'a pas ete trouve." << endl;
}
int Automat::getNumSlot(){
return numSlots;
}
