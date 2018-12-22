void init_bdd(FILE * f, int *n, Film *film){
    char l[255];
    char *o;
    
    int i=0;
    fseek(f,0,SEEK_SET);
    printf("NB ligne : %d", *n);
    while(fgets(l, 255, f)){
         
        (film+i)->id = atoi(strtok(l,";"));

        printf(" ID : %d\n", film[i].id);

        printf("%s",strtok(NULL,";"));
        
        (film+i)->annee = atoi(strtok(NULL,";"));

        printf("\nAnnee : %d", film[i].annee);

        printf("\n----------\n");
        i++;
    }
}