#include "membre.h"

using namespace std;

membre::membre()
{
    m_ID = "inconnu";
    m_tel ="inconnu";
    m_nom="inconnu" ;
    m_prenom="inconnu" ;
    m_adresse="inconnu" ;
    m_email="inconnu" ;
}

membre::membre(string id,string tel,string nom,string preno,string addr, string mail,string tac) : m_ID(id),m_tel(tel),
m_nom(nom),m_prenom(preno), m_adresse(addr) , m_email(mail),m_tache(tac)
{
}

string membre::get_tache()
{
    return m_tache ;
}
string membre::get_ID()
{
    return m_ID ;
}

string membre::get_tel()
{
    return m_tel ;
}
string membre::get_nom()
{
    return m_nom ;
}

string membre::get_prenon()
{
    return m_prenom ;
}

string membre::get_addresse()
{
    return m_adresse ;
}
string membre::get_email()
{
    return m_email ;
}


void membre::set_ID(string id)
{
    m_ID = id ;
}
    void membre::set_nom(string name)
    {
        m_nom = name ;
    }
    void membre::set_prenom(string pren)
    {
        m_prenom=pren ;
    }
    void membre::set_addresse(string addre)
    {
        m_adresse=addre ;
    }
    void membre::set_email(string mail)
    {
        m_email = mail ;
    }
    void membre::set_tel(string tl)
    {
        m_tel = tl;
    }
    void membre::set_tache(string ta)
    {
        m_tache = ta ;
    }
    string membre::decritoi()
    {
        string str ;
        str += "id : " ;
        str += get_ID() ;
        str += "\n nom : ";
        str += m_nom ;
        str += "\n prenom : ";
        str += m_prenom;
        str += "\n addresse : ";
        str += m_adresse;
        str += "\n tel : ";
        str += m_tel;
        str += "\n email : ";
        str += m_email ;
        str += "\n tache : ";
        str += m_tache ;
        return str ;
    }
