#include <iostream>
#include <membre.h>
#include <tache.h>
#include <conio.h>
#include <windows.h>
#include <string>
#include <list>
#include <iterator>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <stdlib.h>
#include <fstream>


using namespace std;
//variable
list<membre> members ;
list<tache> tasks ;
//pour la recherche
list<membre> members1 ;
list<membre> members2 ;
list<membre> members3 ;
list<membre> members4 ;
list<membre> members5 ;
list<membre> members6 ;
list<tache> taches1 ;
list<tache> taches2 ;
list<tache> taches3 ;
list<tache> taches4 ;
//fonctions de recherche de membre
void rech_nom(list<membre> &list1 , list<membre> &list2,string nom,string &rec) ;
void rech_prenom(list<membre> &list1 , list<membre> &list2,string prenom,string &rec) ;
void rech_tel(list<membre> &list1 , list<membre> &list2,string tel,string &rec) ;
void rech_addresse(list<membre> &list1 , list<membre> &list2,string adresse,string &rec) ;
void rech_email(list<membre> &list1 , list<membre> &list2,string email,string &rec) ;
void rech_tache(list<membre> &list1 , list<membre> &list2,string tache,string &rec) ;
//fonctions de recherche de taches
void rech_nom_tach(list<tache> &list1 , list<tache> &list2,string nom,string &rec) ;
void rech_ddeb(list<tache> &list1 , list<tache> &list2,string ddeb,string &rec) ;
void rech_ddef(list<tache> &list1 , list<tache> &list2,string ddef,string &rec) ;
void rech_eta(list<tache> &list1 , list<tache> &list2,string etat,string &rec) ;
//------------
bool autre_tache ;
string rep_acu,maVariable,maVariable_Tache;
//verifions
void verify(string cas);
//controlleurs de membre
string afficher_accueil();
void creer_membre() ;
void modifier_membre() ;
string afficher_membre() ;
void supprimer_membre () ;
string rechercher_membre () ;
//controlleurs de tache
void creer_tache() ;
void modifier_tache() ;
string afficher_tache() ;
void supprimer_tache() ;
string rechercher_tache();
//autres fonctions necessaireq
void assigner_tache() ;
string afficher_tasklist_member();
bool is_number(const string &s) ;
bool is_in_date_format(string t_date) ;
void enregistrer_membre() ;
void enregistrer_tache();
void maj_members();
void maj_tache();
bool is_readable(const string &file) ;
void n_time();
//-------------------------------
string const s_membre("Membres.txt");
string const s_tache("Taches.txt");


int main()
{
    n_time();

    //on recupere les occurences deja cree dans la base de donnée(fichier)
    maj_members();
    maj_tache() ;
    //fin de recuperation

    system("color 4F");
    //respectivement le username , le pass , reponse a l'accueil ,

    string login("") ;
    string password("") ;
    cout <<"Bonjour Monsieur/Madamme . Veillez vous identifiez s'il vous plait ! " <<endl ;
    cout <<"Identifiant : ";
    getline(cin, login);
    cout <<"Mot de passe : " ;
    int x[200] ;
for(int i=0; i<200;i++)
{
x[i]=getch();
if(x[i]!='\r')
    cout<<"*";
if(x[i]=='\r')
break;
 else if(x[i]=='\b')
{
if(i==0)
cout<<"\b"<<" "<<"\b";
else if(i>=1)
{
//x[i-1]='\0';
//make the previous byte null if backspase is pressed
 i=i-2;
cout<<"\b"<<" "<<"\b\b"<<" "<<"\b";
 }
}
password +=x[i] ;
}
cout <<endl ;

int nbr = 3 ;

if(login != "admin" || password != "toto")
{
    nbr -- ;
    cout<<endl ;
    cout << "echec de la connexion . utilisateur ou mot de passe incorrect ! reesayez plus tard ! " <<endl ;
    main() ;
    exit(0) ;
}

int si_dej (0);
do
{
    if(si_dej == 0 )
    {
        cout <<"connexion reuissie !\n\n" <<endl ;
    si_dej++ ;
    }
    cout << afficher_accueil() ;
    cout <<"Indiquez une operation par son numero \n \t > " ;
    cin>>rep_acu ;
    verify("rep_acu");
    //-------------conversion----------
    int rep_acu_int ;
    istringstream iss(rep_acu) ;
    iss>>rep_acu_int ;
    //-------------conversion----------
    switch(rep_acu_int)
    {
        case 1:
            creer_membre() ;
            break ;

        case 2:
            modifier_membre() ;
            break ;

            case 3:
            cout << afficher_membre() ;
            break;

        case 4:
            supprimer_membre() ;
            break ;

            case 5:
            rechercher_membre() ;
            break;

        case 6:
            creer_tache() ;
            break ;

            case 7:
            modifier_tache() ;
            break;

        case 8:
            cout << afficher_tache()<<endl ;
            break ;

            case 9:
            supprimer_tache() ;
            break;

        case 10:
            rechercher_tache() ;
            break ;

            case 11:
            assigner_tache() ;
            break;

        case 12:
            cout <<afficher_tasklist_member()<<endl ;
            break ;
        case 13:
            exit(0);
            default :

            break ;
    }
    verify("autre_tache") ;
}while(autre_tache);
    return 0 ;
}
//affichons l'accueil
string afficher_accueil()
{
    string str ;
    str =  "+=======================================================================================================+\n";
    str += "|                                             MENU PRINCIPAL                                            |\n";
    str += "|-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|\n";
    str += "|                                                                                                       |\n";
    str += "|                          Membre                                            Tache                      |\n";
    str += "|-------------------------------------------------------------------------------------------------------|\n";
    str += "|   1- Creer                                          ||     6- Creer                                   |\n";
    str += "|   2- Modifier                                       ||     7- Modifier                                |\n";
    str += "|   3- afficher                                       ||     8- afficher                                |\n";
    str += "|   4- Spprimer                                       ||     9- Spprimer                                |\n";
    str += "|   5- rechercher/afficher sous critere(s)            ||     10- rechercher/afficher sous critere(s)    |\n";
    str += "|                                                                                                       |\n";
    str += "|-------------------------------------------------------------------------------------------------------|\n";
    str += "|                                      11- Assigner une tache a un membre                               |\n";
    str += "|                                      12- Afficher la liste des taches assignees a un membre           |\n";
    str += "|                                      13- Quitter                                                      |\n";
    str += "|-------------------------------------------------------------------------------------------------------|\n";
    str += "|-------------------------------------------------------------------------------------------------------|\n";
    str += "+-------------------------------------------------------------------------------------------------------+\n";
    return str ;
}
string afficher_membre()
{
list<membre>::iterator it = members.begin();
    string lilo="" ;
    if(members.empty())
    {
        cout <<"\n-----------------------------------------------------------------------------------\n";
        cout <<"                       Aucun membre enregistre pour le moment                         \n";
        cout <<"-----------------------------------------------------------------------------------"<<endl ;
    }
        else
	while(it != members.end())
    {
        lilo += it -> decritoi() ;
        lilo += "\n\n\n" ;
        it++;
    }
    return lilo ;
}


//controlleurs de membre
void creer_membre()
{
    string inst_id,ID,nom,prenom,adresse,email,tel,tache ;
    cout <<"=============================\\                   /===================================\n";
    cout <<"============================     AJOUT DE MEMBRE    =================================\n";
    cout <<"=============================/                   \\===================================\n";
    cout <<"  veillez remplir ci-dessous ses information                                            |\n";
    cout <<"  ID : "; getline(cin, inst_id) ;
    while(inst_id.empty())
    {
        cout <<"(obligatoire) ";
        getline(cin, inst_id) ;
    }
//-------Verification--------
    bool sid_exist =true ;
    list<membre>::iterator it = members.begin();

    while(it != members.end())
    {
        if(inst_id == it -> get_ID())
            sid_exist = false ;
            it++ ;
    }
    if (!sid_exist)
        {
            cout << "l'id que vous avez saisie existe deja !!"<<endl ;
                creer_membre() ;
        }
    else
    {
        ID = inst_id ;
//-------Verification--------
    cout <<"  Nom : "; getline(cin, nom) ;
    cout <<"  Prenom : ";getline(cin, prenom) ;
    cout <<"  tel : "; getline(cin, tel) ;
    if(tel == "") tel = "inconnu" ;
    while (!is_number(tel)|| tel.size()<8 )
    {
        cout<<"numero de telephone invalide (8 chiffre min indicatif precisé par : 00#### ex : 00229 pour le Benin ): " ;
        getline(cin ,tel) ;
    }

    cout <<"  addresse : ";getline(cin, adresse) ;
    if(adresse == "") adresse = "inconnu" ;
    cout <<"  e-mail : ";getline(cin, email) ;
    if(email == "") email = "inconnu" ;
    cout <<"  tache : ";getline(cin, tache) ;
    if(tache == "") tache = "inconnu" ;

    membre m(ID,tel,nom,prenom,adresse,email,tache) ;
    cout <<"+============================== fin de la creation =====================================+\n";
    members.push_back(m);
    }

    enregistrer_membre() ;
    }

void modifier_membre()
{
string rep;
 string varId;
  cout << "Avez vous des informations par rapport au membre a modifier? (1-oui 0-non) "<<endl;
  cin>>rep;
   while (!is_number(rep) || rep != "1" && rep != "0")
  {
          if (!is_number(rep)) cout<<"saisie invalide ! ";
          else if (rep != "1" && rep != "0") cout <<"veillez saisir 1 ou 0 " ;
          cin>>rep ;
  }
   if (rep=="1")
   {
      rechercher_membre ();
       if (maVariable.empty() )
       {
        cout <<"-----------------------------------------------------------------------------------\n";
        cout <<"                       Pas d'element correspondant a votre recherche \n";
        cout <<"-----------------------------------------------------------------------------------"<<endl ;
   }
       else
        {
    cout<< "Precisez nous l'ID du membre a modifier ?"<<endl;
        cout<<"ID:";
        cin>>varId;
        string ID,nom,prenom,adresse,email,tel,tache ;
       list<membre>::iterator it ;
       for( it=members.begin(); it != members.end() ; ++it )
           {
             if(varId ==(it -> get_ID()))
             {
    cout <<"\n-----------------------------------------------------------------------------------\n";
    cout <<"                     MODIFICATION ! ENTREZ LES NOUVELLE VALEURS                    \n";
    cout <<"-----------------------------------------------------------------------------------\n";
        cin.ignore();

    cout <<"  Nom : "; getline(cin,nom);
    if (!nom.empty())it->set_nom(nom) ;
    cout <<"  Prenom : ";getline(cin,prenom);
    if(!prenom.empty())it->set_prenom(prenom) ;
    cout <<"  tel : "; getline(cin, tel) ;
    if(tel != "")it->set_tel(tel) ;
    cout <<"  addresse : ";getline(cin, adresse) ;
    if(adresse != "")it->set_addresse(adresse);
    cout <<"  e-mail : ";getline(cin, email) ;
    if(email != "")it->set_email(email);
    cout <<"  tache : ";getline(cin, tache) ;
    if(tache != "") it->set_tache(tache);
    cout<<"\n modification effectue \n"<<endl ;
                 rep="yes" ;
             break;
             }
           }
       }
            if (rep!="yes") cout <<"modification non effectuee , ID introuvable " <<endl ;
   }else
   {
        cout<<afficher_membre();
        cout<< "Precisez nous l'ID du membre a modifier ?"<<endl;
            cout<<"ID:";
            cin>>varId;
            string ID,nom,prenom,adresse,email,tel,tache ;
       list<membre>::iterator it ;
       for( it=members.begin(); it != members.end() ; ++it )
           {
             if(varId ==(it -> get_ID()))
             {
        cout <<"\n-----------------------------------------------------------------------------------\n";
    cout <<"                     MODIFICATION ! ENTREZ LES NOUVELLE VALEURS                    \n";
    cout <<"-----------------------------------------------------------------------------------\n";
    cout <<"  Nom : "; cin>> nom;
    if (!nom.empty())it->set_nom(nom) ;
    cout <<"  Prenom : ";cin >>prenom ;
    if(!prenom.empty())it->set_prenom(prenom) ;
    cin.ignore();
    cout <<"  tel : "; getline(cin, tel) ;
    if(tel != "")it->set_tel(tel) ;
    cout <<"  addresse : ";getline(cin, adresse) ;
    if(adresse != "")it->set_addresse(adresse);
    cout <<"  e-mail : ";getline(cin, email) ;
    if(email != "")it->set_email(email);
    cout <<"  tache : ";getline(cin, tache) ;
    if(tache != "") it->set_tache(tache);
    cout<<"\n modification effectue \n"<<endl ;
                 rep="yes" ;
             break;
             }
           }
        if (rep!="yes") cout <<"modification non effectuee , ID introuvable " <<endl ;
   }

   enregistrer_membre() ;
}
void supprimer_membre ()
{
    string RS,nouId;
    cout<<"disposez vous des information par rapport au membre a supprimer ? \n 1-oui \n 0-non"<<endl;
    cin>> RS;
    while (!is_number(RS) || RS != "1" && RS != "0")
                {
                    if (!is_number(RS)) cout<<"saisie invalide ! ";
                    else if (RS != "1" && RS != "0") cout <<"veillez saisir 1 ou 0 " ;
                    cin>>RS ;
                }

    if (RS =="1" )
    {
       rechercher_membre();
          cout<< "veillez entrer l'ID du membre a supprimer" <<endl;
         cin>> nouId;
       list<membre>::iterator it ;
       for( it=members.begin(); it != members.end() ; ++it )
           {
             if(nouId ==(it -> get_ID()))
             {
                it = members.erase(it);
                cout<<"vous avez supprimmer le membre : "<<nouId << endl ;
                RS = "yes" ;
             }
             }
        if (RS!="yes") cout <<"suppression non effectuee , ID introuvable " <<endl ;
    } else
    {
    cout << afficher_membre();
    cout<< "veillez entrer maintenant l'ID du membre a supprimer" <<endl;
    cin>> nouId;
    list<membre>::iterator it ;
       for( it=members.begin(); it != members.end() ; ++it )
           {
             if(nouId ==(it -> get_ID()))
             {
                 it = members.erase(it);
                 cout<<"vous avez supprimmer le membre : "<<nouId << endl ;
                 RS = "yes" ;

             }
             }
            if (RS!="yes") cout <<"suppression non effectuee , ID introuvable " <<endl ;
}
enregistrer_membre() ;
}

string rechercher_membre ()
{
    cout <<"=============================== RECHERCHE DE MEMBRE ===================================\n";
    cout <<"\n\t\tAppuyez sur entree si vous n'avez pas d'information sur un critere ! "<<endl ;
    string lilo="" ;
    string nom , prenom,adresse,email,ID,tel,tache ;
    cin.ignore() ;
    cout <<"  ID > ";
    getline(cin, ID) ;
    if(ID != "")
    {
        list<membre>::iterator it ;
        for( it=members.begin(); it != members.end() ; ++it )
        {
        if ( ID == (it -> get_ID()) )
        {
            lilo = it -> decritoi() ;
            break ;
        }
        }
    }
    else
    {
    cout <<"  Nom > ";
    getline(cin, nom);
    cout <<"  Prenom : ";
    getline(cin, prenom) ;
    cout <<"  tel > ";
    getline(cin, tel) ;
    cout <<"  addresse > ";
    getline(cin, adresse) ;
    cout <<"  e-mail > ";
    getline(cin, email) ;
    cout <<"  tache > ";
    getline(cin, tache) ;
    cout <<"-------------------------------------------------------------------------\n" ;
//*********************NOM DEBUT*******************************
    if(nom != "")//100000
    {
        rech_nom(members,members1,nom,lilo) ;
            //--------------------prenom debut-----------------------
            if(prenom != "")//110000
                {
                    rech_prenom(members1,members2,prenom,lilo) ;
                    if(tel != "")//111000
                        {
                            rech_tel(members2,members3,tel,lilo);
                            if(adresse != "")//111100
                                {
                                    rech_addresse(members3,members4,adresse,lilo) ;
                                    if(email != "")//111110
                                    {
                                        rech_email(members4,members5,email,lilo) ;
                                        if(tache != "")//111111
                                            {
                                                rech_tache(members5,members6,tache,lilo);
                                            }
                                    }
                                }
                        }else
                        {
                        if(adresse!="")//110100
                        {
                            rech_addresse(members2,members3,adresse,lilo);
                            if(email != "")//110110
                                {
                                    rech_email(members3,members4,email,lilo) ;
                                    if(tache != "")//110111
                                    {
                                        rech_tache(members4,members5,tache,lilo);
                                    }
                                }
                        }else
                        if(email!="")//110010
                        {
                            rech_email(members2,members3,email,lilo);
                                    if(tache != "")//110011
                                    {
                                        rech_tache(members3,members4,tache,lilo) ;
                                    }
                        }else
                        if(tache!="")//110001
                        {
                            rech_tache(members2,members3,tache,lilo);
                        }
                        }
                }
                if(prenom == "" && adresse != "")//100100
                    {
                    rech_addresse(members1,members2,adresse,lilo) ;
                    if(tel != "")//101100
                        {
                            rech_tel(members2,members3,tel,lilo);
                                    if(email != "")//101110
                                    {
                                        rech_email(members3,members4,email,lilo) ;
                                        if(tache != "")//101111
                                            {
                                                rech_tache(members4,members5,tache,lilo);
                                            }
                                    }
                        }
                    }
                if(prenom == "" && adresse == "" &&tel != "")//101000
                     {
                    rech_tel(members1,members2,tel,lilo) ;
                                    if(email != "")//101010
                                    {
                                        rech_email(members2,members3,email,lilo) ;
                                        if(tache != "")//101001
                                            {
                                                rech_tache(members3,members4,tache,lilo);
                                            }
                                    }
                    }
                if(prenom == "" && adresse == ""&& tel == "" &&email != "")//100010
                    {
                    rech_email(members1,members2,email,lilo) ;
                                        if(tache != "")//100011
                                            {
                                                rech_tache(members2,members3,tache,lilo);
                                            }
                    }

                    if(prenom == "" && adresse == "" &&tel == "" &&email == "" && tache!="")
                        {
                            rech_tache(members1,members2,tache,lilo) ;
                        }
}
//*********************NOM FIN*******************************
//*********************PRENOM DEBUT*******************************
   if(nom == "" && prenom != "")
    {
        rech_prenom(members,members1,prenom,lilo) ;
            if(adresse != "")
                {
                    rech_addresse(members1,members2,adresse,lilo) ;
                            if(tel != "")
                                {
                                    rech_tel(members2,members3,tel,lilo) ;
                                    if(email != "")
                                    {
                                        rech_email(members3,members4,email,lilo) ;
                                        if(tache != "")
                                            {
                                                rech_tache(members4,members5,tache,lilo);
                                            }
                                    }
                                }
                }

                if(adresse == "" && tel !="" )
                    {
                    rech_tel(members1,members2,tel,lilo) ;
                                    if(email != "")
                                    {
                                        rech_email(members2,members3,email,lilo) ;
                                        if(tache != "")
                                            {
                                                rech_tache(members3,members4,tache,lilo);
                                            }
                                    }
                    }
                if(adresse == "" &&tel == "" && email!="")
                     {
                    rech_email(members1,members2,email,lilo) ;
                                        if(tache != "")
                                            {
                                                rech_tache(members2,members3,tache,lilo);
                                            }
                     }

                if(adresse == ""&& tel == "" &&email == "" && tache!= "")
                    {
                    rech_tache(members1,members2,tache,lilo) ;
                                        if(tache != "")
                                            {
                                                rech_tache(members2,members3,tache,lilo);
                                            }
                    }
    }
        }

//*********************PRENOM FIN*******************************
//*********************ADDRESSE DEBUT*******************************
if( nom == "" && prenom == "" && adresse!="" )
    {
        rech_addresse(members,members1,adresse,lilo) ;
                            if(tel != "")
                                {
                                    rech_tel(members1,members2,tel,lilo) ;
                                    if(email != "")
                                    {
                                        rech_email(members2,members3,email,lilo) ;
                                        if(tache != "")
                                            {
                                                rech_tache(members3,members4,tache,lilo);
                                            }
                                    }
                                    }

                if(tel =="" && email !="" )
                    {
                    rech_email(members1,members2,tel,lilo) ;
                                        if(tache != "")
                                            {
                                                rech_tache(members2,members3,tache,lilo);
                                            }
                    }

                if(tel == "" && email=="" && tache!= "")
                     {
                    rech_tache(members1,members2,email,lilo) ;
                                        if(tache != "")
                                            {
                                                rech_tache(members2,members3,tache,lilo);
                                            }
                     }
}
//*********************ADDRESSE FIN*******************************
//*********************TEL DEBUT*******************************
if(nom == "" && prenom == "" && adresse=="" && tel!= "")
    {
                rech_tel(members,members1,tel,lilo) ;
                                    if(email != "")
                                    {
                                        rech_email(members1,members2,email,lilo) ;
                                        if(tache != "")
                                            {
                                                rech_tache(members2,members3,tache,lilo);
                                            }
                                    }
                                    if(email =="" && tache!="")
                                        {
                                            rech_tache(members1,members2,tache,lilo) ;
                                    }
    }
//*********************TEL FIN*******************************
//*********************EMAIL DEBUT*******************************
if(nom == "" && prenom == "" && adresse=="" && tel== ""  && email !="")
    {
                rech_email(members,members1,email,lilo) ;
                                        if(tache != "")
                                            {
                                                rech_tache(members1,members2,tache,lilo);
                                            }
    }
//*********************EMAIL FIN*******************************

//*********************TACHE DEBUT*******************************
if(nom == "" && prenom == "" && adresse=="" && tel== ""  && email ==""&& tache != "")
    {
                rech_tache(members,members1,tache,lilo) ;
    }
//*********************TACHE FIN*******************************
maVariable =lilo ;
if (maVariable.empty() )
        cout<< "\n aucun element trouve !! \n"<<endl;
cout << lilo <<endl;
    return "" ;
}
//controlleurs de tache
string afficher_tache()
{
    list<tache>::iterator it = tasks.begin();
    string contenuListe;
    if(tasks.empty())
    {
    cout <<"\n-----------------------------------------------------------------------------------\n";
    cout <<"                     Aucune tache a afficher pour le moment\n";
    cout <<"-----------------------------------------------------------------------------------\n";
    }
	while(it != tasks.end())
    {
        contenuListe += it -> decristoi() ;
        contenuListe += "\n\n" ;
        it++;
    }
    maVariable_Tache=contenuListe;
    return contenuListe ;
}
void creer_tache()
{
    tache t ;
    string inst_id,m_tache_id,m_tache_nom,m_tache_description,m_tache_date_debut,m_tache_date_fin,m_tache_etat ;
    cout <<"=============================\\                   /===================================\n";
    cout <<"============================     AJOUT DE TACHE    ==================================\n";
    cout <<"=============================/                   \\===================================\n";
    cout <<"  veillez fournir les informations ci-dessous                                           |\n";
    cout <<"  ID > "; cin >>inst_id ;
//-------Verification--------
    bool sid_exist =true ;
    list<tache>::iterator it = tasks.begin();
    while(it != tasks.end())
    {
        if(inst_id == it -> get_tache_id())
            sid_exist = false ;
            it++ ;
    }
    if (!sid_exist)
        {
            cout << "l'id que vous avez saisie existe deja !!" <<endl;
            creer_tache() ;
        }
    else
    {
     t.set_tache_id(inst_id) ;
//-------Verification--------
    //verificatioon ihhhh
    cout <<"  Nom > "; cin >>m_tache_nom ;
    t.set_tache_nom(m_tache_nom) ;
    cin.ignore();

    cout <<"  Description > "; getline(cin, m_tache_description) ;
    if(m_tache_description == "") m_tache_description = "inconnu" ;
    t.set_tache_description(m_tache_description) ;

    cout <<"  Date de debut (jj/mm/aa/) > ";getline(cin, m_tache_date_debut) ;
    if(m_tache_date_debut == "") m_tache_date_debut = "inconnu" ;
    else{
        while (!is_in_date_format(m_tache_date_debut))
        {
            cout<<"date invalide ! (jj/mm/aa/) : " ;
            getline(cin,m_tache_date_debut) ;
        }
    }
    t.set_tache_date_debut(m_tache_date_debut) ;

    cout <<"  Date de fin (jj/mm/aa/) > ";getline(cin, m_tache_date_fin) ;
    if(m_tache_date_fin == "") m_tache_date_fin = "inconnu" ;
    else{
        while (!is_in_date_format(m_tache_date_fin) || !t.date_comparator(m_tache_date_fin))
        {
            if(!t.date_comparator(m_tache_date_fin)) cout <<"eureur ! date de fin anterieur a la date de debut ! " ;
            if (!is_in_date_format(m_tache_date_fin)) cout<<"date invalide ! (jj/mm/aa/) : " ;
            getline(cin,m_tache_date_fin);
        }
    }
    t.set_tache_date_fin(m_tache_date_fin) ;
    cout <<"  Etat de realisation > ";getline(cin, m_tache_etat) ;
    if(m_tache_etat == "") m_tache_etat = "inconnu" ;
    t.set_tache_tache_etat(m_tache_etat) ;
    tasks.push_back(t) ;

    cout <<"+============================== fin de la creation =====================================+\n";
enregistrer_tache() ;
}
}
void modifier_tache()
{
string varId;
cout<<afficher_tache()<<endl;
        cout<< "Precisez nous l'ID de la tache a modifier ?"<<endl;
            cout<<"ID:";
            cin>>varId;
        string nm,ID,dbu,dfi,des,eta ;
        list<tache>::iterator it ;
        for( it=tasks.begin(); it != tasks.end() ; ++it )
           {
             if(varId ==(it -> get_tache_id()))
             {
    cout <<"  MODIFICATION: veuillez entrer les nouvelles valeurs |\n";
    cout <<"Nom : "; cin>> nm;
    if(!nm.empty())it->set_tache_nom(nm) ;
    cout <<"  Date de debut : "; cin>> dbu;
    if(!dbu.empty())
        while (!is_in_date_format(dbu))
        {
            cout<<"date invalide ! (jj/mm/aa/) : " ;
            getline(cin,dbu) ;
        }
    it->set_tache_date_debut(dbu) ;
    cout <<"  Date de fin : ";cin >>dfi ;
    if(!dfi.empty())
        while (!is_in_date_format(dfi) || !(it -> date_comparator(dfi)))
        {
            if(!(it-> date_comparator(dfi))) cout <<"eureur ! date de fin anterieur a la date de debut ! " ;
            if (!is_in_date_format(dfi)) cout<<"date invalide ! (jj/mm/aa/) : " ;
            cin >>dfi ;
        }
    it->set_tache_date_fin(dfi) ;
    cin.ignore();
    cout <<"  Description : "; getline(cin, des) ;
    if(!des.empty())it -> set_tache_description(des);
    cout <<"  etat : ";getline(cin, eta) ;
    if(eta.empty()) it -> set_tache_tache_etat(eta);
    varId="yes" ;
             }
}
        if (varId!="yes") cout <<"modification non effectuee , ID introuvable " <<endl ;
enregistrer_tache();

}

void supprimer_tache()
{
    string RS; string nouId;
    cout<<"disposez vous des information par rapport a la  tache a supprimer ? \n 1-oui \n 0-non"<<endl;
    cin>> RS;
    while (!is_number(RS) || RS != "1" && RS != "0")
                {
                    if (!is_number(RS)) cout<<"saisie invalide ! ";
                    else if (RS != "1" && RS != "0") cout <<"veillez saisir 1 ou 0 " ;
                    cin>>RS ;
                }
    if (RS =="1" )
    {
       rechercher_tache();
          cout<< "veillez entrer l'ID de la tache a supprimer" <<endl;
         cin>> nouId;
       list<tache>::iterator it ;
       for( it=tasks.begin(); it != tasks.end() ; ++it )
           {
             if(nouId ==(it -> get_tache_id()))
             {
                 it = tasks.erase(it);
                 RS = "yes" ;
             }
    }
    if (RS!="yes") cout <<"suppression non effectuee , ID introuvable " <<endl ;
    }else
    {
       cout << afficher_tache();
        cout<< "veillez entrer maintenant l'ID de la tache a supprimer" <<endl;
         cin>> nouId;

       list<tache>::iterator it ;
       for( it=tasks.begin(); it != tasks.end() ; ++it )
           {
             if(nouId ==(it -> get_tache_id()))
             {
                 it = tasks.erase(it);
                 cout<<"vous avez supprimmer une tache : "<<nouId << endl ;
                 RS = "yes" ;
             }
    }
        if (RS!="yes") cout <<"suppression non effectuee , ID introuvable " <<endl ;
}
enregistrer_tache() ;
}
string rechercher_tache()
{
    cout <<"=============================== RECHERCHE DE TACHE ===================================\n";
    cout <<"\n\t\tAppuyez sur entree si vous n'avez pas d'information sur un critere ! "<<endl ;
    string lilo="" ;
    string ID,nom,ddeb,ddef,etat ;
    cin.ignore() ;
    cout <<"  ID > ";
    getline(cin, ID) ;
    if(ID != "")
    {
        list<tache>::iterator it ;
        for( it=tasks.begin(); it != tasks.end() ; ++it )
        {
        if ( ID == (it -> get_tache_id()) )
        {
            lilo = it -> decristoi() ;
            break ;
        }
        }
    }
    else
    {
    cout <<"  Nom > ";
    getline(cin, nom);

    cout <<"  Date de debut > ";
    getline(cin, ddeb) ;

    cout <<"  Date de fin > ";
    getline(cin, ddef) ;

    cout <<"  etat > ";
    getline(cin, etat) ;

    cout <<"------------------------------------------------------------------------------------------------\n" ;
     if(nom != "")
{
        rech_nom_tach(tasks,taches1,nom,lilo) ;

            if(ddeb != "")
                {
                    rech_ddeb(taches1,taches2,ddeb,lilo) ;
                    if(ddef != "")
                        {
                            rech_ddef(taches2,taches3,ddef,lilo);
                            if(etat != "")
                                {
                                    rech_eta(taches3,taches4,etat,lilo) ;
                                }
                        }
                }
                if(ddeb == "" && ddef != "")
                    {
                    rech_ddef(taches1,taches2,ddef,lilo) ;
                    if(etat != "")
                        {
                            rech_eta(taches2,taches3,etat,lilo);
                        }
                    }
                if(ddeb == "" && ddef == "" &&etat != "")
                     {
                    rech_eta(taches1,taches2,etat,lilo) ;
                    }
}
//*********************NOM FIN*******************************
//*********************DDEB DEBUT*******************************
   if(nom == "" && ddeb != "")
    {
        rech_ddeb(tasks,taches1,ddeb,lilo) ;
            if(ddef != "")
                {
                    rech_ddef(taches1,taches2,ddef,lilo) ;
                            if(etat != "")
                                {
                                    rech_eta(taches2,taches3,etat,lilo) ;
                                }
                }

                if(ddeb == "" && etat !="" )
                    {
                        rech_eta(taches1,taches2,etat,lilo) ;
                    }
    }
//*********************DDEB FIN*******************************
//*********************DDEF DEBUT*******************************
if(nom == "" && ddeb == "" &&ddef!="")
    {
        rech_ddef(tasks,taches1,ddef,lilo) ;
            if(etat != "")
                {
                    rech_eta(taches1,taches2,etat,lilo) ;
                }
    }
//*********************DDEF FIN*******************************
//*********************ETAT DEBUT*******************************
if(nom == "" && ddeb == "" && ddef=="" && etat!="")
    {
                    rech_eta(tasks,taches1,etat,lilo) ;
    }
//*********************ETAT FIN*******************************

}
maVariable =lilo ;
if (maVariable.empty() )
        cout<< "\n aucun element trouve !! \n"<<endl;
cout << lilo <<endl;
    return "" ;
}

//autres fonctions necessaire
void assigner_tache()
{
string rep;
string tache_id ;
string tache_nom ;
string varId;
  cout << "Avez vous des informations par rapport au membre  concerne ? (1-oui 0-non) : ";
  cin>>rep;
  while (!is_number(rep) || rep != "1" && rep != "0")
  {
          if (!is_number(rep)) cout<<"saisie invalide ! ";
          else if (rep != "1" && rep != "0") cout <<"veillez saisir 1 ou 0 " ;
          cin>>rep ;
  }
   if (rep=="1")
   {
      rechercher_membre();
      if (!maVariable.empty())
        {
        cout<< "Precisez l'ID du concerne \n ID : "<<endl;
        cin>>varId;
 list<tache>::iterator it ;
       for( it=tasks.begin(); it != tasks.end() ; ++it )
           {
             if(tache_id ==(it -> get_tache_id()))
                tache_nom = it -> get_tache_nom() ;
           }
           if(tache_nom.empty())
           {
               string repp;
               cout <<"tache introuvable . voulez vous en creer ? (1- oui 0- non )" ;
               cin>>repp ;
               while (!is_number(repp) || repp != "1" && repp != "0")
                {
                    if (!is_number(repp)) cout<<"saisie invalide ! ";
                    else if (repp != "1" && repp != "0") cout <<"veillez saisir 1 ou 0 " ;
                    cin>>repp ;
                }
                if (repp =="1") creer_tache() ;
           }else{
//-------------
       list<membre>::iterator it ;
       for( it=members.begin(); it != members.end() ; ++it )
           {
             if(varId ==(it -> get_ID()))
             {
                 if (it->get_tache() == "inconnu") it -> set_tache("") ;
                 string newtache = it->get_tache()+" " ;
                 //on verifie si la tache n'est pas deja assignée
                 size_t found = newtache.find(tache_nom);
                 if (found != string::npos)
                    cout <<"ce membre a deja une tache de ce nom ! " <<endl;
                 //fin de verification
                else
                {
                    newtache += tache_nom ;
                    it -> set_tache(newtache) ;
                    cout<<"tache assignée avec suces ! " <<endl ;
                }

             }
           }
   }
   }
   }else
   {
        cout<< afficher_membre()<<endl;
        cout<< "Precisez l'ID du concerne "<<endl;
            cout<<"ID:";
            cin>>varId;

            list<membre>::iterator it ;
        for( it=members.begin(); it != members.end() ; ++it )
           {
             if(varId ==(it -> get_ID()))
             {
                rep= "yes" ;
             }
        }
        if (rep !="yes" )
            cout <<"membre introuvable ! "<<endl ;
        else
        {
        cout<< "Precisez nous l'ID de la tache a assigner : ";
        cin>>tache_id;

        list<tache>::iterator it ;
        for( it=tasks.begin(); it != tasks.end() ; ++it )
           {
             if(tache_id ==(it -> get_tache_id()))
                tache_nom = it -> get_tache_nom() ;
           }

           if(tache_nom.empty())
           {
               string repp;
               cout <<"tache introuvable . voulez vous en creer ? (1- oui 0- non )" ;
               cin>>repp ;
               while (!is_number(repp) || repp != "1" && repp != "0")
                {
                    if (!is_number(repp)) cout<<"saisie invalide ! ";
                    else if (repp != "1" && repp != "0") cout <<"veillez saisir 1 ou 0 " ;
                    cin>>repp ;
                }
                if (repp =="1") creer_tache() ;
           }else{
//-------------
       list<membre>::iterator it ;
       for( it=members.begin(); it != members.end() ; ++it )
           {
             if(varId ==(it -> get_ID()))
             {
                 if (it->get_tache() == "inconnu") it -> set_tache("") ;
                 string newtache = it->get_tache()+" ";
                 newtache += tache_nom ;
                 it -> set_tache(newtache) ;
             }
           }
   }
enregistrer_membre() ;
}
}
}
string afficher_tasklist_member()
{
string lilo="" ;
string rep;
string varId;
  cout << "pouvez/pouvez vous specifiez le membre dont vous voulez voir les taches ? (1-oui 0-non) : ";
  cin>>rep;
  while (!is_number(rep) || rep != "1" && rep != "0")
  {
          if (!is_number(rep)) cout<<"saisie invalide ! ";
          else if (rep != "1" && rep != "0") cout <<"veillez saisir 1 ou 0 " ;
          cin>>rep ;
  }
   if (rep=="1")
   {
      rechercher_membre();
      if (maVariable.empty()) cout<< "\n Pas d'elements correspondant a votre recherche \n"<<endl;
       else
        {
            cout<< "Precisez l'ID du concerne "<<endl;
            cin>>varId;
        }
       list<membre>::iterator it ;
       for( it=members.begin(); it != members.end() ; ++it )
           {
             if(varId ==(it -> get_ID()))
                {
                    lilo += "ID : ";
                    lilo +=it ->get_ID() +"\n";
                    lilo +="Nom : " +it->get_nom() +" \n prenom : " + it ->get_prenon() ;
                    lilo +="\n taches assignees : " + it->get_tache();
                    break ;
                }
             }
    }else
   {
       list<membre>::iterator it ;
       for( it=members.begin(); it != members.end() ; ++it )
           {
                    lilo += "ID : ";
                    lilo +=it ->get_ID() +"\n";
                    lilo +=" Nom : " +it->get_nom() +" \n  prenom : " + it ->get_prenon() ;
                    lilo +="\n   taches assignees : " + it->get_tache()+"\n\n";
           }
   }
    return lilo ;
}
 void verify(string cas)
    {
    //----on verifie si l'adminnistrateur veux faire une autre tache , si c'est le cas on reaffiche le menu sinon baff
    if(cas == "autre_tache")
    {
    string ret1 ;
    int iret1 = 0 ;
    cout <<" \n 1-MENU PRINCIPAL   0-QUITTER > " ;
    cin>>ret1 ;
    while(!is_number(ret1) || ret1!="1" && ret1!="0")
    {
        cout <<"entrez invalide selectionnez 1  ou 0 "<<endl ;
        cin>>ret1 ;
    }
    iret1 = atoi(ret1.c_str()) ;
    if(iret1 == 1) autre_tache = true ;
    else
    if(iret1 == 0) autre_tache = false ;
    //-----------------------------------------------------------------------------------------------------------------
    }
    else if(cas == "rep_acu")
    {
        bool ret2 ;
        do
        {
        ret2 = false ;
        if(!is_number(rep_acu))
        {
            cout <<"saisie invalide. saisissez un numero : " ;
            cin >> rep_acu ;
        }
        else
        {
        int rep_int ;
        istringstream iss1(rep_acu) ;
        iss1>>rep_int;

        for(int i = 1 ; i<14 ; i++)
        if(rep_int == i)
        {ret2 = true ; break ;}
        if(ret2 == false)
        {
            cout << "saisie invalide ! choisissez un numero valide indiqué dans le menu : "<<endl ;
            cin >> rep_acu ;
        }
        }
        }while(ret2==false);
    }
    }
bool is_in_date_format(string t_date)
{
    string jj(""),mm(""),aa("");
    int ijj,imm,iaa =0 ;
    jj += t_date[0];jj += t_date[1] ;
    mm += t_date[3];mm += t_date[4] ;
    aa += t_date[6];aa += t_date[7] ;
    ijj = atoi(jj.c_str()) ;
    imm = atoi(mm.c_str()) ;
    iaa = atoi(aa.c_str()) ;
    if(t_date.length()!=8  || !is_number(jj) || !is_number(mm) || !is_number(aa) || t_date[2]!='/' || t_date[5]!='/' || ( ijj<1 || imm<1 ) || (ijj > 31 || imm >12))
        return false ;
        else if((imm == 04 || imm == 06 || imm==9 || imm == 11) && (ijj > 30) )
        return false ;
        else if (imm == 02 && ijj>28 )
            return false ;
        else
            return true ;
}
     bool is_number(const string &s)
{
    string::const_iterator it = s.begin() ;
    while(it != s.end() && isdigit(*it))
        ++it ;
    return  !s.empty() && it == s.end() ;
}
void enregistrer_tache()
{
 ofstream monFlux(s_tache.c_str());
 if(monFlux)
 {
    string ocure="" ;
           list<tache>::iterator it ;
       for( it=tasks.begin(); it != tasks.end() ; ++it )
           {
                ocure += it -> decristoi() ;
                ocure += "\n" ;
           }
        monFlux <<ocure;
 }
}
void enregistrer_membre()
{
    ofstream monFlux(s_membre.c_str());
    string ocure="" ;
           list<membre>::iterator it ;
       for( it=members.begin(); it != members.end() ; ++it )
           {
                ocure += it -> decritoi() ;
                ocure += "\n" ;
           }
        monFlux <<ocure;
}
  void maj_members()
    {
    ifstream lire1(s_membre.c_str()) ;
    //----------------lecture fait a 3h42 ------------------
    string line="" ;
    string info[7] ;
    int pos=0 ;
        while(getline(lire1,line))
        {
            string s1="";
            	string revers1="";
            	for (int i = line.size() ; i >0 ; i--)
                    revers1 +=line[i];

                for (int i = 0; i <revers1.size()  ; i++)
                    {
                        if(revers1[i] == ':')
                        s1 = revers1.substr(1,i-2) ;
                    }
                    string revers2="";
            	for (int i = s1.size()-1 ; i >=0 ; i--)
                    revers2 +=s1[i];

                    info[pos] = revers2 ;
                    pos++ ;
                    if(pos==7)
                    {
                        membre m ;
                        m.set_ID(info[0]);
                        m.set_nom(info[1]);
                        m.set_prenom(info[2]);
                        m.set_addresse(info[3]);
                        m.set_tel(info[4]);
                        m.set_email(info[5]);
                        m.set_tache(info[6]);
                        members.push_back(m);
                        pos =0 ;
                    }

        }
    //----------------lecture fait a 3h42 ------------------
    }
    void maj_tache()
    {
        ifstream lire2(s_tache.c_str()) ;
    //----------------lecture fait a 3h42 ------------------
    string lina="" ;
    string infa[6] ;
    int po=0 ;
        while(getline(lire2,lina))
        {
            string s1="";
            string revers1="";
            	for (int i = lina.size() ; i >0 ; i--)
                    revers1 +=lina[i];

                for (int i = 0; i <revers1.size()  ; i++)
                    {
                        if(revers1[i] == ':')
                        s1 = revers1.substr(1,i-2) ;
                    }
                    string revers2="";
            	for (int i = s1.size()-1 ; i >=0 ; i--)
                    revers2 +=s1[i];

                    infa[po] = revers2 ;
                    po++ ;
                    if(po==6)
                    {
                        tache t ;
                        t.set_tache_id(infa[0]);
                        t.set_tache_nom(infa[1]);
                        t.set_tache_description(infa[2]);
                        t.set_tache_date_debut(infa[3]);
                        t.set_tache_date_fin(infa[4]);
                        t.set_tache_tache_etat(infa[5]);
                        tasks.push_back(t);
                        po =0 ;
                    }
        }
    //----------------lecture fait a 3h42 -----------------------
    }
void rech_nom(list<membre> &list1 , list<membre> &list2,string nom,string &rec)
{
        list2.clear();
        list<membre>::iterator ite1=list1.begin()  , ite2=list2.begin() ;
        while(ite1 != list1.end())
    {
            if ( nom == (ite1 -> get_nom()) )
            {
                list2.insert(ite2,*ite1) ;
                ++ite2;
            }
            ite1++;
    }
    ite2 = list2.begin();
	while ( ite2 != list2.end() )
        {
                rec += ite2 -> decritoi() ;
                rec += "\n" ;
            ite2++ ;
        }
}

void rech_prenom(list<membre> &list1 , list<membre> &list2,string prenom,string &rec)
{
        list2.clear();
        rec = "" ;
        list<membre>::iterator ite1=list1.begin()  , ite2=list2.begin() ;
        while( ite1 != list1.end() )
    {
            if ( prenom == (ite1 -> get_prenon()) )
            {
                list2.insert(ite2,*ite1) ;
                ++ite2;
            }
            ite1++;
    }
    ite2 = list2.begin();
	while ( ite2 != list2.end() )
        {
            if(prenom==ite2->get_prenon())
            {
                rec += ite2 -> decritoi() ;
                rec += "\n" ;
            ite2++ ;
        }
        }
}
void rech_tel(list<membre> &list1 , list<membre> &list2,string tel,string &rec)
{
        list2.clear();
        rec = "" ;
        list<membre>::iterator ite1=list1.begin()  , ite2=list2.begin() ;
        while( ite1 != list1.end() )
    {
            if ( tel == (ite1 -> get_tel()) )
            {
                list2.insert(ite2,*ite1) ;
                ++ite2;
            }
            ite1++;
    }
    ite2 = list2.begin();
	while ( ite2 != list2.end() )
        {
                rec += ite2 -> decritoi() ;
                rec += "\n" ;
            ite2++ ;
        }

}
void rech_addresse(list<membre> &list1 , list<membre> &list2,string adresse,string &rec)
{
        list2.clear();
        rec = "" ;
        list<membre>::iterator ite1=list1.begin()  , ite2=list2.begin() ;
        while( ite1 != list1.end() )
    {
            if ( adresse == (ite1 -> get_addresse()) )
            {
                list2.insert(ite2,*ite1) ;
                ++ite2;
            }
            ite1++;
    }
    ite2 = list2.begin();
	while ( ite2 != list2.end() )
        {
                rec += ite2 -> decritoi() ;
                rec += "\n" ;
            ite2++ ;
        }
}
void rech_email(list<membre> &list1 , list<membre> &list2,string email,string &rec)
{
        list2.clear();
        rec = "" ;
        list<membre>::iterator ite1=list1.begin()  , ite2=list2.begin() ;
        while( ite1 != list1.end() )
    {
            if ( email == (ite1 -> get_email()) )
            {
                list2.insert(ite2,*ite1) ;
                ++ite2;
            }
            ite1++;
    }
    ite2 = list2.begin();
	while ( ite2 != list2.end() )
        {
                rec += ite2 -> decritoi() ;
                rec += "\n" ;
            ite2++ ;
        }

}
void rech_tache(list<membre> &list1 , list<membre> &list2,string tache,string &rec)
{
        list2.clear();
        rec = "" ;
        list<membre>::iterator ite1=list1.begin()  , ite2=list2.begin() ;
        while( ite1 != list1.end() )
    {
            if ( tache == (ite1 -> get_tache()) )
            {
                list2.insert(ite2,*ite1) ;
                ++ite2;
            }
            ite1++;
    }
    ite2 = list2.begin();
	while ( ite2 != list2.end() )
        {
                rec += ite2 -> decritoi() ;
                rec += "\n" ;
            ite2++ ;
        }
}
void rech_nom_tach(list<tache> &list1 , list<tache> &list2,string nom,string &rec)
{
     list2.clear();
        rec = "" ;
        list<tache>::iterator ite1=list1.begin()  , ite2=list2.begin() ;
        while( ite1 != list1.end() )
    {
            if ( nom == (ite1 -> get_tache_nom()) )
            {
                list2.insert(ite2,*ite1) ;
                ++ite2;
            }
            ite1++;
    }
    ite2 = list2.begin();
	while ( ite2 != list2.end() )
        {
                rec += ite2 -> decristoi() ;
                rec += "\n" ;
            ite2++ ;
        }
}
void rech_ddeb(list<tache> &list1 , list<tache> &list2,string ddeb,string &rec)
{
    list2.clear();
        rec = "" ;
        list<tache>::iterator ite1=list1.begin()  , ite2=list2.begin() ;
        while( ite1 != list1.end() )
    {
            if ( ddeb == (ite1 -> get_tache_date_debut()) )
            {
                list2.insert(ite2,*ite1) ;
                ++ite2;
            }
            ite1++;
    }
    ite2 = list2.begin();
	while ( ite2 != list2.end() )
        {
                rec += ite2 -> decristoi() ;
                rec += "\n" ;
            ite2++ ;
        }
}
void rech_ddef(list<tache> &list1 , list<tache> &list2,string ddef,string &rec)
{
    list2.clear();
        rec = "" ;
        list<tache>::iterator ite1=list1.begin()  , ite2=list2.begin() ;
        while( ite1 != list1.end() )
    {
            if ( ddef == (ite1 -> get_tache_date_fin()) )
            {
                list2.insert(ite2,*ite1) ;
                ++ite2;
            }
            ite1++;
    }
    ite2 = list2.begin();
	while ( ite2 != list2.end() )
        {
                rec += ite2 -> decristoi() ;
                rec += "\n" ;
            ite2++ ;
        }
}
void rech_eta(list<tache> &list1 , list<tache> &list2,string etat,string &rec)
{
    list2.clear();
        rec = "" ;
        list<tache>::iterator ite1=list1.begin()  , ite2=list2.begin() ;
        while( ite1 != list1.end() )
    {
            if ( etat == (ite1 -> get_tache_tache_etat()) )
            {
                list2.insert(ite2,*ite1) ;
                ++ite2;
            }
            ite1++;
    }
    ite2 = list2.begin();
	while ( ite2 != list2.end() )
        {
                rec += ite2 -> decristoi() ;
                rec += "\n" ;
            ite2++ ;
        }
}
void n_time()
    {
    //on verifie si ç'est la premiere execution du fichier pour enooncer les conditions d'itulisation
    string mbr_file("Membres.txt");
    string tche_file("Taches.txt");
    string condi_file("condi.txt");
    ofstream output;
    if(!is_readable(mbr_file.c_str()) && !is_readable(tche_file.c_str()))
        {
    ifstream lire(condi_file.c_str()) ;
    string lina="" ;
    int line = 0 ;
    string rep ;
        while(getline(lire,lina))
        {
            cout <<lina<<endl;
            if(line%40==0)
            {
cout<<"                                                                                                          ____________ "<<endl ;
cout<<"                                                                                                         |   SUIVANT  | "<<endl ;
cout<<"                                                                                                         |____________|  "<<endl ;
            getline(cin,lina) ;
            }
            line ++ ;
        }
            cout <<" 0 - je refuse                                                              1 - j'accepte\n";
            cout <<"     les                                                                        les      \n";
            cout <<"     conditions                                                                 conditions\n";
            cin>>rep ;
             while (!is_number(rep) || rep != "1" && rep != "0")
                {
                    if (!is_number(rep)) cout<<"saisie invalide ! ";
                    else if (rep != "1" && rep != "0") cout <<"veillez saisir 1 ou 0 " ;
                    cin>>rep ;
                }
                if(rep == "1")
                {
cout <<"_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
cout <<"|                                                                                                                                            |\n";
cout <<"----------------------------------------------------------------------------------------------------------------------------------------------\n";
cout <<"|                                            T  A  S  K       M  A  N  A G  E  R     1.0.0                                                   |\n";
cout <<"----------------------------------------------------------------------------------------------------------------------------------------------\n";
cout <<"|                                                                                                                                            |\n";
cout <<"_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
            system("echo .>Membres.txt") ;
            system("echo .>Taches.txt") ;
                }
                else
                {
                    cout <<"\n A PLUS TARD ! \n " ;
                    exit(10) ;
                }
        }
    }
bool is_readable(const string &file)
{
  ifstream fichier(file.c_str());
  return !fichier.fail();
}
