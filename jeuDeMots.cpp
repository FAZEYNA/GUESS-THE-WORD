#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
//BUT
//Saisie du mot à deviner ;
//Mélange des lettres ;
//Boucle qui se répète tant que le mot mystère n'a pas été trouvé.

string melangerLettres(string motMystere);

int main()
{
    string const motMystere{"BANANE"};
    string reponse{""}, reponseRejouer{""};
    int essai{5};

    cout << "Bienvenue cher joueur ! Essayer de trouver le mot mystere. ATTENTION A LA CASSE !" << endl;
    do{
        do{ // CONTROLE DES REPONSES OUI ET NON
            cout << "Voulez-vous commencer la partie ?";
            cin >> reponseRejouer;
            cout << endl;
        }while(reponseRejouer != "non" && reponseRejouer != "oui");

        if(reponseRejouer == "oui")
        {
            do{
                cout << "Quel est ce mot : " << melangerLettres(motMystere) << " ? " << endl;
                cout << "Saisissez votre reponse." << endl;
                cin >> reponse;
                cout << endl;
                essai--;
                if(motMystere == reponse)
                {
                    cout << "Vous avez trouve !!!!!!!!!!!" << endl;
                    break;
                }
                else
                {
                    if(essai > 0)
                        cout << "Il vous reste " << essai << " tentatives." << endl;
                    else
                    {
                        "Vous avez perdu !";
                        break;
                    }   
                }      
            }while(motMystere != reponse);
        }
        else
        {
            break;
        }        
    }while(true);

    return 0;
}

string melangerLettres(string motMystere)
{
    srand(time(0)); //INITIALISATION DE LA GENERATION DES NBRES ALEATOIRES
    int nbreAleatoire{0};
    string motMelange{""};

    while (motMystere != "")
    {
       nbreAleatoire = rand() % motMystere.size();

       motMelange += motMystere[nbreAleatoire];

       motMystere.erase(nbreAleatoire,1);
    }
    return motMelange;
}