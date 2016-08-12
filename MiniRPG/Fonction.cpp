#include "Fonction.h"

using namespace std;

///Coisit entre deux mots celui qui correspond au genre renseigné
string accorde(string masculin, string feminin, bool estMasculin)
{
    switch(estMasculin)
    {
    case true :
        return masculin;
        break;
    case false :
        return feminin;
        break;
    }
}

///Marque un arrêt avant de fermer le programme et indique comment fermer la console
void finProgramme(bool jeuFini,bool joueurEstMasculin)
{
    if(jeuFini)
    {
        finLigne(1000);
        finLigne(1000);
        phrase("Bon, bah");
        sleep(500);
        phrase(".");
        sleep(500);
        phrase(".");
        sleep(500);
        phrase(".");
        finLigne(500);
        finLigne(500);
        phrase("Voil\x85.");
        finLigne(1500);
        finLigne(1500);
        phrase("The End.");
        finLigne(1000);
        finLigne(1000);
        finLigne(1000);
        phrase("Et vous \x88tes m\x88me pas mort.");
        finLigne(500);
        finLigne(500);
        finLigne(500);
        finLigne(500);
        phrase("Appuyez sur la croix, en haut \x85 droite pour fermer.");
        finLigne(2500);
        finLigne(2500);
        phrase("L'autre droite.");
        finLigne(2500);
        finLigne(2500);
        phrase("Celle qui apparait en rouge quand vous passez dessus.");
        finLigne(1000);
        finLigne(1000);
        finLigne(1000);
        phrase("Putain...");
        finLigne(1000);
        finLigne(1000);
        finLigne(1000);
        phrase("J'ai pass\x82 du temps pour rendre ce jeu impossible \x85 finir.");
        finLigne(2500);
        finLigne(2500);
        phrase("J'ai d\x96 tester ce jeu en cheatant comme un lama pour ne pas mourir comme une merde face aux mannequins ambidextres.");
        finLigne(2500);
        finLigne(2500);
        phrase("Et toi qui arrive, la fleur au fusil.");
        finLigne(2500);
        finLigne(2500);
        phrase("ET QUI LE TERMINE SANS TRICHER !!!!!!!");
        finLigne(2500);
        finLigne(2500);
        phrase("Je sais pas combien de fois tu as du recommencer, mais celle-ci \x82tait de trop.");
        finLigne(2000);
        finLigne(2000);
        finLigne(2000);
        phrase("Enfoir\x82" + accorde("","e",joueurEstMasculin) + ".");
    }

finLigne(500);
finLigne(500);
finLigne(500);

phrase("'Entrer' pour terminer ");

cin.sync();
cin.get();
}

///Permet de ralentir l'affichage pour le rendre moins brusque
void sleep(unsigned milliseconds)
{
    Sleep(milliseconds*1.5);
}

///Saute une ligne et marque un temps d'arrêt
void finLigne(unsigned milliseconds)
{
    sleep(milliseconds);
    cout << endl;
}

///Affiche une phrase avec une attente entre chaque charactère
void phrase(string phrase)
{
    for(unsigned int i = 0;i < phrase.size();i++)
    {
        sleep(20);
        cout << phrase[i];
    }
}

///Affiche un nombre dans une phrase avec le même temps d'attente
///N'affiche pas chiffre par chiffre mais le nombre d'un coup
void nombre(int nombre)
{
        sleep(26);
        cout << nombre;
}

///Affiche une ligne de félicitation décalée par rapport au texte
void felicitations(string mots)
{
    for(unsigned int i = 0;i < mots.size();i++)
    {
        switch(mots[i])
        {
        case '\x82' :
            mots[i] = '\x90';
            break;

        case '\x8A' :
            mots[i] = '\xD4';
            break;

        case '\x85' :
            mots[i] = '\xB7';
            break;

        case '\x88' :
            mots[i] = '\xD2';
            break;

        case '\x93' :
            mots[i] = '\xE2';
            break;

        default :
            mots[i] = toupper(mots[i]);
            break;
        }
    }

    cout << endl;
    sleep(500);
    cout << endl;
    sleep(500);
    cout << endl << "               ";
    sleep(500);
    phrase(mots);
    phrase(" !!!");
    cout << endl;
    sleep(500);
    cout << endl;
    sleep(500);
    cout << endl;
    finLigne(1500);
}

///Lit le dossier de sauvegarde et recherche si le joueur a déjà fini un chapitre
///Seule la dernière sauvegarde est prise en compte
int joueurEstConnu(string nomJoueur, bool joueurEstMasculin)
{
    string ligne, nom = nomJoueur, nomChampion;
    char sortieDuDesert = '0';

    ifstream sauvegardes("sauvegardes.txt");

    if(!sauvegardes)
    {
        return 0;
    }

    while(getline(sauvegardes,ligne))
    {
        nomChampion = "";

        for(int i = 2;ligne[i-1] != '$';i++)
        {
            if(ligne[i] != '$')
            {
                nomChampion += ligne[i];
            }
            else if(ligne[i-1] != '$')
            {
                for(unsigned int j = 0;j < nom.size();j++)
                {
                    nom[j] = tolower(nom[j]);
                }

                for(unsigned int j = 0;j < nomChampion.size();j++)
                {
                    nomChampion[j] = tolower(nomChampion[j]);
                }

                if(nom == nomChampion)
                {
                    if((joueurEstMasculin && ligne[0] == '1') || (!joueurEstMasculin && ligne[0] == '0'))
                    {
                        sortieDuDesert = ligne[i+1];
                    }
                }
            }
        }
    }

    return getChiffre(sortieDuDesert);
}

///Retourne la valeur d'un chiffre de type 'char'
int getChiffre(char lettre)
{
    if(lettre == '0')
    {
        return 0;
    }
    else if(lettre == '1')
    {
        return 1;
    }
    else if(lettre == '2')
    {
        return 2;
    }
    else if(lettre == '3')
    {
        return 3;
    }
    return -1;
}

///Calcul et liste des phrases correspondant aux effets des armes
int ajouteEffet(Arme &arme)
{
    srand(time(0));

    if(rand()%100 < 20)
    {
        switch(arme.getEffet())
        {
        case Enflamme :
            phrase(accorde("Le ","La ",arme.estMasculin()) + arme.getNom() + " est enflamm\x82" + accorde("","e",arme.estMasculin()) + ".");
            finLigne(500);
            return arme.getDegatEffet();
            break;

        case BordPointu :
            phrase(accorde("Le ","La ",arme.estMasculin()) + arme.getNom() + " a un bord tr\x8As pointu.");
            finLigne(500);
            return arme.getDegatEffet();
            break;

        case HuileEssentielle :
            phrase(accorde("Le ","La ",arme.estMasculin()) + arme.getNom() + " est recouvert" + accorde("","e",arme.estMasculin()) + " d'huiles essentielles.");
            finLigne(500);
            return arme.getDegatEffet();
            break;

        case BoutQuiColle :
            phrase(accorde("Le ","La ",arme.estMasculin()) + arme.getNom() + " a le bout qui colle.");
            finLigne(500);
            return arme.getDegatEffet();
            break;

        case Humide :
            phrase(accorde("Le ","La ",arme.estMasculin()) + arme.getNom() + " est humide.");
            finLigne(500);
            return arme.getDegatEffet();
            break;

        case Farci :
            phrase(accorde("Le ","La ",arme.estMasculin()) + arme.getNom() + " est farci" + accorde("","e",arme.estMasculin()) + ".");
            finLigne(500);
            return arme.getDegatEffet();
            break;

        case Communiste :
            phrase(accorde("Le ","La ",arme.estMasculin()) + arme.getNom() + " est communiste.");
            finLigne(500);
            return arme.getDegatEffet();
            break;

        case PartieContondante :
            phrase(accorde("Le ","La ",arme.estMasculin()) + arme.getNom() + " est tenu" + accorde("","e",arme.estMasculin()) + " par la partie contondante pour frapper avec la partie tigeuse.");
            finLigne(500);
            return arme.getDegatEffet();
            break;

        case PasAPas :
            phrase("La truite, ");
            sleep(500);
            phrase("remonte le ruisseau,");
            sleep(500);
            phrase("pas \x85 pas.");
            finLigne(500);
            return arme.getDegatEffet();
            break;

        case DansLesYeux :
            phrase("Ah, ");
            sleep(500);
            phrase("dans les yeux !!");
            finLigne(500);
            return arme.getDegatEffet();
            break;

        case Lisse :
            phrase(accorde("Le ","La ",arme.estMasculin()) + arme.getNom() + " est tr\x8As lisse.");
            finLigne(500);
            return arme.getDegatEffet();
            break;

        case Couleur :
            phrase(accorde("Le ","La ",arme.estMasculin()) + arme.getNom() + " est extr\x8Amement color\x82" + accorde("","e",arme.estMasculin()) + ".");
            finLigne(500);
            return arme.getDegatEffet();
            break;

        case Rougeole :
            phrase(accorde("Le ","La ",arme.estMasculin()) + arme.getNom() + " a la rouge\x93lite a\x8Bg\x96\ae du nourisson albinos.");
            finLigne(500);
            phrase("C'est potentiellement contagieux.");
            finLigne(500);
            return arme.getDegatEffet();
            break;

        case Musicien :
            phrase(accorde("Le ","La ",arme.estMasculin()) + arme.getNom() + " est musicien" + accorde("","ne",arme.estMasculin()) + " \x85 ses heures perdues.");
            finLigne(500);
            return arme.getDegatEffet();
            break;

        default :
            return 0;
            break;
        }
    }
    else
    {
        srand(time(0));

        if(rand()%100 < 20)
        {
            phrase("Coups critique !!");
            finLigne(500);
            return arme.getDegat()/2;
        }
        return 0;
    }
}

///Assigne à chaque case de la grille du Desert une valeur correspondant au type de terrain
void creationDesert(int grilleDesert[][25],string carteDesert[][25][9])
{
    for(int htr = 0;htr <= 24;htr++)
    {
        for(int lgr = 0;lgr <= 24;lgr++)
        {
            grilleDesert[lgr][htr] = Desert;
        }
    }

    ///Création de l'océan
    for(int htr = 20;htr <= 24;htr++)
    {
        for(int lgr = 0;lgr <= 11;lgr++)
        {
            grilleDesert[lgr][htr] = Ocean;
        }
    }

    for(int lgr = 0;lgr <= 6;lgr++)
    {
        grilleDesert[lgr][18] = Ocean;
        grilleDesert[lgr][19] = Ocean;

        for(int htr = 10;htr <= 13;htr++)
        {
            if(lgr <= 2)
            {
                grilleDesert[lgr][htr] = Ocean;
            }

            if(lgr == 3 && htr != 13)
            {
                grilleDesert[lgr][htr] = Ocean;
            }
        }
    }

    for(int htr = 0;htr <= 3;htr++)
    {
        grilleDesert[0][htr] = Ocean;
    }

    for(int lgr = 12;lgr <= 18;lgr++)
    {
        grilleDesert[lgr][0] = Ocean;

        if(lgr <= 16)
        {
            grilleDesert[lgr][1] = Ocean;
        }

        if(lgr == 13 || lgr == 14)
        {
            grilleDesert[lgr][2] = Ocean;
        }
    }

    for(int lgr = 19;lgr <= 24;lgr++)
    {
        for(int htr = 0;htr <= 11;htr++)
        {
            if((lgr == 19 || lgr == 20) && htr <= 4)
            {
                grilleDesert[lgr][htr] = Ocean;
            }

            if(lgr >= 21)
            {
                grilleDesert[lgr][htr] = Ocean;
            }
        }

        if(lgr == 23 || lgr == 24)
        {
            grilleDesert[lgr][18] = Ocean;
            grilleDesert[lgr][19] = Ocean;
            grilleDesert[lgr][20] = Ocean;
        }

        for(int htr = 21;htr <= 24;htr++)
        {
            grilleDesert[lgr][htr] = Ocean;
        }
    }

    grilleDesert[18][23] = Ocean;
    grilleDesert[18][24] = Ocean;
    grilleDesert[20][11] = Ocean;
    grilleDesert[21][20] = Ocean;
    grilleDesert[22][20] = Ocean;
    grilleDesert[24][12] = Ocean;

    ///Création des plages
        ///Ouest
    for(int htr = 5;htr <= 8;htr++)
    {
        grilleDesert[0][htr] = PlageO;
    }

    for(int htr = 20;htr <= 23;htr++)
    {
        grilleDesert[12][htr] = PlageO;
    }

    grilleDesert[1][1] = PlageO;
    grilleDesert[1][2] = PlageO;
    grilleDesert[1][3] = PlageO;
    grilleDesert[4][10] = PlageO;
    grilleDesert[4][11] = PlageO;
    grilleDesert[4][12] = PlageO;
    grilleDesert[7][18] = PlageO;

        ///Sud
    grilleDesert[1][9] = PlageS;
    grilleDesert[2][9] = PlageS;
    grilleDesert[3][9] = PlageS;

    for(int lgr = 8;lgr <= 11;lgr++)
    {
        grilleDesert[lgr][19] = PlageS;
    }

    for(int lgr = 13;lgr <= 16;lgr++)
    {
        grilleDesert[lgr][24] = PlageS;
    }

        ///Est
    grilleDesert[11][1] = PlageE;
    grilleDesert[17][23] = PlageE;

    for(int htr = 2;htr <= 9;htr++)
    {
        if(htr <= 4)
        {
            grilleDesert[18][htr] = PlageE;
        }
        else if(htr >= 6)
        {
            grilleDesert[20][htr] = PlageE;
        }
    }

        ///Nord
    for(int lgr = 2;lgr <= 10;lgr++)
    {
        grilleDesert[lgr][0] = PlageN;
    }

    grilleDesert[13][3] = PlageN;
    grilleDesert[14][3] = PlageN;
    grilleDesert[16][2] = PlageN;
    grilleDesert[19][5] = PlageN;

        ///Nord-Ouest
    grilleDesert[0][4] = PlageNO;
    grilleDesert[1][0] = PlageNO;
    grilleDesert[15][2] = PlageNO;
    grilleDesert[17][1] = PlageNO;

        ///Nord-Est
    grilleDesert[11][0] = PlageNE;
    grilleDesert[12][2] = PlageNE;
    grilleDesert[18][1] = PlageNE;
    grilleDesert[20][5] = PlageNE;

        ///Sud-Est
    grilleDesert[17][24] = PlageSE;
    grilleDesert[20][10] = PlageSE;

        ///Sud-Ouest
    grilleDesert[0][9] = PlageSO;
    grilleDesert[7][19] = PlageSO;
    grilleDesert[12][24] = PlageSO;

    ///Création des parois
        ///Ouest

        ///Sud
    grilleDesert[1][16] = ParoiS;
    grilleDesert[2][16] = ParoiS;
    grilleDesert[3][16] = ParoiS;
    grilleDesert[5][17] = ParoiS;
    grilleDesert[6][17] = ParoiS;
    grilleDesert[19][20] = ParoiS;
    grilleDesert[21][19] = ParoiS;
    grilleDesert[23][17] = ParoiS;

        ///Est
    grilleDesert[18][21] = ParoiE;
    grilleDesert[19][11] = ParoiE;
    grilleDesert[22][18] = ParoiE;

        ///Nord
    grilleDesert[1][14] = ParoiN;
    grilleDesert[2][14] = ParoiN;
    grilleDesert[20][12] = ParoiN;
    grilleDesert[21][12] = ParoiN;
    grilleDesert[22][12] = ParoiN;

        ///Nord-Ouest
    grilleDesert[0][14] = ParoiNO;
    grilleDesert[3][13] = ParoiNO;

        ///Nord-Est
    grilleDesert[23][12] = ParoiNE;
    grilleDesert[24][13] = ParoiNE;

        ///Sud-Est
    grilleDesert[18][22] = ParoiSE;
    grilleDesert[20][20] = ParoiSE;
    grilleDesert[22][19] = ParoiSE;
    grilleDesert[24][17] = ParoiSE;

        ///Sud-Ouest
    grilleDesert[0][16] = ParoiSO;
    grilleDesert[4][17] = ParoiSO;

    ///Création des côtes
    for(int lgr = 2;lgr <= 16;lgr++)
    {
        if(lgr <= 10)
        {
            grilleDesert[lgr][1] = Cote;
        }
        else if(lgr == 11 || lgr == 12)
        {
            grilleDesert[lgr][3] = Cote;
        }
        else if(lgr >= 15)
        {
            grilleDesert[lgr][3] = Cote;
        }
    }

    for(int htr = 4;htr <= 8;htr++)
    {
        grilleDesert[1][htr] = Cote;
    }

    for(int htr = 9;htr <= 12;htr++)
    {
        grilleDesert[5][htr] = Cote;
    }

    for(int htr = 2;htr <= 10;htr++)
    {
        if(htr <= 4)
        {
            grilleDesert[17][htr] = Cote;
        }
        else if(htr == 5)
        {
            grilleDesert[17][htr] = Cote;
            grilleDesert[18][htr] = Cote;
        }
        else if(htr == 6)
        {
            grilleDesert[18][htr] = Cote;
            grilleDesert[19][htr] = Cote;
        }
        else if(htr >= 7)
        {
            grilleDesert[19][htr] = Cote;
        }
    }

    for(int lgr = 7;lgr <= 16;lgr++)
    {
        if(lgr == 7)
        {
            grilleDesert[lgr][17] = Cote;
        }
        else if(lgr <= 11)
        {
            grilleDesert[lgr][18] = Cote;
        }
        else if(lgr == 12)
        {
            grilleDesert[lgr][18] = Cote;
            grilleDesert[lgr][19] = Cote;
        }
        else if(lgr == 13)
        {
            for(int htr = 19;htr <= 23;htr++)
            {
                grilleDesert[lgr][htr] = Cote;
            }
        }
        else if(lgr >= 14)
        {
            grilleDesert[lgr][23] = Cote;
        }
    }

    for(int lgr = 12;lgr <= 15;lgr++)
    {
        grilleDesert[lgr][4] = Cote;
    }

    grilleDesert[1][4] = CoteNO;
    grilleDesert[2][2] = Cote;
    grilleDesert[2][3] = Cote;
    grilleDesert[2][4] = Cote;
    grilleDesert[4][9] = Cote;
    grilleDesert[2][8] = Cote;
    grilleDesert[3][8] = Cote;
    grilleDesert[4][8] = Cote;
    grilleDesert[4][9] = CoteSO;
    grilleDesert[4][13] = CoteNO;
    grilleDesert[5][13] = Cote;
    grilleDesert[7][17] = CoteSO;
    grilleDesert[8][17] = Cote;
    grilleDesert[10][2] = Cote;
    grilleDesert[11][2] = CoteNE;
    grilleDesert[12][3] = CoteNE;
    grilleDesert[12][19] = CoteSO;
    grilleDesert[15][3] = CoteNO;
    grilleDesert[16][22] = Cote;
    grilleDesert[17][2] = CoteNO;
    grilleDesert[17][22] = Cote;
    grilleDesert[18][5] = CoteNE;

    ///Création des angles de paroi
        ///Nord-Ouest
    grilleDesert[3][14] = AngleNO;

        ///Nord-Est
    grilleDesert[19][12] = AngleNE;
    grilleDesert[23][13] = AngleNE;

        ///Sud-Est
    grilleDesert[18][20] = AngleSE;
    grilleDesert[20][19] = AngleSE;
    grilleDesert[22][17] = AngleSE;

        ///Sud-Ouest
    grilleDesert[4][16] = AngleSO;

    ///Création de l'oasis
    grilleDesert[12][12] = Oasis;
    grilleDesert[13][12] = Palmier;

    ///Création du campement de bandit
    grilleDesert[5][4] = Camp;
    grilleDesert[6][4] = Camp;

    ///Création de la frontière
    grilleDesert[24][14] = Frontiere;
    grilleDesert[24][15] = Frontiere;
    grilleDesert[24][16] = Frontiere;

    ///Initialisation de la carte
    for(int lgr = 0;lgr <= 24;lgr++)
    {
        for(int htr = 0;htr <= 24;htr++)
        {
            for(int i = 0;i <= 8;i++)
            {
                carteDesert[lgr][htr][i] = " ";
            }
        }
    }

}
void creationMarai(int grilleMarai[][25], string carteMarai[][25][9])
{
    ///Création du marai
    for(int lgr = 0;lgr <= 24;lgr++)
    {
        for(int htr = 0;htr <= 24;htr++)
        {
            grilleMarai[lgr][htr] = Marai;
        }
    }

    ///Création du bourbier
    for(int htr = 2;htr <= 7;htr++)
    {
        grilleMarai[0][htr] = Bourbier;
        grilleMarai[1][htr] = Bourbier;
    }

    grilleMarai[0][8] = Bourbier;
    grilleMarai[2][2] = Bourbier;
    grilleMarai[3][2] = Bourbier;

    for(int lgr = 0;lgr <= 15;lgr++)
    {
        grilleMarai[lgr][0] = Bourbier;
        grilleMarai[lgr][1] = Bourbier;

        if(lgr >= 9 && lgr != 15)
        {
            grilleMarai[lgr][2] = Bourbier;
        }
    }

    grilleMarai[10][3] = Bourbier;
    grilleMarai[11][3] = Bourbier;
    grilleMarai[11][4] = Bourbier;
    grilleMarai[16][0] = Bourbier;

    for(int htr = 0;htr <= 7;htr++)
    {
        if(htr != 2 && htr != 3 && htr != 7)
        {
            grilleMarai[23][htr] = Bourbier;
        }

        grilleMarai[24][htr] = Bourbier;
    }

    grilleMarai[21][0] = Bourbier;
    grilleMarai[22][0] = Bourbier;
    grilleMarai[22][6] = Bourbier;

    for(int htr = 12;htr <= 24 ;htr++)
    {
        for(int lgr = 22;lgr <= 24;lgr++)
        {
            if(lgr == 22 && htr <= 22 && htr >= 16)
            {

            }
            else
            {
                grilleMarai[lgr][htr] = Bourbier;
            }
        }
    }

    grilleMarai[21][24] = Bourbier;
    grilleMarai[22][23] = Bourbier;
    grilleMarai[22][24] = Bourbier;
    grilleMarai[24][11] = Bourbier;

    for(int lgr = 10;lgr <= 14;lgr++)
    {
        grilleMarai[lgr][21] = Bourbier;
    }

    for(int lgr = 9;lgr <= 15;lgr++)
    {
        grilleMarai[lgr][22] = Bourbier;
    }

    for(int lgr = 8;lgr <= 15;lgr++)
    {
        grilleMarai[lgr][23] = Bourbier;
    }

    for(int lgr = 7;lgr <= 17;lgr++)
    {
        grilleMarai[lgr][24] = Bourbier;
    }

    grilleMarai[11][20] = Bourbier;
    grilleMarai[12][20] = Bourbier;

    for(int htr = 14;htr <= 24;htr++)
    {
        grilleMarai[0][htr] = Bourbier;

        if(htr >= 16)
        {
            grilleMarai[1][htr] = Bourbier;
        }
    }

    grilleMarai[2][23] = Bourbier;
    grilleMarai[2][24] = Bourbier;
    grilleMarai[3][24] = Bourbier;

    ///Création du lac
    for(int lgr = 9;lgr <= 16;lgr++)
    {
        for(int htr = 14;htr <= 17;htr++)
        {
            grilleMarai[lgr][htr] = Lac;
        }

        if(lgr != 16)
        {
            grilleMarai[lgr][18] = Lac;
        }
    }

    grilleMarai[7][16] = Lac;
    grilleMarai[7][17] = Lac;
    grilleMarai[8][15] = Lac;
    grilleMarai[8][16] = Lac;
    grilleMarai[8][17] = Lac;
    grilleMarai[13][13] = Lac;
    grilleMarai[14][13] = Lac;
    grilleMarai[15][13] = Lac;

    ///Création de la cabane
    grilleMarai[10][4] = Cabane;

    ///Création de la tour
    grilleMarai[13][15] = TourHaut;
    grilleMarai[13][16] = TourBas;

    ///Création des pontons
    for(int lgr = 0;lgr <= 24;lgr++)
    {
        if(lgr == 0)
        {
            grilleMarai[lgr][10] = Ponton;
            grilleMarai[lgr][11] = Ponton;
            grilleMarai[lgr][12] = Ponton;
        }
        else if(lgr <= 6)
        {
            grilleMarai[lgr][11] = Ponton;
        }
        else if(lgr == 7)
        {
            grilleMarai[lgr][11] = Ponton;
            grilleMarai[lgr][10] = Ponton;
        }
        else if(lgr <= 9)
        {
            grilleMarai[lgr][10] = Ponton;
        }
        else if(lgr == 10)
        {
            grilleMarai[lgr][9] = Ponton;
            grilleMarai[lgr][10] = Ponton;
        }
        else if(lgr <= 21)
        {
            grilleMarai[lgr][9] = Ponton;
        }
        else
        {
            grilleMarai[lgr][8] = Ponton;
            grilleMarai[lgr][9] = Ponton;
            grilleMarai[lgr][10] = Ponton;
        }
    }

    grilleMarai[6][16] = Ponton;
    grilleMarai[7][15] = Ponton;
    grilleMarai[9][4] = Ponton;
    grilleMarai[10][5] = Ponton;

    ///Création de la barque
    grilleMarai[7][16] = Barque;

    ///Création des roseaux
        ///Simples
    for(int htr = 9;htr <= 13;htr++)
    {
        if(htr != 11)
        {
            grilleMarai[1][htr] = Roseau;
        }
    }

    grilleMarai[2][8] = Roseau;
    grilleMarai[4][3] = Roseau;
    grilleMarai[8][3] = Roseau;
    grilleMarai[12][5] = Roseau;
    grilleMarai[15][3] = Roseau;
    grilleMarai[16][2] = Roseau;
    grilleMarai[17][1] = Roseau;
    grilleMarai[20][1] = Roseau;
    grilleMarai[20][23] = Roseau;
    grilleMarai[21][5] = Roseau;
    grilleMarai[21][7] = Roseau;
    grilleMarai[21][11] = Roseau;
    grilleMarai[21][16] = Roseau;
    grilleMarai[21][22] = Roseau;
    grilleMarai[22][2] = Roseau;
    grilleMarai[22][3] = Roseau;
    grilleMarai[18][23] = Roseau;
    grilleMarai[16][22] = Roseau;
    grilleMarai[15][20] = Roseau;
    grilleMarai[9][20] = Roseau;
    grilleMarai[8][21] = Roseau;
    grilleMarai[7][22] = Roseau;
    grilleMarai[6][23] = Roseau;
    grilleMarai[4][23] = Roseau;
    grilleMarai[3][22] = Roseau;
    grilleMarai[2][15] = Roseau;
    grilleMarai[2][12] = Roseau;
    grilleMarai[3][10] = Roseau;
    grilleMarai[3][12] = Roseau;
    grilleMarai[4][10] = Roseau;
    grilleMarai[6][10] = Roseau;
    grilleMarai[7][12] = Roseau;
    grilleMarai[8][9] = Roseau;
    grilleMarai[9][9] = Roseau;
    grilleMarai[10][11] = Roseau;

    for(int lgr = 11;lgr <= 14;lgr++)
    {
        grilleMarai[lgr][8] = Roseau;
    }

    grilleMarai[13][10] = Roseau;
    grilleMarai[14][10] = Roseau;
    grilleMarai[15][10] = Roseau;
    grilleMarai[16][8] = Roseau;
    grilleMarai[17][10] = Roseau;
    grilleMarai[18][10] = Roseau;
    grilleMarai[19][8] = Roseau;

        ///Nord
    grilleMarai[0][9] = RoseauN;
    grilleMarai[3][3] = RoseauN;
    grilleMarai[5][2] = RoseauN;
    grilleMarai[6][2] = RoseauN;
    grilleMarai[7][2] = RoseauN;
    grilleMarai[11][5] = RoseauN;
    grilleMarai[13][3] = RoseauN;
    grilleMarai[14][3] = RoseauN;
    grilleMarai[18][0] = RoseauN;
    grilleMarai[19][0] = RoseauN;
    grilleMarai[21][1] = RoseauN;
    grilleMarai[22][7] = RoseauN;
    grilleMarai[23][7] = RoseauN;
    grilleMarai[24][7] = RoseauN;

        ///Est
    grilleMarai[22][4] = RoseauE;
    grilleMarai[21][6] = RoseauE;

    for(int htr = 12;htr <= 21;htr++)
    {
        if(htr <= 15)
        {
            grilleMarai[21][htr] = RoseauE;
        }
        else if(htr >= 17)
        {
            grilleMarai[22][htr] = RoseauE;
        }
    }

        ///Sud
    grilleMarai[24][11] = RoseauS;
    grilleMarai[23][11] = RoseauS;
    grilleMarai[22][11] = RoseauS;
    grilleMarai[19][24] = RoseauS;
    grilleMarai[17][23] = RoseauS;
    grilleMarai[14][20] = RoseauS;
    grilleMarai[0][13] = RoseauS;
    grilleMarai[5][24] = RoseauS;

        ///Ouest
    for(int htr = 4;htr <= 21;htr++)
    {
        if(htr <= 7)
        {
            grilleMarai[2][htr] = RoseauO;
        }
        else if(htr >= 16)
        {
            grilleMarai[2][htr] = RoseauO;
        }
    }

    grilleMarai[12][4] = RoseauO;
    grilleMarai[15][21] = RoseauO;
    grilleMarai[1][14] = RoseauO;

        ///Nord-Est
    grilleMarai[8][2] = RoseauNE;
    grilleMarai[9][3] = RoseauNE;
    grilleMarai[20][0] = RoseauNE;
    grilleMarai[22][1] = RoseauNE;
    grilleMarai[23][2] = RoseauNE;
    grilleMarai[22][16] = RoseauNE;

        ///Nord-Ouest
    grilleMarai[1][8] = RoseauNO;
    grilleMarai[2][3] = RoseauNO;
    grilleMarai[4][2] = RoseauNO;
    grilleMarai[12][3] = RoseauNO;
    grilleMarai[15][2] = RoseauNO;
    grilleMarai[16][1] = RoseauNO;
    grilleMarai[17][0] = RoseauNO;

        ///Sud-Ouest
    grilleMarai[18][24] = RoseauSO;
    grilleMarai[16][23] = RoseauSO;
    grilleMarai[15][22] = RoseauSO;
    grilleMarai[13][20] = RoseauSO;
    grilleMarai[4][24] = RoseauSO;
    grilleMarai[3][23] = RoseauSO;
    grilleMarai[2][22] = RoseauSO;
    grilleMarai[1][15] = RoseauSO;

        ///Sud-Est
    grilleMarai[23][3] = RoseauSE;
    grilleMarai[22][5] = RoseauSE;
    grilleMarai[22][22] = RoseauSE;
    grilleMarai[21][23] = RoseauSE;
    grilleMarai[20][24] = RoseauSE;
    grilleMarai[10][20] = RoseauSE;
    grilleMarai[9][21] = RoseauSE;
    grilleMarai[8][22] = RoseauSE;
    grilleMarai[7][23] = RoseauSE;
    grilleMarai[6][24] = RoseauSE;

        ///Nord-Sud
    grilleMarai[11][19] = RoseauNS;
    grilleMarai[12][19] = RoseauNS;

    ///Initialisation de la carte
    for(int lgr = 0;lgr <= 24;lgr++)
    {
        for(int htr = 0;htr <= 24;htr++)
        {
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = " ";
            }
        }
    }
}
void creationTour(int grilleTourBas[][20], int grilleTourHaut[][20], string carteTourBas[][20][9], string carteTourHaut[][20][9])
{
    for(int lgr = 0;lgr <= 19;lgr++)
    {
        for(int htr = 0;htr <= 19;htr++)
        {
            grilleTourBas[lgr][htr] = Vide;
            grilleTourHaut[lgr][htr] = Vide;
        }
    }

    ///Création du sol
    for(int lgr = 0;lgr <= 19;lgr++)
    {
        grilleTourBas[lgr][9] = Dalle;
        grilleTourHaut[lgr][9] = Dalle;
        grilleTourBas[lgr][10] = Dalle;
        grilleTourHaut[lgr][10] = Dalle;
    }

    for(int htr = 1;htr <= 19;htr++)
    {
        grilleTourBas[9][htr] = Dalle;
        grilleTourHaut[9][htr] = Dalle;
        grilleTourBas[10][htr] = Dalle;
        grilleTourHaut[10][htr] = Dalle;
    }

    ///Création des colonnes
        ///Petites colonnes
    for(int lgr = 0;lgr <= 19;lgr+=2)
    {
        if(lgr == 10)
        {
            lgr++;
        }
        grilleTourBas[lgr][8] = PetiteColonne;
        grilleTourHaut[lgr][8] = PetiteColonne;
        grilleTourBas[lgr][11] = PetiteColonne;
        grilleTourHaut[lgr][11] = PetiteColonne;
    }

    for(int htr = 0;htr <= 19;htr+=2)
    {
        if(htr == 10)
        {
            htr++;
        }
        grilleTourBas[8][htr] = PetiteColonne;
        grilleTourHaut[8][htr] = PetiteColonne;
        grilleTourBas[11][htr] = PetiteColonne;
        grilleTourHaut[11][htr] = PetiteColonne;
    }

    grilleTourBas[6][6] = PetiteColonne;
    grilleTourHaut[6][6] = PetiteColonne;
    grilleTourBas[7][7] = PetiteColonne;
    grilleTourHaut[7][7] = PetiteColonne;
    grilleTourBas[12][7] = PetiteColonne;
    grilleTourHaut[12][7] = PetiteColonne;
    grilleTourBas[7][12] = PetiteColonne;
    grilleTourHaut[7][12] = PetiteColonne;
    grilleTourBas[6][13] = PetiteColonne;
    grilleTourHaut[6][13] = PetiteColonne;
    grilleTourBas[13][6] = PetiteColonne;
    grilleTourHaut[13][6] = PetiteColonne;
    grilleTourBas[12][12] = PetiteColonne;
    grilleTourHaut[12][12] = PetiteColonne;
    grilleTourBas[13][13] = PetiteColonne;
    grilleTourHaut[13][13] = PetiteColonne;

        ///Grandes colonnes
            ///Nord-Est
    grilleTourBas[1][0] = GrandeColonneNE;
    grilleTourHaut[1][0] = GrandeColonneNE;
    grilleTourBas[3][2] = GrandeColonneNE;
    grilleTourHaut[3][2] = GrandeColonneNE;
    grilleTourBas[5][4] = GrandeColonneNE;
    grilleTourHaut[5][4] = GrandeColonneNE;
    grilleTourBas[15][4] = GrandeColonneNE;
    grilleTourHaut[15][4] = GrandeColonneNE;
    grilleTourBas[17][2] = GrandeColonneNE;
    grilleTourHaut[17][2] = GrandeColonneNE;
    grilleTourBas[19][0] = GrandeColonneNE;
    grilleTourHaut[19][0] = GrandeColonneNE;
    grilleTourBas[1][18] = GrandeColonneNE;
    grilleTourHaut[1][18] = GrandeColonneNE;
    grilleTourBas[3][16] = GrandeColonneNE;
    grilleTourHaut[3][16] = GrandeColonneNE;
    grilleTourBas[5][14] = GrandeColonneNE;
    grilleTourHaut[5][14] = GrandeColonneNE;
    grilleTourBas[15][14] = GrandeColonneNE;
    grilleTourHaut[15][14] = GrandeColonneNE;
    grilleTourBas[17][16] = GrandeColonneNE;
    grilleTourHaut[17][16] = GrandeColonneNE;
    grilleTourBas[19][18] = GrandeColonneNE;
    grilleTourHaut[19][18] = GrandeColonneNE;

            ///Nord-Ouest
    grilleTourBas[0][0] = GrandeColonneNO;
    grilleTourHaut[0][0] = GrandeColonneNO;
    grilleTourBas[2][2] = GrandeColonneNO;
    grilleTourHaut[2][2] = GrandeColonneNO;
    grilleTourBas[4][4] = GrandeColonneNO;
    grilleTourHaut[4][4] = GrandeColonneNO;
    grilleTourBas[14][4] = GrandeColonneNO;
    grilleTourHaut[14][4] = GrandeColonneNO;
    grilleTourBas[16][2] = GrandeColonneNO;
    grilleTourHaut[16][2] = GrandeColonneNO;
    grilleTourBas[18][0] = GrandeColonneNO;
    grilleTourHaut[18][0] = GrandeColonneNO;
    grilleTourBas[0][18] = GrandeColonneNO;
    grilleTourHaut[0][18] = GrandeColonneNO;
    grilleTourBas[2][16] = GrandeColonneNO;
    grilleTourHaut[2][16] = GrandeColonneNO;
    grilleTourBas[4][14] = GrandeColonneNO;
    grilleTourHaut[4][14] = GrandeColonneNO;
    grilleTourBas[14][14] = GrandeColonneNO;
    grilleTourHaut[14][14] = GrandeColonneNO;
    grilleTourBas[16][16] = GrandeColonneNO;
    grilleTourHaut[16][16] = GrandeColonneNO;
    grilleTourBas[18][18] = GrandeColonneNO;
    grilleTourHaut[18][18] = GrandeColonneNO;

            ///Sud-Ouest
    grilleTourBas[0][1] = GrandeColonneSO;
    grilleTourHaut[0][1] = GrandeColonneSO;
    grilleTourBas[2][3] = GrandeColonneSO;
    grilleTourHaut[2][3] = GrandeColonneSO;
    grilleTourBas[4][5] = GrandeColonneSO;
    grilleTourHaut[4][5] = GrandeColonneSO;
    grilleTourBas[14][5] = GrandeColonneSO;
    grilleTourHaut[14][5] = GrandeColonneSO;
    grilleTourBas[16][3] = GrandeColonneSO;
    grilleTourHaut[16][3] = GrandeColonneSO;
    grilleTourBas[18][1] = GrandeColonneSO;
    grilleTourHaut[18][1] = GrandeColonneSO;
    grilleTourBas[0][19] = GrandeColonneSO;
    grilleTourHaut[0][19] = GrandeColonneSO;
    grilleTourBas[2][17] = GrandeColonneSO;
    grilleTourHaut[2][17] = GrandeColonneSO;
    grilleTourBas[4][15] = GrandeColonneSO;
    grilleTourHaut[4][15] = GrandeColonneSO;
    grilleTourBas[14][15] = GrandeColonneSO;
    grilleTourHaut[14][15] = GrandeColonneSO;
    grilleTourBas[16][17] = GrandeColonneSO;
    grilleTourHaut[16][17] = GrandeColonneSO;
    grilleTourBas[18][19] = GrandeColonneSO;
    grilleTourHaut[18][19] = GrandeColonneSO;

            ///Sud-Est
    grilleTourBas[1][1] = GrandeColonneSE;
    grilleTourHaut[1][1] = GrandeColonneSE;
    grilleTourBas[3][3] = GrandeColonneSE;
    grilleTourHaut[3][3] = GrandeColonneSE;
    grilleTourBas[5][5] = GrandeColonneSE;
    grilleTourHaut[5][5] = GrandeColonneSE;
    grilleTourBas[5][15] = GrandeColonneSE;
    grilleTourHaut[5][15] = GrandeColonneSE;
    grilleTourBas[3][17] = GrandeColonneSE;
    grilleTourHaut[3][17] = GrandeColonneSE;
    grilleTourBas[1][19] = GrandeColonneSE;
    grilleTourHaut[1][19] = GrandeColonneSE;
    grilleTourBas[15][5] = GrandeColonneSE;
    grilleTourHaut[15][5] = GrandeColonneSE;
    grilleTourBas[17][3] = GrandeColonneSE;
    grilleTourHaut[17][3] = GrandeColonneSE;
    grilleTourBas[19][1] = GrandeColonneSE;
    grilleTourHaut[19][1] = GrandeColonneSE;
    grilleTourBas[15][15] = GrandeColonneSE;
    grilleTourHaut[15][15] = GrandeColonneSE;
    grilleTourBas[17][17] = GrandeColonneSE;
    grilleTourHaut[17][17] = GrandeColonneSE;
    grilleTourBas[19][19] = GrandeColonneSE;
    grilleTourHaut[19][19] = GrandeColonneSE;

    ///Création des escaliers
    grilleTourBas[9][0] = Escalier;
    grilleTourHaut[9][0] = Escalier;
    grilleTourBas[10][0] = Escalier;
    grilleTourHaut[10][0] = Escalier;

    ///Création du haut de la tour
    ///Création des passerelles
    grilleTourHaut[6][11] = PasserelleAngleNONE;
    grilleTourHaut[8][17] = PasserelleAngleNE;
    grilleTourHaut[9][18] = PasserelleAngleSO;
    grilleTourHaut[10][5] = PasserelleAngleNESO;
    grilleTourHaut[10][18] = PasserelleAngleSE;
    grilleTourHaut[11][6] = Passerelle;
    grilleTourHaut[11][17] = PasserelleAngleNO;

        ///Nord
    grilleTourHaut[3][18] = PasserelleN;
    grilleTourHaut[6][6] = PasserelleNAngleSOSE;
    grilleTourHaut[9][17] = PasserelleN;
    grilleTourHaut[10][17] = PasserelleN;
    grilleTourHaut[11][5] = PasserelleN;
    grilleTourHaut[12][5] = PasserelleNAngleSE;

        ///Sud
    grilleTourHaut[2][3] = PasserelleSAngleNONE;
    grilleTourHaut[3][19] = PasserelleS;
    grilleTourHaut[5][6] = PasserelleSAngleNONE;
    grilleTourHaut[6][12] = PasserelleS;
    grilleTourHaut[8][18] = PasserelleS;
    grilleTourHaut[9][2] = PasserelleSAngleNO;
    grilleTourHaut[10][2] = PasserelleSAngleNE;
    grilleTourHaut[11][7] = PasserelleS;
    grilleTourHaut[11][18] = PasserelleS;

        ///Est
    grilleTourHaut[1][9] = PasserelleEAngleNO;
    grilleTourHaut[1][10] = PasserelleEAngleSO;
    grilleTourHaut[10][1] = PasserelleE;
    grilleTourHaut[12][6] = PasserelleE;
    grilleTourHaut[12][17] = PasserelleE;
    grilleTourHaut[12][18] = PasserelleEAngleSO;
    grilleTourHaut[13][2] = PasserelleEAngleNOSO;
    grilleTourHaut[16][7] = PasserelleEAngleNO;

        ///Ouest
    grilleTourHaut[2][18] = PasserelleOAngleNE;
    grilleTourHaut[7][17] = PasserelleO;
    grilleTourHaut[9][1] = PasserelleO;
    grilleTourHaut[13][4] = PasserelleOAngleNESE;
    grilleTourHaut[10][6] = PasserelleO;
    grilleTourHaut[18][9] = PasserelleOAngleNE;
    grilleTourHaut[18][10] = PasserelleOAngleSE;

        ///Nord-Est
    grilleTourHaut[2][17] = PasserelleNE;
    grilleTourHaut[3][3] = PasserelleNEAngleSO;
    grilleTourHaut[4][18] = PasserelleNE;
    grilleTourHaut[5][1] = PasserelleNEAngleSO;
    grilleTourHaut[7][11] = PasserelleNE;
    grilleTourHaut[8][16] = PasserelleNE;
    grilleTourHaut[10][4] = PasserelleNE;
    grilleTourHaut[12][16] = PasserelleNE;
    grilleTourHaut[16][4] = PasserelleNEAngleSO;
    grilleTourHaut[17][1] = PasserelleNEAngleSO;
    grilleTourHaut[18][2] = PasserelleNEAngleSO;
    grilleTourHaut[19][9] = PasserelleNE;
    grilleTourHaut[19][13] = PasserelleNEAngleSO;

        ///Nord-Ouest
    grilleTourHaut[0][9] = PasserelleNO;
    grilleTourHaut[0][12] = PasserelleNOAngleSE;
    grilleTourHaut[1][3] = PasserelleNOAngleSE;
    grilleTourHaut[2][1] = PasserelleNOAngleSE;
    grilleTourHaut[5][11] = PasserelleNO;
    grilleTourHaut[7][2] = PasserelleNOAngleSE;
    grilleTourHaut[7][16] = PasserelleNO;
    grilleTourHaut[9][4] = PasserelleNO;
    grilleTourHaut[11][16] = PasserelleNO;
    grilleTourHaut[13][1] = PasserelleNOAngleSE;
    grilleTourHaut[15][7] = PasserelleNO;
    grilleTourHaut[17][17] = PasserelleNOAngleSE;

        ///Sud-Ouest
    grilleTourHaut[0][10] = PasserelleSO;
    grilleTourHaut[0][17] = PasserelleSOAngleNE;
    grilleTourHaut[2][19] = PasserelleSO;
    grilleTourHaut[3][6] = PasserelleSOAngleNE;
    grilleTourHaut[5][12] = PasserelleSO;
    grilleTourHaut[7][18] = PasserelleSO;
    grilleTourHaut[9][5] = PasserelleSO;
    grilleTourHaut[9][19] = PasserelleSO;
    grilleTourHaut[10][7] = PasserelleSO;
    grilleTourHaut[12][19] = PasserelleSOAngleNE;
    grilleTourHaut[15][8] = PasserelleSO;
    grilleTourHaut[17][2] = PasserelleSOAngleNE;
    grilleTourHaut[18][13] = PasserelleSOAngleNE;

        ///Sud-Est
    grilleTourHaut[1][12] = PasserelleSEAngleNO;
    grilleTourHaut[4][19] = PasserelleSE;
    grilleTourHaut[7][6] = PasserelleSEAngleNO;
    grilleTourHaut[7][12] = PasserelleSE;
    grilleTourHaut[10][19] = PasserelleSE;
    grilleTourHaut[12][7] = PasserelleSE;
    grilleTourHaut[13][5] = PasserelleSEAngleNO;
    grilleTourHaut[16][8] = PasserelleSE;
    grilleTourHaut[17][19] = PasserelleSEAngleNO;
    grilleTourHaut[19][10] = PasserelleSE;
    grilleTourHaut[19][17] = PasserelleSEAngleNO;

        ///Nord-Sud
    grilleTourHaut[1][17] = PasserelleNS;
    grilleTourHaut[3][1] = PasserelleNS;
    grilleTourHaut[4][1] = PasserelleNS;
    grilleTourHaut[4][6] = PasserelleNS;
    grilleTourHaut[8][2] = PasserelleNS;
    grilleTourHaut[11][2] = PasserelleNS;
    grilleTourHaut[12][2] = PasserelleNS;
    grilleTourHaut[18][17] = PasserelleNS;

    for(int lgr = 13;lgr <= 16;lgr++)
    {
        grilleTourHaut[lgr][19] = PasserelleNS;

        if(lgr >= 14)
        {
            grilleTourHaut[lgr][1] = PasserelleNS;

            if(lgr != 16)
            {
                grilleTourHaut[lgr][4] = PasserelleNS;
            }
        }
    }

        ///Est-Ouest
    for(int htr = 4;htr <= 16;htr++)
    {
        if(htr <= 8)
        {
            grilleTourHaut[1][htr] = PasserelleEO;
            grilleTourHaut[18][htr] = PasserelleEO;
        }
        else if(htr >= 14)
        {
            grilleTourHaut[0][htr] = PasserelleEO;
            grilleTourHaut[19][htr] = PasserelleEO;
        }
    }

    for(int htr = 2;htr <= 10;htr++)
    {
        if(htr <= 5)
        {
            grilleTourHaut[5][htr] = PasserelleEO;

            if(htr >= 3)
            {
                grilleTourHaut[7][htr] = PasserelleEO;
            }
        }
        else if(htr >= 7)
        {
            grilleTourHaut[6][htr] = PasserelleEO;
        }
    }

    grilleTourHaut[0][13] = PasserelleEO;
    grilleTourHaut[1][11] = PasserelleEO;
    grilleTourHaut[2][2] = PasserelleEO;
    grilleTourHaut[3][4] = PasserelleEO;
    grilleTourHaut[3][5] = PasserelleEO;
    grilleTourHaut[13][3] = PasserelleEO;
    grilleTourHaut[16][5] = PasserelleEO;
    grilleTourHaut[16][6] = PasserelleEO;
    grilleTourHaut[17][18] = PasserelleEO;
    grilleTourHaut[18][3] = PasserelleEO;
    grilleTourHaut[18][11] = PasserelleEO;
    grilleTourHaut[18][12] = PasserelleEO;

}
void creationArchipel(int grilleArchipel[][30], string carteArchipel[][30][9])
{
    int lgrMin, lgrMax;

    ///Création de l'océan
    for(int lgr = 0;lgr <= 29;lgr++)
    {
        for(int htr = 0;htr <= 29;htr++)
        {
            grilleArchipel[lgr][htr] = Ocean;
        }
    }

    ///Création des côtes
    for(int lgr = 0;lgr <= 4;lgr++)
    {
        grilleArchipel[lgr][2] = Cote;
        grilleArchipel[lgr][3] = Cote;
        grilleArchipel[lgr][4] = Cote;
    }

    for(int lgr = 2;lgr <= 5;lgr++)
    {
        grilleArchipel[lgr][9] = Cote;
        grilleArchipel[lgr][10] = Cote;
        grilleArchipel[lgr][11] = Cote;
    }

    for(int lgr = 8;lgr <= 13;lgr++)
    {
        grilleArchipel[lgr][7] = Cote;
    }

    for(int lgr = 12;lgr <= 19;lgr++)
    {
        if(lgr <= 16)
        {
            grilleArchipel[lgr][6] = Cote;
        }
        if(lgr >= 16)
        {
            grilleArchipel[lgr][3] = Cote;
        }
    }
    for(int lgr = 21;lgr <= 25;lgr++)
    {
        grilleArchipel[lgr][9] = Cote;
        grilleArchipel[lgr][10] = Cote;
    }

    for(int lgr = 11;lgr <= 21;lgr++)
    {
        for(int htr = 18;htr <= 28;htr++)
        {
            grilleArchipel[lgr][htr] = Cote;
        }
    }

    grilleArchipel[6][8] = Cote;
    grilleArchipel[6][9] = Cote;
    grilleArchipel[7][8] = Cote;
    grilleArchipel[15][5] = Cote;
    grilleArchipel[16][4] = Cote;
    grilleArchipel[16][5] = Cote;
    grilleArchipel[20][10] = Cote;
    grilleArchipel[24][8] = Cote;
    grilleArchipel[25][8] = Cote;

    grilleArchipel[1][2] = CoteNO;
    grilleArchipel[1][4] = CoteSO;
    grilleArchipel[3][17] = CoteSE;
    grilleArchipel[3][27] = CoteNE;
    grilleArchipel[4][2] = CoteNE;
    grilleArchipel[4][4] = CoteSE;
    grilleArchipel[4][17] = CoteSO;
    grilleArchipel[4][27] = CoteNO;
    grilleArchipel[5][8] = CoteNO;
    grilleArchipel[5][11] = CoteSE;
    grilleArchipel[6][10] = CoteSE;
    grilleArchipel[7][7] = CoteNO;
    grilleArchipel[7][9] = CoteSE;
    grilleArchipel[8][8] = CoteSE;
    grilleArchipel[11][6] = CoteNO;
    grilleArchipel[11][23] = CoteNO;
    grilleArchipel[11][26] = CoteSO;
    grilleArchipel[12][19] = CoteSO;
    grilleArchipel[12][21] = CoteNO;
    grilleArchipel[13][19] = CoteSE;
    grilleArchipel[13][20] = CoteNE;
    grilleArchipel[13][26] = CoteSE;
    grilleArchipel[14][5] = CoteNO;
    grilleArchipel[14][7] = CoteSE;
    grilleArchipel[14][22] = CoteSE;
    grilleArchipel[14][23] = CoteNE;
    grilleArchipel[15][4] = CoteNO;
    grilleArchipel[15][21] = CoteNE;
    grilleArchipel[15][26] = CoteSO;
    grilleArchipel[17][4] = CoteSE;
    grilleArchipel[17][21] = CoteNO;
    grilleArchipel[17][26] = CoteSE;
    grilleArchipel[18][22] = CoteSO;
    grilleArchipel[18][23] = CoteNO;
    grilleArchipel[19][19] = CoteSO;
    grilleArchipel[19][20] = CoteNO;
    grilleArchipel[19][26] = CoteSO;
    grilleArchipel[20][9] = CoteNO;
    grilleArchipel[20][11] = CoteSE;
    grilleArchipel[20][19] = CoteSE;
    grilleArchipel[20][21] = CoteNE;
    grilleArchipel[21][23] = CoteNE;
    grilleArchipel[21][26] = CoteSE;
    grilleArchipel[23][8] = CoteNO;
    grilleArchipel[23][10] = CoteSE;

    grilleArchipel[11][20] = Ocean;
    grilleArchipel[14][27] = Ocean;
    grilleArchipel[14][28] = Ocean;
    grilleArchipel[15][18] = Ocean;
    grilleArchipel[15][19] = Ocean;
    grilleArchipel[16][18] = Ocean;
    grilleArchipel[16][19] = Ocean;
    grilleArchipel[16][20] = Ocean;
    grilleArchipel[17][18] = Ocean;
    grilleArchipel[17][19] = Ocean;
    grilleArchipel[18][27] = Ocean;
    grilleArchipel[18][28] = Ocean;
    grilleArchipel[21][20] = Ocean;

    ///Création des plages
        ///Nord
    grilleArchipel[0][2] = PlageN;
    grilleArchipel[2][1] = PlageN;
    grilleArchipel[2][8] = PlageN;
    grilleArchipel[3][1] = PlageN;
    grilleArchipel[3][8] = PlageN;
    grilleArchipel[3][16] = PlageN;
    grilleArchipel[4][8] = PlageN;
    grilleArchipel[4][16] = PlageN;
    grilleArchipel[6][7] = PlageN;
    grilleArchipel[8][6] = PlageN;
    grilleArchipel[9][6] = PlageN;
    grilleArchipel[10][6] = PlageN;
    grilleArchipel[12][5] = PlageN;
    grilleArchipel[12][18] = PlageN;
    grilleArchipel[13][5] = PlageN;
    grilleArchipel[13][18] = PlageN;
    grilleArchipel[14][20] = PlageN;
    grilleArchipel[15][23] = PlageN;
    grilleArchipel[16][2] = PlageN;
    grilleArchipel[16][21] = PlageN;
    grilleArchipel[16][23] = PlageN;
    grilleArchipel[17][2] = PlageN;
    grilleArchipel[17][23] = PlageN;
    grilleArchipel[18][2] = PlageN;
    grilleArchipel[18][20] = PlageN;
    grilleArchipel[19][2] = PlageN;
    grilleArchipel[19][18] = PlageN;
    grilleArchipel[20][18] = PlageN;
    grilleArchipel[21][8] = PlageN;
    grilleArchipel[22][8] = PlageN;
    grilleArchipel[24][7] = PlageN;
    grilleArchipel[25][7] = PlageN;
    grilleArchipel[27][26] = PlageN;

        ///Sud
    grilleArchipel[0][4] = PlageS;
    grilleArchipel[2][5] = PlageS;
    grilleArchipel[2][12] = PlageS;
    grilleArchipel[3][5] = PlageS;
    grilleArchipel[3][12] = PlageS;
    grilleArchipel[3][28] = PlageS;
    grilleArchipel[4][12] = PlageS;
    grilleArchipel[4][28] = PlageS;
    grilleArchipel[12][28] = PlageS;
    grilleArchipel[14][26] = PlageS;
    grilleArchipel[15][7] = PlageS;
    grilleArchipel[15][22] = PlageS;
    grilleArchipel[16][7] = PlageS;
    grilleArchipel[16][22] = PlageS;
    grilleArchipel[16][28] = PlageS;
    grilleArchipel[17][22] = PlageS;
    grilleArchipel[18][4] = PlageS;
    grilleArchipel[18][26] = PlageS;
    grilleArchipel[19][4] = PlageS;
    grilleArchipel[20][28] = PlageS;
    grilleArchipel[21][11] = PlageS;
    grilleArchipel[22][11] = PlageS;
    grilleArchipel[24][10] = PlageS;
    grilleArchipel[25][10] = PlageS;
    grilleArchipel[27][28] = PlageS;

    for(int lgr = 9;lgr <= 13;lgr++)
    {
        grilleArchipel[lgr][8] = PlageS;
    }

        ///Est
    grilleArchipel[5][3] = PlageE;
    grilleArchipel[13][27] = PlageE;
    grilleArchipel[17][5] = PlageE;
    grilleArchipel[17][6] = PlageE;
    grilleArchipel[17][27] = PlageE;
    grilleArchipel[20][3] = PlageE;
    grilleArchipel[20][20] = PlageE;
    grilleArchipel[21][22] = PlageE;
    grilleArchipel[21][27] = PlageE;
    grilleArchipel[22][24] = PlageE;
    grilleArchipel[22][25] = PlageE;
    grilleArchipel[26][8] = PlageE;
    grilleArchipel[26][9] = PlageE;
    grilleArchipel[28][27] = PlageE;

    for(int htr = 17;htr <= 27;htr++)
    {
        grilleArchipel[5][htr] = PlageE;

        if(htr >= 18 && htr <= 26)
        {
            grilleArchipel[3][htr]= PlageE;
        }
    }

        ///Ouest
    grilleArchipel[1][9] = PlageO;
    grilleArchipel[1][10] = PlageO;
    grilleArchipel[1][11] = PlageO;
    grilleArchipel[10][24] = PlageO;
    grilleArchipel[10][25] = PlageO;
    grilleArchipel[11][22] = PlageO;
    grilleArchipel[11][27] = PlageO;
    grilleArchipel[12][20] = PlageO;
    grilleArchipel[15][3] = PlageO;
    grilleArchipel[15][27] = PlageO;
    grilleArchipel[19][10] = PlageO;
    grilleArchipel[19][11] = PlageO;
    grilleArchipel[19][27] = PlageO;
    grilleArchipel[26][27] = PlageO;

    for(int htr = 17;htr <= 27;htr++)
    {
        grilleArchipel[2][htr] = PlageO;

        if(htr >= 18 && htr <= 26)
        {
            grilleArchipel[4][htr]= PlageO;
        }
    }

        ///Nord-Ouest
    grilleArchipel[1][1] = PlageNO;
    grilleArchipel[1][8] = PlageNO;
    grilleArchipel[2][16] = PlageNO;
    grilleArchipel[5][7] = PlageNO;
    grilleArchipel[7][6] = PlageNO;
    grilleArchipel[10][23] = PlageNO;
    grilleArchipel[11][5] = PlageNO;
    grilleArchipel[11][18] = PlageNO;
    grilleArchipel[11][21] = PlageNO;
    grilleArchipel[14][4] = PlageNO;
    grilleArchipel[15][2] = PlageNO;
    grilleArchipel[17][20] = PlageNO;
    grilleArchipel[18][18] = PlageNO;
    grilleArchipel[19][9] = PlageNO;
    grilleArchipel[20][8] = PlageNO;
    grilleArchipel[23][7] = PlageNO;
    grilleArchipel[26][26] = PlageNO;

        ///Nord-Est
    grilleArchipel[4][1] = PlageNE;
    grilleArchipel[5][2] = PlageNE;
    grilleArchipel[5][16] = PlageNE;
    grilleArchipel[20][2] = PlageNE;
    grilleArchipel[21][18] = PlageNE;
    grilleArchipel[21][21] = PlageNE;
    grilleArchipel[22][23] = PlageNE;
    grilleArchipel[15][20] = PlageNE;
    grilleArchipel[14][18] = PlageNE;
    grilleArchipel[26][7] = PlageNE;
    grilleArchipel[28][26] = PlageNE;

        ///Sud-Est
    grilleArchipel[4][5] = PlageSE;
    grilleArchipel[5][4] = PlageSE;
    grilleArchipel[5][12] = PlageSE;
    grilleArchipel[5][28] = PlageSE;
    grilleArchipel[6][11] = PlageSE;
    grilleArchipel[7][10] = PlageSE;
    grilleArchipel[8][9] = PlageSE;
    grilleArchipel[14][8] = PlageSE;
    grilleArchipel[17][7] = PlageSE;
    grilleArchipel[20][4] = PlageSE;
    grilleArchipel[20][12] = PlageSE;
    grilleArchipel[23][11] = PlageSE;
    grilleArchipel[26][10] = PlageSE;
    grilleArchipel[13][28] = PlageSE;
    grilleArchipel[14][19] = PlageSE;
    grilleArchipel[17][28] = PlageSE;
    grilleArchipel[21][19] = PlageSE;
    grilleArchipel[21][28] = PlageSE;
    grilleArchipel[22][26] = PlageSE;
    grilleArchipel[28][28] = PlageSE;

        ///Sud-Ouest
    grilleArchipel[1][5] = PlageSO;
    grilleArchipel[1][12] = PlageSO;
    grilleArchipel[2][28] = PlageSO;
    grilleArchipel[10][26] = PlageSO;
    grilleArchipel[11][19] = PlageSO;
    grilleArchipel[11][28] = PlageSO;
    grilleArchipel[15][28] = PlageSO;
    grilleArchipel[18][19] = PlageSO;
    grilleArchipel[19][12] = PlageSO;
    grilleArchipel[19][28] = PlageSO;
    grilleArchipel[26][28] = PlageSO;

    ///Création de l'oeil du cyclope

    ///Création de la barque
    grilleArchipel[6][3] = Barque;

    ///Création des escaliers
    grilleArchipel[16][25] = Escalier;
    grilleArchipel[27][27] = Escalier;

    ///Initialisation de la carte
    for(int htr = 0;htr <= 29;htr++)
    {
        for(int lgr = 0;lgr <= 29;lgr++)
        {
            for(int i = 0; i <= 8;i++)
            {
                carteArchipel[lgr][htr][i] = " ";
            }
        }
    }

}
void creationGrotte(int grilleGrotte[][15], string carteGrotte[][15][9])
{
    for(int lgr = 0;lgr <= 24;lgr++)
    {
        for(int htr = 0;htr <= 14;htr++)
        {
            grilleGrotte[lgr][htr] = Mur;
        }
    }

    grilleGrotte[5][1] = VideAngleSOSE;
    grilleGrotte[7][4] = VideAngleNO;
    grilleGrotte[7][5] = VideAngleSO;
    grilleGrotte[15][1] = VideAngleNO;
    grilleGrotte[16][1] = Vide;
    grilleGrotte[16][2] = VideAngleSO;
    grilleGrotte[17][2] = VideAngleNE;
    grilleGrotte[17][3] = VideAngleSE;
    grilleGrotte[20][2] = VideAngleNOSOSE;
    grilleGrotte[22][13] = VideAngleNOSO;
    grilleGrotte[23][7] = VideAngleNOSO;
    grilleGrotte[23][12] = VideAngleNO;
    grilleGrotte[23][13] = Vide;

    ///Création des Murs
        ///Nord
    grilleGrotte[2][13] = MurNAngleSOSE;
    grilleGrotte[4][0] = MurNAngleSO;
    grilleGrotte[5][0] = MurN;
    grilleGrotte[5][13] = MurNAngleSOSE;
    grilleGrotte[6][0] = MurNAngleSE;
    grilleGrotte[6][4] = MurN;
    grilleGrotte[8][0] = MurNAngleSOSE;
    grilleGrotte[11][1] = MurNAngleSOSE;
    grilleGrotte[14][1] = MurNAngleSO;
    grilleGrotte[16][0] = MurN;
    grilleGrotte[18][2] = MurNAngleSE;
    grilleGrotte[18][5] = MurNAngleSOSE;
    grilleGrotte[18][9] = MurNAngleSOSE;
    grilleGrotte[20][13] = MurNAngleSOSE;
    grilleGrotte[21][1] = MurNAngleSE;

        ///Sud
    grilleGrotte[5][5] = MurSAngleNO;
    grilleGrotte[6][5] = MurS;
    grilleGrotte[15][2] = MurS;
    grilleGrotte[17][5] = MurSAngleNE;
    grilleGrotte[18][7] = MurSAngleNONE;
    grilleGrotte[18][11] = MurSAngleNONE;
    grilleGrotte[20][5] = MurSAngleNONE;
    grilleGrotte[22][1] = MurSAngleNONE;
    grilleGrotte[23][14] = MurS;

        ///Est
    grilleGrotte[8][4] = MurE;
    grilleGrotte[8][5] = MurE;
    grilleGrotte[17][1] = MurE;
    grilleGrotte[17][4] = MurE;
    grilleGrotte[17][8] = MurEAngleNOSO;
    grilleGrotte[24][6] = MurE;
    grilleGrotte[24][7] = MurE;
    grilleGrotte[24][12] = MurE;
    grilleGrotte[24][13] = MurE;

        ///Ouest
    grilleGrotte[0][13] = MurOAngleNESE;
    grilleGrotte[2][8] = MurOAngleNESE;
    grilleGrotte[5][4] = MurOAngleNE;
    grilleGrotte[11][4] = MurOAngleNE;
    grilleGrotte[14][2] = MurOAngleSE;
    grilleGrotte[16][3] = MurO;
    grilleGrotte[16][4] = MurO;
    grilleGrotte[19][8] = MurOAngleNESE;
    grilleGrotte[23][6] = MurO;
    grilleGrotte[23][8] = MurOAngleSE;
    grilleGrotte[23][11] = MurOAngleNE;

        ///Nord-Est
    grilleGrotte[8][3] = MurNE;
    grilleGrotte[10][10] = MurNEAngleSO;
    grilleGrotte[12][4] = MurNE;
    grilleGrotte[17][0] = MurNE;
    grilleGrotte[19][7] = MurNEAngleSO;
    grilleGrotte[21][8] = MurNEAngleSO;
    grilleGrotte[24][5] = MurNE;
    grilleGrotte[24][11] = MurNE;

        ///Nord-Ouest
    grilleGrotte[0][0] = MurNOAngleSE;
    grilleGrotte[2][5] = MurNOAngleSE;
    grilleGrotte[7][3] = MurNO;
    grilleGrotte[15][0] = MurNO;
    grilleGrotte[17][7] = MurNOAngleSE;
    grilleGrotte[20][1] = MurNO;
    grilleGrotte[20][10] = MurNOAngleSE;
    grilleGrotte[22][12] = MurNO;
    grilleGrotte[23][5] = MurNO;

        ///Sud-Ouest
    grilleGrotte[2][10] = MurSOAngleNE;
    grilleGrotte[4][1] = MurSO;
    grilleGrotte[7][6] = MurSO;
    grilleGrotte[10][11] = MurSOAngleNE;
    grilleGrotte[14][8] = MurSOAngleNE;
    grilleGrotte[16][5] = MurSO;
    grilleGrotte[17][9] = MurSOAngleNE;
    grilleGrotte[22][14] = MurSO;

        ///Sud-Est
    grilleGrotte[6][1] = MurSE;
    grilleGrotte[8][6] = MurSE;
    grilleGrotte[12][5] = MurSE;
    grilleGrotte[18][3] = MurSE;
    grilleGrotte[19][9] = MurSEAngleNO;
    grilleGrotte[20][11] = MurSEAngleNO;
    grilleGrotte[21][2] = MurSE;
    grilleGrotte[21][10] = MurSEAngleNO;
    grilleGrotte[24][8] = MurSE;
    grilleGrotte[24][14] = MurSE;

        ///Nord-Sud
    for(int lgr = 3;lgr <= 19;lgr++)
    {
        if(lgr <= 10)
        {
            grilleGrotte[lgr][8] = MurNS;

            if(lgr != 10)
            {
                grilleGrotte[lgr][10] = MurNS;
            }

            if(lgr != 5)
            {
                grilleGrotte[lgr][13] = MurNS;
            }
        }
        else
        {
            if(lgr <= 16 && lgr != 12 && lgr != 13 && lgr != 14)
            {
                grilleGrotte[lgr][8] = MurNS;
            }

            if(lgr != 18)
            {
                grilleGrotte[lgr][11] = MurNS;
            }

            grilleGrotte[lgr][13] = MurNS;
        }
    }
    grilleGrotte[1][0] = MurNS;
    grilleGrotte[1][13] = MurNS;
    grilleGrotte[2][0] = MurNS;
    grilleGrotte[3][0] = MurNS;
    grilleGrotte[3][5] = MurNS;
    grilleGrotte[4][5] = MurNS;
    grilleGrotte[7][0] = MurNS;
    grilleGrotte[12][1] = MurNS;
    grilleGrotte[13][1] = MurNS;
    grilleGrotte[19][2] = MurNS;
    grilleGrotte[19][5] = MurNS;
    grilleGrotte[20][8] = MurNS;
    grilleGrotte[21][13] = MurNS;

        ///Est-Ouest
    for(int htr = 1;htr <= 12;htr++)
    {
        grilleGrotte[0][htr] = MurEO;

        if(htr >= 3 && htr <= 7)
        {
            grilleGrotte[14][htr] = MurEO;
        }
    }
    grilleGrotte[2][6] = MurEO;
    grilleGrotte[2][7] = MurEO;
    grilleGrotte[2][9] = MurEO;
    grilleGrotte[5][2] = MurEO;
    grilleGrotte[5][3] = MurEO;
    grilleGrotte[11][2] = MurEO;
    grilleGrotte[11][3] = MurEO;
    grilleGrotte[18][6] = MurEO;
    grilleGrotte[18][10] = MurEO;
    grilleGrotte[20][3] = MurEO;
    grilleGrotte[20][4] = MurEO;
    grilleGrotte[21][9] = MurEO;
    grilleGrotte[23][9] = MurEO;
    grilleGrotte[23][10] = MurEO;

        ///Impasse Nord
    grilleGrotte[22][0] = ImpasseN;

        ///Impasse Sud
    grilleGrotte[0][14] = ImpasseS;
    grilleGrotte[2][14] = ImpasseS;
    grilleGrotte[5][14] = ImpasseS;
    grilleGrotte[8][1] = ImpasseS;
    grilleGrotte[20][14] = ImpasseS;

        ///Impasse Est
    grilleGrotte[9][0] = ImpasseE;
    grilleGrotte[12][8] = ImpasseE;
    grilleGrotte[21][5] = ImpasseE;
    grilleGrotte[23][1] = ImpasseE;

        ///Impasse Ouest
    grilleGrotte[10][1] = ImpasseO;

    ///Création des escaliers
    grilleGrotte[11][5] = Escalier;
    grilleGrotte[22][7] = Escalier;

    ///Initialisation de la carte
    for(int htr = 0;htr <= 14;htr++)
    {
        for(int lgr = 0;lgr <= 24;lgr++)
        {
            for(int i = 0; i <= 8;i++)
            {
                carteGrotte[lgr][htr][i] = " ";
            }
        }
    }

}

///Vérifie que le joueur a l'autoriation d'aller dans cette direction
bool bonneDirectionDesert(const int grilleDesert[][25],const int joueurPosX,const int joueurPosY,const string direction)
{
    if(direction[0] == '1' || direction[0] == 'n')
    {
        if(grilleDesert[joueurPosX][joueurPosY] == ParoiN || grilleDesert[joueurPosX][joueurPosY] == ParoiNE || grilleDesert[joueurPosX][joueurPosY] == ParoiNO)
        {
            escaladeInterditeDesert();
        }
        else if(joueurPosY-1 >= 0)
        {
            if(grilleDesert[joueurPosX][joueurPosY-1] == Ocean)
            {
                nageInterditeDesert();
            }
            else
            {
                return true;
            }
        }
        else
        {
            nageInterditeDesert();
        }
    }
    else if(direction[0] == '2' || direction[0] == 'o')
    {
        if(grilleDesert[joueurPosX][joueurPosY] == ParoiNO || grilleDesert[joueurPosX][joueurPosY] == ParoiSO)
        {
            escaladeInterditeDesert();
        }
        else if(joueurPosX-1 >= 0)
        {
            if(grilleDesert[joueurPosX-1][joueurPosY] == Ocean)
            {
                nageInterditeDesert();
            }
            else
            {
                return true;
            }
        }
        else
        {
            nageInterditeDesert();
        }
    }
    else if(direction[0] == '3' || direction[0] == 'e')
    {
        if(grilleDesert[joueurPosX][joueurPosY] == ParoiE || grilleDesert[joueurPosX][joueurPosY] == ParoiNE || grilleDesert[joueurPosX][joueurPosY] == ParoiSE)
        {
            escaladeInterditeDesert();
        }
        else if(joueurPosX+1 <= 24)
        {
            if(grilleDesert[joueurPosX+1][joueurPosY] == Ocean)
            {
                nageInterditeDesert();
            }
            else
            {
                return true;
            }
        }
        else if(grilleDesert[joueurPosX][joueurPosY] == Frontiere)
        {
            phrase("Malheureusement, la porte du poste fronti\x8Are est bien ferm\x82\ae.");
            finLigne(500);
            phrase("Vous pouvez continuer \x85 essayer de passer au travers, mais bon, ");
            sleep(500);
            phrase("\x87\aa marchera pas pour autant.");
            finLigne(500);
            finLigne(500);
        }
        else
        {
            nageInterditeDesert();
        }
    }
    else if(direction[0] == '4' || direction[0] == 's')
    {
        if(grilleDesert[joueurPosX][joueurPosY] == ParoiS || grilleDesert[joueurPosX][joueurPosY] == ParoiSE || grilleDesert[joueurPosX][joueurPosY] == ParoiSO)
        {
            escaladeInterditeDesert();
        }
        else if(joueurPosY+1 <= 24)
        {
            if(grilleDesert[joueurPosX][joueurPosY+1] == Ocean)
            {
                nageInterditeDesert();
            }
            else
            {
                return true;
            }
        }
        else
        {
            nageInterditeDesert();
        }
    }

    return false;
}
bool bonneDirectionMarai(const int grilleMarai[][25],const int joueurPosX,const int joueurPosY,const string direction)
{
    if(direction[0] == '1' || direction[0] == 'n')
    {
        if(joueurPosY-1 >= 0)
        {
            if(grilleMarai[joueurPosX][joueurPosY] == Cabane)
            {
                phrase("Vous vous dirigez vers le nord, mais le mur de la cabane vous emp\x88\ache d'avancer.");
                finLigne(1000);
            }
            else if(grilleMarai[joueurPosX][joueurPosY-1] == Bourbier)
            {
                bourbierInterdit();
            }
            else if(grilleMarai[joueurPosX][joueurPosY-1] == Lac && grilleMarai[joueurPosX][joueurPosY] != Barque && grilleMarai[joueurPosX][joueurPosY] != TourBas && grilleMarai[joueurPosX][joueurPosY] != TourHaut && grilleMarai[joueurPosX][joueurPosY] != TourHaut)
            {
                nageInterditeMarai();
            }
            else if(grilleMarai[joueurPosX][joueurPosY-1] == Bourbier)
            {
                bourbierInterdit();
            }
            else
            {
                return true;
            }
        }
        else
        {
            bourbierInterdit();
        }
    }
    else if(direction[0] == '2' || direction[0] == 'o')
    {
        if(joueurPosX-1 >= 0)
        {
            if(grilleMarai[joueurPosX-1][joueurPosY] == Lac && grilleMarai[joueurPosX][joueurPosY] != Barque && grilleMarai[joueurPosX][joueurPosY] != TourBas && grilleMarai[joueurPosX][joueurPosY] != TourHaut)
            {
                nageInterditeMarai();
            }
            else if(grilleMarai[joueurPosX-1][joueurPosY] == Bourbier)
            {
                bourbierInterdit();
            }
            else
            {
                return true;
            }
        }
        else
        {
            phrase("Le marai qui devrait s'\x82tendre devant vous est subitement remplac\x82 par");
            sleep(250);
            phrase(".");
            sleep(250);
            phrase(".");
            sleep(250);
            phrase(".");
            sleep(500);
            ///Bouchâge de trou
            phrase(" rien du tout.");
            finLigne(500);
            finLigne(500);
            phrase("Il semblerai que le cr\x82\aateur du monde n'ai pas encore fini cette partie.");
            finLigne(750);
            phrase("Vous devriez revenir plus tard.");
            finLigne(1000);
            phrase("Bien plus tard.");
            ///Bouchâge de trou
        }
    }
    else if(direction[0] == '3' || direction[0] == 'e')
    {
        if(joueurPosX+1 <= 24)
        {
            if(grilleMarai[joueurPosX][joueurPosY] == Cabane)
            {
                phrase("Vous vous dirigez vers l'est, mais le mur de la cabane vous emp\x88\ache d'avancer.");
                finLigne(1000);
            }
            else if(grilleMarai[joueurPosX+1][joueurPosY] == Lac && grilleMarai[joueurPosX][joueurPosY] != Barque && grilleMarai[joueurPosX][joueurPosY] != TourBas && grilleMarai[joueurPosX][joueurPosY] != TourHaut)
            {
                nageInterditeMarai();
            }
            else if(grilleMarai[joueurPosX+1][joueurPosY] == Bourbier)
            {
                bourbierInterdit();
            }
            else
            {
                return true;
            }
        }
        else
        {
            phrase("Derri\x8Are vous, un vieillard se tient au milieu du ponton, appuy\x82, ou plut\x93t affal\x82 sur une esp\x8A\ace de branche.");
            finLigne(750);
            phrase("Soudain, ");
            sleep(750);
            phrase("il s'addresse \x85 vous.");
            finLigne(500);
            finLigne(500);
            phrase("Vieillard :");
            finLigne(250);
            phrase("Vous");
            sleep(250);
            phrase(".");
            sleep(250);
            phrase(".");
            sleep(250);
            phrase(".");
            sleep(250);
            phrase(" ne pass");
            sleep(150);
            phrase(".");
            sleep(150);
            phrase(".");
            sleep(150);
            phrase(".");
            sleep(150);
            phrase(" *tousse*");
            sleep(150);
            phrase(".");
            sleep(150);
            phrase(".");
            sleep(150);
            phrase(".");
            sleep(150);
            phrase(" *tousse*");
            sleep(150);
            phrase(".");
            sleep(150);
            phrase(".");
            sleep(150);
            phrase(".");
            sleep(150);
            phrase(" passerez paaaaaaaaaaas");
            sleep(150);
            phrase(".");
            sleep(150);
            phrase(".");
            sleep(150);
            phrase(".");
            sleep(150);
            phrase(" *tousse*");
            sleep(150);
            phrase(".");
            sleep(150);
            phrase(".");
            sleep(150);
            phrase(".");
            sleep(150);
            phrase(" *tousse*");
            sleep(150);
            phrase(".");
            sleep(150);
            phrase(".");
            sleep(150);
            phrase(".");
            sleep(150);
            phrase(" *tousse*");
            finLigne(500);
            finLigne(500);
            finLigne(500);
            phrase("Apr\x8As avoir compt\x82 le nombre de mouche tournant autour de lui, vous \x88tes plut\x93t d'accord avec sa d\x82\acision.");
            finLigne(500);
        }
    }
    else if(direction[0] == '4' || direction[0] == 's')
    {
        if(joueurPosY+1 <= 24)
        {
            if(grilleMarai[joueurPosX][joueurPosY+1] == Bourbier)
            {
                bourbierInterdit();
            }
            else if(grilleMarai[joueurPosX][joueurPosY+1] == Lac && grilleMarai[joueurPosX][joueurPosY] != Barque && grilleMarai[joueurPosX][joueurPosY] != TourBas && grilleMarai[joueurPosX][joueurPosY] != TourHaut)
            {
                nageInterditeMarai();
            }
            else
            {
                return true;
            }
        }
        else
        {
            bourbierInterdit();
        }
    }

    finLigne(500);
    finLigne(500);

    return false;
}
bool bonneDirectionArchipel(int grilleArchipel[][30],int joueurPosX,int joueurPosY,string direction)
{
    if(direction[0] == '1' || direction[0] == 'n')
    {
        if(joueurPosY-1 >= 0)
        {
            if(grilleArchipel[joueurPosX][joueurPosY-1] == Ocean && grilleArchipel[joueurPosX][joueurPosY] != Barque)
            {
                nageInterditeArchipel();
            }
            else
            {
                return true;
            }
        }
        else
        {
            phrase("Des mers plus profondes s'\x82tendent au nord.");
            finLigne(500);
            phrase("Une si petite barque ne pourrait pas y survivre.");
            finLigne(500);
            finLigne(500);
        }
    }
    else if(direction[0] == '2' || direction[0] == 'o')
    {
        if(joueurPosX-1 >= 0)
        {
            if(grilleArchipel[joueurPosX-1][joueurPosY] == Ocean && grilleArchipel[joueurPosX][joueurPosY] != Barque)
            {
                nageInterditeArchipel();
            }
            else
            {
                return true;
            }
        }
        else
        {
            phrase("Un mur invisible vous emp\x88\ache de retourner en arri\x8Are.");
            finLigne(500);

            if(joueurPosY == 2 || joueurPosY == 3 || joueurPosY == 4)
            {
                phrase("Vous essayez de le grimper, de le fracasser avec du sable, mais rien y fait.");
                finLigne(500);
                phrase("Vous tentez m\x88me une formule ancestrale interdite \x85 base d'\x82pices et de flocon d'avoine, qui reste sans effet.");
            }
            else
            {
                phrase("Votre petit navire rebondit dessus.");
                finLigne(500);
                phrase("\xB7 chaque fois que vous avancez, vous reculez im\x82\adiatement de 10 m\x8Atres.");
            }

            finLigne(500);
            phrase("C'est comme si une force sup\x82rieure ne voulait pas que vous retourniez dans le d\x82sert.");
            finLigne(1000);
        }
    }
    else if(direction[0] == '3' || direction[0] == 'e')
    {
        if(joueurPosX+1 <= 29)
        {
            if(grilleArchipel[joueurPosX+1][joueurPosY] == Ocean && grilleArchipel[joueurPosX][joueurPosY] != Barque)
            {
                nageInterditeArchipel();
            }
            else
            {
                return true;
            }
        }
        else
        {
            phrase("Des mers plus profondes s'\x82tendent \x85 l'est.");
            finLigne(500);
            phrase("Une si petite barque ne pourrait pas y survivre.");
            finLigne(500);
            finLigne(500);
        }
    }
    else if(direction[0] == '4' || direction[0] == 's')
    {
        if(joueurPosY+1 <= 29)
        {
            if(grilleArchipel[joueurPosX][joueurPosY+1] == Ocean && grilleArchipel[joueurPosX][joueurPosY] != Barque)
            {
                nageInterditeArchipel();
            }
            else
            {
                return true;
            }
        }
        else
        {
            phrase("Des mers plus profondes s'\x82tendent au sud.");
            finLigne(500);
            phrase("Une si petite barque ne pourrait pas y survivre.");
            finLigne(500);
            finLigne(500);
        }
    }

    return false;
}

///Supprime la croix de la carte pour pouvoir modifier son emplacement
void setCaseCarteDesert(string carteDesert[][25][9], int lgr, int htr, int grilleDesert[][25], bool champDeVision)
{
    if(lgr <= 24 && lgr >= 0 && htr <= 24 && htr >= 0)
    {
        int position = grilleDesert[lgr][htr];

        if(!champDeVision)
        {
            setCaseCarteDesert(carteDesert,lgr-1,htr,grilleDesert,true);
            setCaseCarteDesert(carteDesert,lgr,htr-1,grilleDesert,true);
            setCaseCarteDesert(carteDesert,lgr,htr+1,grilleDesert,true);
            setCaseCarteDesert(carteDesert,lgr+1,htr,grilleDesert,true);
        }

        switch(position)
        {
        case Ocean :
            for(int i = 0;i <= 8;i++)
            {
                carteDesert[lgr][htr][i] = "~";
            }
            carteDesert[lgr][htr][0] = " ";
            carteDesert[lgr][htr][3] = " ";
            carteDesert[lgr][htr][5] = " ";
            carteDesert[lgr][htr][7] = " ";
            break;

        case Desert :
            for(int i = 0;i <= 8;i++)
            {
                carteDesert[lgr][htr][i] = " ";
            }
            break;

        case Cote :
            for(int i = 0;i <= 8;i++)
            {
                carteDesert[lgr][htr][i] = ".";
            }
            break;

        case CoteNE :
            for(int i = 0;i <= 8;i++)
            {
                carteDesert[lgr][htr][i] = ".";
            }
            carteDesert[lgr][htr][1] = "\xB0";
            carteDesert[lgr][htr][2] = "\xB0";
            carteDesert[lgr][htr][5] = "\xB0";
            break;

        case CoteNO :
            for(int i = 0;i <= 8;i++)
            {
                carteDesert[lgr][htr][i] = ".";
            }
            carteDesert[lgr][htr][0] = "\xB0";
            carteDesert[lgr][htr][1] = "\xB0";
            carteDesert[lgr][htr][3] = "\xB0";
            break;

        case CoteSO :
            for(int i = 0;i <= 8;i++)
            {
                carteDesert[lgr][htr][i] = ".";
            }
            carteDesert[lgr][htr][3] = "\xB0";
            carteDesert[lgr][htr][6] = "\xB0";
            carteDesert[lgr][htr][7] = "\xB0";
            break;

        case PlageN :
            carteDesert[lgr][htr][0] = "~";
            carteDesert[lgr][htr][1] = "~";
            carteDesert[lgr][htr][2] = "~";
            carteDesert[lgr][htr][3] = "\xB0";
            carteDesert[lgr][htr][4] = "\xB0";
            carteDesert[lgr][htr][5] = "\xB0";
            carteDesert[lgr][htr][6] = ".";
            carteDesert[lgr][htr][7] = ".";
            carteDesert[lgr][htr][8] = ".";
            break;

        case PlageS :
            carteDesert[lgr][htr][0] = ".";
            carteDesert[lgr][htr][1] = ".";
            carteDesert[lgr][htr][2] = ".";
            carteDesert[lgr][htr][3] = "\xB0";
            carteDesert[lgr][htr][4] = "\xB0";
            carteDesert[lgr][htr][5] = "\xB0";
            carteDesert[lgr][htr][6] = "~";
            carteDesert[lgr][htr][7] = "~";
            carteDesert[lgr][htr][8] = "~";
            break;

        case PlageE :
            carteDesert[lgr][htr][0] = ".";
            carteDesert[lgr][htr][1] = "\xB0";
            carteDesert[lgr][htr][2] = "~";
            carteDesert[lgr][htr][3] = ".";
            carteDesert[lgr][htr][4] = "\xB0";
            carteDesert[lgr][htr][5] = "~";
            carteDesert[lgr][htr][6] = ".";
            carteDesert[lgr][htr][7] = "\xB0";
            carteDesert[lgr][htr][8] = "~";
            break;

        case PlageO :
            carteDesert[lgr][htr][0] = "~";
            carteDesert[lgr][htr][1] = "\xB0";
            carteDesert[lgr][htr][2] = ".";
            carteDesert[lgr][htr][3] = "~";
            carteDesert[lgr][htr][4] = "\xB0";
            carteDesert[lgr][htr][5] = ".";
            carteDesert[lgr][htr][6] = "~";
            carteDesert[lgr][htr][7] = "\xB0";
            carteDesert[lgr][htr][8] = ".";
            break;

        case PlageNE :
            for(int i = 0;i <= 8 ;i++)
            {
                carteDesert[lgr][htr][i] = "~";
            }
            carteDesert[lgr][htr][3] = "\xB0";
            carteDesert[lgr][htr][6] = "\xB0";
            carteDesert[lgr][htr][7] = "\xB0";
            break;

        case PlageNO :
            for(int i = 0;i <= 8 ;i++)
            {
                carteDesert[lgr][htr][i] = "~";
            }
            carteDesert[lgr][htr][8] = "\xB0";
            carteDesert[lgr][htr][5] = "\xB0";
            carteDesert[lgr][htr][7] = "\xB0";

            break;

        case PlageSO :
            for(int i = 0;i <= 8 ;i++)
            {
                carteDesert[lgr][htr][i] = "~";
            }
            carteDesert[lgr][htr][1] = "\xB0";
            carteDesert[lgr][htr][2] = "\xB0";
            carteDesert[lgr][htr][5] = "\xB0";
            break;

        case PlageSE :
            for(int i = 0;i <= 8 ;i++)
            {
                carteDesert[lgr][htr][i] = "~";
            }
            carteDesert[lgr][htr][1] = "\xB0";
            carteDesert[lgr][htr][3] = "\xB0";
            carteDesert[lgr][htr][0] = "\xB0";
            break;

        case ParoiN :
            carteDesert[lgr][htr][0] = "\xC4";
            carteDesert[lgr][htr][1] = "\xC4";
            carteDesert[lgr][htr][2] = "\xC4";
            break;

        case ParoiS :
            carteDesert[lgr][htr][6] = "\xC4";
            carteDesert[lgr][htr][7] = "\xC4";
            carteDesert[lgr][htr][8] = "\xC4";
            break;

        case ParoiE :
            carteDesert[lgr][htr][2] = "\xB3";
            carteDesert[lgr][htr][5] = "\xB3";
            carteDesert[lgr][htr][8] = "\xB3";
            break;

        case ParoiNE :
            carteDesert[lgr][htr][0] = "\xC4";
            carteDesert[lgr][htr][1] = "\xC4";
            carteDesert[lgr][htr][2] = "\xBF";
            carteDesert[lgr][htr][5] = "\xB3";
            carteDesert[lgr][htr][8] = "\xB3";
            break;

        case ParoiNO :
            carteDesert[lgr][htr][0] = "\xDA";
            carteDesert[lgr][htr][1] = "\xC4";
            carteDesert[lgr][htr][2] = "\xC4";
            carteDesert[lgr][htr][3] = "\xB3";
            carteDesert[lgr][htr][6] = "\xB3";
            break;

        case ParoiSO :
            carteDesert[lgr][htr][0] = "\xB3";
            carteDesert[lgr][htr][3] = "\xB3";
            carteDesert[lgr][htr][6] = "\xC0";
            carteDesert[lgr][htr][7] = "\xC4";
            carteDesert[lgr][htr][8] = "\xC4";
            break;

        case ParoiSE :
            carteDesert[lgr][htr][2] = "\xB3";
            carteDesert[lgr][htr][5] = "\xB3";
            carteDesert[lgr][htr][6] = "\xC4";
            carteDesert[lgr][htr][7] = "\xC4";
            carteDesert[lgr][htr][8] = "\xD9";
            break;

        case AngleNE :
            carteDesert[lgr][htr][2] = "\xC0";
            break;

        case AngleNO :
            carteDesert[lgr][htr][0] = "\xD9";
            break;

        case AngleSO :
            carteDesert[lgr][htr][6] = "\xBF";
            break;

        case AngleSE :
            carteDesert[lgr][htr][8] = "\xDA";
            break;

        case Oasis :
            for(int i = 0;i <= 8;i++)
            {
                carteDesert[lgr][htr][i] = "~";
            }
            break;

        case Palmier :
            carteDesert[lgr][htr][0] = "/";
            carteDesert[lgr][htr][1] = "Y";
            carteDesert[lgr][htr][2] = "\\";
            carteDesert[lgr][htr][4] = "|";
            carteDesert[lgr][htr][7] = "_";
            break;

        case Camp :
            for(int i = 0;i <= 8;i++)
            {
                carteDesert[lgr][htr][i] = "+";
            }
            break;

        case Frontiere :
            carteDesert[lgr][htr][2] = "x";
            carteDesert[lgr][htr][5] = "x";
            carteDesert[lgr][htr][8] = "x";
            break;

        default :
            for(int i = 0;i <= 8;i++)
            {
                carteDesert[lgr][htr][i] = " ";
            }
            break;
        }
    }
}
void setCaseCarteMarai(string carteMarai[][25][9], int lgr, int htr, int grilleMarai[][25], bool champDeVision)
{
    if(lgr <= 24 && lgr >= 0 && htr <= 24 && htr >= 0)
    {
        int position = grilleMarai[lgr][htr];

        for(int i = 0;i <= 8;i++)
        {
            carteMarai[lgr][htr][i] = " ";
        }

        if(!champDeVision)
        {
            setCaseCarteMarai(carteMarai,lgr-1,htr,grilleMarai,true);
            setCaseCarteMarai(carteMarai,lgr,htr-1,grilleMarai,true);
            setCaseCarteMarai(carteMarai,lgr,htr+1,grilleMarai,true);
            setCaseCarteMarai(carteMarai,lgr+1,htr,grilleMarai,true);

            if(position == Barque)
            {
                setCaseCarteMarai(carteMarai,lgr-1,htr-1,grilleMarai,true);
                setCaseCarteMarai(carteMarai,lgr-1,htr+1,grilleMarai,true);
                setCaseCarteMarai(carteMarai,lgr+1,htr-1,grilleMarai,true);
                setCaseCarteMarai(carteMarai,lgr+1,htr+1,grilleMarai,true);
                setCaseCarteMarai(carteMarai,lgr,htr-2,grilleMarai,true);
                setCaseCarteMarai(carteMarai,lgr,htr+2,grilleMarai,true);
                setCaseCarteMarai(carteMarai,lgr-2,htr,grilleMarai,true);
                setCaseCarteMarai(carteMarai,lgr+2,htr,grilleMarai,true);
            }
        }

        switch(position)
        {
        case Bourbier :
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = "\xB1";
            }
            break;

        case Roseau :
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = "\x8C";
            }
            break;

        case RoseauN :
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = "\x8C";
            }
            carteMarai[lgr][htr][0] = "\xB1";
            carteMarai[lgr][htr][1] = "\xB1";
            carteMarai[lgr][htr][2] = "\xB1";
            break;

        case RoseauS :
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = "\x8C";
            }
            carteMarai[lgr][htr][6] = "\xB1";
            carteMarai[lgr][htr][7] = "\xB1";
            carteMarai[lgr][htr][8] = "\xB1";
            break;

        case RoseauE :
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = "\x8C";
            }
            carteMarai[lgr][htr][2] = "\xB1";
            carteMarai[lgr][htr][5] = "\xB1";
            carteMarai[lgr][htr][8] = "\xB1";
            break;

        case RoseauO :
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = "\x8C";
            }
            carteMarai[lgr][htr][0] = "\xB1";
            carteMarai[lgr][htr][3] = "\xB1";
            carteMarai[lgr][htr][6] = "\xB1";
            break;

        case RoseauNE :
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = "\xB1";
            }
            carteMarai[lgr][htr][3] = "\x8C";
            carteMarai[lgr][htr][4] = "\x8C";
            carteMarai[lgr][htr][6] = "\x8C";
            carteMarai[lgr][htr][7] = "\x8C";
            break;

        case RoseauNO :
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = "\xB1";
            }
            carteMarai[lgr][htr][4] = "\x8C";
            carteMarai[lgr][htr][5] = "\x8C";
            carteMarai[lgr][htr][7] = "\x8C";
            carteMarai[lgr][htr][8] = "\x8C";
            break;

        case RoseauSO :
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = "\xB1";
            }
            carteMarai[lgr][htr][1] = "\x8C";
            carteMarai[lgr][htr][2] = "\x8C";
            carteMarai[lgr][htr][4] = "\x8C";
            carteMarai[lgr][htr][5] = "\x8C";
            break;

        case RoseauSE :
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = "\xB1";
            }
            carteMarai[lgr][htr][0] = "\x8C";
            carteMarai[lgr][htr][1] = "\x8C";
            carteMarai[lgr][htr][3] = "\x8C";
            carteMarai[lgr][htr][4] = "\x8C";
            break;

        case RoseauNS :
            carteMarai[lgr][htr][0] = "~";
            carteMarai[lgr][htr][1] = "~";
            carteMarai[lgr][htr][2] = "~";
            carteMarai[lgr][htr][3] = "\x8C";
            carteMarai[lgr][htr][4] = "\x8C";
            carteMarai[lgr][htr][5] = "\x8C";
            carteMarai[lgr][htr][6] = "\xB1";
            carteMarai[lgr][htr][7] = "\xB1";
            carteMarai[lgr][htr][8] = "\xB1";
            break;

        case Lac :
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = "~";
            }
            carteMarai[lgr][htr][0] = " ";
            carteMarai[lgr][htr][3] = " ";
            carteMarai[lgr][htr][5] = " ";
            carteMarai[lgr][htr][7] = " ";
            break;

        case Ponton :
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = "=";
            }
            break;

        case Cabane :
            carteMarai[lgr][htr][3] = "/";
            carteMarai[lgr][htr][1] = "_";
            carteMarai[lgr][htr][5] = "\\";
            carteMarai[lgr][htr][6] = "|";
            carteMarai[lgr][htr][7] = "_";
            carteMarai[lgr][htr][8] = "|";
            break;

        case TourHaut :
            carteMarai[lgr][htr][1] = "|";
            carteMarai[lgr][htr][3] = "/";
            carteMarai[lgr][htr][5] = "\\";
            carteMarai[lgr][htr][6] = "|";
            carteMarai[lgr][htr][8] = "|";
            break;

        case TourBas :
            for(int i = 0;i <= 8;i++)
            {
                if(i != 1 && i != 4 && i != 7)
                {
                    carteMarai[lgr][htr][i] = "|";
                }
                else if(i == 7)
                {
                    carteMarai[lgr][htr][i] = "_";
                }
            }
            break;

        case Barque :
            carteMarai[lgr][htr][1] = "|";
            carteMarai[lgr][htr][2] = ">";
            carteMarai[lgr][htr][3] = "_";
            carteMarai[lgr][htr][4] = "|";
            carteMarai[lgr][htr][5] = "_";
            carteMarai[lgr][htr][6] = "\\";
            carteMarai[lgr][htr][7] = "_";
            carteMarai[lgr][htr][8] = "/";
            break;

        case Marai :
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = "'";
            }
            break;

        case MaraiN :
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = "'";
            }
            carteMarai[lgr][htr][0] = "~";
            carteMarai[lgr][htr][1] = "~";
            carteMarai[lgr][htr][2] = "~";
            break;

        case MaraiS :
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = "'";
            }
            carteMarai[lgr][htr][6] = "~";
            carteMarai[lgr][htr][7] = "~";
            carteMarai[lgr][htr][8] = "~";
            break;

        case MaraiE :
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = "'";
            }
            carteMarai[lgr][htr][2] = "~";
            carteMarai[lgr][htr][5] = "~";
            carteMarai[lgr][htr][8] = "~";
            break;

        case MaraiO :
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = "'";
            }
            carteMarai[lgr][htr][0] = "~";
            carteMarai[lgr][htr][3] = "~";
            carteMarai[lgr][htr][6] = "~";
            break;

        case MaraiNE :
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = "~";
            }
            carteMarai[lgr][htr][3] = "'";
            carteMarai[lgr][htr][4] = "'";
            carteMarai[lgr][htr][6] = "'";
            carteMarai[lgr][htr][7] = "'";
            break;

        case MaraiNO :
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = "~";
            }
            carteMarai[lgr][htr][4] = "'";
            carteMarai[lgr][htr][5] = "'";
            carteMarai[lgr][htr][7] = "'";
            carteMarai[lgr][htr][8] = "'";
            break;

        case MaraiSO :
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = "~";
            }
            carteMarai[lgr][htr][1] = "'";
            carteMarai[lgr][htr][2] = "'";
            carteMarai[lgr][htr][4] = "'";
            carteMarai[lgr][htr][5] = "'";
            break;

        case MaraiSE :
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = "~";
            }
            carteMarai[lgr][htr][0] = "'";
            carteMarai[lgr][htr][1] = "'";
            carteMarai[lgr][htr][3] = "'";
            carteMarai[lgr][htr][4] = "'";
            break;

        default :
            for(int i = 0;i <= 8;i++)
            {
                carteMarai[lgr][htr][i] = " ";
            }
        }
    }
}
void setCaseCarteTourBas(string carteTourBas[][20][9],int lgr,int htr,int grilleTourBas[][20],bool champDeVision)
{
    if(lgr <= 19 && lgr >= 0 && htr <= 19 && htr >= 0)
    {
        int position = grilleTourBas[lgr][htr];

        if(!champDeVision)
        {
            setCaseCarteTourBas(carteTourBas,lgr-1,htr,grilleTourBas,true);
            setCaseCarteTourBas(carteTourBas,lgr,htr-1,grilleTourBas,true);
            setCaseCarteTourBas(carteTourBas,lgr,htr+1,grilleTourBas,true);
            setCaseCarteTourBas(carteTourBas,lgr+1,htr,grilleTourBas,true);
        }

        switch(position)
        {
        case PetiteColonne :
            carteTourBas[lgr][htr][0] = "\xDA";
            carteTourBas[lgr][htr][1] = "\xC4";
            carteTourBas[lgr][htr][2] = "\xBF";
            carteTourBas[lgr][htr][3] = "\xB3";
            carteTourBas[lgr][htr][4] = "\xB2";
            carteTourBas[lgr][htr][5] = "\xB3";
            carteTourBas[lgr][htr][6] = "\xC0";
            carteTourBas[lgr][htr][7] = "\xC4";
            carteTourBas[lgr][htr][8] = "\xD9";
            break;

        case GrandeColonneNE :
            carteTourBas[lgr][htr][0] = "\xC4";
            carteTourBas[lgr][htr][1] = "\xC4";
            carteTourBas[lgr][htr][2] = "\xBF";
            carteTourBas[lgr][htr][3] = "\xB2";
            carteTourBas[lgr][htr][4] = "\xB2";
            carteTourBas[lgr][htr][5] = "\xB3";
            carteTourBas[lgr][htr][6] = "\xB2";
            carteTourBas[lgr][htr][7] = "\xB2";
            carteTourBas[lgr][htr][8] = "\xB3";
            break;

        case GrandeColonneNO :
            carteTourBas[lgr][htr][0] = "\xDA";
            carteTourBas[lgr][htr][1] = "\xC4";
            carteTourBas[lgr][htr][2] = "\xC4";
            carteTourBas[lgr][htr][3] = "\xB3";
            carteTourBas[lgr][htr][4] = "\xB2";
            carteTourBas[lgr][htr][5] = "\xB2";
            carteTourBas[lgr][htr][6] = "\xB3";
            carteTourBas[lgr][htr][7] = "\xB2";
            carteTourBas[lgr][htr][8] = "\xB2";
            break;

        case GrandeColonneSO :
            carteTourBas[lgr][htr][0] = "\xB3";
            carteTourBas[lgr][htr][1] = "\xB2";
            carteTourBas[lgr][htr][2] = "\xB2";
            carteTourBas[lgr][htr][3] = "\xB3";
            carteTourBas[lgr][htr][4] = "\xB2";
            carteTourBas[lgr][htr][5] = "\xB2";
            carteTourBas[lgr][htr][6] = "\xC0";
            carteTourBas[lgr][htr][7] = "\xC4";
            carteTourBas[lgr][htr][8] = "\xC4";
            break;

        case GrandeColonneSE :
            carteTourBas[lgr][htr][0] = "\xB2";
            carteTourBas[lgr][htr][1] = "\xB2";
            carteTourBas[lgr][htr][2] = "\xB3";
            carteTourBas[lgr][htr][3] = "\xB2";
            carteTourBas[lgr][htr][4] = "\xB2";
            carteTourBas[lgr][htr][5] = "\xB3";
            carteTourBas[lgr][htr][6] = "\xC4";
            carteTourBas[lgr][htr][7] = "\xC4";
            carteTourBas[lgr][htr][8] = "\xD9";
            break;

        case Dalle :
            for(int i = 0;i <= 8;i++)
            {
                carteTourBas[lgr][htr][i] = "\x01";
            }
            break;

        case Escalier :
            carteTourBas[lgr][htr][0] = "\xDA";
            carteTourBas[lgr][htr][1] = "-";
            carteTourBas[lgr][htr][2] = "\xBF";
            carteTourBas[lgr][htr][3] = "|";
            carteTourBas[lgr][htr][4] = " ";
            carteTourBas[lgr][htr][5] = "|";
            carteTourBas[lgr][htr][6] = "\xC1";
            carteTourBas[lgr][htr][8] = "\xC1";
            carteTourBas[lgr][htr][7] = "H";
            break;

        default :
            for(int i = 0;i <= 8;i++)
            {
                carteTourBas[lgr][htr][i] = " ";
            }
            break;
        }
    }
}
void setCaseCarteTourHaut(string carteTourHaut[][20][9],int lgr,int htr,int grilleTourHaut[][20],bool champDeVision)
{
    if(lgr <= 19 && lgr >= 0 && htr <= 19 && htr >= 0)
    {
        int position = grilleTourHaut[lgr][htr];

        if(!champDeVision)
        {
            setCaseCarteTourHaut(carteTourHaut,lgr-1,htr,grilleTourHaut,true);
            setCaseCarteTourHaut(carteTourHaut,lgr,htr-1,grilleTourHaut,true);
            setCaseCarteTourHaut(carteTourHaut,lgr,htr+1,grilleTourHaut,true);
            setCaseCarteTourHaut(carteTourHaut,lgr+1,htr,grilleTourHaut,true);
        }

        switch(position)
        {
        case PetiteColonne :
            carteTourHaut[lgr][htr][0] = "\xDA";
            carteTourHaut[lgr][htr][1] = "\xC4";
            carteTourHaut[lgr][htr][2] = "\xBF";
            carteTourHaut[lgr][htr][3] = "|";
            carteTourHaut[lgr][htr][4] = "\xB2";
            carteTourHaut[lgr][htr][5] = "|";
            carteTourHaut[lgr][htr][6] = "\xC0";
            carteTourHaut[lgr][htr][7] = "\xC4";
            carteTourHaut[lgr][htr][8] = "\xD9";
            break;

        case GrandeColonneNE :
            carteTourHaut[lgr][htr][0] = "\xC4";
            carteTourHaut[lgr][htr][1] = "\xC4";
            carteTourHaut[lgr][htr][2] = "\xBF";
            carteTourHaut[lgr][htr][3] = "\xB2";
            carteTourHaut[lgr][htr][4] = "\xB2";
            carteTourHaut[lgr][htr][5] = "|";
            carteTourHaut[lgr][htr][6] = "\xB2";
            carteTourHaut[lgr][htr][7] = "\xB2";
            carteTourHaut[lgr][htr][8] = "|";
            break;

        case GrandeColonneNO :
            carteTourHaut[lgr][htr][0] = "\xDA";
            carteTourHaut[lgr][htr][1] = "\xC4";
            carteTourHaut[lgr][htr][2] = "\xC4";
            carteTourHaut[lgr][htr][3] = "|";
            carteTourHaut[lgr][htr][4] = "\xB2";
            carteTourHaut[lgr][htr][5] = "\xB2";
            carteTourHaut[lgr][htr][6] = "|";
            carteTourHaut[lgr][htr][7] = "\xB2";
            carteTourHaut[lgr][htr][8] = "\xB2";
            break;

        case GrandeColonneSO :
            carteTourHaut[lgr][htr][0] = "|";
            carteTourHaut[lgr][htr][1] = "\xB2";
            carteTourHaut[lgr][htr][2] = "\xB2";
            carteTourHaut[lgr][htr][3] = "|";
            carteTourHaut[lgr][htr][4] = "\xB2";
            carteTourHaut[lgr][htr][5] = "\xB2";
            carteTourHaut[lgr][htr][6] = "\xC0";
            carteTourHaut[lgr][htr][7] = "\xC4";
            carteTourHaut[lgr][htr][8] = "\xC4";
            break;

        case GrandeColonneSE :
            carteTourHaut[lgr][htr][0] = "\xB2";
            carteTourHaut[lgr][htr][1] = "\xB2";
            carteTourHaut[lgr][htr][2] = "|";
            carteTourHaut[lgr][htr][3] = "\xB2";
            carteTourHaut[lgr][htr][4] = "\xB2";
            carteTourHaut[lgr][htr][5] = "|";
            carteTourHaut[lgr][htr][6] = "\xC4";
            carteTourHaut[lgr][htr][7] = "\xC4";
            carteTourHaut[lgr][htr][8] = "\xD9";
            break;

        case Dalle :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "\x01";
            }
            break;

        case Escalier :
            carteTourHaut[lgr][htr][0] = "\xDA";
            carteTourHaut[lgr][htr][1] = "\xC4";
            carteTourHaut[lgr][htr][2] = "\xBF";
            carteTourHaut[lgr][htr][3] = "|";
            carteTourHaut[lgr][htr][4] = " ";
            carteTourHaut[lgr][htr][5] = "|";
            carteTourHaut[lgr][htr][6] = "\xC1";
            carteTourHaut[lgr][htr][7] = "H";
            carteTourHaut[lgr][htr][8] = "\xC1";
            break;

        case Passerelle :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "=";
            }
            break;

        case PasserelleN :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "=";
            }
            carteTourHaut[lgr][htr][0] = "\xC4";
            carteTourHaut[lgr][htr][1] = "\xC4";
            carteTourHaut[lgr][htr][2] = "\xC4";
            break;

        case PasserelleS :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "=";
            }
            carteTourHaut[lgr][htr][6] = "\xC4";
            carteTourHaut[lgr][htr][7] = "\xC4";
            carteTourHaut[lgr][htr][8] = "\xC4";
            break;

        case PasserelleE :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "=";
            }
            carteTourHaut[lgr][htr][2] = "|";
            carteTourHaut[lgr][htr][5] = "|";
            carteTourHaut[lgr][htr][8] = "|";
            break;

        case PasserelleO :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "=";
            }
            carteTourHaut[lgr][htr][0] = "|";
            carteTourHaut[lgr][htr][3] = "|";
            carteTourHaut[lgr][htr][6] = "|";
            break;

        case PasserelleNE :
            carteTourHaut[lgr][htr][0] = "\xC4";
            carteTourHaut[lgr][htr][1] = "\xC4";
            carteTourHaut[lgr][htr][2] = "\xBF";
            carteTourHaut[lgr][htr][3] = "=";
            carteTourHaut[lgr][htr][4] = "=";
            carteTourHaut[lgr][htr][5] = "|";
            carteTourHaut[lgr][htr][6] = "=";
            carteTourHaut[lgr][htr][7] = "=";
            carteTourHaut[lgr][htr][8] = "|";
            break;

        case PasserelleNO :
            carteTourHaut[lgr][htr][0] = "\xDA";
            carteTourHaut[lgr][htr][1] = "\xC4";
            carteTourHaut[lgr][htr][2] = "\xC4";
            carteTourHaut[lgr][htr][3] = "|";
            carteTourHaut[lgr][htr][4] = "=";
            carteTourHaut[lgr][htr][5] = "=";
            carteTourHaut[lgr][htr][6] = "|";
            carteTourHaut[lgr][htr][7] = "=";
            carteTourHaut[lgr][htr][8] = "=";
            break;

        case PasserelleSO :
            carteTourHaut[lgr][htr][0] = "|";
            carteTourHaut[lgr][htr][1] = "=";
            carteTourHaut[lgr][htr][2] = "=";
            carteTourHaut[lgr][htr][3] = "|";
            carteTourHaut[lgr][htr][4] = "=";
            carteTourHaut[lgr][htr][5] = "=";
            carteTourHaut[lgr][htr][6] = "\xC0";
            carteTourHaut[lgr][htr][7] = "\xC4";
            carteTourHaut[lgr][htr][8] = "\xC4";
            break;

        case PasserelleSE :
            carteTourHaut[lgr][htr][0] = "=";
            carteTourHaut[lgr][htr][1] = "=";
            carteTourHaut[lgr][htr][2] = "|";
            carteTourHaut[lgr][htr][3] = "=";
            carteTourHaut[lgr][htr][4] = "=";
            carteTourHaut[lgr][htr][5] = "|";
            carteTourHaut[lgr][htr][6] = "\xC4";
            carteTourHaut[lgr][htr][7] = "\xC4";
            carteTourHaut[lgr][htr][8] = "\xD9";
            break;

        case PasserelleNS :
            carteTourHaut[lgr][htr][0] = "\xC4";
            carteTourHaut[lgr][htr][1] = "\xC4";
            carteTourHaut[lgr][htr][2] = "\xC4";
            carteTourHaut[lgr][htr][3] = "=";
            carteTourHaut[lgr][htr][4] = "=";
            carteTourHaut[lgr][htr][5] = "=";
            carteTourHaut[lgr][htr][6] = "\xC4";
            carteTourHaut[lgr][htr][7] = "\xC4";
            carteTourHaut[lgr][htr][8] = "\xC4";
            break;

        case PasserelleEO :
            carteTourHaut[lgr][htr][0] = "|";
            carteTourHaut[lgr][htr][1] = "=";
            carteTourHaut[lgr][htr][2] = "|";
            carteTourHaut[lgr][htr][3] = "|";
            carteTourHaut[lgr][htr][4] = "=";
            carteTourHaut[lgr][htr][5] = "|";
            carteTourHaut[lgr][htr][6] = "|";
            carteTourHaut[lgr][htr][7] = "=";
            carteTourHaut[lgr][htr][8] = "|";
            break;

        case PasserelleAngleNE :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "=";
            }
            carteTourHaut[lgr][htr][2] = "\xC0";
            break;

        case PasserelleAngleNO :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "=";
            }
            carteTourHaut[lgr][htr][0] = "\xD9";
            break;

        case PasserelleAngleSO :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "=";
            }
            carteTourHaut[lgr][htr][6] = "\xBF";
            break;

        case PasserelleAngleSE :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "=";
            }
            carteTourHaut[lgr][htr][8] = "\xDA";
            break;

        case PasserelleSAngleNE :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "=";
            }
            carteTourHaut[lgr][htr][6] = "\xC4";
            carteTourHaut[lgr][htr][7] = "\xC4";
            carteTourHaut[lgr][htr][8] = "\xC4";
            carteTourHaut[lgr][htr][2] = "\xC0";
            break;

        case PasserelleSAngleNO :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "=";
            }
            carteTourHaut[lgr][htr][6] = "\xC4";
            carteTourHaut[lgr][htr][7] = "\xC4";
            carteTourHaut[lgr][htr][8] = "\xC4";
            carteTourHaut[lgr][htr][0] = "\xD9";
            break;

        case PasserelleOAngleNE :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "=";
            }
            carteTourHaut[lgr][htr][0] = "|";
            carteTourHaut[lgr][htr][3] = "|";
            carteTourHaut[lgr][htr][6] = "|";
            carteTourHaut[lgr][htr][2] = "\xC0";
            break;

        case PasserelleEAngleSO :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "=";
            }
            carteTourHaut[lgr][htr][2] = "|";
            carteTourHaut[lgr][htr][5] = "|";
            carteTourHaut[lgr][htr][8] = "|";
            carteTourHaut[lgr][htr][6] = "\xBF";
            break;

        case PasserelleEAngleNO :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "=";
            }
            carteTourHaut[lgr][htr][2] = "|";
            carteTourHaut[lgr][htr][5] = "|";
            carteTourHaut[lgr][htr][8] = "|";
            carteTourHaut[lgr][htr][0] = "\xD9";
            break;

        case PasserelleNAngleSE :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "=";
            }
            carteTourHaut[lgr][htr][0] = "\xC4";
            carteTourHaut[lgr][htr][1] = "\xC4";
            carteTourHaut[lgr][htr][2] = "\xC4";
            carteTourHaut[lgr][htr][8] = "\xDA";
            break;

        case PasserelleOAngleSE :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "=";
            }
            carteTourHaut[lgr][htr][0] = "|";
            carteTourHaut[lgr][htr][3] = "|";
            carteTourHaut[lgr][htr][6] = "|";
            carteTourHaut[lgr][htr][8] = "\xDA";
            break;

        case PasserelleNEAngleSO :
            carteTourHaut[lgr][htr][0] = "\xC4";
            carteTourHaut[lgr][htr][1] = "\xC4";
            carteTourHaut[lgr][htr][2] = "\xBF";
            carteTourHaut[lgr][htr][3] = "=";
            carteTourHaut[lgr][htr][4] = "=";
            carteTourHaut[lgr][htr][5] = "|";
            carteTourHaut[lgr][htr][6] = "\xBF";
            carteTourHaut[lgr][htr][7] = "=";
            carteTourHaut[lgr][htr][8] = "|";
            break;

        case PasserelleNOAngleSE :
            carteTourHaut[lgr][htr][0] = "\xDA";
            carteTourHaut[lgr][htr][1] = "\xC4";
            carteTourHaut[lgr][htr][2] = "\xC4";
            carteTourHaut[lgr][htr][3] = "|";
            carteTourHaut[lgr][htr][4] = "=";
            carteTourHaut[lgr][htr][5] = "=";
            carteTourHaut[lgr][htr][6] = "|";
            carteTourHaut[lgr][htr][7] = "=";
            carteTourHaut[lgr][htr][8] = "\xDA";
            break;

        case PasserelleSOAngleNE :
            carteTourHaut[lgr][htr][0] = "|";
            carteTourHaut[lgr][htr][1] = "=";
            carteTourHaut[lgr][htr][2] = "\xC0";
            carteTourHaut[lgr][htr][3] = "|";
            carteTourHaut[lgr][htr][4] = "=";
            carteTourHaut[lgr][htr][5] = "=";
            carteTourHaut[lgr][htr][6] = "\xC0";
            carteTourHaut[lgr][htr][7] = "\xC4";
            carteTourHaut[lgr][htr][8] = "\xC4";
            break;

        case PasserelleSEAngleNO :
            carteTourHaut[lgr][htr][0] = "\xD9";
            carteTourHaut[lgr][htr][1] = "=";
            carteTourHaut[lgr][htr][2] = "|";
            carteTourHaut[lgr][htr][3] = "=";
            carteTourHaut[lgr][htr][4] = "=";
            carteTourHaut[lgr][htr][5] = "|";
            carteTourHaut[lgr][htr][6] = "\xC4";
            carteTourHaut[lgr][htr][7] = "\xC4";
            carteTourHaut[lgr][htr][8] = "\xD9";
            break;

        case PasserelleAngleNESO :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "=";
            }
            carteTourHaut[lgr][htr][2] = "\xC0";
            carteTourHaut[lgr][htr][6] = "\xBF";
            break;

        case PasserelleAngleNONE :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "=";
            }
            carteTourHaut[lgr][htr][0] = "\xD9";
            carteTourHaut[lgr][htr][2] = "\xC0";
            break;

        case PasserelleNAngleSOSE :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "=";
            }
            carteTourHaut[lgr][htr][0] = "\xC4";
            carteTourHaut[lgr][htr][1] = "\xC4";
            carteTourHaut[lgr][htr][2] = "\xC4";
            carteTourHaut[lgr][htr][6] = "\xBF";
            carteTourHaut[lgr][htr][8] = "\xDA";
            break;

        case PasserelleSAngleNONE :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "=";
            }
            carteTourHaut[lgr][htr][6] = "\xC4";
            carteTourHaut[lgr][htr][7] = "\xC4";
            carteTourHaut[lgr][htr][8] = "\xC4";
            carteTourHaut[lgr][htr][0] = "\xD9";
            carteTourHaut[lgr][htr][2] = "\xC0";
            break;

        case PasserelleEAngleNOSO :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "=";
            }
            carteTourHaut[lgr][htr][2] = "|";
            carteTourHaut[lgr][htr][5] = "|";
            carteTourHaut[lgr][htr][8] = "|";
            carteTourHaut[lgr][htr][0] = "\xD9";
            carteTourHaut[lgr][htr][6] = "\xBF";
            break;

        case PasserelleOAngleNESE :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = "=";
            }
            carteTourHaut[lgr][htr][0] = "|";
            carteTourHaut[lgr][htr][3] = "|";
            carteTourHaut[lgr][htr][6] = "|";
            carteTourHaut[lgr][htr][2] = "\xC0";
            carteTourHaut[lgr][htr][8] = "\xDA";
            break;

        default :
            for(int i = 0;i <= 8;i++)
            {
                carteTourHaut[lgr][htr][i] = " ";
            }
            break;
        }
    }
}
void setCaseCarteArchipel(string carteArchipel[][30][9], int lgr, int htr, int grilleArchipel[][30], bool champDeVision)
{
    if(lgr <= 29 && lgr >= 0 && htr <= 29 && htr >= 0)
    {
        int position = grilleArchipel[lgr][htr];

        if(!champDeVision)
        {
            setCaseCarteArchipel(carteArchipel,lgr-1,htr,grilleArchipel,true);
            setCaseCarteArchipel(carteArchipel,lgr,htr-1,grilleArchipel,true);
            setCaseCarteArchipel(carteArchipel,lgr,htr+1,grilleArchipel,true);
            setCaseCarteArchipel(carteArchipel,lgr+1,htr,grilleArchipel,true);

            if(position == Barque)
            {
                setCaseCarteArchipel(carteArchipel,lgr-1,htr-1,grilleArchipel,true);
                setCaseCarteArchipel(carteArchipel,lgr-1,htr+1,grilleArchipel,true);
                setCaseCarteArchipel(carteArchipel,lgr+1,htr-1,grilleArchipel,true);
                setCaseCarteArchipel(carteArchipel,lgr+1,htr+1,grilleArchipel,true);
                setCaseCarteArchipel(carteArchipel,lgr,htr-2,grilleArchipel,true);
                setCaseCarteArchipel(carteArchipel,lgr,htr+2,grilleArchipel,true);
                setCaseCarteArchipel(carteArchipel,lgr-2,htr,grilleArchipel,true);
                setCaseCarteArchipel(carteArchipel,lgr+2,htr,grilleArchipel,true);
            }
        }

        switch(position)
        {
        case Ocean :
            for(int i = 0;i <= 8;i++)
            {
                carteArchipel[lgr][htr][i] = "~";
            }
            carteArchipel[lgr][htr][0] = " ";
            carteArchipel[lgr][htr][3] = " ";
            carteArchipel[lgr][htr][5] = " ";
            carteArchipel[lgr][htr][7] = " ";
            break;

        case Cote :
            for(int i = 0;i <= 8;i++)
            {
                carteArchipel[lgr][htr][i] = ".";
            }
            break;

        case CoteNE :
            for(int i = 0;i <= 8;i++)
            {
                carteArchipel[lgr][htr][i] = ".";
            }
            carteArchipel[lgr][htr][1] = "\xB0";
            carteArchipel[lgr][htr][2] = "\xB0";
            carteArchipel[lgr][htr][5] = "\xB0";
            break;

        case CoteNO :
            for(int i = 0;i <= 8;i++)
            {
                carteArchipel[lgr][htr][i] = ".";
            }
            carteArchipel[lgr][htr][0] = "\xB0";
            carteArchipel[lgr][htr][1] = "\xB0";
            carteArchipel[lgr][htr][3] = "\xB0";
            break;

        case CoteSO :
            for(int i = 0;i <= 8;i++)
            {
                carteArchipel[lgr][htr][i] = ".";
            }
            carteArchipel[lgr][htr][3] = "\xB0";
            carteArchipel[lgr][htr][6] = "\xB0";
            carteArchipel[lgr][htr][7] = "\xB0";
            break;

        case CoteSE :
            for(int i = 0;i <= 8;i++)
            {
                carteArchipel[lgr][htr][i] = ".";
            }
            carteArchipel[lgr][htr][5] = "\xB0";
            carteArchipel[lgr][htr][7] = "\xB0";
            carteArchipel[lgr][htr][8] = "\xB0";
            break;

        case PlageN :
            carteArchipel[lgr][htr][0] = "~";
            carteArchipel[lgr][htr][1] = "~";
            carteArchipel[lgr][htr][2] = "~";
            carteArchipel[lgr][htr][3] = "\xB0";
            carteArchipel[lgr][htr][4] = "\xB0";
            carteArchipel[lgr][htr][5] = "\xB0";
            carteArchipel[lgr][htr][6] = ".";
            carteArchipel[lgr][htr][7] = ".";
            carteArchipel[lgr][htr][8] = ".";
            break;

        case PlageS :
            carteArchipel[lgr][htr][0] = ".";
            carteArchipel[lgr][htr][1] = ".";
            carteArchipel[lgr][htr][2] = ".";
            carteArchipel[lgr][htr][3] = "\xB0";
            carteArchipel[lgr][htr][4] = "\xB0";
            carteArchipel[lgr][htr][5] = "\xB0";
            carteArchipel[lgr][htr][6] = "~";
            carteArchipel[lgr][htr][7] = "~";
            carteArchipel[lgr][htr][8] = "~";
            break;

        case PlageE :
            carteArchipel[lgr][htr][0] = ".";
            carteArchipel[lgr][htr][1] = "\xB0";
            carteArchipel[lgr][htr][2] = "~";
            carteArchipel[lgr][htr][3] = ".";
            carteArchipel[lgr][htr][4] = "\xB0";
            carteArchipel[lgr][htr][5] = "~";
            carteArchipel[lgr][htr][6] = ".";
            carteArchipel[lgr][htr][7] = "\xB0";
            carteArchipel[lgr][htr][8] = "~";
            break;

        case PlageO :
            carteArchipel[lgr][htr][0] = "~";
            carteArchipel[lgr][htr][1] = "\xB0";
            carteArchipel[lgr][htr][2] = ".";
            carteArchipel[lgr][htr][3] = "~";
            carteArchipel[lgr][htr][4] = "\xB0";
            carteArchipel[lgr][htr][5] = ".";
            carteArchipel[lgr][htr][6] = "~";
            carteArchipel[lgr][htr][7] = "\xB0";
            carteArchipel[lgr][htr][8] = ".";
            break;

        case PlageNE :
            for(int i = 0;i <= 8 ;i++)
            {
                carteArchipel[lgr][htr][i] = "~";
            }
            carteArchipel[lgr][htr][3] = "\xB0";
            carteArchipel[lgr][htr][6] = "\xB0";
            carteArchipel[lgr][htr][7] = "\xB0";
            break;

        case PlageNO :
            for(int i = 0;i <= 8 ;i++)
            {
                carteArchipel[lgr][htr][i] = "~";
            }
            carteArchipel[lgr][htr][8] = "\xB0";
            carteArchipel[lgr][htr][5] = "\xB0";
            carteArchipel[lgr][htr][7] = "\xB0";

            break;

        case PlageSO :
            for(int i = 0;i <= 8 ;i++)
            {
                carteArchipel[lgr][htr][i] = "~";
            }
            carteArchipel[lgr][htr][1] = "\xB0";
            carteArchipel[lgr][htr][2] = "\xB0";
            carteArchipel[lgr][htr][5] = "\xB0";
            break;

        case PlageSE :
            for(int i = 0;i <= 8 ;i++)
            {
                carteArchipel[lgr][htr][i] = "~";
            }
            carteArchipel[lgr][htr][1] = "\xB0";
            carteArchipel[lgr][htr][3] = "\xB0";
            carteArchipel[lgr][htr][0] = "\xB0";
            break;

        case Barque :
            carteArchipel[lgr][htr][1] = "|";
            carteArchipel[lgr][htr][2] = ">";
            carteArchipel[lgr][htr][3] = "_";
            carteArchipel[lgr][htr][4] = "|";
            carteArchipel[lgr][htr][5] = "_";
            carteArchipel[lgr][htr][6] = "\\";
            carteArchipel[lgr][htr][7] = "_";
            carteArchipel[lgr][htr][8] = "/";
            break;

        case Escalier :
            carteArchipel[lgr][htr][0] = "\xDA";
            carteArchipel[lgr][htr][1] = "-";
            carteArchipel[lgr][htr][2] = "\xBF";
            carteArchipel[lgr][htr][3] = "|";
            carteArchipel[lgr][htr][4] = " ";
            carteArchipel[lgr][htr][5] = "|";
            carteArchipel[lgr][htr][6] = "\xC1";
            carteArchipel[lgr][htr][8] = "\xC1";
            carteArchipel[lgr][htr][7] = "H";
            break;

        default :
            for(int i = 0;i <= 8;i++)
            {
                carteArchipel[lgr][htr][i] = " ";
            }
        }
    }
}
void setCaseCarteGrotte(string carteGrotte[][15][9], int lgr, int htr, int grilleGrotte[][15], bool champDeVision)
{
    if(lgr <= 24 && lgr >= 0 && htr <= 14 && htr >= 0)
    {
        int position = grilleGrotte[lgr][htr];

        if(!champDeVision)
        {
            setCaseCarteGrotte(carteGrotte,lgr-1,htr,grilleGrotte,true);
            setCaseCarteGrotte(carteGrotte,lgr,htr-1,grilleGrotte,true);
            setCaseCarteGrotte(carteGrotte,lgr,htr+1,grilleGrotte,true);
            setCaseCarteGrotte(carteGrotte,lgr+1,htr,grilleGrotte,true);
        }

        switch(position)
        {
        case Mur :
            for(int i = 0;i <= 8;i++)
            {
                carteGrotte[lgr][htr][i] = "\xB0";
            }
            break;

        case MurN :
            carteGrotte[lgr][htr][0] = "\xC4";
            carteGrotte[lgr][htr][1] = "\xC4";
            carteGrotte[lgr][htr][2] = "\xC4";
            break;

        case MurS :
            carteGrotte[lgr][htr][6] = "\xC4";
            carteGrotte[lgr][htr][7] = "\xC4";
            carteGrotte[lgr][htr][8] = "\xC4";
            break;

        case MurE :
            carteGrotte[lgr][htr][2] = "|";
            carteGrotte[lgr][htr][5] = "|";
            carteGrotte[lgr][htr][8] = "|";
            break;

        case MurO :
            carteGrotte[lgr][htr][0] = "|";
            carteGrotte[lgr][htr][3] = "|";
            carteGrotte[lgr][htr][6] = "|";
            break;

        case MurNO :
            carteGrotte[lgr][htr][0] = "\xDA";
            carteGrotte[lgr][htr][1] = "\xC4";
            carteGrotte[lgr][htr][2] = "\xC4";
            carteGrotte[lgr][htr][3] = "|";
            carteGrotte[lgr][htr][6] = "|";
            break;

        case MurNE :
            carteGrotte[lgr][htr][0] = "\xC4";
            carteGrotte[lgr][htr][1] = "\xC4";
            carteGrotte[lgr][htr][2] = "\xBF";
            carteGrotte[lgr][htr][5] = "|";
            carteGrotte[lgr][htr][8] = "|";
            break;

        case MurSE :
            carteGrotte[lgr][htr][8] = "\xD9";
            carteGrotte[lgr][htr][6] = "\xC4";
            carteGrotte[lgr][htr][7] = "\xC4";
            carteGrotte[lgr][htr][2] = "|";
            carteGrotte[lgr][htr][5] = "|";
            break;

        case MurSO :
            carteGrotte[lgr][htr][6] = "\xC0";
            carteGrotte[lgr][htr][7] = "\xC4";
            carteGrotte[lgr][htr][8] = "\xC4";
            carteGrotte[lgr][htr][0] = "|";
            carteGrotte[lgr][htr][3] = "|";
            break;

        case MurNS :
            carteGrotte[lgr][htr][0] = "\xC4";
            carteGrotte[lgr][htr][1] = "\xC4";
            carteGrotte[lgr][htr][2] = "\xC4";
            carteGrotte[lgr][htr][6] = "\xC4";
            carteGrotte[lgr][htr][7] = "\xC4";
            carteGrotte[lgr][htr][8] = "\xC4";
            break;

        case MurEO :
            carteGrotte[lgr][htr][0] = "|";
            carteGrotte[lgr][htr][2] = "|";
            carteGrotte[lgr][htr][3] = "|";
            carteGrotte[lgr][htr][5] = "|";
            carteGrotte[lgr][htr][6] = "|";
            carteGrotte[lgr][htr][8] = "|";
            break;

        case ImpasseN :
            carteGrotte[lgr][htr][0] = "\xDA";
            carteGrotte[lgr][htr][1] = "\xC4";
            carteGrotte[lgr][htr][2] = "\xBF";
            carteGrotte[lgr][htr][3] = "|";
            carteGrotte[lgr][htr][5] = "|";
            carteGrotte[lgr][htr][6] = "|";
            carteGrotte[lgr][htr][8] = "|";
            break;

        case ImpasseS :
            carteGrotte[lgr][htr][0] = "|";
            carteGrotte[lgr][htr][2] = "|";
            carteGrotte[lgr][htr][3] = "|";
            carteGrotte[lgr][htr][5] = "|";
            carteGrotte[lgr][htr][6] = "\xC0";
            carteGrotte[lgr][htr][7] = "\xC4";
            carteGrotte[lgr][htr][8] = "\xD9";
            break;

        case ImpasseE :
            carteGrotte[lgr][htr][0] = "\xC4";
            carteGrotte[lgr][htr][1] = "\xC4";
            carteGrotte[lgr][htr][2] = "\xBF";
            carteGrotte[lgr][htr][5] = "|";
            carteGrotte[lgr][htr][6] = "\xC4";
            carteGrotte[lgr][htr][7] = "\xC4";
            carteGrotte[lgr][htr][8] = "\xD9";
            break;

        case ImpasseO :
            carteGrotte[lgr][htr][0] = "\xDA";
            carteGrotte[lgr][htr][1] = "\xC4";
            carteGrotte[lgr][htr][2] = "\xC4";
            carteGrotte[lgr][htr][3] = "|";
            carteGrotte[lgr][htr][6] = "\xC0";
            carteGrotte[lgr][htr][7] = "\xC4";
            carteGrotte[lgr][htr][8] = "\xC4";
            break;

        case Escalier :
            carteGrotte[lgr][htr][0] = "\xDA";
            carteGrotte[lgr][htr][1] = "\xC4";
            carteGrotte[lgr][htr][2] = "\xBF";
            carteGrotte[lgr][htr][3] = "|";
            carteGrotte[lgr][htr][4] = " ";
            carteGrotte[lgr][htr][5] = "|";
            carteGrotte[lgr][htr][6] = "\xC1";
            carteGrotte[lgr][htr][8] = "\xC1";
            carteGrotte[lgr][htr][7] = "H";
            break;

        case MurNAngleSE :
            carteGrotte[lgr][htr][0] = "\xC4";
            carteGrotte[lgr][htr][1] = "\xC4";
            carteGrotte[lgr][htr][2] = "\xC4";
            carteGrotte[lgr][htr][8] = "\xDA";
            break;

        case MurNAngleSO :
            carteGrotte[lgr][htr][0] = "\xC4";
            carteGrotte[lgr][htr][1] = "\xC4";
            carteGrotte[lgr][htr][2] = "\xC4";
            carteGrotte[lgr][htr][6] = "\xBF";
            break;

        case MurNAngleSOSE :
            carteGrotte[lgr][htr][0] = "\xC4";
            carteGrotte[lgr][htr][1] = "\xC4";
            carteGrotte[lgr][htr][2] = "\xC4";
            carteGrotte[lgr][htr][6] = "\xBF";
            carteGrotte[lgr][htr][8] = "\xDA";
            break;

        case MurOAngleSE :
            carteGrotte[lgr][htr][0] = "|";
            carteGrotte[lgr][htr][3] = "|";
            carteGrotte[lgr][htr][6] = "|";
            carteGrotte[lgr][htr][8] = "\xDA";
            break;

        case MurOAngleNE :
            carteGrotte[lgr][htr][0] = "|";
            carteGrotte[lgr][htr][3] = "|";
            carteGrotte[lgr][htr][6] = "|";
            carteGrotte[lgr][htr][2] = "\xC0";
            break;

        case MurOAngleNESE :
            carteGrotte[lgr][htr][0] = "|";
            carteGrotte[lgr][htr][3] = "|";
            carteGrotte[lgr][htr][6] = "|";
            carteGrotte[lgr][htr][2] = "\xC0";
            carteGrotte[lgr][htr][8] = "\xDA";
            break;

        case MurEAngleNOSO :
            carteGrotte[lgr][htr][0] = "\xD9";
            carteGrotte[lgr][htr][2] = "|";
            carteGrotte[lgr][htr][5] = "|";
            carteGrotte[lgr][htr][8] = "|";
            carteGrotte[lgr][htr][6] = "\xBF";
            break;

        case MurSAngleNONE :
            carteGrotte[lgr][htr][0] = "\xD9";
            carteGrotte[lgr][htr][2] = "\xC0";
            carteGrotte[lgr][htr][6] = "\xC4";
            carteGrotte[lgr][htr][7] = "\xC4";
            carteGrotte[lgr][htr][8] = "\xC4";
            break;

        case MurSAngleNO :
            carteGrotte[lgr][htr][0] = "\xD9";
            carteGrotte[lgr][htr][6] = "\xC4";
            carteGrotte[lgr][htr][7] = "\xC4";
            carteGrotte[lgr][htr][8] = "\xC4";
            break;

        case MurSAngleNE :
            carteGrotte[lgr][htr][2] = "\xC0";
            carteGrotte[lgr][htr][6] = "\xC4";
            carteGrotte[lgr][htr][7] = "\xC4";
            carteGrotte[lgr][htr][8] = "\xC4";
            break;

        case MurNEAngleSO :
            carteGrotte[lgr][htr][0] = "\xC4";
            carteGrotte[lgr][htr][1] = "\xC4";
            carteGrotte[lgr][htr][2] = "\xBF";
            carteGrotte[lgr][htr][5] = "|";
            carteGrotte[lgr][htr][6] = "\xBF";
            carteGrotte[lgr][htr][8] = "|";
            break;

        case MurNOAngleSE :
            carteGrotte[lgr][htr][0] = "\xDA";
            carteGrotte[lgr][htr][1] = "\xC4";
            carteGrotte[lgr][htr][2] = "\xC4";
            carteGrotte[lgr][htr][3] = "|";
            carteGrotte[lgr][htr][6] = "|";
            carteGrotte[lgr][htr][8] = "\xDA";
            break;

        case MurSOAngleNE :
            carteGrotte[lgr][htr][0] = "|";
            carteGrotte[lgr][htr][2] = "\xC0";
            carteGrotte[lgr][htr][3] = "|";
            carteGrotte[lgr][htr][6] = "\xC0";
            carteGrotte[lgr][htr][7] = "\xC4";
            carteGrotte[lgr][htr][8] = "\xC4";
            break;

        case MurSEAngleNO :
            carteGrotte[lgr][htr][0] = "\xD9";
            carteGrotte[lgr][htr][2] = "|";
            carteGrotte[lgr][htr][5] = "|";
            carteGrotte[lgr][htr][6] = "\xC4";
            carteGrotte[lgr][htr][7] = "\xC4";
            carteGrotte[lgr][htr][8] = "\xD9";
            break;

        case VideAngleNE :
            carteGrotte[lgr][htr][2] = "\xC0";
            break;

        case VideAngleNO :
            carteGrotte[lgr][htr][0] = "\xD9";
            break;

        case VideAngleSO :
            carteGrotte[lgr][htr][6] = "\xBF";
            break;

        case VideAngleSE :
            carteGrotte[lgr][htr][8] = "\xDA";
            break;

        case VideAngleNOSO :
            carteGrotte[lgr][htr][0] = "\xD9";
            carteGrotte[lgr][htr][6] = "\xBF";
            break;

        case VideAngleSOSE :
            carteGrotte[lgr][htr][6] = "\xBF";
            carteGrotte[lgr][htr][8] = "\xDA";
            break;

        case VideAngleNOSOSE :
            carteGrotte[lgr][htr][0] = "\xD9";
            carteGrotte[lgr][htr][6] = "\xBF";
            carteGrotte[lgr][htr][8] = "\xDA";
            break;

        default :
            for(int i = 0;i <= 8;i++)
            {
                carteGrotte[lgr][htr][i] = " ";
            }
        }
    }
}

///Affiche une carte des endroits découvert par le joueur
///Indique par une croix où se situe le joueur
void afficheCarteDesert(string carteDesert[][25][9], int joueurPosX, int joueurPosY)
{
    for(int htr = 0;htr <= 24;htr++)
    {
        for(int i = 0;i <= 2;i++)
        {
            for(int lgr = 0;lgr <= 24;lgr++)
            {
                for(int j = 0;j <= 2;j++)
                {
                    if(lgr == joueurPosX && htr == joueurPosY)
                    {
                        if(carteDesert[joueurPosX][joueurPosY][4] == "|" && i*3+j == 3)
                        {
                            cout << "X ";
                        }
                        else if(carteDesert[joueurPosX][joueurPosY][4] != "|" && i*3+j == 4)
                        {
                            cout << "X ";
                        }
                        else
                        {
                            cout << carteDesert[lgr][htr][i*3+j] << " ";
                        }
                    }
                    else
                    {
                        cout << carteDesert[lgr][htr][i*3+j] << " ";
                    }
                }
            }
            cout << endl;
        }
    }
}
void afficheCarteMarai(string carteMarai[][25][9], int joueurPosX, int joueurPosY)
{
    for(int htr = 0;htr <= 24;htr++)
    {
        for(int i = 0;i <= 2;i++)
        {
            for(int lgr = 0;lgr <= 24;lgr++)
            {
                for(int j = 0;j <= 2;j++)
                {
                    if(lgr == joueurPosX && htr == joueurPosY)
                    {
                        if(carteMarai[joueurPosX][joueurPosY][4] != "|" && i*3+j == 4 && joueurPosX != 0 && joueurPosY != 0)
                        {
                            cout << "X ";
                        }
                        else
                        {
                            cout << carteMarai[lgr][htr][i*3+j] << " ";
                        }
                    }
                    else
                    {
                        cout << carteMarai[lgr][htr][i*3+j] << " ";
                    }
                }
            }
            cout << endl;
        }
    }
}
void afficheCarteTourBas(string carteTourBas[][20][9], int joueurPosX, int joueurPosY)
{
    for(int htr = 0;htr <= 19;htr++)
    {
        for(int i = 0;i <= 2;i++)
        {
            for(int lgr = 0;lgr <= 19;lgr++)
            {
                for(int j = 0;j <= 2;j++)
                {
                    if(lgr == joueurPosX && htr == joueurPosY && i*3+j == 4)
                    {
                        cout << "X ";
                    }
                    else
                    {
                        cout << carteTourBas[lgr][htr][i*3+j] << " ";
                    }
                }
            }
            cout << endl;
        }
    }
}
void afficheCarteTourHaut(string carteTourHaut[][20][9], int joueurPosX, int joueurPosY)
{
    for(int htr = 0;htr <= 19;htr++)
    {
        for(int i = 0;i <= 2;i++)
        {
            for(int lgr = 0;lgr <= 19;lgr++)
            {
                for(int j = 0;j <= 2;j++)
                {
                    if(lgr == joueurPosX && htr == joueurPosY && i*3+j == 4)
                    {
                        cout << "X ";
                    }
                    else
                    {
                        cout << carteTourHaut[lgr][htr][i*3+j] << " ";
                    }
                }
            }
            cout << endl;
        }
    }
}
void afficheCarteArchipel(string carteArchipel[][30][9], int joueurPosX, int joueurPosY)
{
    for(int htr = 0;htr <= 29;htr++)
    {
        for(int i = 0;i <= 2;i++)
        {
            for(int lgr = 0;lgr <= 29;lgr++)
            {
                for(int j = 0;j <= 2;j++)
                {
                    if(lgr == joueurPosX && htr == joueurPosY)
                    {
                        if(carteArchipel[joueurPosX][joueurPosY][4] != "|" && i*3+j == 4)
                        {
                            cout << "X ";
                        }
                        else
                        {
                            cout << carteArchipel[lgr][htr][i*3+j] << " ";
                        }
                    }
                    else
                    {
                        cout << carteArchipel[lgr][htr][i*3+j] << " ";
                    }
                }
            }
            cout << endl;
        }
    }
}
void afficheCarteGrotte(string carteGrotte[][15][9], int joueurPosX, int joueurPosY)
{
    for(int htr = 0;htr <= 14;htr++)
    {
        for(int i = 0;i <= 2;i++)
        {
            for(int lgr = 0;lgr <= 24;lgr++)
            {
                for(int j = 0;j <= 2;j++)
                {
                    if(lgr == joueurPosX && htr == joueurPosY && i*3+j == 4)
                    {
                        cout << "X ";
                    }
                    else
                    {
                        cout << carteGrotte[lgr][htr][i*3+j] << " ";
                    }
                }
            }
            cout << endl;
        }
    }
}

///Affiche une phrase indiquant que le joueur ne peut pas passer par l'océan
void nageInterditeDesert()
{
    int aleatoire;

    srand(time(0));

    aleatoire = rand() % 3;

    phrase("Vous vous demandez si vous n'avez pas plus de chance de vous \x82\achapper par la mer");

    switch(aleatoire)
    {
    case 0 :
        phrase(".");;
        finLigne(500);
        phrase("Soudain, un \x82norme aileron surgissant hors de l'eau r\x82pondit \x85 votre question.");
        break;
    case 1 :
        phrase(", mais la vue d'un morceau de corps d\x82rivant vous dissuade.");
        finLigne(1000);
        phrase("Surtout que vous ne savez pas \x85 quelle partie du corps il appartenait.");
        break;
    case 2 :
        phrase(", et d\x82\acidez alors de cherchez une pi\x8A\ace plus loin pour choisir \x85 pile ou face.");
        break;
    }

    finLigne(500);
    finLigne(500);
}
void nageInterditeArchipel()
{
    int aleatoire;

    srand(time(0));

    aleatoire = rand() % 4;

    phrase("Vous vous demandez si vous avez vraiment besoin du bateau.");
    finLigne(500);

    switch(aleatoire)
    {
    case 0 :
        phrase("Une puissante voix venue du ciel vous r\x82pond d'un ton grave.");
        finLigne(500);
        finLigne(500);
        phrase("Puissante voix venue du ciel qui vous r\x82pond d'un ton grave :");
        finLigne(1000);
        phrase("Oui.");
        break;
    case 1 :
        phrase("Dans le fond relativement peu profond, vous appercevez un squelette.");
        finLigne(1000);
        phrase("Enfin, un morceau de bras par-ci, une partie de jambe l\x85-bas.");
        finLigne(1000);
        phrase("Oh, et \x87\aa, c'est peut-\x88tre un bout du cr\x83ne.");
        break;
    case 2 :
        phrase("Un panneau (encore un, mais vous essayez de rester calme) que vous n'aviez pas vu attire votre attention.");
        finLigne(500);
        finLigne(500);
        phrase("Panneau que vous n'aviez pas vu :");
        finLigne(250);
        phrase("Nage interdite sauf les mardis pairs d'ann\x82\aes impaires si le jour du mois suivant ayant le m\x88me num\x82ro n'est pas le m\x88me que celui du jour du mois pr\x82\ac\x82\adent ayant ce num\x82ro, sauf si le nombre d'oiseau dans un p\x82rim\x8Atre en kilom\x8Atre du num\x82ro du jour dans l'ann\x82\ae (sauf si on est un mardi o\x97 dans ce cas le p\x82rim\x8Atre \x82quivaut aux dates d'anniversaires de vos parents divis\x82\aes par la racine cubique du nombre de grains de sable dans un p\x82rim\x8Atre en kilom\x8Atre du num\x82ro du jour dans l'ann\x82\ae (sauf si on est un mercredi non-f\x82ri\x82 o\x97 l\x85, on prend en compte la somme des num\x82ros des jours restant dans la premi\x8Are moiti\x82 du prochain semestre)) correspond au nombre total de calories consomm\x82\aes ces 6 derni\x8Ares heures et que vous avez parl\x82 \x85 au moins 3271 personnes diff\x82rentes ces 72122305569845 derni\x8Ares minutes, exept\x82 les polyglotes allemand-malgaches qui comptent pour du beurre (si c'est du beurre demi-sel lancez un sceau de 46 d\x82s \x85 18.5 faces, la multiplication des valeurs du premier cinqui\x8Ame doit \x88tre inf\x82rieurs \x85 celle de l'avant dernier cinqui\x8Ame, sinon il faut...");
        finLigne(750);
        finLigne(750);
        phrase("Vous oubliez cette id\x82\ae.");
        finLigne(1000);
        phrase("Comment avez-vous r\x82ussi \x85 ne pas voir ce panneau.");
        break;

    case 3 :
        phrase("Sauf qu'il ne faut pas nager apr\x8As avoir mang\x82.");
        finLigne(500);
        phrase("Vous ne savez pas combien de temps apr\x82s, mais mieux vaut ne pas tenter la peau de l'ours avant de mettre la charit\x82 apr\x8As les boeufs.");
    }

    finLigne(500);
    finLigne(500);
}

///Affiche une phrase indiquant que le joueur ne peut pas passer par les façades
void escaladeInterditeDesert()
{
    int aleatoire;

    srand(time(0));

    aleatoire = rand() % 4;

    phrase("Vous vous demandez ce qu'il y a derri\x8Are cette facade, ");

    switch(aleatoire)
    {
    case 0 :
        phrase("puis vous remarquez un nid de vautour dont un bras ensanglant\x82 d\x82passe.");
        finLigne(2000);
        phrase("Vous faites demi-tour.");
        sleep(1000);
        break;
    case 1 :
        phrase("avant d'appercevoir un squelette empal\x82 sur une cr\x8Ate.");
        finLigne(1000);
        phrase("Apr\x8As une courte d\x82lib\x82ration, vous concluez que ce squelette n'est pas un exemple \x85 suivre.");
        break;
    case 2 :
        phrase("mais des grattement sinistres semblant en provenir vous font passer cette curiosit\x82 dangereuse.");
        break;
    case 3 :
        phrase(" et un appel \x85 l'aide suivit de bruits caract\x82ristiques de craquement d'os, r\x82pondent \x85 votre question assez efficacement.");
        break;
    }

    finLigne(500);
    finLigne(500);
}

///Affiche une phrase indiquant que le joueur ne peut pas aller dans le bourbier
void bourbierInterdit()
{
    int aleatoire;

    srand(time(0));

    aleatoire = rand() % 4;

    phrase("Il a pas l'air si terrible que \x87\aa, ce bourbier.");
    finLigne(500);

    switch(aleatoire)
    {
    case 0 :
        phrase("Des gargouillits provenant de la vase en face de vous, suivit par un bras flottant, vous font douter de vos paroles.");
        break;

    case 1 :
        phrase("Vous voyez m\x88me une petite \x8Cle au loin.");
        finLigne(1500);
        phrase("Ah non.");
        finLigne(500);
        phrase("C'est un groupe de cadavres.");
        break;

    case 2 :
        phrase("Pour ponctuer votre phrase, une t\x88te de poisson d\x82\achiquet\x82\ae remonta \x85 la surface.");
        finLigne(1000);
        phrase("Elle est assez grande pour que vous puissiez y construire une petite cabane.");
        break;

    case 3 :
        phrase("Vous apercevez du mouvement au loin.");
        finLigne(1500);
        phrase("Ce n'est rien.");
        finLigne(1500);
        phrase("Juste deux \x82normes monstres qui s'affrontent.");
    }

    finLigne(500);
    finLigne(500);
    phrase("Bon, le bourbier n'est pas terrible,");
    sleep(1000);
    phrase(" contrairement \x85 ce qui y vit.");
    finLigne(1000);
}

///Affiche une phrase indiquant que le joueur ne peut pas aller sur le lac sans barque
void nageInterditeMarai()
{
    int aleatoire;

    srand(time(0));

    aleatoire = rand() % 5;

    switch(aleatoire)
    {
    case 0 :
        phrase("D\x82j\x85 que vous pataugez dans de la vase jusqu'aux genoux, l'id\x82\ae de vous mouiller enti\x8Arement de vous tente pas.");
        break;

    case 1 :
        phrase("Nan, vous n'avez pas apport\x82 votre maillot.");
        finLigne(500);
        phrase("Ce sera pour une autre fois.");
        break;

    case 2 :
        phrase("L'eau est troip froide pour que vous y nagiez.");
        break;

    case 3 :
        phrase("Vous n'aimez pas vous baigner sans ma\x8Ctre nageur.");
        break;

    case 4 :
        phrase("Votre horoscope vous a d\x82\aconseill\x82 de vous baigner dans un lac situ\x82 dans un marai \x85 c\x93t\x82 d'un d\x82sert.");
        finLigne(1000);
        phrase("Ils sont dou\x82s ces m\x82\adium.");
        break;
    }

    finLigne(500);
    finLigne(500);
}
