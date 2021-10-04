#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAXCHAR 1024

/* theo tardy*/

int main(int argc, char *argv[])
{
    long ip0=0;
    long ip1=0;
    long ip2=0;
    long ip3=0;
    long ip=0;
    int i=1; 
    int j=0;
    char output1[99]={0};
    char output2[99]={0};
    char output3[99]={0};
    char output_temp[99]={0};

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
            j=1;
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
            output = strtok(NULL, ",");

        }
        
        // suppression des guillemets, passer tout ca en fonction apres
        memset(output_temp, ' ',99);
        j=1;
        while (output1[j]!='"')
        {
            output_temp[j-1]=output1[j];
            j++;
        }
        memset(output1, ' ',99);
        strcpy(output1, output_temp);

        memset(output_temp, ' ',99);
        j=1;
        while (output2[j]!='"')
        {
            output_temp[j-1]=output2[j];
            j++;
        }
        memset(output2, ' ',99);
        strcpy(output2, output_temp);

        memset(output_temp, ' ',99);
        j=1;
        while (output3[j]!='"')
        {
            output_temp[j-1]=output3[j];
            j++;
        }
        memset(output3, ' ',99);
        strcpy(output3, output_temp);

        printf("output numero 1 :%s\n",output1);
        printf("output numero 2 :%s\n",output2);
        printf("output numero 3 :%s\n",output3);

        
    }    






    return 0;
}