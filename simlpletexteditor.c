#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1000
char buffer[MAX_LINES][MAX_LINE_LENGTH];
int line_count =0;
void load_file(const char *filename){
    FILE *file =fopen(filename, "r");
    if(file ==NULL){
        perror("Error opening file");
        return;
    }
    line_count =0;
    while (fgets(buffer[line_count],MAX_LINE_LENGTH, file)){
        line_count++;
        
    }
    fclose(file);
    
}
void save_file(const char *filename){
    FILE *file = fopen(filename,"w");
    if(file ==NULL){
        perror("Error opening file");
        return;
    }
    for(int i =0; i<line_count; i++){
        fprintf(file,"%s",buffer[i]);
    }
    fclose(file);

}
void print_buffer(){
    for (int i=0;i<line_count;i++){
        printf("%s", buffer[i]);
    }
}
int main(int argc,char *argv[]){
    if(argc !=2){
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    load_file(argv[1]);
    print_buffer();
    printf("\nEditing functionality not implemented yet.\n");
    save_file(argv[1]);
    return 0;
}

