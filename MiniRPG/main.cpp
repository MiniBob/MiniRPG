#include <cmath>
#include "main.h"

using namespace std;

Arme Aucune("Aucune",0,0,true);

int main ()
{
    bool areneFinie = false, maraiFini = false, archipelFini = false;
    int introFinie, desertFini = 0;
    bool joueurEstMasculin, jeuFini = false;/*

    Joueur Test("Test",true);

    desert(Test);return 0;*/

    joueurEstMasculin = estMasculinJoueur();

    Joueur Joueur(getNomJoueur(joueurEstMasculin),joueurEstMasculin);

    introFinie = intro(Joueur);

    if(introFinie != -1)
    {
        if(introFinie == 1)
        {
            areneFinie = true;
        }
        else if(introFinie == 2)
        {
            areneFinie = true;
            desertFini = 2;
        }
        else if(introFinie == 3)
        {
            areneFinie = true;
            desertFini = 3;
        }

        if(!areneFinie)
        {
            areneFinie = arene(Joueur);
        }

        if(areneFinie)
        {
            if(desertFini == 0)
            {
                desertFini = desert(Joueur);
            }

            if(desertFini == 2)
            {
                maraiFini = marai(Joueur);
            }
            else if(desertFini == 3)
            {
                archipelFini = archipel(Joueur);
            }

            if(archipelFini || maraiFini)
            {
                jeuFini = true;
            }
        }
    }

    finProgramme(jeuFini,joueurEstMasculin);

    return 0;
}

///Fonctions qui permettent d'interagir avec le joueur

///Demande au joueur de spécifier son sexe
bool estMasculinJoueur()
{
    ///Discussion pour obtenir le sexe du joueur
    bool joueurEstMasculin,genreVide(true);
    string genre,espace(" ");

    phrase("Tiens, encore un qui glandouille.");
    finLigne(500);
    phrase("J'aurai du prendre mes lunnettes, j'arrive pas \x85 voir si vous \x88tes un homme ou une femme.");
    finLigne(500);
    phrase("Dans le doute, toujours demander. ");
    finLigne(1000);
    phrase("Alors, vous \x88tes un homme, ou une femme ?");
    cout << endl;

    do
    {
        getline(cin,genre);

        if(genre.size() >= 1)
        {
            for(unsigned int i = 0;i < genre.size();i++)
            {
                if(genre[i] != espace[0])
                {
                    genreVide = false;
                }
            }
        }

        if(genreVide)
        {
            finLigne(500);
            phrase("Allez");
            sleep(500);
            phrase(", ne soyez pas timide.");
            finLigne(500);
            phrase("C'est pas comme si on vous demandait de le montrer, votre sexe, ");
            sleep(500);
            phrase("juste de nous dire lequel c'est.");
        }
        else
        {

            for(unsigned int i = 0;i < genre.size();i++)
            {
                genre[i] = tolower(genre[i]);
            }

            if(genre == "homme")
            {
                joueurEstMasculin = true;
            }
            else if(genre == "femme")
            {
                joueurEstMasculin = false;
            }
            else
            {
                cout << endl;
                phrase("Ne compliquez pas les choses et dites, en un seul mot, si vous \x88tes un HOMME ou une FEMME.");
                genreVide = true;
            }
        }

        finLigne(500);

    }while(genreVide);

    phrase("Ah d'accord...");
    finLigne(1000);
    phrase("J'aurai dit ");
    phrase(accorde("une femme","un homme",joueurEstMasculin));
    phrase(", moi.");
    finLigne(300);
    finLigne(300);
    finLigne(300);
    phrase("*r\x82\afl\x82\achit*");
    finLigne(750);
    finLigne(750);
    finLigne(750);
    phrase(accorde("Vous \x88tes s\x96re ?","Vous auriez pu vous \x82piler...",joueurEstMasculin));
    finLigne(500);
    phrase("Enfin, bref. ");
    sleep(500);
    phrase("On va dire que vous \x88tes ce que vous \x88tes.");
    finLigne(500);

    return joueurEstMasculin;
}

///Demande le nom du joueur
string getNomJoueur(bool joueurEstMasculin)
{
    ///Discussion pour obtenir le nom du joueur
    bool nomVide(true);
    string nomJoueur,espace(" ");

    phrase("Et comment qu'");
    phrase(accorde("il","elle",joueurEstMasculin));
    phrase(" s'appelle ");
    phrase(accorde("celui","celle",joueurEstMasculin));
    phrase("-l\x85 ?");
    finLigne(500);

    do
    {
        getline(cin,nomJoueur);

        if(nomJoueur.size() >= 1)
        {
            for(unsigned int i = 0;i < nomJoueur.size();i++)
            {
                if(nomJoueur[i] != espace[0])
                {
                    nomVide = false;
                }
            }
        }

        if(nomVide)
        {
            phrase("Allez");
            sleep(500);
            phrase(", on me dit son petit nom si on veut pas passer la journ\x82\ae ici.");
            cout << endl;
        }

    }while(nomVide);

    cout << endl;

    return nomJoueur;
}

///Détermine les événements en fonction de la direction du joueur
void deplacementDesert(Joueur &joueur, int grilleDesert[][25], string carteDesert[][25][9], int &joueurPosX, int &joueurPosY, bool deplacementDesertSafe, bool &campGaucheFini, bool &campDroiteFini, bool &premiereVisiteFrontiere, bool carteTrouvee)
{
    string direction,reponse;
    int position,positionX,positionY;
    bool recommencer;

    setCaseCarteDesert(carteDesert,joueurPosX,joueurPosY,grilleDesert);

    do
    {
        recommencer = false;

        phrase("O\x97 voulez-vous aller ?");
        finLigne(500);
        cout << "            ";
        phrase("1.Nord");
        cout << endl;
        phrase("2.Ouest     ");

        if(carteTrouvee)
        {
            phrase("5.Carte");
        }
        else
        {
            cout << "       ";
        }
        cout << "      ";
        phrase("3.Est");
        cout << endl << "            ";
        phrase("4.Sud");
        cout << endl;


        getline(cin,direction);
        cout << endl << endl;

        for(unsigned int i = 0;i < direction.size();i++)
        {
            direction[i] = tolower(direction[i]);
        }

        if(direction != "1.nord" && direction != "1" && direction != "nord" && direction != "n")
        {
            if(direction != "2.ouest" && direction != "2" && direction != "ouest" && direction != "o")
            {
                if(direction != "3.est" && direction != "3" && direction != "est" && direction != "e")
                {
                    if(direction != "4.sud" && direction != "4" && direction != "sud" && direction != "s")
                    {
                        if(carteTrouvee)
                        {
                            if(direction == "5.carte" || direction == "5" || direction == "carte" || direction == "c")
                            {
                                afficheCarteDesert(carteDesert,joueurPosX,joueurPosY);
                            }
                        }

                        recommencer = true;
                    }
                }
            }
        }

        if(!recommencer && direction[0] != '5' && direction[0] != 'c')
        {
            recommencer = !bonneDirectionDesert(grilleDesert,joueurPosX,joueurPosY,direction);
        }

    }while(recommencer);

    position = grilleDesert[joueurPosX][joueurPosY];
    positionX = joueurPosX;
    positionY = joueurPosY;

    if(direction[0] == '1' || direction[0] == 'n')
    {
        joueurPosY--;
    }
    else if(direction[0] == '2' || direction[0] == 'o')
    {
        joueurPosX--;
    }
    else if(direction[0] == '3' || direction[0] == 'e')
    {
        joueurPosX++;
    }
    else if(direction[0] == '4' || direction[0] == 's')
    {
        joueurPosY++;
    }

    ///Approche d'une sortie
    if((joueurPosX <= 4 && joueurPosY >= 13 && (positionX >= 5 || positionY <= 12)) || (joueurPosX >= 20 && joueurPosY >= 12 && positionX <= 19))
    {
        if(time(0) % 2 == 0)
        {
            phrase("Vous voyez que devant vous le passage se r\x82tr\x82\acit,");
        }
        else
        {
            phrase("Le chemin dessin\x82 par les parois se r\x82tr\x82\acit,");
        }

        phrase(" signe que vous approchez de la fin du d\x82sert.");
        finLigne(500);
        finLigne(500);
    }

    ///Approche du poste frontière à l'est
    if(joueurPosX >= 23 && joueurPosY >= 13 && (positionX <= 22 || positionY <= 12))
    {
        phrase("Lessiv\x82 par cette longue marche dans cet interminable d\x82sert, c'est seulement apr\x8As quelques minutes que vous remarquez que vous avancez en direction d'un poste-fronti\x8Are.");
        finLigne(500);
        finLigne(500);
    }

    ///Garde du poste frontière
    Personnage Garde("Garde",true);

    ///Évènement des lieux où se trouve le joueur
        ///Devant le poste frontière à l'est
    if((joueurPosY == 14 || joueurPosY == 15 || joueurPosY == 16) && joueurPosX == 24)
    {
        if(carteTrouvee)
        {
            phrase("Vous arrivez au pied d'une \x82norme porte gard\x82\ae par un garde sur ses gardes.");
            finLigne(500);
            finLigne(500);

            setCaseCarteDesert(carteDesert,joueurPosX,joueurPosY,grilleDesert);

            joueurPosX = positionX;
            joueurPosY = positionY;

            if(premiereVisiteFrontiere)
            {
                Garde.dit("Halte !!");
                finLigne(500);
                phrase("La fronti\x8Are est ferm\x82\ae pour cause de porte ferm\x82\ae.");
                finLigne(500);
                phrase("Ordre du roi.");
                finLigne(500);
                phrase("Sa Majest\x82 a \x82galement ajout\x82 que la fronti\x8Are sera ouverte d\x8As que la porte sera ouverte.");
                finLigne(500);
                phrase("Et que la porte sera ouverte lorsque le campement de bandit au nord-ouest du d\x82sert sera vid\x82.");
                finLigne(1000);
                phrase("Ou un truc du genre.");
                finLigne(1000);
                phrase("Il faudra que vous repartiez au nord-ouest d'abord, si vous voulez passer.");
                finLigne(500);

                if(campDroiteFini && campGaucheFini)
                {
                    phrase("Sauf si vous l'avez fait avant de venir ici.");
                    finLigne(1000);
                    phrase("C'est le cas ?");
                    finLigne(500);

                    getline(cin,reponse);
                    finLigne(500);

                    for(unsigned int i = 0;i < reponse.size();i++)
                    {
                        reponse[i] = tolower(reponse[i]);
                    }

                    while(reponse != "oui" && reponse != "non")
                    {
                        phrase("Arr\x82tez de marmonner, j'comprend rien d'ici.");
                        finLigne(500);
                        phrase("Est-ce que vous avez nettoy\x82 le campement, oui ou non ?");
                        finLigne(500);
                        getline(cin,reponse);
                        finLigne(500);

                        for(unsigned int i = 0;i < reponse.size();i++)
                        {
                            reponse[i] = tolower(reponse[i]);
                        }
                    }

                    finLigne(500);

                    if(reponse == "non")
                    {
                        phrase("Alors revenez lorsque vous aurez termin\x82 le travail, ou lorsque quelqu'un d'autre l'aura fait \x85 votre place.");
                        finLigne(500);
                    }
                }

                premiereVisiteFrontiere = false;
            }
            else
            {
                Garde.dit("Halte !!");
                finLigne(500);
                phrase("La fronti\x8Are est ferm\x82\ae pour cause de porte ferm\x82\ae.");
                finLigne(500);
                phrase("Ordre...");
                finLigne(1500);
                phrase("Je vous ai d\x82j\x85 vu non ?");
                finLigne(300);
                finLigne(300);
                finLigne(300);
                phrase("*r\x82\afl\x82\achit*");
                finLigne(750);
                finLigne(750);
                finLigne(750);
                phrase("Comme j'ai pas envie de tout redire, on va dire que oui.");
                finLigne(500);
                phrase("Alors, ");
                sleep(500);
                phrase("vous nous l'avez nettoy\x82, ce campement ?");
                finLigne(500);

                getline(cin,reponse);
                finLigne(500);

                for(unsigned int i = 0;i < reponse.size();i++)
                {
                    reponse[i] = tolower(reponse[i]);
                }

                while(reponse != "oui" && reponse != "non")
                {
                    phrase("Arr\x82tez de marmonner, j'comprend rien d'ici.");
                    finLigne(500);
                    phrase("Est-ce que vous avez nettoy\x82 le campement, oui ou non ?");
                    finLigne(500);
                    getline(cin,reponse);
                    finLigne(500);

                    for(unsigned int i = 0;i < reponse.size();i++)
                    {
                        reponse[i] = tolower(reponse[i]);
                    }
                }

                if(!campDroiteFini || !campGaucheFini || reponse == "non")
                {
                    phrase("Non ?");
                    finLigne(500);
                    phrase("Alors vous ne passerez pas.");
                    finLigne(500);
                }
            }

            if(campDroiteFini && campGaucheFini && reponse == "oui")
            {
                phrase("(Il sort une tr\x8As-longue-vue de sa poche et la pointe vers le nord-ouest).");
                finLigne(1500);
                finLigne(1500);
                phrase("Excellent !!");
                finLigne(500);
                phrase("Le roi va \x88tre content lorsqu'il apprendra la nouvelle, ");
                sleep(1000);
                phrase("dans 8 jours.");
                finLigne(1000);
                phrase("D'ici la, la porte reste ferm\x82\ae.");
                finLigne(1000);
                phrase("Ordre du roi.");
                finLigne(1500);
                phrase("Sauf si vous avez de quoi nous corrompre.");
                finLigne(750);
                phrase("Le pot-de-vin s'\x82l\x8Ave \x85 10 pi\x8A\aces par personne.");
                finLigne(750);
                phrase("Mais je serai seul dans le coup, donc \x87\aa fera 42 pi\x8A\aces.");
                finLigne(1000);
                phrase("Alors ?");
                finLigne(750);
                phrase("Vous acceptez ?");
                finLigne(750);

                getline(cin,reponse);
                finLigne(500);

                for(unsigned int i = 0;i < reponse.size();i++)
                {
                    reponse[i] = tolower(reponse[i]);
                }

                while(reponse != "oui" && reponse != "non")
                {
                    phrase("On dit que la justice est aveugle, mais comme je fait pas dans cette merde, je suis sourd.");
                    finLigne(500);
                    phrase("Donc parlez plus fort et ");
                    sleep(500);
                    phrase("ar-");
                    sleep(500);
                    phrase("ti-");
                    sleep(500);
                    phrase("cu-");
                    sleep(500);
                    phrase("lez.");
                    finLigne(1000);
                    phrase("\xD2tes-vous malh\x93nn\x8Ate ?");
                    finLigne(500);
                    getline(cin,reponse);
                    finLigne(500);

                    for(unsigned int i = 0;i < reponse.size();i++)
                    {
                        reponse[i] = tolower(reponse[i]);
                    }
                }

                if(reponse == "non")
                {
                    phrase("Non ?");
                    finLigne(500);
                    phrase("Alors vous ne passerez pas.");
                    finLigne(500);
                }
                else
                {
                    phrase("Bien, je pourrais enfin me r\x82inscrire \x85 mon journal po");
                    sleep(250);
                    phrase(".");
                    sleep(250);
                    phrase(".");
                    sleep(250);
                    phrase(".");
                    sleep(250);
                    phrase("litique");
                    finLigne(1000);
                    phrase("Euh, allez-y, d\x82p\x82\achez-vous.");
                    finLigne(1000);
                    phrase("J'ai des choses \x85 faire.");
                    finLigne(1000);
                    joueurPosX = 0;
                    joueurPosY = 0;
                }
            }
        }
        else
        {
            phrase("Un mot est affich\x82 sur la porte du poste-fronti\x8Are.");
            finLigne(250);
            finLigne(250);
            phrase("Mot :");
            finLigne(250);
            phrase("J'suis parti. ");
            finLigne(750);
            phrase("Revenez plus tard.");
            finLigne(500);
            finLigne(500);
            phrase("Apparement, il est parti.");
            finLigne(500);
            phrase("Vous devriez revenir plus tard.");
            finLigne(500);
        }
        finLigne(500);
    }
        ///Devant le passage de l'ouest
    else if(joueurPosX == 0 && joueurPosY == 15)
    {
        Ennemi Instructeur("Chef instructeur",1000,115,150,125,"Hache Purificatrice",200,25,31105,100,false,true,Enflamme,150,"Hache Purificatrice",200,100,false,Enflamme,275,100);
        Ennemi Biscuit("Ptit Cookie",1500,50,175,175,"souvenir du papatriote",175,9,0,0,true,true,Communiste,170);

        phrase("Vous approchez d'un passage bloqu\x82 par un monstre fait de pain d'\x82pice.");
        finLigne(1000);
        phrase("\xB7 c\x93t\x82 de lui se dresse un homme que vous avez d\x82j\x85 rencontr\x82, ");
        sleep(1000);
        phrase("l'instructeur !!");
        finLigne(1000);
        phrase("De toute \x82\avidence, vous allez devoir affronter deux monstres.");
        finLigne(500);

        if(combatDesert(joueur,Instructeur))
        {
            Instructeur.dit("Ah !!");
            finLigne(1000);
            phrase("J'ai pas fais");
            sleep(500);
            phrase(".");
            sleep(500);
            phrase(".");
            sleep(500);
            phrase(".");
            phrase("le con aujourd'hui.");
            finLigne(1000);
            phrase("J'avais");
            sleep(500);
            phrase(".");
            sleep(500);
            phrase(".");
            sleep(500);
            phrase(".");
            phrase("pari\x82");
            sleep(500);
            phrase(".");
            sleep(500);
            phrase(".");
            sleep(500);
            phrase(".");
            phrase("sur vous");
            sleep(500);
            phrase(".");
            sleep(500);
            phrase(".");
            sleep(500);
            phrase(".");
            finLigne(500);
            phrase("Pas");
            sleep(500);
            phrase(".");
            sleep(500);
            phrase(".");
            sleep(500);
            phrase(".");
            phrase("con");
            sleep(500);
            phrase(".");
            sleep(500);
            phrase(".");
            sleep(500);
            phrase(".");
            finLigne(1000);
            finLigne(1000);
            phrase("L'instructeur est mort.");

            felicitations("L'instructeur est mort");

            phrase("Le monstre, qui a regard\x82 le combat sans intervenir, se tourne vers vous, pas tr\x8As tr\x8As content.");
            finLigne(500);
            finLigne(500);
            Biscuit.dit("PAPATRIOTE !!!!!");
            finLigne(500);

            if(combatDesert(joueur,Biscuit))
            {
                phrase("Vous approchez du biscuit et sortez un verre de lait.");
                finLigne(500);
                finLigne(500);
                Biscuit.dit("NOOOOOOOOOON !!!!!");
                finLigne(500);
                phrase("PAS LE LAAAAAAIIIIIT !!!!!!!!");
                felicitations("!!! PASSAGE CENSUR\x90");
                phrase("Repu, vous avancez dans la passe en passant devant le panneau indiquant aux passants qu'ils se dirigent vers leur destination.");
                joueurPosX = 24;
                joueurPosY = 24;
            }
        }
    }
        ///Autres cas
    else if(grilleDesert[joueurPosX][joueurPosY] == Cote || grilleDesert[joueurPosX][joueurPosY] == CoteNE || grilleDesert[joueurPosX][joueurPosY] == CoteNO || grilleDesert[joueurPosX][joueurPosY] == CoteSO || grilleDesert[joueurPosX][joueurPosY] == CoteSE)
    {
        if(position != Cote && position != CoteNE && position != CoteNO && position != CoteSO && position != CoteSE && position != PlageO  && position != PlageE  && position != PlageN  && position != PlageS  && position != PlageNE  && position != PlageNO  && position != PlageSO  && position != PlageSE)
        {
            if(time(0) % 2 == 0)
            {
                phrase("Le sable s'affine sous vos pas a mesure que le son des vagues s'intensifie.");
            }
            else
            {
                phrase("La l\x82g\x8Are brise revient vous rafraichir le visage et quelques mouettes viennent rompre le silence aride du d\x82sert.");
            }
            finLigne(500);
            phrase("Vous approchez de l'oc\x82\aan.");
        }
        else
        {
            phrase("Vous sentez toujours la fraicheur de l'oc\x82\aan et sa senteur marine.");
        }

        finLigne(500);

        if(!deplacementDesertSafe)
        {
            if(!rencontreEnnemiDesert(joueur))
            {
                setCaseCarteDesert(carteDesert,joueurPosX,joueurPosY,grilleDesert);
                joueurPosX = positionX;
                joueurPosY = positionY;
            }
        }
    }
    else if(grilleDesert[joueurPosX][joueurPosY] == PlageN || grilleDesert[joueurPosX][joueurPosY] == PlageE || grilleDesert[joueurPosX][joueurPosY] == PlageS || grilleDesert[joueurPosX][joueurPosY] == PlageO)
    {
        if(position != Cote && position != CoteNE && position != CoteNO && position != CoteSO && position != CoteSE)
        {
            phrase("Vous continuez d'avancer, l'oc\x82\aan est ");
        }
        else
        {
            phrase("Vous avancez hors de port\x82 des vagues venant de l'oc\x82\aan ");
        }

        switch(grilleDesert[joueurPosX][joueurPosY])
        {
        case PlageN :
            phrase("au nord.");
            break;
        case PlageS :
            phrase("au sud.");
            break;
        case PlageE :
            phrase("\x85 l'est.");
            break;
        case PlageO :
            phrase("\x85 l'est.");
            break;
        }

        finLigne(500);

        if(!deplacementDesertSafe)
        {
            if(!rencontreEnnemiDesert(joueur))
            {
                setCaseCarteDesert(carteDesert,joueurPosX,joueurPosY,grilleDesert);
                joueurPosX = positionX;
                joueurPosY = positionY;
            }
        }
    }
    else if(grilleDesert[joueurPosX][joueurPosY] == PlageNO || grilleDesert[joueurPosX][joueurPosY] == PlageNE || grilleDesert[joueurPosX][joueurPosY] == PlageSE || grilleDesert[joueurPosX][joueurPosY] == PlageSO)
    {
        phrase("L'oc\x82\aan vous borde ");

        switch(grilleDesert[joueurPosX][joueurPosY])
        {
        case PlageNE :
            phrase("au nord et \x85 l'est.");
            break;

        case PlageNO :
            phrase("au nord et \x85 l'ouest.");
            break;

        case PlageSO :
            phrase("au sud et \x85 l'ouest.");
            break;

        case PlageSE :
            phrase("au sud et \x85 l'est.");
            break;
        }

        finLigne(500);

        if(!deplacementDesertSafe)
        {
            if(!rencontreEnnemiDesert(joueur))
            {
                setCaseCarteDesert(carteDesert,joueurPosX,joueurPosY,grilleDesert);
                joueurPosX = positionX;
                joueurPosY = positionY;
            }
        }
    }
    else if(grilleDesert[joueurPosX][joueurPosY] == ParoiN || grilleDesert[joueurPosX][joueurPosY] == ParoiS || grilleDesert[joueurPosX][joueurPosY] == ParoiE)
    {
        phrase("Une immense paroi se dresse ");

        switch(grilleDesert[joueurPosX][joueurPosY])
        {
        case ParoiN :
            phrase("au nord.");
            break;

        case ParoiS :
            phrase("au sud.");
            break;

        case ParoiE :
            phrase("\x85 l'est.");
            break;
        }

        finLigne(500);

        if(!deplacementDesertSafe)
        {
            if(!rencontreEnnemiDesert(joueur))
            {
                setCaseCarteDesert(carteDesert,joueurPosX,joueurPosY,grilleDesert);
                joueurPosX = positionX;
                joueurPosY = positionY;
            }
        }
    }
    else if(grilleDesert[joueurPosX][joueurPosY] == ParoiNO || grilleDesert[joueurPosX][joueurPosY] == ParoiNE || grilleDesert[joueurPosX][joueurPosY] == ParoiSE || grilleDesert[joueurPosX][joueurPosY] == ParoiSO)
    {
        phrase("Vous vous retrouvez dans un angle, une paroi ");

        switch(grilleDesert[joueurPosX][joueurPosY])
        {
        case ParoiNE :
            phrase("au nord et une autre \x85 l'est.");
            break;

        case ParoiNO :
            phrase("au nord et une autre \x85 l'ouest.");
            break;

        case ParoiSO :
            phrase("au sud et une autre \x85 l'ouest.");
            break;

        case ParoiSE :
            phrase("au sud et une autre \x85 l'est.");
            break;
        }

        finLigne(500);

        if(!deplacementDesertSafe)
        {
            if(!rencontreEnnemiDesert(joueur))
            {
                setCaseCarteDesert(carteDesert,joueurPosX,joueurPosY,grilleDesert);
                joueurPosX = positionX;
                joueurPosY = positionY;
            }
        }
    }
    else if(grilleDesert[joueurPosX][joueurPosY] == Desert)
    {
        if(position == Cote)
        {
            phrase("Tout juste rentr\x82" + accorde("","e",joueur.estMasculin()) + " dans le d\x82sert, que le soleil vous agresse d\x82j\x85.");
            finLigne(500);
            if(!deplacementDesertSafe)
            {
                if(!rencontreEnnemiDesert(joueur))
                {
                    setCaseCarteDesert(carteDesert,joueurPosX,joueurPosY,grilleDesert);
                    joueurPosX = positionX;
                    joueurPosY = positionY;
                }
            }

        }
        else
        {
           int aleatoire;

           srand(time(0));

           aleatoire = rand() % 11;

           switch(aleatoire)
           {
           case 0 :
            phrase("Une immense dune se dresse devant vous.");
            finLigne(500);
            phrase("Vous pouvez vous amuser \x85 faire de la luge si vous voulez.");
            finLigne(500);
            phrase("Sinon, rien de sp\x82\acial.");
            finLigne(500);
            if(!deplacementDesertSafe)
            {
                if(!rencontreEnnemiDesert(joueur))
                {
                    setCaseCarteDesert(carteDesert,joueurPosX,joueurPosY,grilleDesert);
                    joueurPosX = positionX;
                    joueurPosY = positionY;
                }
            }
            break;

           case 1 :
            phrase("Un cactus vous regarde arriver sto\x8Bquement.");
            finLigne(500);
            phrase("Vous utilisez votre ");
            phrase(joueur.getNomArme());
            phrase(" pour extraire du jus de cactus sans pulpe, reconnu pour ses propri\x82t\x82s r\x82gicides.");
            finLigne(1500);
            phrase("Comme vous n'\x88tes pas ");
            phrase(accorde("roi","reine",joueur.estMasculin()));
            phrase(", cela vous revigore un peu.");
            joueur.setPv(10);
            break;

           case 2 :
            phrase("En approchant, vous appercevez quelques rochers plac\x82s de sorte \x85 former un abri de fortune, pour peu qu'ils ne s'effondrent pas sur vous.");
            finLigne(500);
            phrase("Vous vous y reposez un moment.");
            finLigne(500);
            phrase("En vous r\x82veillant, vous ne savez pas si votre enthousiasme est d\x96 \x85 votre sieste, ou au fait que les rochers ne vous soient pas tomb\x82s dessus.");
            joueur.setEnergie(50,true);
            break;

           case 3 :
            phrase("Vous passez \x85 c\x93t\x82 de carcasses de b\x88tes que vous pr\x82\af\x82rez croiser mortes que vivantes.");
            finLigne(500);
            if(!deplacementDesertSafe)
            {
                if(!rencontreEnnemiDesert(joueur))
                {
                    setCaseCarteDesert(carteDesert,joueurPosX,joueurPosY,grilleDesert);
                    joueurPosX = positionX;
                    joueurPosY = positionY;
                }
            }
            break;

           case 4 :
            phrase("Du d\x82sert");
            sleep(500);
            phrase(".");
            sleep(500);
            phrase(".");
            sleep(500);
            phrase(".");
            finLigne(500);
            phrase("Encore du d\x82sert");
            sleep(500);
            phrase(".");
            sleep(500);
            phrase(".");
            sleep(500);
            phrase(".");
            finLigne(500);
            phrase("Rien que du d\x82sert.");
            finLigne(750);
            if(!deplacementDesertSafe)
            {
                if(!rencontreEnnemiDesert(joueur))
                {
                    setCaseCarteDesert(carteDesert,joueurPosX,joueurPosY,grilleDesert);
                    joueurPosX = positionX;
                    joueurPosY = positionY;
                }
            }
            break;

           case 5:
            phrase("\xB7 force de marcher, vous avez l'impression d'avoir des fourmis dans les jambes, ");
            sleep(1000);
            phrase("mais ce ne sont que quelques scorpions qui vous grimpent dessus.");
            finLigne(500);
            if(!deplacementDesertSafe)
            {
                if(!rencontreEnnemiDesert(joueur))
                {
                    setCaseCarteDesert(carteDesert,joueurPosX,joueurPosY,grilleDesert);
                    joueurPosX = positionX;
                    joueurPosY = positionY;
                }
            }
            break;

           case 6 :
            phrase("Vous avez du sable dans vos chaussures.");
            finLigne(500);
            if(!deplacementDesertSafe)
            {
                if(!rencontreEnnemiDesert(joueur))
                {
                    setCaseCarteDesert(carteDesert,joueurPosX,joueurPosY,grilleDesert);
                    joueurPosX = positionX;
                    joueurPosY = positionY;
                }
            }
            break;

           case 7 :
            phrase("Vous remarquez des traces de pas dans le sable.");
            finLigne(500);
            phrase("Vous jubilez avant de vous appercevoir qu'en fait, \x87\aa fait 5 minutes que vous tournez en rond.");
            finLigne(500);
            if(!deplacementDesertSafe)
            {
                if(!rencontreEnnemiDesert(joueur))
                {
                    setCaseCarteDesert(carteDesert,joueurPosX,joueurPosY,grilleDesert);
                    joueurPosX = positionX;
                    joueurPosY = positionY;
                }
            }
            break;

           case 8 :
            phrase("Vous tr\x82\abuchez sur du sable et tombez.");
            finLigne(500);
            if(!deplacementDesertSafe)
            {
                if(!rencontreEnnemiDesert(joueur))
                {
                    setCaseCarteDesert(carteDesert,joueurPosX,joueurPosY,grilleDesert);
                    joueurPosX = positionX;
                    joueurPosY = positionY;
                }
            }
            break;

           case 9 :
            phrase("Un serpent qui passait par l\x85 continue son chemin.");
            finLigne(500);
            if(!deplacementDesertSafe)
            {
                if(!rencontreEnnemiDesert(joueur))
                {
                    setCaseCarteDesert(carteDesert,joueurPosX,joueurPosY,grilleDesert);
                    joueurPosX = positionX;
                    joueurPosY = positionY;
                }
            }
            break;

           case 10 :
            phrase("Devant vous un mirage s'\x82tend aussi loin que porte votre regard.");
            finLigne(500);
            phrase("O\x97 que vous regardiez, vous ne voyeez que \x87\aa.");
            finLigne(500);
            phrase("Une immensit\x82 infinie de");
            sleep(500);
            phrase(".");
            sleep(500);
            phrase(".");
            sleep(500);
            phrase(".");
            finLigne(500);
            phrase("Ah,");
            sleep(500);
            phrase(" c'est parti.");
            if(!deplacementDesertSafe)
            {
                if(!rencontreEnnemiDesert(joueur))
                {
                    setCaseCarteDesert(carteDesert,joueurPosX,joueurPosY,grilleDesert);
                    joueurPosX = positionX;
                    joueurPosY = positionY;
                }
            }
            break;
           }
        }

        finLigne(500);
    }
    else if(grilleDesert[joueurPosX][joueurPosY] == Palmier)
    {
        phrase("Vous appercevez des palmiers au pied desquels vous vous effondrez, et profitez de la fraicheur apport\x82\ae par leurs ombres.");
        cout << endl;
        finLigne(2000);
        phrase("Lorsque vous vous r\x82veillez, vous \x88tes en pleine forme, tout comme le soleil qui est encore et toujours \x85 son z\x82nith.");

        joueur.setEnergie(joueur.getEnergieMax(),true);

        finLigne(1000);

        if(position != Oasis)
        {
            phrase("A l'ouest se trouve un petit lac en partie couvert par les palmiers.");
            finLigne(500);
            phrase("Une petite baignade ne vous ferait pas de mal.");
        }
        else
        {
            phrase("Comme vous l'imaginiez, pouvoir se reposer apr\x8As un bain vous a fait le plus grand bien.");
        }
    }
    else if(grilleDesert[joueurPosX][joueurPosY] == Oasis)
    {
        phrase("Vous arrivez au bord d'un lac couvert par les feuilles de palmiers ayant pouss\x82 \x85 c\x93t\x82.");
        finLigne(500);
        phrase("Vous buvez tout votre saoul et profitez pour plongez une t\x88te dedans.");
        finLigne(500);
        phrase("Vous vous sentez revigor\x82" + accorde("","e",joueur.estMasculin()) + ".");

        joueur.setPv(joueur.getPvMax());

        finLigne(1000);

        if(position != Palmier)
        {
            phrase("\xB7 la vue des palmiers \x85 l'est, vous songez qu'une sieste ne serait pas de trop.");
        }
        else
        {
            phrase("En effet, ce bain \x82tait providentiel.");
        }
    }
    else if(grilleDesert[joueurPosX][joueurPosY] == Camp)
    {
        if(!campGaucheFini && !campDroiteFini)
        {
            phrase("Des fortifications faites de pierres et de planches semblent d\x82limiter un campement.");
            finLigne(1000);
            phrase("Vous d\x82\aduisez qu'il sagit d'un campement de bandit lorsque vous vous faites attaquer par des bandits.");
            finLigne(1000);
        }

        if(joueurPosX == 5 && !campGaucheFini)
        {
            if(campDroiteFini)
            {
                phrase("Vous arrivez dans la seconde partie du campement.");
                finLigne(1000);
                phrase("Comme pour la premi\x8Are, les bandits vous foncent dessus, mais un \x85 un.");
                finLigne(500);
            }

            if(combatCampBandit(joueur,campGaucheFini,campDroiteFini))
            {
                if(!campDroiteFini)
                {
                    phrase("est.");
                    finLigne(500);
                    campGaucheFini = true;
                }
            }
            else if(joueur.estVivant())
            {
                setCaseCarteDesert(carteDesert,joueurPosX,joueurPosY,grilleDesert);
                joueurPosX = positionX;
                joueurPosY = positionY;
            }
        }
        else if(joueurPosX == 6 && !campDroiteFini)
        {
            if(campGaucheFini)
            {
                phrase("Vous arrivez dans la seconde partie du campement.");
                finLigne(1000);
                phrase("Comme pour la premi\x8Are, les bandits vous foncent dessus, mais un \x85 un.");
                finLigne(500);
            }

            if(combatCampBandit(joueur,campGaucheFini,campDroiteFini))
            {
                phrase("ouest.");
                finLigne(500);
                campDroiteFini = true;
            }
            else if(joueur.estVivant())
            {
                setCaseCarteDesert(carteDesert,joueurPosX,joueurPosY,grilleDesert);
                joueurPosX = positionX;
                joueurPosY = positionY;
            }
        }
        else
        {
            phrase("Vous vous baladez dans le campement vide.");
            finLigne(500);
            phrase("Vous avez toujours chaud.");
            finLigne(1000);
        }
    }

    setCaseCarteDesert(carteDesert,joueurPosX,joueurPosY,grilleDesert);

    cout << endl;
    finLigne(1000);
}
bool deplacementMarai(Joueur &joueur, int grilleMarai[][25], string carteMarai[][25][9], int &joueurPosX, int &joueurPosY, int &nbMorsure, bool &cabaneVisitee)
{
    string direction,reponse;
    int position,positionX,positionY;
    bool recommencer;

    setCaseCarteMarai(carteMarai,joueurPosX,joueurPosY,grilleMarai);

    do
    {
        recommencer = false;

        finLigne(500);
        phrase("O\x97 voulez-vous aller ?");
        finLigne(500);
        cout << "            ";
        phrase("1.Nord");
        cout << endl;
        phrase("2.Ouest");
        cout << "     ";
        phrase("5.Carte");
        cout << "      ";
        phrase("3.Est");
        cout << endl << "            ";
        phrase("4.Sud");
        cout << endl;


        getline(cin,direction);
        cout << endl << endl;

        for(unsigned int i = 0;i < direction.size();i++)
        {
            direction[i] = tolower(direction[i]);
        }

        if(direction != "1.nord" && direction != "1" && direction != "nord" && direction != "n")
        {
            if(direction != "2.ouest" && direction != "2" && direction != "ouest" && direction != "o")
            {
                if(direction != "3.est" && direction != "3" && direction != "est" && direction != "e")
                {
                    if(direction != "4.sud" && direction != "4" && direction != "sud" && direction != "s")
                    {
                        if(direction == "5.carte" || direction == "5" || direction == "carte" || direction == "c")
                        {
                            afficheCarteMarai(carteMarai,joueurPosX,joueurPosY);
                        }

                        recommencer = true;
                    }
                }
            }
        }

        if(!recommencer && direction[0] != '5' && direction[0] != 'c')
        {
            recommencer = !bonneDirectionMarai(grilleMarai,joueurPosX,joueurPosY,direction);
        }

    }while(recommencer);

    position = grilleMarai[joueurPosX][joueurPosY];
    positionX = joueurPosX;
    positionY = joueurPosY;

    if(direction[0] == '1' || direction[0] == 'n')
    {
        joueurPosY--;
    }
    else if(direction[0] == '2' || direction[0] == 'o')
    {
        joueurPosX--;
    }
    else if(direction[0] == '3' || direction[0] == 'e')
    {
        joueurPosX++;
    }
    else if(direction[0] == '4' || direction[0] == 's')
    {
        joueurPosY++;
    }

    ///Évènement des lieux où se trouve le joueur

    ///Si le joueur veux retourner en arrière (càd à l'est)

    if(grilleMarai[positionX][positionY] == Barque && grilleMarai[joueurPosX][joueurPosY] != Lac && grilleMarai[joueurPosX][joueurPosY] != TourBas && grilleMarai[joueurPosX][joueurPosY] != TourHaut)
    {
        phrase("Vous descendez de la barque ");

        if(grilleMarai[joueurPosX][joueurPosY] == Ponton)
        {
            phrase("pour arriver sur un ponton.");
            finLigne(1000);
            phrase("Vous \x88tes soulag\x82" + accorde("","e",joueur.estMasculin()) + " de ne pas atterrir directement dans le marai.");
        }
        else if(grilleMarai[joueurPosX][joueurPosY] == TourBas)
        {

        }
        else
        {
            phrase("pour atterrir, ");
            sleep(500);
            phrase("enfin, pour amerrir dans le marai et retrouver la vase qui vous a tant manqu\x82\ae.");
            finLigne(500);
        }

        phrase("La barque devrait rester ici.");
        finLigne(1500);
        phrase("Normalement.");
        finLigne(500);
        finLigne(500);
    }
    else if(grilleMarai[joueurPosX][joueurPosY] == Barque)
    {
        phrase("Vous montez dans la barque, et comme si vous manipuliez les vents, la voile se gonfle dans la direction que vous souhaitez.");
        finLigne(500);
    }
    else if(grilleMarai[joueurPosX][joueurPosY] == Roseau)
    {
        if(position != RoseauN && position != RoseauS && position != RoseauE && position != RoseauO && position != RoseauNE && position != RoseauNO && position != RoseauSO && position != RoseauSE && position != RoseauNS && position != Roseau)
        {
            phrase("Les roseaux se densifient au point de former une sorte de f\x93r\x88t.");
        }
        else
        {
            phrase("Vous continuez d'avancer dans cette petite jungle.");
            finLigne(500);
            if(position == RoseauN || position == RoseauS || position == RoseauE || position == RoseauO || position == RoseauNE || position == RoseauNO || position == RoseauSO || position == RoseauSE || position == RoseauNS)
            {
                phrase("Vous vous \x82loignez de ce bourbier.");
            }
        }

        if(!rencontreEnnemiMarai(joueur))
        {
            setCaseCarteMarai(carteMarai,joueurPosX,joueurPosY,grilleMarai);
            joueurPosX = positionX;
            joueurPosY = positionY;
        }
    }
    else if(grilleMarai[joueurPosX][joueurPosY] == RoseauN || grilleMarai[joueurPosX][joueurPosY] == RoseauS || grilleMarai[joueurPosX][joueurPosY] == RoseauE || grilleMarai[joueurPosX][joueurPosY] == RoseauO || grilleMarai[joueurPosX][joueurPosY] == RoseauNE || grilleMarai[joueurPosX][joueurPosY] == RoseauNO || grilleMarai[joueurPosX][joueurPosY] == RoseauSO || grilleMarai[joueurPosX][joueurPosY] == RoseauSE)
    {
        if(position == Marai || position == Ponton)
        {
            phrase("Vous arrivez dans un amas de roseaux.");
        }
        else
        {
            phrase("Vous continuez \x85 vous frayer un chemin entre les roseaux.");
        }

        finLigne(500);
        phrase("Le bourdier est ");

        switch(grilleMarai[joueurPosX][joueurPosY])
        {
        case RoseauN :
            phrase("au nord.");
            break;

        case RoseauS :
            phrase("au sud.");
            break;

        case RoseauE :
            phrase("\x85 l'est.");
            break;

        case RoseauO :
            phrase("\x85 l'ouest.");
            break;

        case RoseauNE :
            phrase("au nord et \x85 l'est.");
            break;

        case RoseauNO :
            phrase("au nord et \x85 l'ouest.");
            break;

        case RoseauSO :
            phrase("au sud et \x85 l'ouest.");
            break;

        case RoseauSE :
            phrase("au sud et \x85 l'est.");
            break;
        }

        if(!rencontreEnnemiMarai(joueur))
        {
            setCaseCarteMarai(carteMarai,joueurPosX,joueurPosY,grilleMarai);
            joueurPosX = positionX;
            joueurPosY = positionY;
        }
    }
    else if(grilleMarai[joueurPosX][joueurPosY] == RoseauNS)
    {
        if(position == Marai || position == Ponton)
        {
            phrase("Vous arrivez dans un amas de roseaux.");
        }
        else
        {
            phrase("Vous continuez \x85 vous frayer un chemin entre les roseaux.");
        }

        finLigne(500);
        phrase("Le lac est au nord et le bourbier est au sud.");
        finLigne(500);
        phrase("Le lac doit rejoindre l'oc\x82\aan en passant petit \x85 petir par ici.");

        if(!rencontreEnnemiMarai(joueur))
        {
            setCaseCarteMarai(carteMarai,joueurPosX,joueurPosY,grilleMarai);
            joueurPosX = positionX;
            joueurPosY = positionY;
        }
    }
    else if(grilleMarai[joueurPosX][joueurPosY] == Ponton)
    {
        if(position != Ponton && position != Cabane && position != Barque)
        {
            phrase("Vous avancez jusqu'\x85 un ponton pour vous extirper de ce mar\x82\acage.");
            finLigne(1500);
            phrase("Enfin au sec, vous avez toujours l'impression d'avoir de la vase jusqu'aux genoux.");
            finLigne(1000);
        }
        else
        {
            phrase("Vous continuez d'avancer en regardant le mar\x82\acage d'un mauvais oeil.");
            finLigne(500);
        }

        if(!rencontreEnnemiMarai(joueur))
        {
            setCaseCarteMarai(carteMarai,joueurPosX,joueurPosY,grilleMarai);
            joueurPosX = positionX;
            joueurPosY = positionY;
        }
    }
    else if(grilleMarai[joueurPosX][joueurPosY] == Cabane)
    {
        if(!cabaneVisitee)
        {
            phrase("Vous p\x82n\x82trez dans une cabane en rondin.");
            finLigne(500);
            finLigne(500);
            phrase("Vous tombez nez-\x85-nez avec un vieillard qui commence \x85 vous menacer avec sa canne.");
            finLigne(500);
            finLigne(500);
            phrase("Vous commencer \x85 le prendre au s\x82rieux lorsqu'il d\x82gage du pommeau une fine dague.");
            finLigne(1500);
            phrase("Vous recommencez \x85 le prendre pour un vieux s\x82nile lorsqu'il fait tomber sa lame par terre et se bloque le dos en voulant la rammasser.");
            finLigne(500);
            finLigne(500);
            phrase("\x80\aa ressemble fort \x85 un lieu inutile.");
            finLigne(500);
            phrase("Donc vous prennez l'arme du vieux et partez.");
            finLigne(500);
            finLigne(500);

            joueur.nouvelleArme("dague de vieillard",joueur.getDegatArme()*1.5,joueur.getEffortArme()*1.5,false,BoutQuiColle,joueur.getDegatEffet());

            finLigne(500);
            finLigne(500);

            cabaneVisitee = true;
        }
        else
        {
            phrase("Vous redoutez de rerentrer dans la cabane, mais vous retrouvez le vieux affal\x82 par terre dans une position \x82trange.");
            finLigne(500);
            finLigne(500);
            finLigne(500);
            phrase("Il a d\x96 s'endormir.");
            finLigne(500);
            finLigne(500);
            finLigne(500);
            phrase("Il a s\x96rement d\x96 s'endormir.");
            finLigne(500);
            finLigne(500);
            finLigne(500);
            phrase("Vous ne pr\x82\af\x82rez pas v\x82rifier.");
            finLigne(500);
        }
    }
    else if(grilleMarai[joueurPosX][joueurPosY] == TourBas)
    {
        /*if(!tourBas(joueur))
        {
            return false;
        }*/

    }
    else if(grilleMarai[joueurPosX][joueurPosY] == TourHaut)
    {
        grilleMarai[positionX][positionY] = Lac;
        grilleMarai[13][15] = TourHaut;
        setCaseCarteMarai(carteMarai,positionX,positionY,grilleMarai);
        setCaseCarteMarai(carteMarai,joueurPosX,joueurPosY,grilleMarai);

        phrase("La tour est gigantesque.");
        finLigne(500);
        phrase("Tellement grande, qu'on ne vous voit pas derri\x8Are.");
        finLigne(500);
    }
    else if(grilleMarai[joueurPosX][joueurPosY] == Marai || grilleMarai[joueurPosX][joueurPosY] == MaraiN || grilleMarai[joueurPosX][joueurPosY] == MaraiS || grilleMarai[joueurPosX][joueurPosY] == MaraiE || grilleMarai[joueurPosX][joueurPosY] == MaraiO || grilleMarai[joueurPosX][joueurPosY] == MaraiNE || grilleMarai[joueurPosX][joueurPosY] == MaraiNO || grilleMarai[joueurPosX][joueurPosY] == MaraiSO || grilleMarai[joueurPosX][joueurPosY] == MaraiSE)
    {
        int aleatoire;

        phrase("Le marai se perd dans le lac ");

        switch(grilleMarai[joueurPosX][joueurPosY])
        {
        case MaraiN :
            phrase("au nord.");
            break;
        case MaraiS :
            phrase("au sud.");
            break;
        case MaraiE :
            phrase("\x85 l'est.");
            break;
        case MaraiO :
            phrase("\x85 l'ouest.");
            break;
        case MaraiNE :
            phrase("au nord et \x85 l'est.");
            break;
        case MaraiNO :
            phrase("au nord et \x85 l'ouest.");
            break;
        case MaraiSO :
            phrase("au sud et \x85 l'ouest.");
            break;
        case MaraiSE :
            phrase("au sud et \x85 l'est.");
            break;
        }

        srand(time(0));

        aleatoire = rand() % 11;

        switch(aleatoire)
        {
        case 1 :
            phrase("AAAAAH !!!");
            finLigne(500);
            phrase("Quelque chose vous a attrap\x82 le pied !!!");
            finLigne(500);
            phrase("AAAAAH !!!");
            finLigne(500);
            phrase("AAAAAH !!!");
            finLigne(500);
            phrase("Ah non.");
            finLigne(1000);
            phrase("Vous avez juste tr\x82\abuch\x82 sur un roseau cass\x82.");
            break;

        case 2 :
            phrase("Ah, ");
            sleep(500);
            phrase("vous vous \x88tes fait" + accorde("","e",joueur.estMasculin()) + " mordre par quelque chose.");
            nbMorsure ++;
            finLigne(500);
            phrase("Vous avez ");
            nombre(nbMorsure);
            phrase(" morsure");
            if(nbMorsure != 1)
            {
                phrase("s");
            }
            phrase(".");
            break;

        case 3 :
            phrase("Vous avancez p\x82niblement en essayant de compter le nombre de poisson dans chacune de vos bottes.");
            break;

        case 4 :
            phrase("\xB7 mesure que vous avancez, vous vous demandez si vous ne pr\x82\af\x82reriez pas retourner dans le d\x82sert.");
            finLigne(1000);
            phrase("Un ni\x8Ame coup de roseau mal plac\x82 penche en votre faveur.");
            break;

        case 5 :
            phrase("Pour oublier o\x97 vous \x88tes, ");
            sleep(1500);
            phrase("nan, vous n'y arrivez pas.");
            break;

        case 6 :
            phrase("Au d\x82tour d'un roseau vous apercevez ");
            sleep(1500);
            phrase("un autre roseau.");
            break;

        case 7 :
            phrase("Vous commencez \x85 \x82laborer un plan pour construire un radeau avec les roseaux.");
            finLigne(500);
            phrase("Le plan est parfait, mais vous percutez un roseau trop fort et vous perdez le fil de vos pens\x82\aes.");
            break;

        case 8 :
            phrase("Vous continuez d'avancer.");
            break;

        case 9 :
            phrase("Vous utilisez un roseau cass\x82 pour vous gratter le dos.");
            break;

        case 10 :
            phrase("Ce qui doit \x88tre une pierre vous fait tomber.");
            finLigne(500);
            phrase("Vous manquez de vous noyer.");
            finLigne(1000);
            phrase("Un morceau de poisson sur la t\x88te, vous regrettez de ne pas vous \x88tre noy\x82" + accorde("","e",joueur.estMasculin()) + ".");
            break;
        }

        finLigne(500);

        if(!rencontreEnnemiMarai(joueur))
        {
            setCaseCarteMarai(carteMarai,joueurPosX,joueurPosY,grilleMarai);
            joueurPosX = positionX;
            joueurPosY = positionY;
        }
    }
    else if(grilleMarai[joueurPosX][joueurPosY] == Lac)
    {
        grilleMarai[positionX][positionY] = Lac;
        grilleMarai[joueurPosX][joueurPosY] = Barque;
        grilleMarai[13][15] = TourHaut;
        setCaseCarteMarai(carteMarai,positionX,positionY,grilleMarai);
        setCaseCarteMarai(carteMarai,joueurPosX,joueurPosY,grilleMarai);

        phrase("Votre petit voilier fend les petites vagues du lac o\x96 il ne devrait pas il y avoir de vague.");
    }

    if(grilleMarai[joueurPosX-1][joueurPosY] == Barque || grilleMarai[joueurPosX+1][joueurPosY] == Barque || grilleMarai[joueurPosX][joueurPosY-1] == Barque || grilleMarai[joueurPosX][joueurPosY+1] == Barque)
    {
        if(joueur.estVivant())
        {
            phrase("Vous voyez une barque ");

            if(grilleMarai[joueurPosX-1][joueurPosY] == Barque)
            {
                phrase("\x85 l'ouest.");
                setCaseCarteMarai(carteMarai,joueurPosX-1,joueurPosY,grilleMarai,true);
            }
            else if(grilleMarai[joueurPosX+1][joueurPosY] == Barque)
            {
                phrase("\x85 l'est.");
                setCaseCarteMarai(carteMarai,joueurPosX+1,joueurPosY,grilleMarai,true);
            }
            else if(grilleMarai[joueurPosX][joueurPosY-1] == Barque)
            {
                phrase("au nord.");
                setCaseCarteMarai(carteMarai,joueurPosX,joueurPosY-1,grilleMarai,true);
            }
            else if(grilleMarai[joueurPosX][joueurPosY+1] == Barque)
            {
                phrase("au sud.");
                setCaseCarteMarai(carteMarai,joueurPosX,joueurPosY+1,grilleMarai,true);
            }
        }
    }

    finLigne(500);

    setCaseCarteMarai(carteMarai,joueurPosX,joueurPosY,grilleMarai);

    if(!joueur.estVivant())
    {
        return false;
    }

    return true;
}
bool deplacementArchipel(Joueur &joueur, int grilleArchipel[][30], string carteArchipel[][30][9], int &joueurPosX, int &joueurPosY)
{
    string direction,reponse;
    int position,positionX,positionY;
    bool recommencer;

    setCaseCarteArchipel(carteArchipel,joueurPosX,joueurPosY,grilleArchipel);

    do
    {
        recommencer = false;

        finLigne(500);
        phrase("O\x97 voulez-vous aller ?");
        finLigne(500);
        cout << "            ";
        phrase("1.Nord");
        cout << endl;
        phrase("2.Ouest");
        cout << "     ";
        phrase("5.Carte");
        cout << "      ";
        phrase("3.Est");
        cout << endl << "            ";
        phrase("4.Sud");
        cout << endl;


        getline(cin,direction);
        cout << endl << endl;

        for(unsigned int i = 0;i < direction.size();i++)
        {
            direction[i] = tolower(direction[i]);
        }

        if(direction != "1.nord" && direction != "1" && direction != "nord" && direction != "n")
        {
            if(direction != "2.ouest" && direction != "2" && direction != "ouest" && direction != "o")
            {
                if(direction != "3.est" && direction != "3" && direction != "est" && direction != "e")
                {
                    if(direction != "4.sud" && direction != "4" && direction != "sud" && direction != "s")
                    {
                        if(direction == "5.carte" || direction == "5" || direction == "carte" || direction == "c")
                        {
                            afficheCarteArchipel(carteArchipel,joueurPosX,joueurPosY);
                        }

                        recommencer = true;
                    }
                }
            }
        }

        if(!recommencer && direction[0] != '5' && direction[0] != 'c')
        {
            recommencer = !bonneDirectionArchipel(grilleArchipel,joueurPosX,joueurPosY,direction);
        }

    }while(recommencer);

    position = grilleArchipel[joueurPosX][joueurPosY];
    positionX = joueurPosX;
    positionY = joueurPosY;

    if(direction[0] == '1' || direction[0] == 'n')
    {
        joueurPosY--;
    }
    else if(direction[0] == '2' || direction[0] == 'o')
    {
        joueurPosX--;
    }
    else if(direction[0] == '3' || direction[0] == 'e')
    {
        joueurPosX++;
    }
    else if(direction[0] == '4' || direction[0] == 's')
    {
        joueurPosY++;
    }

    ///Évènement des lieux où se trouve le joueur

    if(grilleArchipel[positionX][positionY] == Barque && grilleArchipel[joueurPosX][joueurPosY] != Ocean)
    {
        if(time(0) % 2 == 0)
        {
            phrase("Vous remarquez que vous arrivez sur une \x8Cle lorsque votre barque s'\x82\achoue sur la plage.");
        }
        else
        {
            phrase("Tel un c\x82l\x82\abre navigateur ib\x82rique, vous arrivez sur une \x8Cle alors que vous en visiez une autre.");
        }
        finLigne(500);
    }
    else if(grilleArchipel[joueurPosX][joueurPosY] == Barque)
    {
        phrase("Vous montez dans la barque, ");

        if(time(0) % 2 ==0)
        {
            phrase("et comme si vous manipuliez les vents, la voile se gonfle dans la direction que vous souhaitez.");
        }
        else
        {
            phrase("et im\x82\adiatement, la voile se dirige selon votre volont\x82.");
        }
        finLigne(500);
    }
    else if(grilleArchipel[joueurPosX][joueurPosY] == Ocean)
    {
        srand(time(0));

        int aleatoire = rand() % 10;

        grilleArchipel[positionX][positionY] = Ocean;
        grilleArchipel[joueurPosX][joueurPosY] = Barque;
        setCaseCarteArchipel(carteArchipel,positionX,positionY,grilleArchipel);
        setCaseCarteArchipel(carteArchipel,joueurPosX,joueurPosY,grilleArchipel);

        switch(aleatoire)
        {
        case 0 :
            phrase("Votre petit voilier fend les vagues tel un petit voilier fendant les vagues.");
            break;

        case 1 :
            phrase("Avec ce roulis, vous \x88tes content" + accorde("","e",joueur.estMasculin()) + " de ne pas \x88tre malade.");
            finLigne(1500);
            phrase("Malg\x82 ce roulis, vous n'\x88tes pas encore \x88tre malade.");
            break;

        case 2 :
            phrase("Oh, ");
            sleep(500);
            phrase("un poisson.");
            finLigne(1500);
            phrase("Oh, ");
            sleep(500);
            phrase("un autre poisson.");
            finLigne(1500);
            phrase("Oh, ");
            sleep(500);
            phrase("encore un poisson.");
            finLigne(1500);
            phrase("Bref, ");
            sleep(500);
            phrase("vous passez au-dessus d'un banc de poisson.");
            break;

        case 3 :
            phrase("Pour passer le temps, vous vous amusez (fa\x87on de parler) \x85 compter les mouettes qui tournent autour des poissons en-dessous de vous.");
            finLigne(1500);
            phrase("Vous vous demandez alors si vous ressemblez \x85 un poisson vu de dessus.");
            finLigne(1500);
            phrase("Esp\x82rons que les mouettes ne se posent pas ce genre de question.");
            break;

        case 4 :
            phrase("Deux yeux vous observent \x85 travers l'eau.");
            finLigne(1000);
            phrase("Ils vous fixent");
            sleep(750);
            phrase(".");
            sleep(750);
            phrase(".");
            sleep(750);
            phrase(".");
            finLigne(750);
            phrase("Ils ne vous lachent pas");
            sleep(750);
            phrase(".");
            sleep(750);
            phrase(".");
            sleep(750);
            phrase(".");
            finLigne(750);
            phrase("Vous d\x82tournez le regard.");
            finLigne(1000);
            phrase("Merde, votre reflet a encore gagn\x82 le duel de regard.");
            break;

        case 5 :
        case 6 :
        case 7 :
        case 8 :
        case 9 :
            phrase("En regardant par-dessus bord, vous appercevez quelque chose dans le fond.");
            finLigne(500);
            phrase("Vous n'\x88tes pas s\x96r" + accorde("","e",joueur.estMasculin()) + ", c'\x82tait peut-\x88tre un tr\x82sor, ou juste une algue.");
            finLigne(1500);
            phrase("Ah non.");
            finLigne(1000);
            phrase("C'\x82tait un squelette.");
            finLigne(500);
            phrase("D'ailleur, il lui manque ");

            srand(time(0));

            int partieManquante = rand() % 14;

            if(time(0) % 2 == 0 && partieManquante != 8)
            {
                phrase("la t\x88te");

                if(partieManquante <= 3 || partieManquante >= 9)
                {
                    phrase(" et ");
                }
                else
                {
                    phrase(", ");
                }
            }

            switch(partieManquante)
            {
            case 0 :
                phrase("un bras.");
                break;

            case 1 :
                phrase("les deux bras.");
                break;

            case 2 :
                phrase("une jambe.");
                break;

            case 3 :
                phrase("les deux jambes.");
                break;

            case 4 :
                phrase("un bras et une jambe.");
                break;

            case 5 :
                phrase("les deux bras et une jambe.");
                break;

            case 6 :
                phrase("un bras et les deux jambes.");
                break;

            case 7 :
                phrase("les bras et les jambes.");
                break;

            case 8 :
                phrase("la t\x88te.");
                break;

            case 9 :
            case 10 :
            case 11 :
            case 12 :
            case 13 :
                phrase("une phalange au ");
                aleatoire = rand() % 5;

                switch(aleatoire)
                {
                case 0 :
                    phrase("gros");
                    break;

                case 1 :
                    phrase("deuxi\x8Ame");
                    break;

                case 2 :
                    phrase("troisi\x8Ame");
                    break;

                case 3 :
                    phrase("quatri\x8Ame");
                    break;

                case 4 :
                    phrase("petit");
                    break;
                }

                phrase(" orteille du pied ");

                if(time(0) % 2 == 0)
                {
                    phrase("gauche.");
                }
                else
                {
                    phrase("droit.");
                }
            }
            break;
        }
        finLigne(500);
    }
    else if(grilleArchipel[joueurPosX][joueurPosY] == Cote || grilleArchipel[joueurPosX][joueurPosY] == CoteNE || grilleArchipel[joueurPosX][joueurPosY] == CoteNO || grilleArchipel[joueurPosX][joueurPosY] == CoteSO || grilleArchipel[joueurPosX][joueurPosY] == CoteSE)
    {
        if(position == PlageN || position == PlageS || position == PlageE || position == PlageO || position == PlageNE || position == PlageNO || position == PlageSO || position == PlageSE)
        {
            phrase("Vous vous \x82loignez de l'oc\x82\aan.");
        }
        else if(position == Escalier)
        {
            phrase("Vous posez le pied sur le sable et l'odeur de l'oc\x82an vient vite remplacer l'odeur humide de la grotte.");
        }
        else
        {
            if(time(0) % 2 == 0)
            {
                phrase("Vous entendez les vagues aller et venir, mais vous continuez d'avancer sans appercevoir les c\x93tes.");
            }
            else
            {
                phrase("Vous continuez d'avancer sur le sable \x85 bonne distance du chahut de la plage.");
            }
        }

        finLigne(500);

        if(!rencontreEnnemiArchipel(joueur))
        {
            setCaseCarteArchipel(carteArchipel,joueurPosX,joueurPosY,grilleArchipel);
            joueurPosX = positionX;
            joueurPosY = positionY;
        }
    }
    else if(grilleArchipel[joueurPosX][joueurPosY] == PlageN || grilleArchipel[joueurPosX][joueurPosY] == PlageE || grilleArchipel[joueurPosX][joueurPosY] == PlageS || grilleArchipel[joueurPosX][joueurPosY] == PlageO)
    {
        if(position == Escalier)
        {
            phrase("Vous posez le pied sur le sable et l'odeur de l'oc\x82an vient vite remplacer l'odeur humide de la grotte.");
        }

        if(position != Cote && position != CoteNE && position != CoteNO && position != CoteSO && position != CoteSE && position != Escalier)
        {
            phrase("Vous continuez d'avancer, l'oc\x82\aan est ");
        }
        else
        {
            phrase("Vous avancez hors de port\x82 des vagues venant de l'oc\x82\aan ");
        }

        switch(grilleArchipel[joueurPosX][joueurPosY])
        {
        case PlageN :
            phrase("au nord.");
            break;
        case PlageS :
            phrase("au sud.");
            break;
        case PlageE :
            phrase("\x85 l'est.");
            break;
        case PlageO :
            phrase("\x85 l'est.");
            break;
        }

        finLigne(500);

        if(!rencontreEnnemiArchipel(joueur))
        {
            setCaseCarteArchipel(carteArchipel,joueurPosX,joueurPosY,grilleArchipel);
            joueurPosX = positionX;
            joueurPosY = positionY;
        }

    }
    else if(grilleArchipel[joueurPosX][joueurPosY] == PlageNO || grilleArchipel[joueurPosX][joueurPosY] == PlageNE || grilleArchipel[joueurPosX][joueurPosY] == PlageSE || grilleArchipel[joueurPosX][joueurPosY] == PlageSO)
    {
        phrase("L'oc\x82\aan vous borde ");

        switch(grilleArchipel[joueurPosX][joueurPosY])
        {
        case PlageNE :
            phrase("au nord et \x85 l'est.");
            break;

        case PlageNO :
            phrase("au nord et \x85 l'ouest.");
            break;

        case PlageSO :
            phrase("au sud et \x85 l'ouest.");
            break;

        case PlageSE :
            phrase("au sud et \x85 l'est.");
            break;
        }

        finLigne(500);

        if(!rencontreEnnemiArchipel(joueur))
        {
            setCaseCarteArchipel(carteArchipel,joueurPosX,joueurPosY,grilleArchipel);
            joueurPosX = positionX;
            joueurPosY = positionY;
        }
    }

    if(grilleArchipel[joueurPosX-1][joueurPosY] == Barque || grilleArchipel[joueurPosX+1][joueurPosY] == Barque || grilleArchipel[joueurPosX][joueurPosY-1] == Barque || grilleArchipel[joueurPosX][joueurPosY+1] == Barque)
    {
        if(joueur.estVivant())
        {
            if(position != Barque)
            {
                phrase("Vous voyez une barque ");
            }
            else
            {
                phrase("En vous retournant, vous \x88tes rassur\x82" + accorde("","e",joueur.estMasculin()) + " de voir que la barque que vous venez de quitter est toujours derri\x8Are vous, ");
            }

            if(grilleArchipel[joueurPosX-1][joueurPosY] == Barque)
            {
                phrase("\x85 l'ouest.");
                setCaseCarteArchipel(carteArchipel,joueurPosX-1,joueurPosY,grilleArchipel,true);
            }
            else if(grilleArchipel[joueurPosX+1][joueurPosY] == Barque)
            {
                phrase("\x85 l'est.");
                setCaseCarteArchipel(carteArchipel,joueurPosX+1,joueurPosY,grilleArchipel,true);
            }
            else if(grilleArchipel[joueurPosX][joueurPosY-1] == Barque)
            {
                phrase("au nord.");
                setCaseCarteArchipel(carteArchipel,joueurPosX,joueurPosY-1,grilleArchipel,true);
            }
            else if(grilleArchipel[joueurPosX][joueurPosY+1] == Barque)
            {
                phrase("au sud.");
                setCaseCarteArchipel(carteArchipel,joueurPosX,joueurPosY+1,grilleArchipel,true);
            }
        }
    }

    finLigne(500);
    finLigne(500);

    setCaseCarteArchipel(carteArchipel,joueurPosX,joueurPosY,grilleArchipel);

    if(!joueur.estVivant())
    {
        return false;
    }

    return true;
}

///Rencontre aléatoire des ennemis
///La difficulté augmente avec le niveau du joueur
bool rencontreEnnemiDesert(Joueur &joueur)
{
    ///Initialisation des ennemis des rencontres aléatoires
    /*case 1*/ Ennemi Sirene("Sir\x8Ane",125,100,10,5,"regard langoureux et sexy",10,10,2,1,true,false,Enflamme,15,"queue de poisson ail\x82\ae",10,10,false,Lisse,15,100);
    /*case 2*/ Ennemi Racaille("Basan\x82 qui a peur du cochon",100,110,15,6,"voiture brul\x82\ae",10,12,6,0,false,true,Enflamme,20,"viande \x85 l'ail",15,12,false,Farci,25,50);
    ///case 3
    /*case 4*/ Ennemi Voyageur("Voyageur tr\x8As perdu",130,100,25,9,"b\x83ton de marche",20,11,10,1,true,true,BordPointu,25,"carte obsel\x8Ate",25,15,false,Enflamme,35,25);
    /*case 5*/ Ennemi Kadoc("C\x82l\x8A\abre philosophe breton",135,120,25,15,"poulette \x82gar\x82\ae",25,20,15,10,false,true,Farci,30,"conseil sur la pr\x82paration d'un gratin",25,20,true,Rougeole,40,25);
    ///case 6
    /*case 7*/ Ennemi Truite("Truite",165,125,30,23,"remont\x82\ae du ruisseau",30,13,35,2,false,false,PasAPas,50,"technique ancestrale de la remont\x82\ae du ruisseau",30,28,false,PasAPas,45,25);
    /*case 8*/ Ennemi Polystiro("Mutant de classe un-demi",200,130,45,35,"petit bout",45,16,75,6,true,true,DansLesYeux,60,"courant d'air",45,32,true,Couleur,65,25);
    ///case 9
    /*case 10*/ Ennemi Frigo("R\x82\afrig\x82rateur zoulou",350,140,50,50,"bac \x85 gla\x87on",50,15,115,8,true,true,Communiste,60,"cong\x82lateur maya",50,40,true,Humide,75,25);
    /*case 11*/ Ennemi Lama("Lama unijambiste ninja",400,150,65,75,"crachat",65,20,200,10,true,true,Musicien,85,"karat\x82",65,44,true,BoutQuiColle,95,25);
    ///case 12
    /*case 13*/ Ennemi Yeti("Y\x82ti",600,150,80,50,"grosse boule de neige",80,50,250,2,false,true,Enflamme,100,"boule de poil",80,52,false,HuileEssentielle,120,25);
    /*case 14*/ Ennemi Candidat("Candidat de Koh-Lanta",550,165,90,75,"bol de manioc et de riz",90,27,325,0,true,true,Farci,100,"statue \x82trange",90,56,false,Enflamme,135,25);
    ///case 15
    /*case 16*/ Ennemi Souris("Souris \x82lectrique",700,175,120,100,"tazer",120,28,425,13,true,false,DansLesYeux,125,"court-circuit",105,64,true,Communiste,160,25);
    /*case 17*/ Ennemi Proprietaire("Gamin parcourant le monde pour faire combattre des animaux entre eux",200,50,125,225,"pok\x8boule",false,true,125,30,500,2,HuileEssentielle,125,"aspifion",125,68,true,Farci,185,25);
    ///case 18
    /*case 19*/ Ennemi Mangouste("Mangouste",750,180,140,150,"attaque de mangouste",140,30,600,2,false,false,Communiste,150,"calamar mal cuit",155,76,true,BordPointu,225,25);
    /*case 20*/ Ennemi Schtroumpf("Schtroumpf",1000,175,150,180,"salsepareille",150,25,800,6,false,true,Humide,175,"bonnet blanc",175,80,true,PartieContondante,250,25);
    ///case 21

    bool combatGagne(true);

    ///Tirage de l'ennemi rencontré
    int typeEnnemi, valeurMax;

    do
    {
        srand(time(0));

        typeEnnemi = rand() % joueur.getLvl() + joueur.getLvl()/(11/6);

        valeurMax = joueur.getLvl()-1 + joueur.getLvl()/(11/6);

    }while(valeurMax - typeEnnemi > 6);

    finLigne(500);
    finLigne(500);

    switch(typeEnnemi)
    {
    case 1 :
        phrase("Une sir\x8Ane se balade et d\x82\acide de vous attaquer.");
        combatGagne = combatDesert(joueur,Sirene);
        break;

    case 2 :
        phrase("Un inconnu arrive en scooter et insulte votre maman.");
        combatGagne = combatDesert(joueur,Racaille);
        break;

    case 3 :
        ///Aucune rencontre
        break;

    case 4 :
        phrase("Un voyageur tr\x8As perdu vous attaque pour vous piquer votre carte.");
        combatGagne = combatDesert(joueur,Voyageur);
        break;

    case 5 :
        phrase("Vous croisez un \x82trange individu qui commence \x85 vous donner des conseils sur la pr\x82paration d'un gratin.");
        combatGagne = combatDesert(joueur,Kadoc);
        break;

    case 6 :
        ///Aucune rencontre
        break;

    case 7 :
        phrase("Un ruiseau apparait et une truite enrag\x82\ae en sort.");
        combatGagne = combatDesert(joueur,Truite);
        break;

    case 8 :
        phrase("Un individu louche vous propose de vous faire une d\x82monstration de ses pouvoirs.");
        combatGagne = combatDesert(joueur,Polystiro);
        break;

    case 9 :
        ///Aucune rencontre
        break;

    case 10 :
        phrase("Vous passez \x85 c\x93t\x82 d'une prise \x82lectrique \x85 m\x88me le sable qui relie un frigo.");
        combatGagne = combatDesert(joueur,Frigo);
        break;

    case 11 :
        phrase("Un nuage de fum\x82\ae s'\x82tend soudainement autour de vous, et un cri japonais retenti.");
        combatGagne = combatDesert(joueur,Lama);
        break;

    case 12 :
        ///Aucune rencontre
        break;

    case 13 :
        phrase("Vous tombez sur un y\x82ti.");
        combatGagne = combatDesert(joueur,Yeti);
        break;

    case 14 :
        phrase("Vous arrivez vers un poteau avec quelqu'un \x85 son sommet.");
        combatGagne = combatDesert(joueur,Candidat);
        break;

    case 15 :
        ///Aucune rencontre
        break;

    case 16 :
        phrase("Une souris \x82lectrique sauvage apparait.");
        combatGagne = combatDesert(joueur,Souris);
        break;

    case 17 :
        phrase("Un propri\x82taire de souris \x82lectriques apparait.");
        combatGagne = combatDesert(joueur,Proprietaire);
        break;

    case 18 :
        ///Aucune rencontre
        break;

    case 19 :
        phrase("Une mangouste vous attaque.");
        combatGagne = combatDesert(joueur,Mangouste);
        break;

    case 20 :
        phrase("Les schtroumpfs semblent avoir lanc\x82 leur invasion du monde.");
        combatGagne = combatDesert(joueur,Schtroumpf);
        break;

    case 21 :
        ///Aucune rencontre
        break;

    default :
        ///Aucune rencontre
        break;
    }

    if(!combatGagne && joueur.estVivant())
    {
        phrase("Vous retournez d'o\x97 vous venez.");
        finLigne(500);
        phrase("Au moins, la-bas, vous n'\x88tes pas mort.");
        finLigne(500);

        return false;
    }

    return true;
}
bool rencontreEnnemiMarai(Joueur &joueur)
{
    ///Initialisation des ennemis des rencontres aléatoires
    /*case 16*/ Ennemi Pizza("Pizza surgel\x82\ae",700,175,105,100,"c\x93t\x82 pas cuit",110,28,425,13,true,false,Enflamme,125,"pizza avec poivron",105,64,false,Humide,160,25);
    /*case 17*/ Ennemi Roseau("Stylo enrag\x82",200,50,125,225,"fuite d'encre",false,true,125,30,500,3,DansLesYeux,125,"crayon de papier",125,68,false,Enflamme,185,25);
    ///case 18
    /*case 19*/ Ennemi Vache("Vache n\x82vros\x82\ae",750,180,155,150,"lait caill\x82",160,30,750,12,true,false,Farci,150,"fromage all\x82g\x82",155,76,true,BordPointu,225,25);
    /*case 20*/ Ennemi Sac("Sac \x85 dos",1000,175,175,180,"sangle d\x82r\x82gl\x82\ae",175,25,1000,6,false,true,HuileEssentielle,200,"sacoche bien r\x82gl\x82\ae",175,80,false,Communiste,250,25);
    ///case 21
    /*case 22*/ Ennemi Stylo("Roseau en bermuda",1300,185,200,190,"coup qui fait mal",200,30,2000,8,true,true,Communiste,200,"boisson alcoolis\x82\ae russe",210,75,true,Enflamme,250,25);
    /*case 23*/ Ennemi Crapaud("Gros crapaud",1600,200,225,200,"langue bien rapeuse",225,35,4000,10,false,true,Lisse,250,"raquette en plomb",235,110,false,BoutQuiColle,275,25);
    ///case 24
    /*case 25*/ Ennemi Jedi("Ma\x8Ctre de la puissance",2000,500,250,230,"t\x82l\x82kin\x82sie",250,115,6500,0,false,true,PartieContondante,250,"\x82p\x82\ae lumineuse",250,125,Couleur,280,25);
    /*case 26*/ Ennemi Zeppelin("Zeppelin",2300,275,275,250,"citrouille",275,75,9000,25,false,true,Communiste,265,"poney rose",285,140,Farci,305,25);
    ///case 27
    /*case 28*/ Ennemi Jongleur("Jongleur indien",2650,300,300,265,"tomahak enflamm\x82",300,85,30,50,true,true,DansLesYeux,280,"corne de lapin",310,165,HuileEssentielle,320,25);
    /*case 29*/ Ennemi Balle("Balle rebondissante",3000,10,325,300,"rebond inattendu",325,3,50,100,true,false,PartieContondante,300,"ingr\x82\adient allerg\x8Ane",350,180,Musicien,350,25);

    bool combatGagne = true;

    ///Tirage de l'ennemi rencontré
    int typeEnnemi, valeurMax;

    do
    {
        srand(time(0));

        typeEnnemi = rand() % joueur.getLvl() + joueur.getLvl()/(11/6);

        valeurMax = joueur.getLvl()-1 + joueur.getLvl()/(11/6);

    }while(valeurMax - typeEnnemi > 6);

    cout << endl;

    switch(typeEnnemi)
    {
    case 16 :
        phrase("Au loin, vous voyez les roseaux s'\x82\acarter sur le passage d'un monstre.");
        finLigne(1000);
        phrase("C'EST UNE PIZZA SURGEL\x90\aE QUI VOUS ATTAQUE !!!");
        finLigne(500);
        finLigne(500);
        combatGagne = combatMarai(joueur,Pizza);
        break;

    case 17 :
        phrase("Un roseau n'a pas aim\x82 la mani\x8Are dont vous avez bouscul\x82 son camarade.");
        finLigne(500);
        finLigne(500);
        combatGagne = combatMarai(joueur,Roseau);
        break;

    case 18 :
        ///Aucune rencontre
        break;

    case 19 :
        phrase("Une vache vient vous faire part de tous ses problèmes.");
        finLigne(500);
        phrase("Elle prend mal le fait que vous essayez de la grignotter.");
        finLigne(500);
        finLigne(500);
        combatGagne = combatMarai(joueur,Vache);
        break;

    case 20 :
        phrase("Vous trouvez au sol un sac \x85 dos.");
        finLigne(500);
        phrase("Vous voulez le ramasser mais il se retourne contre vous.");
        finLigne(500);
        finLigne(500);
        combatGagne = combatMarai(joueur,Sac);
        break;

    case 21 :
        ///Aucune rencontre
        break;

    case 22 :
        phrase("\xB7 force de marcher, vous arrivez \x85 un marchand de stylo violet.");
        finLigne(500);
        phrase("Un stylo ninja magenta \x82tait cach\x82 et vous attaque pour prot\x82ger sa couverture !!");
        finLigne(500);
        finLigne(500);
        combatGagne = combatMarai(joueur,Stylo);
        break;

    case 23 :
        phrase("Vous marchez sur quelque chose qui a couin\x82.");
        finLigne(500);
        phrase("Un gros crapaud surgit soudain hors de l'eau.");
        finLigne(500);
        finLigne(500);
        combatGagne = combatMarai(joueur,Crapaud);
        break;

    case 24 :
        ///Aucune rencontre
        break;

    case 25 :
        phrase("Une faille spatio-temporelle apparait devant vous.");
        finLigne(500);
        phrase("Un individu habill\x82 en moine vous attaque sans raison apparente.");
        finLigne(500);
        finLigne(500);
        combatGagne = combatMarai(joueur,Jedi);
        break;

    case 26 :
        phrase("Vous entendez un bruit de moteur au dessus de vous.");
        finLigne(500);
        finLigne(500);
        combatGagne = combatMarai(joueur,Zeppelin);
        break;

    case 27 :
        ///Aucune rencontre
        break;

    case 28 :
        phrase("Un groupe de roseau assiste \x85 la repr\x82sentation d'un artiste.");
        finLigne(500);
        phrase("Ce dernier ne semble pas appr\x82\acier votre t\x88te.");
        finLigne(500);
        finLigne(500);
        combatGagne = combatMarai(joueur,Jongleur);
        break;

    case 29 :
        phrase("Vous appercevez au loin un point se rapprochez par les airs.");
        finLigne(500);
        phrase("Vous remarquez qu'il sagit d'une balle rebondissante lorsqu'elle vous frappe le visage.");
        finLigne(500);
        finLigne(500);
        combatGagne = combatMarai(joueur,Balle);
        break;

    default :
        ///Aucune rencontre
        break;
    }

    if(!combatGagne && joueur.estVivant())
    {
        phrase("Vous retournez d'o\x97 vous venez.");
        finLigne(500);
        phrase("Au moins, la-bas, vous n'\x88tes pas mort.");
        finLigne(500);

        return false;
    }

    return true;
}
bool rencontreEnnemiArchipel(Joueur &joueur)
{
    return true;
}

    ///Chapitre 1
    ///Introduction à l'interface de combat
int intro(Joueur &joueur)
{
    int i = 0, degatArmeJoueur = 15,effortArmeJoueur = 10,progressionJoueur;
    string reponse;
    bool joueurAFuit(false);

    Ennemi Instructeur("Chef Instructeur",joueur.getPvMax()+joueur.getDefense(),"Hache Purificatrice",joueur.getPvMax()+joueur.getDefense(),0,0,0,false,true);
    Ennemi Mannequin("Mannequin",0,"Regard inpassible",0,0,0,0,true,true);
    Ennemi AutreMannequin("Second mannequin",0,"Regard vide",0,0,0,0,true,true);

    progressionJoueur = joueurEstConnu(joueur.getNom(),joueur.estMasculin());

    if(progressionJoueur == 1)
    {
        phrase("Tiens !!");
        finLigne(1000);
        phrase("Je reconnais ce nom.");
        finLigne(1000);
        phrase("C'est celui ");
        phrase(accorde("du champion","de la championne",joueur.estMasculin()));
        phrase(".");
        finLigne(1000);
        phrase("C'est vous ?");
        finLigne(1000);

        getline(cin,reponse);
        cout << endl;

        for(unsigned int i = 0;i < reponse.size();i++)
        {
            reponse[i] = tolower(reponse[i]);
        }

        while(reponse != "oui" && reponse != "non")
        {
            phrase("Aller, c'est pas difficile.");
            finLigne(500);
            phrase("Est-ce que vous avez termin\x82 l'ar\x8Ane ?");
            cout << endl;
            getline(cin,reponse);
            cout << endl;

            for(unsigned int i = 0;i < reponse.size();i++)
            {
                reponse[i] = tolower(reponse[i]);
            }

        }

        if(reponse == "non")
        {
            phrase("C'est \x82trange, parce que vous avez le m\x88me nom que " + accorde("le champion","la championne",joueur.estMasculin()) + " de l'ar\x8Ane.");
            finLigne(1000);
            phrase("C'est domage, je " + accorde("le","la",joueur.estMasculin()) + " cherchais.");
            finLigne(1000);
        }
        else
        {
            phrase("\x80\aa tombe bien, car je vous cherchais.");
            finLigne(500);
            finLigne(500);
            phrase("Il vous tape durement sur l'\x82paule et vous vous \x82vanouissez.");
            finLigne(1500);
            finLigne(1500);
            phrase("Vous vous r\x82veillez sur du sable chaud.");
            finLigne(500);
            finLigne(500);
            phrase("Vous vous rappelez que cet homme \x82tait l'instructeur, et que vous lui avez fait perdre un pari juteux.");
            finLigne(750);
            finLigne(750);
            phrase("Apparement, il est rancunier.");
            finLigne(500);
            finLigne(500);
            phrase("Apr\x8As avoir repris vos esprits, vous remarquez que ce sable chaud se trouve dans un d\x82sert, tout comme vous.");
            finLigne(500);
            finLigne(500);
            return progressionJoueur;
        }
    }
    else if(progressionJoueur == 2 || progressionJoueur == 3)
    {
        if(progressionJoueur == 2)
        {
            sleep(1000);
            phrase("Ah, ");
            sleep(1000);
            phrase("vous \x88tes " + accorde("celui","celle",joueur.estMasculin()) + " qui a tu\x82 mon pr\x82\ad\x82\acesseur dans le d\x82sert, c'est \x87\aa ?");
            finLigne(500);
            getline(cin,reponse);

            for(unsigned int i = 0;i < reponse.size();i++)
            {
                reponse[i] = tolower(reponse[i]);
            }

            while(reponse != "oui" && reponse != "non")
            {
                phrase("Je crois vous recona\x8Ctre, mais il faut que vous me confirmiez si c'\x82tait vous.");
                finLigne(500);

                getline(cin,reponse);

                for(unsigned int i = 0;i < reponse.size();i++)
                {
                    reponse[i] = tolower(reponse[i]);
                }
            }

            finLigne(500);

            if(reponse == "oui")
            {
                phrase("C'est bien ce que je pensais.");
                finLigne(500);
                phrase("Je suis le nouveau chef des instructeurs, et je serai votre mentor.");
                finLigne(500);
                phrase("Vous pouvez m'appeler Mentor en chef, ou Instructeur Omniscient.");
                finLigne(500);
                finLigne(500);
                phrase("Mais j'ai une pr\x82\af\x82rence pour Chef Omniscient, pas vous ?");
                finLigne(500);
                finLigne(500);
                phrase("Tenez, il a laiss\x82 \x87\aa avant de partir vous retrouver.");
                finLigne(500);
                finLigne(500);
                phrase("Il l'avait donn\x82 en h\x82ritage \x85 un de ces mannequins, mais aucun n'a surv\x82\acu \x85 l'annonce de sa mort.");
                finLigne(500);
                finLigne(500);
                phrase("Trop de bonheur.");
                finLigne(1000);
                phrase("Ils n'avaient pas l'habitude.");
                finLigne(500);

                Arme NouvelleArme("Hache Purificatrice",200,100,false,Enflamme,275);

                joueur.recoitRecompense(0,0,NouvelleArme,100);
                joueur.setLvl(11);

                phrase("Si je me souvient bien, vous vous dirigiez vers le marai mar\x82\acageux, n'est-ce pas ?");
                finLigne(500);
                finLigne(500);
                phrase("Attendez, je vais vous y conduire.");
                finLigne(500);
                return progressionJoueur;
            }
            else if(reponse == "non");
            {
                phrase("On a d\x96 me faire une mauvaise description alors.");
                finLigne(1000);
                phrase("Bah, je verrai \x87\aa plus tard.");
                finLigne(1000);
            }
        }
        else if(progressionJoueur == 3)
        {
            finLigne(1000);
            phrase("Ah, ");
            sleep(1000);
            phrase("vous \x88tes " + accorde("celui","celle",joueur.estMasculin()) + " qui a travers\x82 la fronti\x8Are au-del\x85 du d\x82sert, non ?");
            finLigne(500);
            getline(cin,reponse);

            for(unsigned int i = 0;i < reponse.size();i++)
            {
                reponse[i] = tolower(reponse[i]);
            }

            while(reponse != "oui" && reponse != "non")
            {
                phrase("D'apr\x8As ce qu'on m'a dit, " + accorde("un homme","une femme",joueur.estMasculin()) + " vous ressemblant aurait convaincu les gardes de " + accorde("le","la",joueur.estMasculin()) + " laisser passer.");
                finLigne(500);
                phrase("C'\x82tait vous ou pas ?");
                finLigne(500);

                getline(cin,reponse);

                for(unsigned int i = 0;i < reponse.size();i++)
                {
                    reponse[i] = tolower(reponse[i]);
                }
            }

            finLigne(500);

            if(reponse == "oui")
            {
                phrase("Vu que vous \x88tes r\x82\aapparu" + accorde("","e",joueur.estMasculin()) + " de ce c\x93t\x82-ci du d\x82sert, on va faire une ellipse le temps que vous arriviez de l'autre c\x93t\x82.");
                finLigne(750);
                finLigne(750);
                finLigne(750);
                phrase("Pendant le voyage, vous trouvez une arme.");
                finLigne(500);
                finLigne(500);

                joueur.returnVanilla();

                joueur.nouvelleArme("tapette \x85 mouche",200,100,false,HuileEssentielle,275);

                phrase("Le voyage est long, et vous perdez toute votre exp\x82rience.");
                finLigne(500);
                finLigne(500);

                phrase("Heureusement, vous la regagnez en passant votre temps \x85 chasser les mouches qui tournent autour de vous.");
                finLigne(1000);

                joueur.setLvl(11);

                return progressionJoueur;
            }
            else
            {
                phrase("Oui, si vous \x88tes ici, c'est que vous n'\x88tes pas l\x85-bas.");
                finLigne(1500);
                phrase("Je suis philosophe dans l'\x83me.");
                finLigne(1000);
            }
        }

        finLigne(500);
        phrase("Mais oui, je sais !!");
        finLigne(1000);
        phrase("Vous \x88tes " + accorde("le champion","la championne",joueur.estMasculin()) + " de l'ar\x8Ane.");
        finLigne(500);
        getline(cin,reponse);

        for(unsigned int i = 0;i < reponse.size();i++)
        {
            reponse[i] = tolower(reponse[i]);
        }

        while(reponse != "oui" && reponse != "non")
        {
            phrase("Oh, " + accorde("il","elle",joueur.estMasculin()) + " est timide.");
            finLigne(500);
            phrase("Je vous impressionne.");
            finLigne(500);
            phrase("C'est toujours la m\x88me chose.");
            finLigne(500);
            phrase("Mais il me faut une r\x82ponse.");
            finLigne(500);

            getline(cin,reponse);

            for(unsigned int i = 0;i < reponse.size();i++)
            {
                reponse[i] = tolower(reponse[i]);
            }
        }

        finLigne(500);

        if(reponse == "oui")
        {
            phrase("Je savais bien que je ne me trompais pas sur toute la ligne.");
            finLigne(250);
            finLigne(250);
            phrase("Il vous tape durement sur l'\x82paule et vous vous \x82vanouissez.");
            finLigne(1500);
            finLigne(1500);
            phrase("Vous vous r\x82veillez sur du sable chaud.");
            finLigne(500);
            finLigne(500);
            phrase("Vous vous rappelez que cet homme \x82tait l'instructeur, et que vous lui avez fait perdre un pari juteux.");
            finLigne(750);
            finLigne(750);
            phrase("Apparement, il est rancunier.");
            finLigne(500);
            finLigne(500);
            phrase("Apr\x8As avoir repris vos esprits, vous remarquez que ce sable chaud se trouve dans un d\x82sert, tout comme vous.");
            finLigne(500);
            finLigne(500);

            return 1;
        }
        else
        {
            phrase("Ah bon.");
            finLigne(500);
            phrase("Faut que je passe chez l'opticen alors.");
            finLigne(500);
        }
    }

    finLigne(500);
    phrase("Bien, ");
    sleep(500);
    phrase("je suis le chef des instructeurs, et je serai votre mentor.");
    finLigne(500);
    phrase("Vous pouvez m'appeler Instructeur en chef, ou Mentor Omniscient.");
    finLigne(500);
    finLigne(500);
    Instructeur.dit("Voyons voir de quoi vous \x88tes capable, " + joueur.getNom() + ".");
    finLigne(500);
    phrase("Tapez ce mannequin l\x85-bas, \x87\aa vous fera un bon exercice.");
    sleep(500);

    while(i < 2)
    {
        i++;

        if(i == 2)
        {
            cout << endl << endl;
            Instructeur.dit("Alors, c'\x82tait un bon exercice non ?");
            finLigne(500);
            phrase("Quelle que soit votre r\x82ponse, c'\x82tait un bon exercice.");
            finLigne(500);
            phrase("Vous avez gagn\x82 votre premier combat, et l'exp\x82rience qui va avec.");
            finLigne(500);

            joueur.recoitRecompense(2,0,Aucune,0);

            Instructeur.dit("Et prenez cette arme, l\x85. Vous n'allez pas devenir " + accorde("le plus fort","la plus forte",joueur.estMasculin()) + " avec des baffes.");
            finLigne(500);

            joueur.nouvelleArme("lance en cuir",degatArmeJoueur,effortArmeJoueur,false,Enflamme,10);

            cout << endl;
            Instructeur.dit("De ce que je vois, vous serez bient\x93t pr\x88t" + accorde("","e",joueur.estMasculin()) + " \x85 rentrer dans l'ar\x8Ane.");
            finLigne(500);
            phrase("Mais avant, essayez votre nouvelle arme.");
            finLigne(500);

            combatArene(joueur,AutreMannequin);
            if(AutreMannequin.getPv() > AutreMannequin.getPvMax()*3/4)
            {
                joueurAFuit = true;
            }
        }
        else
        {
            combatArene(joueur,Mannequin);
            if(Mannequin.getPv() > Mannequin.getPvMax()*3/4)
            {
                joueurAFuit = true;
            }
        }

        if(joueurAFuit)
        {
            cout << endl;
            phrase("Le mannequin vous regarde partir en soupirant, et retourne effrayer les corbeaux.");
            cout << endl;
            finLigne(1000);
            Instructeur.dit("Quel");
            phrase(accorde("","le",joueur.estMasculin()));
            phrase(" l\x83\ache !! Fuir devant un mannequin d'exercice !");
            cout << endl;
            finLigne(500);
            phrase("Hache :");
            finLigne(250);
            phrase("Puuuunis-l");
            phrase(accorde("eeeee","aaaaa",joueur.estMasculin()));
            phrase(" !!!!!");
            finLigne(1000);

            combatArene(joueur,Instructeur);

            if(Instructeur.estVivant() && joueur.estVivant())
            {
                cout << endl;
                phrase("L'instructeur fait un mouvement ample, et balance sa hache dans votre direction en marmonant.");
                cout << endl;
                finLigne(1000);
                phrase("Heureusement, vous arrivez \x85 fuir.");
                cout << endl;
                finLigne(500);
                phrase("Vous essayez d'essuyer la sueur qui coule sur votre front.");
                cout << endl;
                finLigne(1000);
                phrase("Malheureusement, ");
                sleep(250);
                phrase("votre t\x88te roule trop vite pour que votre corps puisse la rattraper...");
            }

            return -1;
        }
    }

    cout << endl;
    Instructeur.dit("Et merde, " + accorde("il","elle",joueur.estMasculin()) + " est toujours vivant" + accorde("","e",joueur.estMasculin()) + " !!");
    finLigne(1500);
    phrase("Et en plus " + accorde("il","elle",joueur.estMasculin()) + " m'a entendu.");
    finLigne(1500);
    phrase("Je pensais pas qu'" + accorde("il","elle",joueur.estMasculin()) + " survivrait.");
    finLigne(1000);
    phrase("J'aurai pas d\x96 parier sur le mannequin.");
    finLigne(1500);
    phrase("Bon, dans ce cas, allez \x85 l'ar\x8Ane. ");
    sleep(1000);
    phrase("C'est par l\x85-bas.");
    finLigne(1000);
    phrase("Vous y avez une chance, de toute \x82vidence.");
    finLigne(1500);
    phrase("Je me rattraperai sur le prochain glandu.");

    felicitations("Vous avez surv\x82\acu aux mannequins ambidextres");

    return 0;
}

    ///Chapitre 2
    ///Succession de 20 combats
bool arene(Joueur &joueur)
{
    int j(1);

    Ennemi Ennemi1("Voyageur perdu",100,100,10,5,"B\x83ton de marche",10,10,2,1,true,true,BordPointu,5); // exp == 4; lvl : 2

    Ennemi Ennemi2("Singe Albinos d'Am\x82rique Australe",100,110,15,6,"banane",Ennemi1.getDegatArme()+0.5*j,Ennemi1.getEffortArme()+1*j,9,(j*j)/2,false,true,BoutQuiColle,Ennemi1.getDegatEffet()+1*j);
    j++;

    Ennemi Ennemi3("Balai sans propri\x82taire",130,100,25,9,"nuage de poussi\x8Are de f\x82\ae",Ennemi2.getDegatArme()+0.5*j,Ennemi2.getEffortArme()+1*j,18,(j*j)/2,true,true,HuileEssentielle,Ennemi2.getDegatEffet()+1*j); // exp == 31; lvl : 3
    j++;

    Ennemi Ennemi4("Chasseur de Singe Albinos d'Am\x82rique Australe",135,120,25,15,"d\x82\acoupeur de banane",Ennemi3.getDegatArme()+0.5*j,Ennemi3.getEffortArme()+1*j,32,(j*j)/2,true,true,Farci,Ennemi3.getDegatEffet()+1*j);
    j++;

    Ennemi Ennemi5("Chaton dissident",165,125,30,23,"bouille trop mignonne",Ennemi4.getDegatArme()+0.5*j,Ennemi4.getEffortArme()+1*j,65,(j*j)/2,false,true,Humide,Ennemi4.getDegatEffet()+1*j); // exp == 128; lvl : 4
    j++;

    Ennemi Ennemi6("Banquier radin",200,130,45,35,"kippa surgel\x82\ae",Ennemi5.getDegatArme()+0.5*j,Ennemi5.getEffortArme()+1*j,88,(j*j)/2,false,true,Enflamme,Ennemi5.getDegatEffet()+1*j);
    j++;

    Ennemi Ennemi7("Caf\x82 italien",350,140,50,50,"go\x86t amer",Ennemi6.getDegatArme()+0.5*j,Ennemi6.getEffortArme()+1*j,175,(j*j)/2,true,true,Communiste,Ennemi6.getDegatEffet()+1*j); // exp == 391; lvl : 5
    j++;

    Ennemi Ennemi8("Transatlantique raciste et homophobe",400,150,65,75,"Pigargue Patriote",Ennemi7.getDegatArme()+0.5*j,Ennemi7.getEffortArme()+1*j,233,(j*j)/2,true,true,Rougeole,Ennemi7.getDegatEffet()+1*j);
    j++;

    Ennemi Ennemi9("Femme pouvant uriner debout",600,150,80,50,"samba envoutante",Ennemi8.getDegatArme()+0.5*j,Ennemi8.getEffortArme()+1*j,348,(j*j)/2,false,false,BoutQuiColle,Ennemi8.getDegatEffet()+1*j); // exp == 972; lvl : 6
    j++;

    Ennemi Ennemi10("Guerrier du nord",400,150,65,75,"bateau dragon",Ennemi9.getDegatArme()+0.5*j,Ennemi9.getEffortArme()+1*j,452,(j*j)/2,true,true,Lisse,Ennemi9.getDegatEffet()+1*j);
    j++;

    Ennemi Ennemi11("Maitre nageur",550,165,90,75,"p\x82\adiluve glacial",Ennemi10.getDegatArme()+0.5*j,Ennemi10.getEffortArme()+1*j,677,(j*j)/2,true,true,Enflamme,Ennemi10.getDegatEffet()+1*j); // exp == 2101; lvl : 7
    j++;

    Ennemi Ennemi12("Koala boulimique",700,175,105,100,"massue hydrophobe",Ennemi11.getDegatArme()+0.5*j,Ennemi11.getEffortArme()+1*j,798,(j*j)/2,false,true,BordPointu,Ennemi11.getDegatEffet()+1*j);
    j++;

    Ennemi Ennemi13("Grand black musculeux et huil\x82",200,50,125,225,"membre sur-developp\x82",Ennemi12.getDegatArme()+0.5*j,Ennemi12.getEffortArme()+1*j,1197,(j*j)/2,true,true,Communiste,Ennemi12.getDegatEffet()+1*j); // exp == 4096; lvl : 8
    j++;

    Ennemi Ennemi14("G\x82rant de restaurant brid\x82",Ennemi13.getPv()+2*j,Ennemi13.getEnergie()+1*j,Ennemi13.getAttaque()+0.5*j,Ennemi13.getDefense()+(2/3)*j,"boulette de riz",Ennemi13.getDegatArme()+0.5*j,Ennemi13.getEffortArme()+1*j,1315,(j*j)/2,false,true,Musicien,Ennemi13.getDegatEffet()+1*j);
    j++;

    Ennemi Ennemi15("Barbare moustachu",Ennemi14.getPv()+2*j,Ennemi14.getEnergie()+1*j,Ennemi14.getAttaque()+0.5*j,Ennemi14.getDefense()+(2/3)*j,"grosse pierre tomb\x82\ae du ciel",Ennemi14.getDegatArme()+0.5*j,Ennemi14.getEffortArme()+1*j,1971,(j*j)/2,false,true,Couleur,Ennemi14.getDegatEffet()+1*j); // exp == 7382; lvl : 9
    j++;

    Ennemi Ennemi16("Bucheron canadien",Ennemi15.getPv()+2*j,Ennemi15.getEnergie()+1*j,Ennemi15.getAttaque()+0.5*j,Ennemi15.getDefense()+(2/3)*j,"machette ray\x82\ae",Ennemi15.getDegatArme()+0.5*j,Ennemi15.getEffortArme()+1*j,2048,(j*j)/2,false,true,BoutQuiColle,Ennemi15.getDegatEffet()+1*j);
    j++;

    Ennemi Ennemi17("Professeur",Ennemi16.getPv()+2*j,Ennemi16.getEnergie()+1*j,Ennemi16.getAttaque()+0.5*j,Ennemi16.getDefense()+(2/3)*j,"crissement de craie",Ennemi16.getDegatArme()+0.5*j,Ennemi16.getEffortArme()+1*j,3071,(j*j)/2,true,true,Musicien,Ennemi16.getDegatEffet()+1*j); // exp == 12501; lvl : 10
    j++;

    Ennemi Ennemi18("Triathl\x8Ate",Ennemi17.getPv()+2*j,Ennemi17.getEnergie()+1*j,Ennemi17.getAttaque()+0.5*j,Ennemi17.getDefense()+(2/3)*j,"transpiration collante",Ennemi17.getDegatArme()+0.5*j,Ennemi17.getEffortArme()+1*j,3392,(j*j)/2,true,true,HuileEssentielle,Ennemi17.getDegatEffet()+1*j);
    j++;

    Ennemi Ennemi19("Chef des Instructeurs",Ennemi18.getPv()+2*j,Ennemi18.getEnergie()+1*j,Ennemi18.getAttaque()+0.5*j,Ennemi18.getDefense()+(2/3)*j,"Hache Repurgatrice",Ennemi18.getDegatArme()+0.5*j,Ennemi18.getEffortArme()+1*j,4240,(j*j)/2,false,true,Humide,Ennemi18.getDegatEffet()+1*j); // exp == 20133; lvl : 11
    j++;

    Ennemi Boss("Grand fr\x8Are des Mannequins",Ennemi19.getPv()+2*j,Ennemi19.getEnergie()+1*j,Ennemi19.getAttaque()+0.5*j,Ennemi19.getDefense()+(2/3)*j,"regard circonspect",Ennemi19.getDegatArme()+0.5*j,Ennemi19.getEffortArme()+1*j,1,(j*j)/2,true,true,Couleur,Ennemi19.getDegatEffet()+1*j);

    phrase("L'ar\x8Ane est une succession de 20 combats, ni plus, ni moins.");
    finLigne(500);
    phrase("Bonne chance !!");
    finLigne(1000);

    felicitations("Vous entrez dans l'ar\x8Ane");

    combatArene(joueur,Ennemi1);
    if(joueur.estVivant())
    {
        phrase("Encore 19.");
        finLigne(500);

        combatArene(joueur,Ennemi2);
        if(joueur.estVivant())
        {
            phrase("Encore 18.");
            finLigne(500);

            joueur.nouvelleArme("vache servant \x85 faire les lances",joueur.getDegatArme()+1*joueur.getLvl(),joueur.getEffortArme()+1*joueur.getLvl(),false,Humide,joueur.getDegatEffet()+1*joueur.getLvl());

            combatArene(joueur,Ennemi3);
            if(joueur.estVivant())
            {
                phrase("Encore 17.");
                finLigne(500);

                combatArene(joueur,Ennemi4);
                if(joueur.estVivant())
                {
                    phrase("Encore 16.");
                    finLigne(500);

                    joueur.nouvelleArme("poisson consanguin",joueur.getDegatArme()+1*joueur.getLvl(),joueur.getEffortArme()+1*joueur.getLvl(),true,Communiste,joueur.getDegatEffet()+1*joueur.getLvl());

                    combatArene(joueur,Ennemi5);
                    if(joueur.estVivant())
                    {
                        phrase("Encore 15.");
                        finLigne(500);

                        combatArene(joueur,Ennemi6);
                        if(joueur.estVivant())
                        {
                            phrase("Encore 14.");
                            finLigne(500);

                            joueur.nouvelleArme("esprit tordu",joueur.getDegatArme()+1*joueur.getLvl(),joueur.getEffortArme()+1*joueur.getLvl(),true,BoutQuiColle,joueur.getDegatEffet()+1*joueur.getLvl());

                            combatArene(joueur,Ennemi7);
                            if(joueur.estVivant())
                            {
                                phrase("Encore 13.");
                                finLigne(500);

                                combatArene(joueur,Ennemi8);
                                if(joueur.estVivant())
                                {
                                    phrase("Encore 12.");
                                    finLigne(500);

                                    joueur.nouvelleArme("gorille jongleur",joueur.getDegatArme()+1*joueur.getLvl(),joueur.getEffortArme()+1*joueur.getLvl(),true,Farci,joueur.getDegatEffet()+1*joueur.getLvl());

                                    combatArene(joueur,Ennemi9);
                                    if(joueur.estVivant())
                                    {
                                        phrase("Encore 11.");
                                        finLigne(500);

                                        combatArene(joueur,Ennemi10);
                                        if(joueur.estVivant())
                                        {
                                            phrase("Encore 10.");
                                            finLigne(500);

                                            joueur.nouvelleArme("litchi gluant",joueur.getDegatArme()+1*joueur.getLvl(),joueur.getEffortArme()+1*joueur.getLvl(),true,BordPointu,joueur.getDegatEffet()+1*joueur.getLvl());

                                            combatArene(joueur,Ennemi11);
                                            if(joueur.estVivant())
                                            {
                                                phrase("Encore 9.");
                                                finLigne(500);

                                                combatArene(joueur,Ennemi12);
                                                if(joueur.estVivant())
                                                {
                                                    phrase("Encore 8.");
                                                    finLigne(500);

                                                    joueur.nouvelleArme("Banana Split",joueur.getDegatArme()+1.5*joueur.getLvl(),joueur.getEffortArme()+1.5*joueur.getLvl(),true,HuileEssentielle,joueur.getDegatEffet()+1*joueur.getLvl());

                                                    combatArene(joueur,Ennemi13);
                                                    if(joueur.estVivant())
                                                    {
                                                        phrase("Encore 7.");
                                                        finLigne(500);

                                                        combatArene(joueur,Ennemi14);
                                                        if(joueur.estVivant())
                                                        {
                                                            phrase("Encore 6.");
                                                            finLigne(500);

                                                            joueur.nouvelleArme("tasse fendue",joueur.getDegatArme()+1.5*joueur.getLvl(),joueur.getEffortArme()+1.5*joueur.getLvl(),false,Enflamme,joueur.getDegatEffet()+1*joueur.getLvl());

                                                            combatArene(joueur,Ennemi15);
                                                            if(joueur.estVivant())
                                                            {
                                                                phrase("Encore 5.");
                                                                finLigne(500);

                                                                combatArene(joueur,Ennemi16);
                                                                if(joueur.estVivant())
                                                                {
                                                                    phrase("Encore 4.");
                                                                    finLigne(500);

                                                                    joueur.nouvelleArme("sac de sel",joueur.getDegatArme()+1.5*joueur.getLvl(),joueur.getEffortArme()+1.5*joueur.getLvl(),true,Humide,joueur.getDegatEffet()+1*joueur.getLvl());

                                                                    combatArene(joueur,Ennemi17);
                                                                    if(joueur.estVivant())
                                                                    {
                                                                        phrase("Encore 3.");
                                                                        finLigne(500);

                                                                        combatArene(joueur,Ennemi18);
                                                                        if(joueur.estVivant())
                                                                        {
                                                                            phrase("Encore 2.");
                                                                            finLigne(500);

                                                                            joueur.nouvelleArme("Tour pench\x82\ae",joueur.getDegatArme()+1.5*joueur.getLvl(),joueur.getEffortArme()+1.5*joueur.getLvl(),false,BoutQuiColle,joueur.getDegatEffet()+1*joueur.getLvl());

                                                                            combatArene(joueur,Ennemi19);
                                                                            if(joueur.estVivant())
                                                                            {
                                                                                phrase("Et le dernier pour la fin.");
                                                                                finLigne(500);

                                                                                combatArene(joueur,Boss);
                                                                                if(joueur.estVivant())
                                                                                {
                                                                                    felicitations("Vous avez surv\x82\acu a l'ar\x8Ane hyperglyc\x82mique");

                                                                                    ofstream sauvegarde("sauvegardes.txt",ios::app);

                                                                                    if(sauvegarde)
                                                                                    {
                                                                                        phrase("Grand vainqueur de l'ar\x8Ane, votre nom restera dans les annales de l'histoire.");
                                                                                        finLigne(500);
                                                                                        phrase("Si vous deviez revenir, votre nom rappelerai ce que vous avez fait.");
                                                                                        finLigne(1000);

                                                                                        sauvegarde << joueur.estMasculin() << ";" << joueur.getNom() << "$" << 1 <<  endl;
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        phrase("Malheureusement, un probleme technique fera que personne ne se souviendra de votre nom.");
                                                                                        finLigne(1000);
                                                                                    }

                                                                                    finLigne(500);
                                                                                    phrase("Une fois sorti" + accorde("","e",joueur.estMasculin()) + " de l'ar\x8Ane, ");
                                                                                    sleep(500);
                                                                                    phrase("vous vous rendez dans une auberge miteuse apr\x8As avoir constat\x82 que tous ces combats ne vous avaient rapport\x82 que peu de pi\x8A\aces.");
                                                                                    cout << endl;
                                                                                    finLigne(1000);
                                                                                    cout << endl;
                                                                                    phrase("Vous vous r\x82veillez le lendemain, \x85 moiti\x82 nu" + accorde("","e",joueur.estMasculin()) + " dans un d\x82sert.");
                                                                                    finLigne(2000);
                                                                                    phrase("Vous n'avez plus aucune pi\x8A\ace sur vous, ni aucune arme, et toute votre exp\x82rience a \x82t\x82 vol\x82\ae.");
                                                                                    cout << endl;
                                                                                    finLigne(1500);
                                                                                    phrase("Mouais");
                                                                                    sleep(700);
                                                                                    phrase(".");
                                                                                    sleep(700);
                                                                                    phrase(".");
                                                                                    sleep(700);
                                                                                    phrase(".");
                                                                                    cout << endl;
                                                                                    finLigne(1000);
                                                                                    phrase("C'\x82tait bien une auberge de merde.");
                                                                                    cout << endl << endl;
                                                                                    finLigne(2000);
                                                                                    return true;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return false;
}

    ///Chapitre 3
    ///Introduction à l'interface de déplacement
    ///Deux sorties sont possibles
int desert(Joueur &joueur)
{
    int grilleDesert[25][25],joueurPosX = 17,joueurPosY = 2,sortieDuDesert = 0;
    const bool safe = true;
    bool campGaucheFini = false,campDroiteFini = false, premiereVisiteFrontiere = true;
    string carteDesert[25][25][9];

    creationDesert(grilleDesert,carteDesert);

    Ennemi Sirene("Sir\x8Ane",75,100,10,5,"regard langoureux et sexy",10,10,2,1,true,false,Enflamme,10);

    joueur.returnVanilla();

    phrase("Vous regardez \x85 perte de vue cet immense d\x82sert et pensez qu'il n'y a aucune chance que vous le traversiez.");
    finLigne(500);
    finLigne(500);
    phrase("Le soleil est \x82\ablouissant, mais une fine brise vous rafraichit tandis que vous en trouvez la source, ");
    sleep(1500);
    phrase("l'oc\x82\aan qui se trouve derri\x8Are vous.");
    finLigne(500);

    felicitations("Vous d\x82\acouvrez le d\x82sert interminable qui est \x85 c\x93t\x82 d'un oc\x82\aan qui vous fait parvenir une brise rafraichissante");

    phrase("Vous appercevez ce qui ressemble \x85 un mat.");
    finLigne(500);
    phrase("Vous devriez vous y diriger.");
    finLigne(500);
    finLigne(500);
    phrase("Ah oui !!");
    finLigne(500);
    phrase("C'est au nord.");
    finLigne(500);
    finLigne(500);
    finLigne(500);

    while(joueurPosX < 17 || joueurPosY != 1)
    {
        if(joueurPosX >= 17 && joueurPosY == 2)
        {
            deplacementDesert(joueur,grilleDesert,carteDesert,joueurPosX,joueurPosY,safe,campGaucheFini,campDroiteFini,premiereVisiteFrontiere,false);
        }
        else
        {
            deplacementDesert(joueur,grilleDesert,carteDesert,joueurPosX,joueurPosY,!safe,campGaucheFini,campDroiteFini,premiereVisiteFrontiere,false);
        }

        if(!joueur.estVivant())
        {
            phrase("J'aurai du pr\x82\aciser que le nord, c'\x82tait en haut.");
            finLigne(1000);
            return 0;
        }

    }

    phrase("Bonne nouvelle, ");
    sleep(500);
    phrase("vous savez ce que vous faites.");
    finLigne(500);
    phrase("Ou alors vous ne savez pas lire et vous \x88tes arriv\x82" + accorde("","e",joueur.estMasculin()) + " jusqu'ici par erreur.");
    finLigne(1000);
    phrase("Ce qui serai con, vu tout ce que j'ai \x82\acrit jusque l\x85.");
    finLigne(500);
    finLigne(500);
    phrase("Bref, vous arrivez devant ce qui semble \x88tre le reste d'un petit voilier.");
    finLigne(500);
    phrase("Vous doutez de la nature du naufrage, puis vos doutes sont effac\x82s lorsque qu'une sir\x8Ane vous attaque.");
    finLigne(500);
    phrase("Vous attrapez une planche par la partie contondante (selon les conseils d'un ami) et la brandissez face \x85 votre ennemi.");
    finLigne(500);
    finLigne(500);

    joueur.nouvelleArme("planche an\x82mique",10,5,false,PartieContondante,10);

    combatDesert(joueur,Sirene);

    if(!joueur.estVivant())
    {
        return 0;
    }

    finLigne(1000);
    phrase("Vous pensiez plus que le naufrage \x82tait d\x96 \x85 une temp\x88te, mais une attaque de sir\x8Ane semble avoir \x82t\x82 suffisante.");
    cout << endl;
    finLigne(1000);
    phrase("Au vu du mat\x82riel restant dans le restant de navire, ils \x82taient pr\x88t \x85 traverser le d\x82sert.");
    finLigne(1000);
    phrase("Malheureusement pour eux, ce n'est pas le d\x82sert qui les a tu\x82s.");
    cout << endl;
    finLigne(1500);
    phrase("Vous recup\x82rez des gourdes remplies d'eau, ainsi que de quoi faire une carte.");
    finLigne(500);
    phrase("Avec \x87\aa, vous ne devriez pas vous perdre, ni mourir de soif.");
    cout << endl << endl;
    finLigne(1000);

    while(joueur.estVivant())
    {
        if(joueurPosX == 24 && joueurPosY == 24)
        {
            sortieDuDesert = 2;
        }
        else if(joueurPosX == 0 && joueurPosY == 0)
        {
            sortieDuDesert = 3;
        }
        else
        {
            sortieDuDesert = 0;
        }

        if(sortieDuDesert != 0)
        {
            felicitations("Vous \x88tes sorti" + accorde("","e",joueur.estMasculin()) + " du d\x82sert");

            ofstream sauvegarde("sauvegardes.txt",ios::app);

            if(sauvegarde)
            {
                phrase("Enfin d\x82\abarass\x82" + accorde("","e",joueur.estMasculin()) + " de ce maudit d\x82sert, le monde entier entendra parler de cet exploit.");
                finLigne(500);
                phrase("La prochaine fois, vous n'aurez pas \x85 le retraverser.");
                finLigne(1000);

                sauvegarde << joueur.estMasculin() << ";" << joueur.getNom() << "$" << sortieDuDesert <<  endl;
            }
            else
            {
                phrase("Malheureusement, aujourd'hui, personne n'\x82tait pr\x82sent pour qu'on se rapelle ce que vous avez fait.");
                finLigne(1000);
            }

                return sortieDuDesert;
        }

        deplacementDesert(joueur,grilleDesert,carteDesert,joueurPosX,joueurPosY,!safe,campGaucheFini,campDroiteFini,premiereVisiteFrontiere);
    }

    return 0;
}

    ///Chapitre 4.1
    ///Brève utilisation d'une embarcation
bool marai(Joueur &joueur)
{
    int grilleMarai[25][25], grilleTourBas[20][20], grilleTourHaut[20][20], joueurPosX = 24, joueurPosY = 9, nbMorsure = 0;
    string carteMarai[25][25][9], carteTourBas[20][20][9], carteTourHaut[20][20][9];
    bool cabaneVisitee = false;

    creationMarai(grilleMarai,carteMarai);

    phrase("Apr\x8As une longue marche \x85 voir le d\x82sert s'effacer petit \x85 petit, le paysage se transforme.");
    finLigne(500);
    finLigne(500);
    phrase("La terre devient plus molle, l'air plus humide, et surtout, ");
    sleep(500);
    phrase("de l'eau apparait \x85 chaque pas que vous faites.");
    finLigne(500);
    finLigne(500);
    phrase("Vous commencez \x85 avoir de l'eau jusqu'aux chevilles, puis jusqu'aux genoux.");
    finLigne(500);
    finLigne(500);
    felicitations("Vous pataugez dans le marai mar\x82\acageux");
    phrase("J'esp\x8Are que vous aimez l'eau.");
    finLigne(500);

    while(joueur.estVivant())
    {
        deplacementMarai(joueur,grilleMarai,carteMarai,joueurPosX,joueurPosY,nbMorsure,cabaneVisitee);
    }

    return joueur.estVivant();
}

    ///Chapitre 4.2
    ///Grande utilisation d'une embarcation
bool archipel(Joueur &joueur)
{
    finLigne(500);
    phrase("\xB7 mesure que vous avancez, vous sentez la chaleur pesante du d\x82sert s'adoucir.");
    finLigne(500);
    finLigne(500);
    phrase("Les fientes de mouettes s'\x82\acrasant sur votre \x82paule vous laissent penser que vous approchez de la mer.");
    finLigne(500);
    finLigne(500);
    phrase("Un peu plus loin vous appercevez un panneau.");
    finLigne(500);
    finLigne(500);
    phrase("Panneau : ");
    finLigne(250);
    phrase("Vous approchez de la mer.");
    felicitations("Vous approchez de la mer");
    phrase("Encore plus loin, un autre panneau se dresse devant vous.");
    finLigne(500);
    finLigne(500);
    phrase("Autre panneau : ");
    finLigne(250);
    phrase("En fait, vous approchez de l'oc\x82\aan.");
    felicitations("En fait, vous approchez de l'oc\x82\aan");
    phrase("Derri\x8Are l'autre panneau, il y a un dernier panneau.");
    finLigne(500);
    finLigne(500);
    phrase("Dernier panneau (on l'esp\x8Are) : ");
    finLigne(250);
    phrase("Pour tout vous dire, c'est plut\x93t un archipel.");
    felicitations("Pour tout vous dire, c'est plut\x93t un archipel");
    phrase("Vous utilisez votre " + joueur.getNomArme() + " pour massacrer au autre panneau qui vous souhaitait la bienvenue sur l'archipel des \x8Cles flottantes.");

    felicitations("Bienvenue sur l'archipel des \x8Cles flottantes");

    phrase("Bah, vous n'aviez aucune raison de venir ici, mais vous pourriez explorer un peu.");
    finLigne(500);
    phrase("Qui sait ce que vous pourriez trouver.");
    finLigne(500);

    int grilleArchipel[30][30], joueurPosX = 0, joueurPosY = 3;
    string carteArchipel[30][30][9];

    creationArchipel(grilleArchipel,carteArchipel);

    while(joueur.estVivant())
    {
        deplacementArchipel(joueur,grilleArchipel,carteArchipel,joueurPosX,joueurPosY);
    }

    for(int lgr = 0;lgr <= 29;lgr++)
    {
        for(int htr = 0;htr <= 29;htr++)
        {
            setCaseCarteArchipel(carteArchipel,lgr,htr,grilleArchipel);
        }
    }

    afficheCarteArchipel(carteArchipel,joueurPosX,joueurPosY);

    return false;
}
