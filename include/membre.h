#ifndef MEMBRE_H
#define MEMBRE_H
#include <iostream>
#include <string>
#include <tache.h>
#include <list>

using namespace std ;
class membre
{
private:
string m_nom , m_prenom, m_adresse, m_email,m_ID,m_tel,m_tache ;
list<tache> m_list_tache;

public:
    membre();
    membre(string id,string tel,string nom,string preno,string addr, string mail,string tache) ;
    string get_ID ();
    string get_tel();
    string get_nom();
    string get_prenon();
    string get_addresse();
    string get_email();
    string get_tache();
    void set_ID(string id);
    void set_tel(string tel);
    void set_nom(string name);
    void set_prenom(string pren);
    void set_addresse(string addre);
    void set_email(string mail);
    void set_tache(string tch) ;
    string decritoi();
};
#endif
