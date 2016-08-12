#include <cmath>
#include "Joueur.h"

using namespace std;

///Constructeur du joueur
Joueur::Joueur(string nom,bool estMasculin) : Personnage(nom,estMasculin), m_lvl(1)
{

}

///Récupère l'attaque du joueur
void Joueur::attaque(Ennemi &cible)
{
    cout << endl;

    if(m_energie < m_arme.getEffort())
    {
        phrase(m_nom);
        phrase(" a du mal \x85 soulever " + accorde("son ","sa ",m_arme.estMasculin()) + m_arme.getNom() + ", qui semble peser des tonnes.");
        finLigne(500);
    }
    else if(m_energie == 0)
    {
        phrase("Le bras de " + m_nom + " semble lui peser des tonnes. " + m_nom + " arrive \x85 peine \x85 le soulever.");
        finLigne(500);
    }
    else
    {
        phrase(m_nom +" attaque " + accorde("le ","la ",cible.estMasculin()) + cible.getNom());

        if(m_arme.getNom() != "Aucune")
        {
            phrase(" avec " + accorde("son ","sa ",m_arme.estMasculin()) + m_arme.getNom());
        }

        phrase(".");

        Personnage::attaque(cible);
    }

    if(!cible.estVivant())
    {
        cout << endl;
        phrase(accorde("Le ","La ",cible.estMasculin()) + cible.getNom() + " est " + accorde("beurr\x82","mort",cible.getNom() == "Ptit Cookie") + accorde("","e",cible.estMasculin()) + ".");

        finLigne(300);

        Joueur::recoitRecompense(cible.getExp(),cible.getArgent(),cible.dropArme(),cible.getDropRate());
    }
}

///Le joueur récupère de la vis et de l'énergie pendant un combat
void Joueur::medite()
{
    if(m_pv == m_pvMax && m_energie == m_energieMax)
    {
        cout << endl;
        phrase(m_nom);
        phrase(" se concentre pour ne faire qu'un avec la nature et regagner l'\x82nergie et la sant\x82...");
        sleep(1000);
        phrase(" qu'" + accorde("il","elle",m_estMasculin) + " avait d\x82j\x8A.");
        finLigne(500);
        phrase("Dommage...");
    }
    else
    {
        cout << endl;
        phrase(m_nom);
        phrase(" regagne ");

        if(m_pv != m_pvMax)
        {
            m_pv += m_pvMax/5;

            if(m_pv >= m_pvMax)
            {
                m_pv = m_pvMax;
                phrase("la totalit\x82 de ses");
            }
            else
            {
                nombre(m_pvMax/5);
            }

            phrase(" points de vie");

            if(m_energie != m_energieMax)
            {
                phrase(" et ");
            }
        }

        if(m_energie != m_energieMax)
        {
            m_energie += m_energieMax/3;

            if(m_energie >= m_energieMax)
            {
                m_energie = m_energieMax;
                phrase("la totalit\x82 de son \x82nergie");
            }
            else
            {
                nombre(m_energieMax/3);
                phrase(" points d'\x82nergie");
            }
        }

        phrase(". ");
        sleep(500);
        phrase(m_nom + " est pr\x88t" + accorde("","e",m_estMasculin) + " \x85 reprendre le combat.");
    }
    finLigne(500);
}

///Le joueur reçoit de l'expérience et de l'argent après un combat
///Le joueur peut recevoir une arme de l'ennemi
void Joueur::recoitRecompense(int exp,int argent, Arme armeDrop, int dropRate)
{
    int i;
    bool armeDropee;

    srand(time(0));

    int ennemiDrop = rand() % 100;

    ennemiDrop++;

    if(ennemiDrop <= dropRate)
    {
       armeDropee = true;
    }

    if(!armeDropee)
    {
        if(exp == 0 && argent == 0)
        {
            cout << endl;
            phrase(m_nom + " obtient");

            sleep(500);
            phrase(".");
            sleep(500);
            phrase(".");
            sleep(500);
            phrase(".");
            sleep(1000);
            phrase(" rien.");
        }
    }

    if(exp != 0 || argent != 0)
    {
        cout << endl;
        phrase(m_nom + " obtient");

        phrase(" ");

        if(exp == 1)
        {
            nombre(exp);
            phrase(" point d'exp\x82rience");
        }
        else if(exp > 1)
        {
            nombre(exp);
            phrase(" points d'exp\x82rience");
        }

        if(exp != 0 && argent != 0)
        {
            phrase(" et ");
        }

        if(argent == 1)
        {
            nombre(argent);
            phrase(" pi\x8A\ace d'argent");
        }
        else if (argent > 1)
        {
            nombre(argent);
            phrase(" pi\x8A\aces d'argent");
        }

        phrase(".");
    }

    finLigne(250);
    finLigne(250);

    m_exp += exp;
    m_argent += argent;

    while(m_exp > (pow(m_lvl+1,5)-1)/8)
    {
        i = 3*m_lvl;

        m_lvl++;
        phrase("LEVEL UP !!!");
        finLigne(500);
        phrase(m_nom + " passe au niveau ");
        nombre(m_lvl);
        phrase(".");
        finLigne(500);

        phrase("PV : ");
        nombre(m_pvMax);
        phrase(" -> ");
        m_pvMax += 6*i;
        m_pv = m_pvMax;
        nombre(m_pvMax);
        finLigne(500);

        phrase("Energie : ");
        nombre(m_energieMax);
        phrase(" -> ");
        m_energieMax += 3*i;
        m_energie = m_energieMax;
        nombre(m_energieMax);
        finLigne(500);

        phrase("Attaque : ");
        nombre(m_attaque);
        phrase(" -> ");
        m_attaque += 1.5*i;
        nombre(m_attaque);
        finLigne(500);

        phrase("D\x82\afense : ");
        nombre(m_defense);
        phrase(" -> ");
        m_defense += 1.5*i;
        nombre(m_defense);
        cout << endl;
        finLigne(500);
    }

   if(armeDropee)
   {
       if(m_arme.getNom() != armeDrop.getNom())
       {
           if(m_arme.getDegat() < armeDrop.getDegat())
           {
               Joueur::nouvelleArme(armeDrop.getNom(),armeDrop.getDegat(),armeDrop.getEffort(),armeDrop.estMasculin(),armeDrop.getEffet(),armeDrop.getDegatEffet());
           }
           else
           {
               phrase(m_nom + " a trouv\x82 un" + accorde(" ","e ",armeDrop.estMasculin()) + armeDrop.getNom() + ", mais " + accorde("son ","sa ",m_arme.estMasculin()) + m_arme.getNom() + " est plus efficace.");
           }
       }

       finLigne(1000);
   }
}

///Récupère le niveau du joueur
int Joueur::getLvl() const
{
    return m_lvl;
}

///Affiche les caractéristiques du joueur pendant un combat
void Joueur::afficheStat() const
{
    cout << endl;
    phrase("Nom : ");
    phrase(m_nom);
    cout << endl;

    phrase("Lvl : ");
    nombre(m_lvl);
    cout << endl;

    phrase("Exp : ");
    nombre(m_exp);
    cout << endl;

    phrase("Pv : ");
    nombre(m_pv);
    cout << endl;

    phrase("Energie : ");
    nombre(m_energie);
    cout << endl;

    phrase("Attaque : ");
    nombre(m_attaque);
    cout << endl;

    phrase("D\x82\afense : ");
    nombre(m_defense);
    cout << endl;

    phrase("Pi : environ 3");
    finLigne(500);
}

///Affiche les caractéristiques de l'arme du joueur pendant un combat
void Joueur::afficheArme() const
{
    cout << endl;
    phrase("Arme : ");
        phrase(m_arme.getNom());

    if(m_arme.getDegat() != 0 && m_arme.getEffort() != 0)
    {
        phrase(" (d\x82g\x83ts : ");
        nombre(m_arme.getDegat());
        phrase(", effort : ");
        nombre(m_arme.getEffort()+10);
        phrase(")");
    }
    else
    {
        phrase(" (d\x82g\x83ts : on continue de les chercher, effort : 10)");
    }

    finLigne(500);

    if(m_arme.getEffet() != -1)
    {
        phrase("Effet : ");

        switch(m_arme.getEffet())
        {
        case Enflamme :
            phrase("Flam\x8A\ache");
            break;

        case BordPointu :
            phrase("Bord pointu qui pique");
            break;

        case HuileEssentielle :
            phrase("Huile naturelle odorante");
            break;

        case BoutQuiColle :
            phrase("Substance gluante");
            break;

        case Humide :
            phrase("Moite");
            break;

        case Farci :
            phrase("Farci" + accorde("","e",m_arme.estMasculin()) + " selon une recette traditionnelle malgache");
            break;

        case Communiste :
            phrase("Politique Mugabe");
            break;

        case PartieContondante :
            phrase("Partie tigeuse");
        }

        phrase(" (d\x82g\x83ts : ");
        nombre(m_arme.getDegatEffet());
        phrase(")");
    }
}

///Modifie l'arme du joueur
void Joueur::setArme(string nom, int degat, int energie, bool estMasculin, int effet, int degatEffet)
{
    m_arme.setNom(nom);
    m_arme.setDegat(degat);
    m_arme.setEffort(energie);
    m_arme.setGenre(estMasculin);
    m_arme.setEffet(effet);
    m_arme.setDegatEffet(degatEffet);
}

///Affiche les modifications de la nouvelle arme par rapport à la précédente
void Joueur::nouvelleArme(string nom, int degat, int energie, bool estMasculin, int effet, int degatEffet)
{
    int ecartDegat, ecartEffort;

    cout << endl;
    phrase("Cool, une nouvelle arme.");
    finLigne(500);

    ecartDegat = degat - m_arme.getDegat();
    ecartEffort = energie - m_arme.getEffort();

    if(m_arme.getNom() != "Aucune")
    {
        phrase(m_nom + " \x82\achange " + accorde("son ","sa ",m_arme.estMasculin()) + m_arme.getNom() + " contre ");
    }
    else
    {
        phrase(m_nom);
        phrase(" obtient ");
    }

    phrase(accorde("un ","une ",estMasculin) + nom + " (d\x82g\x83t : ");

    if(ecartDegat >= 0)
    {
        phrase("+");
    }

    nombre(ecartDegat);
    phrase(", effort : ");

    if(ecartEffort >= 0)
    {
        phrase("+");
    }

    nombre(ecartEffort);
    phrase(").");

    finLigne(250);
    finLigne(250);

    m_arme.setNom(nom);
    m_arme.setDegat(degat);
    m_arme.setEffort(energie);
    m_arme.setGenre(estMasculin);
    m_arme.setEffet(effet);
    m_arme.setDegatEffet(degatEffet);
}

///Modifie l'argent du joueur
void Joueur::setArgent(int argent)
{
    m_argent = argent;
}

///Modifie l'énergie du joueur
void Joueur::setEnergie(int energie,bool recue)
{
    if(recue)
    {
        m_energie += energie;
    }
    else
    {
        m_energie -= energie;
    }

    if(m_energie > m_energieMax)
    {
        m_energie = m_energieMax;
    }

    if(m_energie < 0)
    {
        m_energie = 0;
    }
}

///Modifie la santé du joueur
void Joueur::setPv(int pv)
{
    m_pv += pv;

    if(m_pv > m_pvMax)
    {
        m_pv = m_pvMax;
    }
}

///Modifie le niveau du joueur avec les caractéristiques correspondant au niveau
void Joueur::setLvl(int lvl)
{
    for(int i = m_lvl;i < lvl;i++)
    {
        m_lvl++;
        m_exp = ((pow(lvl,5)-1)/8)+1;
        m_pvMax += 12*i;
        m_pv = m_pvMax;
        m_energieMax += 6*i;
        m_energie = m_energieMax;
        m_attaque += 3*i;
        m_defense += 3*i;
    }
}

///Le joueur retourne au niveau 1 avec les caractéristiques correspondantes
void Joueur::returnVanilla()
{
    m_lvl = 1;
    m_pvMax = 100;
    m_pv = m_pvMax;
    m_energieMax = 100;
    m_energie = m_energieMax;
    m_attaque = 15;
    m_defense = 5;
    m_exp = 0;
    m_argent = 0;

    m_arme.setNom("Aucune");
    m_arme.setDegat(0);
    m_arme.setEffort(0);
    m_arme.setGenre(true);
    m_arme.setEffet(-1);
    m_arme.setDegatEffet(0);
}
