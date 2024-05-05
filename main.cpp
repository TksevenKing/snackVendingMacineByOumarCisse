#include <iostream>
#include<ctime>
#include<cstdlib>
#include"Automat.h"


using namespace std;



enum State {
    IDLE,
    COLLECT_MONEY,
    DROP,
    RETURN_MONEY
};

int main() {



    Automat automat(15, 10); // Création d'un distributeur automatique avec 10 emplacements, 10 produits par emplacement
    Keypad keypad;
    CoinSlot coinSlot;
    DropCheck dropCheck;

    State currentState = IDLE;
    int selectedSlot = -1;
    int totalPrice = 0;
    int totalAmount = 0;

    srand(time(nullptr)); // Initialisation du générateur de nombres aléatoires avec le temps actuel

    // Ajout de quelques emplacements de produit avec des identifiants uniques
    automat.addSlot("Chips    ",5, 1, 1, 2);
    automat.addSlot("Lays     ", 10,2, 3, 4);
    automat.addSlot("Doritos  ", 3, 3, 5, 6);
    automat.addSlot("Pringles ",20, 4, 7, 8);
    automat.addSlot("Chitos   ", 10,5, 9, 10);
    automat.addSlot("m&m's    ", 3, 6, 11);
    automat.addSlot("m&m'sCoco", 7, 7,12);
    automat.addSlot("HERSHEY'S",15, 8, 13);
    automat.addSlot("MilkyWay ", 10,9, 14);
    automat.addSlot("Skittle  ", 3, 10, 15);
    automat.addSlot("SNICKERS ", 10, 11,16);
    automat.addSlot("TWIX     ",5, 12, 17);
    automat.addSlot("PayDay   ", 10,13, 18);
    automat.addSlot("Bimo     ", 3, 14, 19);
    automat.addSlot("kingBon  ", 3, 15, 20);


//    // Remplissage de tous les emplacements avec le nombre maximal de produits
    automat.fillAll();
   // automat.remplir(1, 3);
  // automat.changeSlot(1,"Poko     ",7);



    while (true) {
        switch (currentState) {
            case IDLE:
                cout << "=============== Etat actuel : IDLE ================" << std::endl;

                    // Affichage des produits disponibles
                #include <iostream>

                cout << " ________________________________________________________" << std::endl;
                cout << "|                                                        |" << std::endl;
                cout << "|                 Snack Vending Machine                  |" << std::endl;
                cout << "|________________________________________________________|" << std::endl;

                cout << "_________________________________________________________\n";
                cout << "| Emplacement |    Produit        |  Prix  |  Quantite  | \n";
                cout << "|-------------|-------------------|--------|-------------\n";

                // Supposons que vous ayez une méthode dans la classe Automat pour obtenir tous les produits
                for (int i = 1; i <= automat.getNumSlot(); ++i) {
                    Slot* slot = automat.searchSlot(i);
                    if (slot != nullptr) {
                        cout << "|     " << slot->getId() << "       | ";
                        cout << slot->getProductName() << "        | ";
                        cout << slot->getPrice() << "       |";
                        cout<<"  "<< slot->getNumProduct() << "        |\n";
                    }
                }

                cout << "|_____________|____________________|________|____________|\n";
                cout << "Selectionnez le numero d'emplacement du produit (ou -1 pour annuler) : ";
                selectedSlot  = keypad.getSelection();
                if (selectedSlot == -1 ) {
                    std::cout << "Achat annule." << std::endl;
                    //currentState = IDLE;
                    exit(0);
                } else if(selectedSlot > automat.getNumSlot()) {
                    cout << "Le produit avec l'ID "<< selectedSlot << " n'a pas ete trouve."<< endl;
                          currentState = IDLE;
                }else{
                    totalPrice = automat.getPrice(selectedSlot);
                    currentState = COLLECT_MONEY;
                }
                break;

            case COLLECT_MONEY:
                cout << "=============== Etat actuel : COLLECT_MONEY ===============" << std::endl;
                cout << "Montant a payer : " << totalPrice << " euros" << std::endl;
                int coin;
				coin  = coinSlot.updateCoinAmount();
                if (coin == -1) {
                    cout << "Achat annule. Retour de l'argent." << std::endl;
                   // coinSlot.returnCoins(totalAmount);
                    currentState = RETURN_MONEY;
                    //currentState = IDLE;
                } else {
                    totalAmount += coin;
                    cout << "Montant insere : " << totalAmount << " euros" << std::endl;
                    if (totalAmount >= totalPrice) {
                            if(automat.isAvailable(selectedSlot)){
                                currentState = DROP;
                            }else{
                                coin = -1;
                                currentState = RETURN_MONEY;
                            }


                    }
                }
                break;

            case DROP:
                cout << "=============== Etat actuel : DROP ===============" << std::endl;
                automat.dropSlot(selectedSlot);
                if (dropCheck.productReleased()) {
                    cout << "Produit livre avec succes !" << std::endl;
                    currentState = RETURN_MONEY;
                } else {
                    cout << "Le produit n'a pas ete livre. Nouvelle tentative en cours ..." << std::endl;
                    currentState = DROP;
                }
                break;

            case RETURN_MONEY:
                cout << "=============== Etat actuel : RETURN_MONEY ===============" << std::endl;
                if(coin == -1){
                	coinSlot.returnCoins(totalAmount);
				}else{
					coinSlot.returnCoins(totalAmount - totalPrice);
				}

                totalAmount = 0;
                int choix ;
                cout << "======== Appuyer sur  '''1''' pour revoir la liste des produits =========="<< endl;
                cin >> choix;
                if(choix == 1){
                    currentState = IDLE;
                }
               // currentState = IDLE;
                break;
        }
    }

    return 0;
}
