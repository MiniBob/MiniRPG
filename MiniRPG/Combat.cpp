#include "Combat.h"

using namespace std;

///Gestion d'un combat au tour par tour dans l'arène
///La fuite est impossible
void combatArene(Joueur &joueur,Ennemi &ennemi)
{
    bool combatActif(true);

    cout << endl << endl;
    phrase("Un combat d\x82");
    phrase("bute entre " + joueur.getNom() + " et " + accorde("le ","la ",ennemi.estMasculin()) + ennemi.getNom() + ".");
    finLigne(300);

    while(combatActif)
    {
        ///Action du joueur
        combatActif = actionArene(joueur,ennemi);

        ///Fin du premier combat du didactitiel
        if(ennemi.getNom() == "Mannequin" && ennemi.getPv() < ennemi.getPvMax()*3/4)
        {
            finLigne(500);
            combatActif = false;
        }

        ///Tour de l'ennemi s'il est toujours vivant et si le joueur n'a pas fuit
        if(ennemi.estVivant() && combatActif)
        {
            combatActif = actionEnnemi(ennemi,joueur);
        }

        ///Phrase de mort de l'arene
        if(!joueur.estVivant() && ennemi.getNom() != "Chef Instructeur")
        {
            cout << endl;
            phrase("Comme le dit un dicton populaire : deux hommes rentrent, un homme sort.");
            finLigne(1000);
            phrase(accorde("Le ","La ",ennemi.estMasculin()) + ennemi.getNom() + " n'a pas laiss\x82 " + joueur.getNom() + " sortir.");
        }

        sleep(1000);
    }
}

///Gestion d'un combat au tour par tour dans le désert
///Fuir fait revenir le joueur à sa position précedente
bool combatDesert(Joueur &joueur,Ennemi &ennemi)
{
    bool combatActif;

    cout << endl << endl;
    phrase("Un combat d\x82");
    phrase("bute entre " + joueur.getNom() + " et " + accorde("le ","la ",ennemi.estMasculin()) + ennemi.getNom() + ".");
    finLigne(300);

    do
    {
        ///Action du joueur
        combatActif = actionDesert(joueur,ennemi);

        if(!combatActif && ennemi.estVivant())
        {
            return false;
        }

        ///Tour de l'ennemi s'il est toujours vivant et si le joueur n'a pas fuit
        if(ennemi.estVivant() && combatActif)
        {
            combatActif = actionEnnemi(ennemi,joueur);
        }

        ///Phrase de mort du Desert
        if(!joueur.estVivant())
        {
            sleep(1000);
            cout << endl;
            phrase("Quand on pense que vous \x88tes " + accorde("le","la",joueur.estMasculin()) + " champion" + accorde("","ne",joueur.estMasculin()) + " de l'ar\x8Ane.");
            cout << endl;
            finLigne(1500);
            phrase("Enfin, vous \x82tiez...");
            cout << endl;
            finLigne(1000);
            return false;
        }
        sleep(500);

    }while(combatActif);

    return true;
}

///Dans le désert
///Succession de 5 combats
///Les 2 suites de combats doivent être finies pour activer le mini-boss
bool combatCampBandit(Joueur &joueur, bool campGaucheFini, bool campDroiteFini)
{
    Ennemi Bandit1("premier Bandit",750,150,125,125,"doliprane",125,30,0,1,true,true,PartieContondante,100);
    Ennemi Bandit2("deuxi\x8Ame Bandit",750,150,125,125,"papier bulle",125,30,0,1,true,true,Enflamme,100);
    Ennemi Bandit3("troisi\x8Ame Bandit",750,150,125,125,"rouge \x85 levre",125,30,0,1,true,true,Farci,100);
    Ennemi Bandit4("quatri\x8Ame Bandit",750,150,125,125,"liane",125,30,0,1,false,true,BordPointu,100);
    Ennemi Bandit5("cinqui\x8Ame Bandit",750,150,125,125,"martini",125,30,0,1,true,true,HuileEssentielle,100);
    Ennemi Bandit6("sixi\x8Ame Bandit",750,150,125,125,"fervex",125,30,0,1,true,true,PartieContondante,100);
    Ennemi Bandit7("septi\x8Ame Bandit",750,150,125,125,"carton",125,30,0,1,true,true,Enflamme,100);
    Ennemi Bandit8("huiti\x8Ame Bandit",750,150,125,125,"vernis \x85 ongle",125,30,0,1,true,true,Farci,100);
    Ennemi Bandit9("neuvi\x8Ame Bandit",750,150,125,125,"foug\x8Are",125,30,0,1,false,true,BordPointu,100);
    Ennemi Bandit10("dernier Bandit",750,150,125,125,"suze",125,30,0,1,false,true,HuileEssentielle,100);
    Ennemi BossCamp("Chef des bandits",1000,200,150,200,"sable fin",150,40,1,10000,true,true,DansLesYeux,150);
    Ennemi Caillou("caillou",1,1,joueur.getPvMax(),1000,"angle pointu",joueur.getPvMax(),0,0,0,true,true);

    if(campGaucheFini || campDroiteFini)
    {
        if(combatDesert(joueur,Bandit6))
        {
            if(combatDesert(joueur,Bandit7))
            {
                if(combatDesert(joueur,Bandit8))
                {
                    if(combatDesert(joueur,Bandit9))
                    {
                        if(combatDesert(joueur,Bandit10))
                        {
                            phrase("Eh ben, ils \x82taient plus nombreux que pr\x82vu.");
                            finLigne(500);
                            phrase("Ce qui est facile quand vous n'aviez pas pr\x82vu de combattre des bandits.");
                            finLigne(1000);
                            cout << endl;
                            phrase("En parlant de combats impr\x82vus, un grand bonhomme s'avance vers vous en enjambant les corps de ses camarades, l'air d\x82termin\x82.");
                            finLigne(500);
                            phrase("Lui, semble avoir pr\x82vu de vous abattre.");
                            finLigne(1000);

                            combatDesert(joueur,BossCamp);

                            if(joueur.estVivant() && BossCamp.estVivant())
                            {
                                phrase("Le chef des bandits vous rattrape et vous fait un croche-patte.");
                                finLigne(1000);
                                phrase("Vous tombez sur un caillou.");
                                finLigne(500);
                                finLigne(500);

                                Caillou.attaque(joueur);
                            }
                            else if(joueur.estVivant())
                            {
                                felicitations("Le chef des bandits est mort");

                                phrase("Bon.");
                                finLigne(1500);
                                phrase("Vous pouvez reprendre votre escapade dans le d\c82sert.");
                                finLigne(500);
                                finLigne(500);
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    else if(!campGaucheFini && !campDroiteFini)
    {
        if(combatDesert(joueur,Bandit1))
        {
            if(combatDesert(joueur,Bandit2))
            {
                if(combatDesert(joueur,Bandit3))
                {
                    if(combatDesert(joueur,Bandit4))
                    {
                        if(combatDesert(joueur,Bandit5))
                        {
                            phrase("Vous pensiez en avoir enfin fini avec ces bandits, mais vous allez devoir continuer, parce que le camp se poursuit \x85 l'");
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

///Gestion d'un combat au tour par tour dans le marai
///Fuir fait revenir le joueur à sa position précedente
bool combatMarai(Joueur &joueur,Ennemi &ennemi)
{
    bool combatActif;

    cout << endl << endl;
    phrase("Un combat d\x82");
    phrase("bute entre " + joueur.getNom() + " et " + accorde("le ","la ",ennemi.estMasculin()) + ennemi.getNom() + ".");
    finLigne(300);

    do
    {
        ///Action du joueur
        combatActif = actionMarai(joueur,ennemi);

        if(!combatActif && ennemi.estVivant())
        {
            return false;
        }

        ///Tour de l'ennemi s'il est toujours vivant et si le joueur n'a pas fuit
        if(ennemi.estVivant() && combatActif)
        {
            combatActif = actionEnnemi(ennemi,joueur);
        }

        ///Phrase de mort du Marai
        if(!joueur.estVivant())
        {
            sleep(1000);
            cout << endl;
            phrase("Gr\x83\ace \x85 vous, cet endroit est devenu le marai des morts.");
            finLigne(500);
            finLigne(500);
            phrase("On devrait en faire un film.");
            finLigne(500);
            finLigne(500);
            return false;
        }
        sleep(500);

    }while(combatActif);

    return true;
}

///Gestion du tour du joueur dans l'arène
///La fuite est impossible
///La fuite pendant l'intro est fatale
bool actionArene(Joueur &joueur,Ennemi &ennemi)
{
    int i;
    string action;

    do
    {
        i = 1;
        ///Description des actions possibles
        cout << endl << endl;
        phrase("Que faites-vous ?");
        finLigne(300);
        phrase("1.Attaquer");
        cout << "      ";
        phrase("2.M\x82\aditer");
        cout << "      ";
        phrase("3.Fuir");
        cout << endl;
        phrase("4.Stat");
        cout << "          ";
        phrase("5.Arme");
        finLigne(300);

        getline(cin,action);

        for(unsigned int j = 0;j < action.size();j++)
        {
            action[j] = tolower(action[j]);
        }

        ///Indentification de l'action effectuée
        if(action == "1" || action == "attaquer" || action == "1.attaquer")
        {
            joueur.attaque(ennemi);
            return ennemi.estVivant();
        }
        else if(action == "2" || action == "mediter" || action == "2.mediter" || action == "m\x82\aditer" || action == "2.m\x82\aditer")
        {
            joueur.medite();
            return true;
        }
        else if(action == "3" || action == "fuir" || action == "3.fuir")
        {
            if(ennemi.getNom() == "Mannequin" || ennemi.getNom() == "Second mannequin" || ennemi.getNom() == "Chef Instructeur")
            {
                return false;
            }
            else
            {
                cout << endl;
                phrase("Ce serait facile de partir maitenant, hein, mais la vie, c'est pas si facile...");
                finLigne(300);
                phrase("Maintenant, battez-vous, ou mourez !!!");
                finLigne(300);
                i = 0;
            }
        }
        else if(action == "4" || action == "stat" || action == "4.stat")
        {
            joueur.afficheStat();
            i = 0;
        }
        else if(action == "5" || action == "arme" || action == "5.arme")
        {
            joueur.afficheArme();
            i = 0;
        }
        else if(action.size() == 0)
        {
            phrase("La t\x82l\x82pathie, c'est pas mon truc.");
            finLigne(500);
            phrase("Il faut \x82\acrire ce que vous voulez faire.");
            finLigne(500);
            i = 0;
        }
        else
        {
            ///Redemande l'action si elle n'a pas été comprise
            cout << endl;
            phrase("Moi pas comprendre quoi toi dire. Moi comprendre que mot dessus. Mais moi comprendre mot sans grande lettre du d\x82\abut ou que chiffre devant.");
            finLigne(500);
            i = 0;
        }

    }while(i == 0);

    return false;
}

///Gestion du tour du joueur dans le désert
bool actionDesert(Joueur &joueur,Ennemi &ennemi)
{
    int i;
    string action;

    do
    {
        i = 1;
        ///Description des actions possibles
        cout << endl << endl;
        phrase("Que faites-vous ?");
        finLigne(300);
        phrase("1.Attaquer");
        cout << "      ";
        phrase("2.M\x82\aditer");
        cout << "      ";
        phrase("3.Fuir");
        cout << endl;
        phrase("4.Stat");
        cout << "          ";
        phrase("5.Arme");
        finLigne(300);

        getline(cin,action);

        for(unsigned int j = 0;j < action.size();j++)
        {
            action[j] = tolower(action[j]);
        }

        ///Indentification de l'action effectuée
        if(action == "1" || action == "attaquer" || action == "1.attaquer")
        {
            joueur.attaque(ennemi);
            return ennemi.estVivant();
        }
        else if(action == "2" || action == "mediter" || action == "2.mediter" || action == "m\x82\aditer" || action == "2.m\x82\aditer")
        {
            joueur.medite();
            return true;
        }
        else if(action == "3" || action == "fuir" || action == "3.fuir")
        {
            srand(time(0));

            int energieFuite = rand() % joueur.getEnergie();

            if(energieFuite > joueur.getEnergieMax()/3)
            {
                joueur.setEnergie(energieFuite,false);
                finLigne(500);
                phrase(accorde("Le ","La ",ennemi.estMasculin()) + ennemi.getNom() + " soupire en vous regardant partir.");
                finLigne(1000);
                return false;
            }
            else
            {
                phrase(joueur.getNom() + " n'a pas trouv\x82 l'\x82nergie pour s'\x82\achapper.");
                finLigne(1000);
                return true;
            }
        }
        else if(action == "4" || action == "stat" || action == "4.stat")
        {
            joueur.afficheStat();
            i = 0;
        }
        else if(action == "5" || action == "arme" || action == "5.arme")
        {
            joueur.afficheArme();
            i = 0;
        }
        else if(action.size() == 0)
        {
            phrase("La t\x82l\x82pathie, c'est pas mon truc.");
            finLigne(500);
            phrase("Il faut \x82\acrire ce que vous voulez faire.");
            finLigne(500);
            i = 0;
        }
        else
        {
            ///Redemande l'action si elle n'a pas été comprise
            cout << endl;
            phrase("Moi pas comprendre quoi toi dire. Moi comprendre que mot dessus. Mais moi comprendre mot sans grande lettre du d\x82\abut ou que chiffre de devant.");
            finLigne(300);
            i = 0;
        }

    }while(i == 0);

    return false;
}

///Gestion du tour du joueur dans le marai
bool actionMarai(Joueur &joueur,Ennemi &ennemi)
{
    int i;
    string action;

    do
    {
        i = 1;
        ///Description des actions possibles
        cout << endl << endl;
        phrase("Que faites-vous ?");
        finLigne(300);
        phrase("1.Attaquer");
        cout << "      ";
        phrase("2.M\x82\aditer");
        cout << "      ";
        phrase("3.Fuir");
        cout << endl;
        phrase("4.Stat");
        cout << "          ";
        phrase("5.Arme");
        finLigne(300);

        getline(cin,action);

        for(unsigned int j = 0;j < action.size();j++)
        {
            action[j] = tolower(action[j]);
        }

        ///Indentification de l'action effectuée
        if(action == "1" || action == "attaquer" || action == "1.attaquer")
        {
            joueur.attaque(ennemi);
            return ennemi.estVivant();
        }
        else if(action == "2" || action == "mediter" || action == "2.mediter" || action == "m\x82\aditer" || action == "2.m\x82\aditer")
        {
            joueur.medite();
            return true;
        }
        else if(action == "3" || action == "fuir" || action == "3.fuir")
        {
            srand(time(0));

            int energieFuite = rand() % joueur.getEnergie();

            if(energieFuite > joueur.getEnergieMax()/3)
            {
                joueur.setEnergie(energieFuite,false);
                finLigne(500);
                phrase(accorde("Le ","La ",ennemi.estMasculin()) + ennemi.getNom() + " soupire en vous regardant partir.");
                finLigne(1000);
                return false;
            }
            else
            {
                phrase(joueur.getNom() + " n'a pas trouv\x82 l'\x82nergie pour s'\x82\achapper.");
                finLigne(1000);
                return true;
            }
        }
        else if(action == "4" || action == "stat" || action == "4.stat")
        {
            joueur.afficheStat();
            i = 0;
        }
        else if(action == "5" || action == "arme" || action == "5.arme")
        {
            joueur.afficheArme();
            i = 0;
        }
        else if(action.size() == 0)
        {
            phrase("La t\x82l\x82pathie, c'est pas mon truc.");
            finLigne(500);
            phrase("Il faut \x82\acrire ce que vous voulez faire.");
            finLigne(500);
            i = 0;
        }
        else
        {
            ///Redemande l'action si elle n'a pas été comprise
            cout << endl;
            phrase("Moi pas comprendre quoi toi dire. Moi comprendre que mot dessus. Mais moi comprendre mot sans grande lettre du d\x82\abut ou que chiffre de devant.");
            finLigne(300);
            i = 0;
        }

    }while(i == 0);

    return false;
}

///Gestion du tour de l'ennemi
bool actionEnnemi(Ennemi &ennemi,Joueur & joueur)
{
    int seuilPv,seuilEffort;

    seuilPv = ennemi.getPvMax()/3;
    seuilEffort = ennemi.getEnergieMax()/3;

    ///Attaque par défaut
    if(ennemi.getNom() == "Mannequin" || ennemi.getNom() == "Second mannequin")
    {
        ennemi.attaque(joueur);
    }
    ///Décide aléatoirement de se soigner ou de se reposer lorsque la vie ou l'énergie est assez basse
    else if(ennemi.getPv() < seuilPv || ennemi.getEnergieMax() < seuilEffort || ennemi.getEnergie() == 0)
    {
        if(time(0) % 2 == 0)
        {
            ennemi.medite();
        }
        else
        {
            ennemi.attaque(joueur);
        }
    }
    else
    {
        ennemi.attaque(joueur);
    }

    return joueur.estVivant();
}
