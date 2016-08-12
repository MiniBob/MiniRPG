#ifndef FONCTION_H
#define FONCTION_H

#include "Arme.h"

///Constantes des effets d'armes
const int Enflamme = 0, BordPointu = 1, HuileEssentielle = 2, BoutQuiColle = 3, Humide = 4, Farci = 5, Communiste = 6, PartieContondante = 7, PasAPas = 8, DansLesYeux = 9;
const int Lisse = 10, Couleur = 11, Rougeole = 12, Musicien = 13;

///Constantes du Desert et de l'Archipel
const int Ocean = 0;                        ///Case d'océan inaccessible
const int Desert = 1;                       ///Case de désert
const int Cote = 2;                         ///Case de côte proche de l'océan
const int PlageN = 3;                       ///Case avec l'océan au nord
const int PlageE = 4;                       ///Case avec l'océan à l'est
const int PlageS = 5;                       ///Case avec l'océan au sud
const int PlageO = 6;                       ///Case avec l'océan à l'ouest
const int PlageNO = 7;                      ///Case avec l'océan au nord et à l'ouest
const int PlageNE = 8;                      ///Case avec l'océan  au nord et à l'est
const int PlageSE = 9;                      ///Case avec l'océan au sud et à l'est
const int PlageSO = 10;                     ///Case avec l'océan au sud et à l'ouest
const int ParoiN = 11;                      ///Case avec une paroi au nord
const int ParoiE = 12;                      ///Case avec une paroi à l'est
const int ParoiS = 13;                      ///Case avec une paroi au sud
const int ParoiO = 14;                      ///Case avec une paroi à l'ouest
const int ParoiNO = 15;                     ///Case avec une paroi au nord et à l'ouest
const int ParoiNE = 16;                     ///Case avec une paroi au nord et à l'est
const int ParoiSE = 17;                     ///Case avec une paroi au sud et à l'est
const int ParoiSO = 18;                     ///Case avec une paroi au sud et à l'ouest
const int AngleNE = 19;                     ///Case avec le coin au nord et à l'est formant un angle de paroi
const int AngleNO = 20;                     ///Case avec le coin au nord et à l'ouest formant un angle de paroi
const int AngleSO = 21;                     ///Case avec le coin au sud et à l'ouest formant un angle de paroi
const int AngleSE = 22;                     ///Case avec une paroi au sud et à l'ouest
const int CoteNE = 23;                      ///Case avec le coin au nord et à l'est formant un angle de plage
const int CoteNO = 24;                      ///Case avec le coin au nord et à l'ouest formant un angle de plage
const int CoteSO = 25;                      ///Case avec le coin au sud et à l'ouest formant un angle de plage
const int CoteSE = 26;                      ///Case avec le coin au sud et à l'est formant un angle de plage
const int Palmier = 27;                     ///Case où se reposer
const int Oasis = 28;                       ///Case où se baigner
const int Camp = 29;                        ///Case de campement de bandit
const int Frontiere = 30;                   ///Case de la frontière à l'est

///Constantes du Marai
const int Bourbier = 0;                     ///Case de bourbier inaccessible
const int Roseau = 1;                       ///Case de roseau proche du bourbier ou du chemin central
const int RoseauN = 2;                      ///Case de roseau avec le bourbier au nord
const int RoseauS = 3;                      ///Case de roseau avec le bourbier au sud
const int RoseauE = 4;                      ///Case de roseau avec le bourbier à l'est
const int RoseauO = 5;                      ///Case de roseau avec le bourbier à l'ouest
const int RoseauNE = 6;                     ///Case de roseau avec le bourbier au nord et à l'est
const int RoseauNO = 7;                     ///Case de roseau avec le bourbier au nord et à l'ouest
const int RoseauSO = 8;                     ///Case de roseau avec le bourbier au sud et à l'ouest
const int RoseauSE = 9;                     ///Case de roseau avec le bourbierau sud et à l'est
const int RoseauNS = 10;                    ///Case de roseau avec le bourbier au sud et le lac au nord
const int Ponton = 11;                      ///Case où un ponton en bois a été posé sur le marécage
const int Cabane = 12;                      ///Case de la cabane du sage
const int TourHaut = 13;                    ///Case du haut de la tour ou de derrière la tour si le joueur ne vient pas du bas de la tour
const int TourBas = 14;                     ///Case du bas de la tour
const int Barque = 15;                      ///Case de la barque
const int Marai = 16;                       ///Case de marai
const int MaraiN = 17;                      ///Case de marai avec le lac au nord
const int MaraiS = 18;                      ///Case de marai avec le lac au sud
const int MaraiE = 19;                      ///Case de marai avec le lac à l'est
const int MaraiO = 20;                      ///Case de marai avec le lac à l'ouest
const int MaraiNE = 21;                     ///Case de marai avec le lac au nord et à l'est
const int MaraiNO = 22;                     ///Case de marai avec le lac au nord et à l'ouest
const int MaraiSO = 23;                     ///Case de marai avec le lac au sud et à l'ouest
const int MaraiSE = 24;                     ///Case de marai avec le lac au sud et à l'est
const int Lac = 25;                         ///Case du lac inaccessible sans la barque

///Constantes de la tour
const int PetiteColonne = 0;                ///Case d'une colonne
const int GrandeColonneNE = 1;              ///Case supérieure droite d'une grande colonne
const int GrandeColonneNO = 2;              ///Case supérieure gauche d'une grande colonne
const int GrandeColonneSO = 3;              ///Case inférieure gauche d'une grande colonne
const int GrandeColonneSE = 4;              ///Case inférieure gauche d'une grande colonne
const int Dalle = 5;                        ///Case de sol recouvert d'une dalle
const int Passerelle = 6;                   ///Case d'une passerelle à l'étage supérieur
const int PasserelleN = 7;                  ///Case de passerelle avec un bord au nord
const int PasserelleS = 8;                  ///Case de passerelle avec un bord au sud
const int PasserelleE = 9;                  ///Case de passerelle avec un bord à l'est
const int PasserelleO = 10;                 ///Case de passerelle avec un bord à l'ouest
const int PasserelleNE = 11;                ///Case de passerelle avec un bord au nord et à l'est
const int PasserelleNO = 12;                ///Case de passerelle avec un bord au nord et à l'ouest
const int PasserelleSO = 13;                ///Case de passerelle avec un bord au sud et à l'ouest
const int PasserelleSE = 14;                ///Case de passerelle avec un bord au sud et à l'est
const int PasserelleNS = 15;                ///Case de passerelle avec un bord au nord et au sud
const int PasserelleEO = 16;                ///Case de passerelle avec un bord à l'est et à l'ouest
const int PasserelleAngleNE = 17;           ///Case de passerelle avec un angle au nord-est
const int PasserelleAngleNO = 18;           ///Case de passerelle avec un angle au nord-ouest
const int PasserelleAngleSO = 19;           ///Case de passerelle avec un angle au sud-ouest
const int PasserelleAngleSE = 20;           ///Case de passerelle avec un angle au sud-est
const int PasserelleSAngleNE = 21;          ///Case de passerelle avec un bord au sud et un angle au nord-est
const int PasserelleSAngleNO = 22;          ///Case de passerelle avec un bord au sud et un angle au nord-ouest
const int PasserelleOAngleNE = 23;          ///Case de passerelle avec un bord  à l'ouest et un angle au nord-est
const int PasserelleEAngleSO = 24;          ///Case de passerelle avec un bord à l'est et un angle au sud-ouest
const int PasserelleEAngleNO = 25;          ///Case de passerelle avec un bord à l'est et un angle au nord-ouest
const int PasserelleNAngleSE = 26;          ///Case de passerelle avec un bord nord et un angle au sud-est
const int PasserelleOAngleSE = 27;          ///Case de passerelle avec un bord à l'ouest et un angle au sud-est
const int PasserelleNEAngleSO = 28;         ///Case de passerelle avec un bord au nord et à l'est et un angle au sud-ouest
const int PasserelleNOAngleSE = 29;         ///Case de passerelle avec un bord au nord et à l'ouest et un angle au sud-est
const int PasserelleSOAngleNE = 30;         ///Case de passerelle avec un bord au sud et à l'ouest et un angle au nord-est
const int PasserelleSEAngleNO = 31;         ///Case de passerelle avec un bord au sud et à l'est et un angle au nord-ouest
const int PasserelleAngleNESO = 32;         ///Case de passerelle avec un angle au nord-est et au sud-ouest
const int PasserelleAngleNONE = 33;         ///Case de passerelle avec un angle au sud-ouest et au sud-est
const int PasserelleNAngleSOSE = 34;        ///Case de passerelle avec un bord au nord et un angle au sud-ouest et au sud-est
const int PasserelleSAngleNONE = 35;        ///Case de passerelle avec un bord au sud et un angle au nord-ouest et au nord-est
const int PasserelleEAngleNOSO = 36;        ///Case de passerelle avec un bord à l'est et un angle au nord-ouest et au sud-ouest
const int PasserelleOAngleNESE = 37;        ///Case de passerelle avec un bord à l'ouest et un angle au nord-est et au sud-est

///Constante de l'Archipel
const int PlageNS = 37;                     ///Case avec l'océan au nord et au sud
const int Escalier = 38;                    ///Case des escaliers menant à la grotte

///Constantes de la grotte de l'archipel
const int Vide = -1;                        ///Case où le joueur peut aller
const int Mur = 0;                          ///Case de mur complet
const int MurN = 1;                         ///Case de mur au nord
const int MurS = 2;                         ///Case de mur au sud
const int MurE = 3;                         ///Case de mur à l'est
const int MurO = 4;                         ///Case de mur à l'ouest
const int MurNO = 5;                        ///Case de mur au nord et à l'ouest
const int MurNE = 6;                        ///Case de mur au nord et à l'est
const int MurSE = 7;                        ///Case de mur au sud et à l'est
const int MurSO = 8;                        ///Case de mur au sud et à l'ouest
const int MurNS = 9;                        ///Case de mur au nord et au sud
const int MurEO = 10;                       ///Case de mur à l'est et à l'ouest
const int ImpasseN = 11;                    ///Case d'impasse où la sortie est au sud
const int ImpasseS = 12;                    ///Case d'impasse où la sortie est au nord
const int ImpasseE = 13;                    ///Case d'impasse où la sortie est à l'ouest
const int ImpasseO = 14;                    ///Case d'impasse où la sortie est à l'est
const int MurNAngleSE = 15;                 ///Case de mur au nord avec un angle au sud-est
const int MurNAngleSO = 16;                 ///Case de mur au nord avec un angle au sud-ouest
const int MurNAngleSOSE = 17;               ///Case de mur au nord avec un angle au sud-ouest et su sud-est
const int MurOAngleSE = 18;                 ///Case de mur à l'ouest avec un angle au sud-est
const int MurOAngleNE = 19;                 ///Case de mur à l'ouest avec un angle au nord-est
const int MurOAngleNESE = 20;               ///Case de mur à l'ouest avec un angle au nord-est et au sud-est
const int MurEAngleNOSO = 21;               ///Case de mur à l'est avec un angle au nord-ouest et au sud-ouest
const int MurSAngleNONE = 22;               ///Case de mur au sud avec un angle au nord-ouest et au nord-est
const int MurSAngleNO = 23;                 ///Case de mur au sud avec un angle au nord-ouest
const int MurSAngleNE = 24;                 ///Case de mur au sud avec un angle au nord-est
const int MurNEAngleSO = 25;                ///Case de mur au nord et à l'est avec un angle au sud-ouest
const int MurNOAngleSE = 26;                ///Case de mur au nord et à l'ouest avec un angle au sud-est
const int MurSOAngleNE = 27;                ///Case de mur au sud et à l'ouest avec un angle au nord-est
const int MurSEAngleNO = 28;                ///Case de mur au sud et à l'est avec un angle au nord-ouest
const int VideAngleNE = 29;                 ///Case de passage avec un angle au nord-est
const int VideAngleNO = 30;                 ///Case de passage avec un angle au nord-ouest
const int VideAngleSO = 31;                 ///Case de passage avec un angle au sud-ouest
const int VideAngleSE = 32;                 ///Case de passage avec un angle au sud-est
const int VideAngleNOSO = 33;               ///Case de passage avec un angle au nord-ouest et au sud-ouest
const int VideAngleSOSE = 34;               ///Case de passage avec un angle au sud-ouest et au sud-est
const int VideAngleNOSOSE = 35;             ///Case de passage avec un angle au nord-ouest, au sud-ouest et au sud-est

///Instructions au joueur
std::string accorde(std::string masculin,std::string feminin,bool estMasculin);
void phrase(std::string phrase);
void nombre(int nombre);
void sleep(unsigned milliseconds);
void finLigne(unsigned milliseconds);
void finProgramme(bool jeuFini,bool joueurEstMasculin);
void felicitations(std::string mots);
int  ajouteEffet(Arme &arme);
int  joueurEstConnu(std::string nomJoueur,bool joueurEstMasculin);
int  getChiffre(char lettre);

///Concerne le désert
void creationDesert(int grilleDesert[][25],std::string carteDesert[][25][9]);
bool bonneDirectionDesert(const int grilleDesert[][25],const int joueurPosX,const int joueurPosY,const std::string direction);
void nageInterditeDesert();
void escaladeInterditeDesert();
void afficheCarteDesert(std::string carteDesert[][25][9],int joueurPosX,int joueurPosY);
void setCaseCarteDesert(std::string carteDesert[][25][9],int lgr,int htr,int grilleDesert[][25],bool champDeVision = false);

///Concerne le marai
void creationMarai(int grilleMarai[][25], std::string carteMarai[][25][9]);
void afficheCarteMarai(std::string carteMarai[][25][9], int joueurPosX, int joueurPosY);
void setCaseCarteMarai(std::string carteMarai[][25][9], int lgr, int htr, int grilleMarai[][25],bool champDeVision = false);
bool bonneDirectionMarai(const int grilleMarai[][25],const int joueurPosX,const int joueurPosY,const std::string direction);
void bourbierInterdit();
void nageInterditeMarai();

///Concerne la tour du marai
void creationTour(int grilleTourBas[][20],int grilleTourHaut[][20],std::string carteTourBas[][20][9],std::string carteTourHaut[][20][9]);
void afficheCarteTourBas(std::string carteTourBas[][20][9],int joueurPosX,int joueurPosY);
void afficheCarteTourHaut(std::string carteTourHaut[][20][9],int joueurPosX,int joueurPosY);
void setCaseCarteTourBas(std::string carteTourBas[][20][9],int lgr,int htr,int grilleTourBas[][20],bool champDeVision = false);
void setCaseCarteTourHaut(std::string carteTourHaut[][20][9],int lgr,int htr,int grilleTourHaut[][20],bool champDeVision = false);
bool bonneDirectionTourBas(int grilleTourBas[][20],int joueurPosX,int joueurPosY,std::string direction);
bool bonneDirectionTourHaut(int grilleTourHaut[][20],int joueurPosX,int joueurPosY,std::string direction);
void avanceContreColonne();
void tombe();

///Concerne l'archipel
void creationArchipel(int grilleArchipel[][30],std::string carteArchipel[][30][9]);
void afficheCarteArchipel(std::string carteArchipel[][30][9],int joueurPosX,int joueurPosY);
void setCaseCarteArchipel(std::string carteArchipel[][30][9],int lgr,int htr,int grilleArchipel[][30],bool champDeVision = false);
bool bonneDirectionArchipel(int grilleArchipel[][30],int joueurPosX,int joueurPosY,std::string direction);
void nageInterditeArchipel();

///Concerne la grotte de l'archipel
void creationGrotte(int grilleGrotte[][15],std::string carteGrotte[][15][9]);
void afficheCarteGrotte(std::string carteGrotte[][15][9],int joueurPosX,int joueurPosY);
void setCaseCarteGrotte(std::string carteGrotte[][15][9],int lgr,int htr,int grilleGrotte[][15],bool champDeVision = false);
bool bonneDirectionGrotte(int grilleGrotte[][15],int joueurPosX,int joueurPosY,std::string direction);
void avanceContreMur();

#endif
