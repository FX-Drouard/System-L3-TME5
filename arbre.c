#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char*argv[]) {
    int l = atoi(argv[1]);
    printf("%d\n",l);
    if (l > 0) {
        char str_cpt[2];
        sprintf(str_cpt, "%d", l-1);
        fork();
        execl("/users/Etu7/28705217/Documents/kursoj/2/sis/6/p/src/tme5/arbre", "arbre", str_cpt, 0);
    }
    // int i = 0;
    // int j = 0;
    // while (i < l && j < 1) {
    //     pid_t p;
    //     if ((p = fork()) == 0) {
    //         fork();
    //         j++;
    //     }
    //     i++;
    // }
    sleep(30);
    return 0;
}