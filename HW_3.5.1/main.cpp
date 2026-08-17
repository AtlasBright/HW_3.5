#include <iostream>
#include <cmath>

struct piramid {
    int root(int* arr){
        return arr[0];
    };

    int from_index (int* arr, int index){
        return arr[index];
    }
    
    int l_child_index(int parent_index){
        return 2 * parent_index + 1;
    }
    
    int r_child_index(int parent_index){
        return 2 * parent_index + 2;
    }
    
    int getLevel(int index) {
        return (int)std::log2(index + 1);
    }
    
    void print_pira(int* arr, int size){
        std::cout << "Пирамида: ";
        std::cout << "0 root " << piramid::from_index(arr, 0) << std::endl;
        
        for(int i = 0; i < size; i++){
            int l_ind = l_child_index(i);
            int r_ind = r_child_index(i);
            bool hasLeft = l_ind < size;
            bool hasRight = r_ind < size;
            
            if(!hasLeft && !hasRight) {
                continue;
            }
            
            int level = getLevel(i)+1;
            
            if(hasLeft){
                std::cout << level << " left(" << arr[i] << ") " 
                          << from_index(arr, l_ind) << std::endl;
            }
            if(hasRight){
                std::cout << level << " right(" << arr[i] << ") " 
                          << from_index(arr, r_ind) << std::endl;
            }
        }
        std::cout << std::endl;
    }    

    void print_orig_arr(int* arr, int size){
        std::cout << "Исходный массив: " << std::endl;
        for(int i=0; i < size; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main (){
    int size = 6;
    int* arr = new int[size] {1, 3, 6, 5, 9, 8};
    piramid p;
    p.print_orig_arr(arr,size);
    p.print_pira(arr, size);
    delete[] arr;
    
    int size2 = 8;
    int* arr2 = new int[size2] {94, 67, 18, 44, 55, 12, 6, 42};
    p.print_orig_arr(arr2,size2);
    p.print_pira(arr2, size2);
    delete[] arr2;

    int size3 = 10;
    int* arr3 = new int[size3] {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    p.print_orig_arr(arr3,size3);
    p.print_pira(arr3, size3);
    delete[] arr3;


}