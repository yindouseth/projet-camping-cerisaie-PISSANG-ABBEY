#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type_emplacement.h"

#define FICHIER "types_emplacements.dat"

Type_Emplacement types[MAX_TYPES];
int nb_types = 0;

// Charger les types depuis le fichier
void chargerTypes() {
    FILE *f = fopen(FICHIER, "rb");
    if (!f) {
        nb_types = 0;
        return;
    }
    nb_types = fread(types, sizeof(Type_Emplacement), MAX_TYPES, f);
    fclose(f);
}

// Sauvegarder les types dans le fichier
void sauvegarderTypes() {
    FILE *f = fopen(FICHIER, "wb");
    if (!f) return;
    fwrite(types, sizeof(Type_Emplacement), nb_types, f);
    fclose(f);
}

// Ajouter un type
void ajouterType() {
    if (nb_types >= MAX_TYPES) {
        printf("Erreur : tableau plein.\n");
        return;
    }
    Type_Emplacement t;
    printf("Entrez l'ID : ");
    scanf("%d", &t.id_type);
    printf("Libellé : ");
    scanf("%29s", t.libelle);
    printf("Prix : ");
    scanf("%f", &t.prix_jour_personne);

    types[nb_types++] = t;
    printf("Type ajouté.\n");
}

// Modifier un type
void modifierType() {
    int id;
    printf("Entrez l'ID du type à modifier : ");
    scanf("%d", &id);

    for (int i = 0; i < nb_types; i++) {
        if (types[i].id_type == id) {
            printf("Nouveau libellé : ");
            scanf("%29s", types[i].libelle);
            printf("Nouveau prix : ");
            scanf("%f", &types[i].prix_jour_personne);
            printf("Type modifié.\n");
            return;
        }
    }
    printf("Type introuvable.\n");
}

// Supprimer un type
void supprimerType() {
    int id;
    printf("Entrez l'ID du type à supprimer : ");
    scanf("%d", &id);

    for (int i = 0; i < nb_types; i++) {
        if (types[i].id_type == id) {
            for (int j = i; j < nb_types - 1; j++) {
                types[j] = types[j + 1];
            }
            nb_types--;
            printf("Type supprimé.\n");
            return;
        }
    }
    printf("Type introuvable.\n");
}

// Consulter un type
void consulterType(int id) {
    for (int i = 0; i < nb_types; i++) {
        if (types[i].id_type == id) {
            printf("ID: %d | Libellé: %s | Prix: %.2f\n",
                   types[i].id_type, types[i].libelle, types[i].prix_jour_personne);
            return;
        }
    }
    printf("Type introuvable.\n");
}

// Lister tous les types
void listerTypes() {
    printf("\nListe des types d'emplacements :\n");
    for (int i = 0; i < nb_types; i++) {
        printf("ID: %d | Libellé: %s | Prix: %.2f\n",
               types[i].id_type, types[i].libelle, types[i].prix_jour_personne);
    }
}
