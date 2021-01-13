#include<stdio.h>
void import(FILE *file, char *path, int &first, int &second);
void exportMaxValue(FILE *file, char *path,const int first,const int second);
void exportCaculatorResult(FILE *file, char *path,const int first,const int second);
void enter(int *first, int *second);// su dung con tro de nhap
void enter(int &first, int &second);
void swap(int *first, int *second);
void swap(int &first, int &second);// hoán vị sử dụng truyền vào tham chiếu
int add(const int first, const int second);
int sub(const int first, const int second);
double mul(const int first, const int second);
float div(const int first, const int second);
int findMax(const int first, const int second);
void print(const int first,const int second);// su dung tham tri de xuat, trong khi xuất thì first và second không thay đổi giá trị nên sử dụng thêm từ khóa const trước
int main(){
    FILE *file;
    char* input_path = "./data/data.in";
    char* max_path = "./data/max.out";
    char* caculator_path = "./data/caculator.out";
    int first, second;
    import(file,input_path,first,second);
    exportMaxValue(file,max_path,first,second);
    exportCaculatorResult(file,caculator_path,first,second);
    // enter(&first, &second);// gọi hàm truyền vào con trỏ
    // enter(first,second);// gọi hàm truyền vào tham chiếu
    // print(first,second);
    // swap(&first, &second);
    // printf("\nafter swap: ");
    // print(first,second);
    // printf("\nnumber add:%d",add(first,second));

    return 0;
}
void import(FILE *file,char *path, int &first, int &second){
    const char* mode = "r";
    file = fopen(path,"r");
    if(file == NULL){
        printf("không thể mở file!");
    }
    else{
        fscanf(file,"%d",&first);
        fscanf(file,"%d",&second);
    }
    fclose(file);
}
void enter(int *first, int *second){// con tro chua dia chi
    printf("enter first number: ");
    scanf("%d",first);// scanf truyen vao 1 dia chi
    printf("enter second number:");
    scanf("%d",second);
}
void enter(int &first, int &second){// truyền vào tham chiếu
    printf("enter first number: ");
    scanf("%d",&first);// scanf truyen vao 1 dia chi, &first: lập địa chỉ của first
    printf("enter second number:");
    scanf("%d",&second);
}
void swap(int *first, int *second){
    int temp = *first;// *first: lấy giá trị của con trỏ first
    *first = *second;
    *second = temp;
}
void swap(int &first, int &second){
     int temp = first;
    first = second;
    second = temp;
}
int add(const int first, const int second){
    return first + second;
}
int sub(const int first, const int second){
    return first - second;
}
double mul(const int first, const int second){
    return first*second;
}
float div(const int first, const int second){
    return (float)first/second;
}
int findMax(const int first, const int second){
    return (first>second)?first:second;
}
void print(const int first,const int second){
    printf("\n{first number:%d, second number: %d}",first,second);
}
void exportMaxValue(FILE *file, char *path,const int first,const int second){
    const char* mode = "w";
    const int max = findMax(first,second);
    file = fopen(path,mode);
    if(file == NULL){
        printf("file không mở được!");
    }
    else{
        fprintf(file,"first: %d, second:%d\n",first,second);
        fprintf(file,"max = %d ",max);
        fclose(file);
    }
    
}
void exportCaculatorResult(FILE *file, char *path,const int first,const int second){
    const char* mode = "w";
    file = fopen(path,mode);
    if(file == NULL){
        printf("file không mở được!");
    }
    else{
        int summary = add(first,second);
        int different = sub(first,second);
        double product = mul(first,second);
        float quotient = div(first,second);
        fprintf(file,"first: %d, second:%d\n",first,second);
        fprintf(file,"summary: %d, different:%d, product:%.0f, quotient: %.2f",summary,different,product,quotient);
        fclose(file);
    }
    
}