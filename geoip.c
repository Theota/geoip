#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAXCHAR 1024

/* theo tardy*/
/* utiliser fseek pour les guillemets, ou copier caractere par caractere ds autre tableau sans prendre les guillemets */

int main(int argc, char *argv[])
{
    long ip0=0;
    long ip1=0;
    long ip2=0;
    long ip3=0;
    long ip=0;
    int i=1; 
    char output1[99]={0};
    char output2[99]={0};
    char output3[99]={0};

    FILE *pfichier;
    char line[MAXCHAR];
    char *output;

    sscanf(argv[1], "%ld.%ld.%ld.%ld",&ip0,&ip1,&ip2,&ip3);

    ip=ip0*256*256*256 + ip1*256*256 + ip2*256 + ip3;
    printf("%ld\n",ip);

    pfichier = fopen("geoip.csv","r");


    while (feof(pfichier) != true)
    {   
        fgets(line, MAXCHAR, pfichier);
        printf("line: %s", line);
        output = strtok(line, ",");

        i=1;

        while ((output != NULL)&&(i<4))
        {
            printf("output: %s\n", output);

            
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

            /*
            if (i==1)
            {
                strcpy(output1, output);
                printf("output numero 1 :%s\n",output);
            }
            if (i==2)
            {
                strcpy(output2, output);
                printf("output numero 2 :%s\n",output2);
            }
            if (i==3)
            {
                strcpy(output3, output);
                printf("output numero 3 :%s\n",output3);
            }
            i++;*/
            output = strtok(NULL, ",");

        }
        
        printf("output numero 1 :%s\n",output1);
        printf("output numero 2 :%s\n",output2);
        printf("output numero 3 :%s\n",output3);
        
    }    






    return 0;
}