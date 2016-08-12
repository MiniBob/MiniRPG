#ifndef MAIN_H
#define MAIN_H

#include "Combat.h"

///Permet d'interagir avec le joueur
bool estMasculinJoueur();
std::string getNomJoueur(bool joueurEstMasculin);
    ///dans le désert
void deplacementDesert(Joueur &joueur,int grilleDesert[][25],std::string carteDesert[][25][9],int &joueurPosX,int &joueurPosY,bool deplacementDesertSafe,bool &campGaucheFini,bool &campDroiteFini,bool &premiereVisiteFrontiere,bool carteTrouvee = true);
bool rencontreEnnemiDesert(Joueur &joueur);
    ///dans le marai
bool deplacementMarai(Joueur &joueur,int grilleMarai[][25],std::string carteMarai[][25][9],int &joueurPosX,int &joueurPosY,int &nbMorsure,bool &cabaneVisitee);
bool rencontreEnnemiMarai(Joueur &joueur);
    ///dans l'archipel
bool deplacementArchipel(Joueur &joueur,int grilleArchipel[][30],std::string carteArchipel[][30][9],int &joueurPosX,int &joueurPosY);
bool rencontreEnnemiArchipel(Joueur &joueur);

///Fonctions principales ou 'chapitres'
int  intro(Joueur &joueur);
bool arene(Joueur &joueur);
int  desert(Joueur &joueur);
bool marai(Joueur &joueur);
bool archipel(Joueur &joueur);

///Sous-chapitre de l'archipel
bool grotte(Joueur &joueur);

///Sous-chapitres du marai
bool tour(Joueur &joueur);
bool tourBas(Joueur &joueur);
bool tourHaut(Joueur &joueur);

#endif
