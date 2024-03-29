#include<stdio.h>
#include<stdlib.h>
#include <sys/stat.h>
bool existFile(char*path);
void createDefaultInputFile(FILE *file, char *path,const int size);
int enter(int **array);
int import(FILE *file,char *path,int **array);
int findMax(const int *array, const int size);
void print(int *array, int size);
void exportInputValue(FILE *file, char *path,const int *array, const int size);
void exportMaxValue(FILE *file, char *path,const int *array, const int size);
int main(){
    int *array,size = 0;
    FILE *file;
    char* input_path = "./data/numbers/data.in";
    char* max_path = "./data/numbers/max.out";
    size = enter(&array);
    exportInputValue(file,input_path,array,size);
    print(array,size);
    exportMaxValue(file,max_path,array,size);
    return 0;
}
bool existFile(char*path){
    struct stat buffer;
    return !stat(path, &buffer);
}
void createDefaultInputFile(FILE *file, char *path,const int size){
    const char* mode = "w";
    if(!existFile(path)){// nếu chưa tồn tại file thì mới tạo mới file
        file = fopen(path,mode);
        fprintf(file,"%d\n",size);
        fclose(file);
    }
}
int enter(int **array){
    int size = 0;
    int temp;
    printf("size: ");
    scanf("%d",&size);
    *array = (int*)malloc(size*sizeof(int));// cap phat bo nho dong
    printf("data: \n");
    for(int index = 0;index<size;index++){
        printf("array[%d]: ",index);
        scanf("%d",&temp);
        *(*array+index) = temp; 
    }
    return size;
}
int import(FILE *file,char *path,int **array){
    int size = 0;
    int temp;
    const char* mode = "r";//read: chế độ đọc file
    file = fopen(path,mode);
    if(file == NULL){// không có file thì tạo mới file
        createDefaultInputFile(file,path,size);
    }
    else{
        fscanf(file,"%d",&size);
        *array = (int*)malloc(size*sizeof(int));// cap phat bo nho dong
        for(int index = 0;index<size;index++){
            fscanf(file,"%d",&temp);
            *(*array+index) = temp; 
        }
    }
    fclose(file);
    return size;
}
int findMax(const int *array, const int size){
    int max = *array;
    for(int index = 1; index <size;index++){
        if(*(array+index)>max){
            max = *(array+index);
        }
    }
    return max;
}
void exportInputValue(FILE *file, char *path,const int *array, const int size){
    const char* mode = "w";
    file = fopen(path,mode);
    fprintf(file,"%d\n",size);
    for(int index=0; index<size; index++){
        fprintf(file,"%d ",*(array+index));
    }
    fclose(file);
}
void exportMaxValue(FILE *file, char *path,const int *array, const int size){
    const char* mode = "a";// append: chèn vào sau file
    const int max = findMax(array,size);
    file = fopen(path,mode);
    fprintf(file,"size: %d\n",size);
    fprintf(file,"data:",size);
    for(int index=0; index<size; index++){
        fprintf(file,"%d ",*(array+index));
    }
    fprintf(file,"\nmax = %d \n",max);
    fprintf(file,"------------------------------------\n");
    fclose(file);
}
void print(int *array, int size){
    printf("\narray:");
    for(int index=0;index<size;index++){
        printf("%d ",*(array+index));
        // printf("%d ",array[index]);// có thể thay thế bằng
    }
}