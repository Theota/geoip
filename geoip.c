#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAXCHAR 1024

/* theo tardy*/

void suppr_quot();

int main(int argc, char *argv[])
{
    long ip0=0;
    long ip1=0;
    long ip2=0;
    long ip3=0;
    long ip=0;
    int i=1; 
    int j=0;
    long ip_from=0;
    long ip_to=0;
    char output1[99]={0};
    char output2[99]={0};
    char output3[99]={0};

    FILE *pfichier;
    char line[MAXCHAR];
    char *output;

    //gestion erreur argument ligne de commande
    if (argc==2)
    {
        sscanf(argv[1], "%ld.%ld.%ld.%ld",&ip0,&ip1,&ip2,&ip3);

        ip=ip0*256*256*256 + ip1*256*256 + ip2*256 + ip3;

        pfichier = fopen("geoip.csv","r");

        while (feof(pfichier) != true)
        {   
            fgets(line, MAXCHAR, pfichier);
            //printf("line: %s", line);
            output = strtok(line, ",");

            i=1;

            //  i<4 car analyse que les 3 premieres cellules de chaque ligne
            while ((output != NULL)&&(i<4))
            {
                j=1;
                //printf("output: %s\n", output);
                switch (i)
                {
                    case 1:
                        strcpy(output1, output);
                        i++;
                        break;
                    case 2:
                        strcpy(output2, output);
                        i++;
                        break;
                    case 3:
                        strcpy(output3, output);
                        i++;
                        break;   
                    default: ;
                        break;
                }
                output = strtok(NULL, ",");
            }

            suppr_quot(output1);
            suppr_quot(output2);
            suppr_quot(output3);

            // convertir string en int
            ip_from=atoi(output1);
            ip_to=atoi(output2);

            // verifier si notre ip est dans la range d'ip de la ligne qu'on analyse
            if ((ip>=ip_from)&&(ip<=ip_to))
            {
                printf("Le pays est : %s\n",output3);
                return 0;
            } 
        }   
    } else 
    {
        printf("Usage:\n");
        printf("\t%s <adresse_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    fclose(pfichier);  
    return 0;
}

// fonction pour supprimer les quotations mark
void  suppr_quot(char output[99])
{
    char output_temp[99]={0};
    int j=1;

    memset(output_temp, ' ',99);
    while (output[j]!=('"'))
    {
        output_temp[j-1]=output[j];
        j++;
    }
    memset(output, ' ',99);
    strcpy(output,output_temp);
}