#ifndef TACHE_H
#define TACHE_H
#include <iostream>
#include <string>
using namespace std ;
class tache
{
private :
    string m_tache_id,m_tache_nom,m_tache_description,m_tache_date_debut,m_tache_date_fin,m_tache_etat ;
public :
    tache() ;
    tache(string id,string nom,string des,string ddeb,string ddef, string et) ;
    string get_tache_id() ;
    string get_tache_nom() ;
    string get_tache_description() ;
    string get_tache_date_debut() ;
    string get_tache_date_fin() ;
    string get_tache_tache_etat();
    void set_tache_id(string id) ;
    void set_tache_nom(string nm) ;
    void set_tache_description(string des) ;
    void set_tache_date_debut(string ddb) ;
    void set_tache_date_fin(string ddf) ;
    void set_tache_tache_etat(string et);
    bool date_comparator(string ndate) ;
    string decristoi() ;

};

#endif // TACHE_H
