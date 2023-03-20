#include <stdio.h>
#include <stdlib.h>

int main() {
    while (1 == 1) {
        system("cls");
        printf("-= <MENIU> =-\n");
        printf("1. Vizualizeaza rapoarte\n");
        printf("2. Adauga raport\n");
        printf("3. Filtrare rapoarte dupa incident\n");
        printf("4. Filtrare rapoarte dupa strada\n");

        int choice;
        do {
            printf("Introdu varianta dorita: ");
            scanf("%d", &choice);
        } while (choice < 1 || choice > 5);

        system("cls");

        if (choice == 1) {
            printf("-= VIZUALIZARE RAPOARTE =-\n");
            printf("Strada Amaradia - Canalizare defecta\n");
            printf("Strada Petre Ispirescu - Copac cazut\n");
            system("pause");
        } else if (choice == 2) {
            char raport[20];
            printf("Adaugare raport: \n");
            scanf("%s", &raport);
            printf("Raportul a fost adaugat cu succes.\n");
            system("pause");

        }

         else if (choice == 3){
            char raport;
            printf("Tipul incidentului:");
            scanf("%c\n",raport);
            system("pause");
         }
         else if(choice == 4){
            char strada;
            printf("Numele strazii:");
            scanf("%c\n",strada);
            system("pause");
         }

    }
    return 0;
}
