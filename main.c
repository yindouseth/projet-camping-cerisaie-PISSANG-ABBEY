#include <stdio.h>
#include "type_emplacement.h"
#include "emplacement.h"

int main() {
    int choix_general;

    // Charger les données au démarrage
    chargerTypes();
    chargerEmplacements();

    do {
    // menu generale de la gestion des emplacements
        printf("\n--- Menu Général Gestion Camping ---\n");
        printf("1. Gestion des Types d’Emplacements\n");
        printf("2. Gestion des Emplacements\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix_general);

        switch (choix_general) {
            case 1: {
                int choix_type;
                do {
                // menu pour la gestion de la section type emplacement
                    printf("\n--- Menu Gestion Types ---\n");
                    printf("1. Ajouter un type\n");
                    printf("2. Modifier un type\n");
                    printf("3. Supprimer un type\n");
                    printf("4. Consulter un type\n");
                    printf("5. Lister tous les types\n");
                    printf("0. Retour\n");
                    printf("Votre choix : ");
                    scanf("%d", &choix_type);

                    // gestion des choix de l'utilisateur
                    switch (choix_type) {
                        case 1: ajouterType(); break;
                        case 2: modifierType(); break;
                        case 3: supprimerType(); break;
                        case 4: {
                            int id;
                            printf("Entrez l'ID : ");
                            scanf("%d", &id);
                            consulterType(id);
                            break;
                        }
                        case 5: listerTypes(); break;
                    }
                } while (choix_type != 0);
                break;
            }

            case 2: {
                int choix_empl;
                do {
                // menu de la gestion de la section emplacement
                    printf("\n--- Menu Gestion Emplacements ---\n");
                    printf("1. Ajouter un emplacement\n");
                    printf("2. Modifier un emplacement\n");
                    printf("3. Supprimer un emplacement\n");
                    printf("4. Consulter un emplacement\n");
                    printf("5. Lister tous les emplacements\n");
                    printf("0. Retour\n");
                    printf("Votre choix : ");
                    scanf("%d", &choix_empl);

                    // gestion des choix de l'utilisateur
                    switch (choix_empl) {
                        case 1: ajouterEmplacement(); break;
                        case 2: modifierEmplacement(); break;
                        case 3: supprimerEmplacement(); break;
                        case 4: {
                            int id;
                            printf("Entrez l'ID : ");
                            scanf("%d", &id);
                            consulterEmplacement(id);
                            break;
                        }
                        case 5: listerEmplacements(); break;
                    }
                } while (choix_empl != 0);
                break;
            }

            case 0:
                sauvegarderTypes(); // sauvegarde des types
                sauvegarderEmplacements(); // sauvegarde des emplacements creer
                printf("Données sauvegardées. Au revoir !\n");
                break;

            default:
                printf("Choix invalide.\n");
        }
    } while (choix_general != 0);

    return 0;
}
