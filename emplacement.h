#ifndef EMPLACEMENT_H_INCLUDED
#define EMPLACEMENT_H_INCLUDED

#define MAX_EMPLACEMENTS 200

typedef struct {
    int id_emplacement;
    char nom[30];
    int capacite;
    int id_type; // clé étrangère vers Type_Emplacement
} Emplacement;

// Variables globales
extern Emplacement emplacements[MAX_EMPLACEMENTS];
extern int nb_emplacement;

// Prototypes
void chargerEmplacements();
void sauvegarderEmplacements();
void ajouterEmplacement();
void modifierEmplacement();
void supprimerEmplacement();
void consulterEmplacement(int id);
void listerEmplacements();

#endif // EMPLACEMENT_H_INCLUDED
