#include "tache.h"
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std ;
    string int_to_string (int a) ;
tache::tache()
{
    m_tache_id = "inconnu" ;
    m_tache_nom = "inconnu" ;
    m_tache_description = "inconnu" ;
    m_tache_date_debut= "inconnu" ;
    m_tache_date_fin = "inconnu" ;
    m_tache_etat="inconnu" ;
}
tache :: tache (string id,string nom,string des,string ddeb,string ddef, string et)
    {
    string tmp ;


    m_tache_id=id;
    m_tache_nom=nom;
    m_tache_description=des;
    m_tache_date_debut=ddeb;
    m_tache_date_fin=ddef;
    m_tache_etat=et;

    }

    string tache::get_tache_id()
    {
        return m_tache_id ;
    }

    string tache::get_tache_nom()
    {
        return m_tache_nom ;
    }

    string tache::get_tache_description()
    {
        return m_tache_description ;
    }

    string tache::get_tache_date_debut()
    {
        return m_tache_date_debut ;
    }
    string tache::get_tache_date_fin()
    {
        return m_tache_date_fin ;
    }

    string tache::get_tache_tache_etat()
    {
        return m_tache_etat ;
    }

    void tache::set_tache_id(string id)
    {
        m_tache_id = id ;
    }

    void tache::set_tache_nom(string nm)
    {
        m_tache_nom = nm ;
    }

    void tache::set_tache_description(string des)
    {
        m_tache_description = des ;
    }

    void tache::set_tache_date_debut(string ddb)
    {
        m_tache_date_debut = ddb ;
    }
    void tache::set_tache_date_fin(string ddf)
    {
        m_tache_date_fin = ddf ;
    }

    void tache::set_tache_tache_etat(string et)
    {
        m_tache_etat = et ;
    }

    string tache::decristoi()
    {
        string str ;
        str += "id : " ;
        str += get_tache_id() ;
        str += "\n nom : ";
        str += get_tache_nom() ;
        str += "\n description : ";
        str += get_tache_description();
        str += "\n date debut : ";
        str += m_tache_date_debut;
        str += "\n dete fin : ";
        str += m_tache_date_fin;
        str += "\n etat : ";
        str += m_tache_etat ;
        return str ;
    }
    string int_to_string (int a)
    {
        ostringstream ss ;
        ss << a ;
        return ss.str() ;
    }
bool tache::date_comparator(string ndate)
{
    string jj1(""),mm1(""),aa1(""), jj2(""),mm2(""),aa2("");
    jj1 += ndate[0];jj1 += ndate[1] ;
    mm1 += ndate[3];mm1 += ndate[4] ;
    aa1 += ndate[6];aa1 += ndate[7] ;
    jj2 += m_tache_date_debut[0];jj2 += m_tache_date_debut[1] ;
    mm2 += m_tache_date_debut[3];mm2 += m_tache_date_debut[4] ;
    aa2 += m_tache_date_debut[6];aa2 += m_tache_date_debut[7] ;
    if(atoi(aa1.c_str()) <  atoi(aa2.c_str()))
    {
                return false ;
    }
    else if (atoi(aa1.c_str()) ==  atoi(aa2.c_str()) && atoi(mm1.c_str())<atoi(mm2.c_str()))
        {
                return false ;
        }
    else if (atoi(aa1.c_str()) ==  atoi(aa2.c_str()) && atoi(mm1.c_str())==atoi(mm2.c_str()) && atoi(jj1.c_str())<atoi(jj2.c_str()))
        {
                return false ;
    }
    else
    return true ;
}
