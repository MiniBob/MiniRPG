#ifndef ENNEMI_H
#define ENNEMI_H

#include "Personnage.h"

class Ennemi : public Personnage
{
    public :
        Ennemi(std::string nom,int attaque, std::string nomArme, int degatArme, int energieArme, int exp, int argent, bool armeEstMasculin, bool estMasculin,int effet = -1,int degatEffet = 0,std::string nomDropArme = "Aucune",int degatDropArme = 0,int energieDropArme = 0,bool dropArmeEstMasculin = true,int effetDrop = -1,int degatEffetDrop = 0,int dropRate = 0);
        Ennemi(std::string nom,int pv,int energie,int attaque,int defense,std::string nomArme,int degatArme,int energieArme,int exp,int argent,bool armeEstMasculin,bool estMasculin,int effet = -1,int degatEffet = 0,std::string nomDropArme = "Aucune",int degatDropArme = 0,int energieDropArme = 0,bool dropArmeEstMasculin = true,int effetDrop = -1,int degatEffetDrop = 0,int dropRate = 0);
        void attaque(Personnage &cible);
        void medite();
        Arme dropArme() const;
        int getDropRate() const;

    private :
        Arme m_dropArme;
        int m_dropRate;
};

#endif
