
#include <stdio.h>
#include<stdlib.h>

struct myArray{
    int total_size;
    int used_size;
    int *ptr;
};

//allocate allocates memory for array in heap 
void allocate(struct myArray *a,int total, int use){
    a->total_size = total;
    a->used_size = use;
    a->ptr = (int *)malloc(total*sizeof(int));
}

//setValue sets the value of an array
void setValue(struct myArray *a){
    int n;
    for(int i=0;i<a->used_size;i++){
        printf("Enter %d element ",i+1);
        scanf("%d",&n);
        (a->ptr)[i] = n;
    }
}

//getValue prints the array
void getValue(struct myArray *a){
    printf("We are showing values now \n");
    int n;
    for(int i=0;i<a->used_size;i++){
        printf("%d \n",(a->ptr)[i]); // (a->ptr)[i] same as *ptr[i] used to access element of dynamic array in heap
        
    }
}


//insert basically shifts current index value to the last and then replaces it with new inserted value
void insert(struct myArray *a, int index,int value){
    printf("Value is inserted \n");
    (a->ptr)[a->used_size] = (a->ptr)[index];
    (a->ptr)[index] =  value; 
    a->used_size++;
    }


int main() {
struct myArray marks;
allocate(&marks,10,2);  //allocating memory to array
setValue(&marks);   //setting value to array
insert(&marks,0,30); //inserting 30 at 0th index
getValue(&marks);   //printing array
}