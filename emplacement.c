#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emplacement.h"
#include "type_emplacement.h" // pour vérifier les types existants

#define FICHIER_EMPLACEMENT "emplacements.dat"

Emplacement emplacements[MAX_EMPLACEMENTS];
int nb_emplacement = 0;

// Charger les emplacements depuis le fichier
void chargerEmplacements() {
    FILE *f = fopen(FICHIER_EMPLACEMENT, "rb");
    if (!f) {
        nb_emplacement = 0;
        return;
    }
    nb_emplacement = fread(emplacements, sizeof(Emplacement), MAX_EMPLACEMENTS, f);
    fclose(f);
}

// Sauvegarder les emplacements dans le fichier
void sauvegarderEmplacements() {
    FILE *f = fopen(FICHIER_EMPLACEMENT, "wb");
    if (!f) return;
    fwrite(emplacements, sizeof(Emplacement), nb_emplacement, f);
    fclose(f);
}

// Ajouter un emplacement
void ajouterEmplacement() {
    if (nb_emplacement >= MAX_EMPLACEMENTS) {
        printf("Erreur : tableau plein.\n");
        return;
    }
    Emplacement e;
    printf("Entrez l'ID de l'emplacement : ");
    scanf("%d", &e.id_emplacement);
    printf("Nom : ");
    scanf("%29s", e.nom);
    printf("Capacité : ");
    scanf("%d", &e.capacite);
    printf("ID du type associé : ");
    scanf("%d", &e.id_type);

    // Vérifier que le type existe
    int existe = 0;
    for (int i = 0; i < nb_types; i++) {
        if (types[i].id_type == e.id_type) {
            existe = 1;
            break;
        }
    }
    if (!existe) {
        printf("Erreur : ce type n'existe pas.\n");
        return;
    }

    emplacements[nb_emplacement++] = e;
    printf("Emplacement ajouté.\n");
}

// Modifier un emplacement
void modifierEmplacement() {
    int id;
    printf("Entrez l'ID de l'emplacement à modifier : ");
    scanf("%d", &id);

    for (int i = 0; i < nb_emplacement; i++) {
        if (emplacements[i].id_emplacement == id) {
            printf("Nouveau nom : ");
            scanf("%29s", emplacements[i].nom);
            printf("Nouvelle capacité : ");
            scanf("%d", &emplacements[i].capacite);
            printf("Nouvel ID de type : ");
            scanf("%d", &emplacements[i].id_type);

            // Vérifier que le type existe
            int existe = 0;
            for (int j = 0; j < nb_types; j++) {
                if (types[j].id_type == emplacements[i].id_type) {
                    existe = 1;
                    break;
                }
            }
            if (!existe) {
                printf("Erreur : ce type n'existe pas.\n");
                return;
            }

            printf("Emplacement modifié.\n");
            return;
        }
    }
    printf("Emplacement introuvable.\n");
}

// Supprimer un emplacement
void supprimerEmplacement() {
    int id;
    printf("Entrez l'ID de l'emplacement à supprimer : ");
    scanf("%d", &id);

    for (int i = 0; i < nb_emplacement; i++) {
        if (emplacements[i].id_emplacement == id) {
            for (int j = i; j < nb_emplacement - 1; j++) {
                emplacements[j] = emplacements[j + 1];
            }
            nb_emplacement--;
            printf("Emplacement supprimé.\n");
            return;
        }
    }
    printf("Emplacement introuvable.\n");
}

// Consulter un emplacement
void consulterEmplacement(int id) {
    for (int i = 0; i < nb_emplacement; i++) {
        if (emplacements[i].id_emplacement == id) {
            printf("ID: %d | Nom: %s | Capacité: %d | Type associé: %d\n",
                   emplacements[i].id_emplacement,
                   emplacements[i].nom,
                   emplacements[i].capacite,
                   emplacements[i].id_type);
            return;
        }
    }
    printf("Emplacement introuvable.\n");
}

// Lister tous les emplacements
void listerEmplacements() {
    printf("\nListe des emplacements :\n");
    for (int i = 0; i < nb_emplacement; i++) {
        printf("ID: %d | Nom: %s | Capacité: %d | Type associé: %d\n",
               emplacements[i].id_emplacement,
               emplacements[i].nom,
               emplacements[i].capacite,
               emplacements[i].id_type);
    }
}
