#ifndef ARME_H
#define ARME_H

#include <string>
#include <windows.h>
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <iostream>

class Arme
{
    public :
        Arme();
        Arme(std::string nom,int degat,int effort,bool estMasculin,int effet = -1,int degatEffet = 0);
        std::string getNom() const;
        int  getDegat() const;
        int  getEffort() const;
        int  getEffet() const;
        int  getDegatEffet() const;
        bool estMasculin() const;
        void setNom(std::string nom);
        void setDegat(int degat);
        void setEffort(int energie);
        void setGenre(bool estMasculin);
        void setEffet(int effet);
        void setDegatEffet(int degatEffet);

    protected :
        std::string m_nom;
        bool m_estMasculin;
        int  m_degat;
        int  m_effort;
        int  m_effet;
        int  m_degatEffet;
};

#endif
