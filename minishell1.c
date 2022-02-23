#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_LIMIT 256
int clafin(char*saisie){
    return saisie[0] == 'q' && saisie[1] == 'u' && saisie[2] == 'i' && saisie[3] == 't';
}
int dernierCaractereSaisiEstEsperluette(char*saisie) {
 return saisie[strlen(saisie) - 1] == '&';
}
int main()
{
   char saisie[MAX_LIMIT];
   while (!clafin(saisie)) {
   printf("écrivez la commande :\n");
   fgets(saisie, MAX_LIMIT, stdin);
   pid_t p = fork();
   if (p == 0) {
       printf("noooooooon!");
       size_t lenNomProcDir = strlen("/bin/");
       size_t lenSaisie = strlen(saisie);
       char * dst = (char*)malloc((lenNomProcDir+lenSaisie)*sizeof(char));
       dst[0] = '/';
       dst[1] = 'b';
       dst[2] = 'i';
       dst[3] = 'n';
       dst[4] = '/';
       strcat(dst,saisie);
       printf(dst);
       p = fork();
       if (p == 0) execl(dst,saisie,0);
   } else {
       printf("je suis ton pere\n");
       if (dernierCaractereSaisiEstEsperluette(saisie)) wait(&p);
   }
   }
   return 0;
}