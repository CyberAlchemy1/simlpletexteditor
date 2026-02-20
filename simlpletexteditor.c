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
        perror("Error opening files");
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
void insert_text(){
    printf("Enter text (end with an empty line): \n");
    char input[MAX_LINE_LENGTH];
    while (fgets(input,MAX_LINE_LENGTH,stdin)){
        if (input[0]=='\n'){
            break;
        }
        strcpy(buffer[line_count],input);
        line_count++;
    }
}
int main(int argc,char *argv[]){
    if(argc !=2){
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    load_file(argv[1]);
    print_buffer();
    insert_text();
    save_file(argv[1]);
    return 0;
}

