#include "Values.h"

Values::Values()
{

}
//affichons l'accueil
string Values::afficher_accueil()
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
string Values::cadran_depart()
{
        string str ;
 str +=  "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
 str +=  "|                                                                                                                                            |\n";
 str +=  "----------------------------------------------------------------------------------------------------------------------------------------------\n";
 str +=  "|                                            T  A  S  K       M  A  N  A G  E  R     1.0.0                                                   |\n";
 str +=  "----------------------------------------------------------------------------------------------------------------------------------------------\n";
 str +=  "|                                                                                                                                            |\n";
 str +=  "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
 return str ;
}
