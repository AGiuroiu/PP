#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // structura necesara pentru salvarea incidentelor
    // un incident i va fi format din orasIncidente[i], strazi[i],incidente[i]
    int orasIncidente[100];
    char *strazi[100];
    int incidente[100];
    int count = 0;

    // Lista de orase a aplicatiei
    char *orase[3];
    int nrOrase = 3;
    orase[0] = "Timisoara";
    orase[1] = "Bucuresti";
    orase[2] = "Craiova";

    // lista de tipuri de incidente
    char *tipIncident[3];
    int nrIncidente = 3;
    tipIncident[0] = "Gaura in asfalt";
    tipIncident[1] = "Bec Defect";
    tipIncident[2] = "Cablu cazut pe carosabil";

    // date de test
    // aici o sa facem citirea evenimentelor existente in fisier
    FILE *file = fopen("incidente.txt", "r");

    char *currentline;

    currentline = (char *)malloc(50 * sizeof(char));
    size_t len = 0;
    int indiceLinie = 0;
    while (fgets(currentline, 50, file) != NULL)
    {

        if (indiceLinie % 3 == 0)
        {
            orasIncidente[indiceLinie / 3] = atoi(currentline);
        }
        if (indiceLinie % 3 == 1)
        {
            strazi[indiceLinie / 3] = currentline;
        }
        if (indiceLinie % 3 == 2)
        {
            incidente[indiceLinie / 3] = atoi(currentline);
        }
        indiceLinie++;
        currentline = (char *)malloc(50 * sizeof(char));
    }
    count = indiceLinie - 1 / 3;

    fclose(file);

    /*
    orasIncidente[0] = 0;
    strazi[0] = "Atomului";
    incidente[0] = 0;
    count = 1;*/

    while (1 == 1)
    {
        system("cls");
        printf("-= <MENIU> =-\n");
        printf("1. Vizualizeaza rapoarte\n");
        printf("2. Adauga raport\n");
        printf("3. Filtrare rapoarte dupa incident\n");
        printf("4. Filtrare rapoarte dupa strada\n");

        int choice;
        do
        {
            printf("Introdu varianta dorita: ");
            scanf("%d", &choice);
        } while (choice < 1 || choice > 5);

        system("cls");

        if (choice == 1)
        {
            printf("-= VIZUALIZARE RAPOARTE =-\n");
            for (int i = 0; i < count; i++)
            {
                char index[10];
                sprintf(index, "%d", i + 1);
                char
                    descIncident[1000] = "";
                strcat(descIncident, index);
                strcat(descIncident, "-");
                strcat(descIncident, orase[orasIncidente[i]]);
                strcat(descIncident, ",");
                strcat(descIncident,
                       strazi[i]);
                strcat(descIncident, ",");
                strcat(descIncident, tipIncident[incidente[i]]);
                printf("%s\n", descIncident);
            }
            system("pause");
        }
        else if (choice == 2)
        {
            int _orasIncident;

           // Citire oras
            printf("Adaugare incident:[1/3] - Selectare oras \n");
            for (int i = 0; i < nrOrase;
                 i++)
            {
                printf("%d - %s \n", i + 1, orase[i]);
            }
            do
            {
                printf("Introdu varianta dorita: ");
                scanf(" %d", &_orasIncident);
            } while (_orasIncident < 1 || _orasIncident > nrOrase + 1);
            // citire strada

            printf("Adaugare incident:[2/3] - Strada: ");

            char temp;
            scanf("%c", &temp); // temp statement to clear buffer
            char *zona;
            zona = (char *)malloc(1000 * sizeof(char));
            scanf("%[^\n]", zona);
            // citire tip incident
            printf("Adaugare incident:[3/3] - Selectare Tip incident \n");
            int incident;
            for (int i = 0; i < nrIncidente; i++)
            {
                printf("%d - %s \n", i + 1, tipIncident[i]);
            }
            do
            {
                printf("Introdu varianta dorita: ");
                scanf(" %d", &incident);
                int choice2;
                switch (choice2)
                {
                case 0:
                    break;
                case 1:
                {
                    orasIncidente[count];
                    count++;
                    FILE *pFile2 = fopen("incidente.txt", "a");
                    fprintf(pFile2, "Timisoara\n");
                    fclose(pFile2);
                    break;
                }
                case 2:
                {
                    strazi[count];
                    count++;
                    FILE *pFile2 = fopen("incidente.txt", "a");
                    fprintf(pFile2, "Alecsandri\n");
                    fclose(pFile2);
                    break;
                }
                case 3:
                {
                    incidente[count];
                    count++;
                    FILE *pFile2 = fopen("incidente.txt", "a");
                    fprintf(pFile2, "bec defect\n" );
                    fclose(pFile2);
                    break;
                }
                }
            } while (incident < 1 || incident > nrIncidente + 1);

            printf("Raportul a fost adaugat cu succes.\n");

            orasIncidente[count] = _orasIncident - 1;
            strazi[count] = zona;
            incidente[count] = incident - 1;
            count++;
            system("pause");
        }

        else if (choice == 3)
        {
            char raport[100];
            printf("Tipul incidentului:");
            scanf("%s", raport);
            system("pause");
        }
        else if (choice == 4)
        {
            char strada[100];
            printf("Numele strazii:");
            scanf("%s", strada);
            system("pause");
        }
        choice = -1;
    }
    return 0;
}
