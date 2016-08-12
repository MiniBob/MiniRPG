#ifndef COMBAT_H
#define COMBAT_H

#include "Joueur.h"

void combatArene(Joueur &joueur,Ennemi &ennemi);
bool combatDesert(Joueur &joueur,Ennemi &ennemi);
bool combatCampBandit(Joueur &joueur,bool campGaucheFini,bool campDroiteFini);
bool combatMarai(Joueur &joueur,Ennemi &ennemi);
bool actionArene(Joueur &joueur,Ennemi &ennemi);
bool actionDesert(Joueur &joueur,Ennemi &ennemi);
bool actionMarai(Joueur &joueur,Ennemi &ennemi);
bool actionEnnemi(Ennemi &ennemi,Joueur &joueur);

#endif
