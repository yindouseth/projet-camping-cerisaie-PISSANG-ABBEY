#ifndef TYPE_EMPLACEMENT_H_INCLUDED
#define TYPE_EMPLACEMENT_H_INCLUDED

#define MAX_TYPES 100

typedef struct {
    int id_type;
    char libelle[30];
    float prix_jour_personne;
} Type_Emplacement;

// Variables globales
extern Type_Emplacement types[MAX_TYPES];
extern int nb_types;

// Prototypes
void chargerTypes();
void sauvegarderTypes();
void ajouterType();
void modifierType();
void supprimerType();
void consulterType(int id);
void listerTypes();

#endif // TYPE_EMPLACEMENT_H_INCLUDED
