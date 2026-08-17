#include <iostream>
#include <cmath>
#include <string>

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
    int get_parent_index(int child_index){
        return (child_index - 1) / 2;
    }
    
    int getLevel(int index) {
        return (int)std::log2(index + 1);
    }
    
    void print_pira(int* arr, int size){
        std::cout << "Пирамида: ";
        std::cout << "0 root " << from_index(arr, 0) << std::endl;
        
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

    void print_point(int* arr, int point){

        if(point == 0){
            std::cout << "Вы находитесь здесь: 0 root "
                      << arr[point] << std::endl;
        }
        else {
            int parent = get_parent_index(point);

            if(point % 2 == 1){
                std::cout << "Вы находитесь здесь: "
                          << getLevel(point)
                          << " left(" << arr[parent] << ") "
                          << arr[point] << std::endl;
            }
            else{
                std::cout << "Вы находитесь здесь: "
                          << getLevel(point)
                          << " right(" << arr[parent] << ") "
                          << arr[point] << std::endl;
            }
        }
    }

    int tree_climbing(int* arr, int size, int point, std::string dir){
        int tmp_point = point;

        if(dir == "left"){
            point = l_child_index(point);
            if(point >= size){
                std::cout << "Ошибка. Бесплодие" << std::endl;
                return tmp_point;
            }
            std::cout << "ОК" << std::endl;
            return point;
        }

        else if(dir == "right"){

            point = r_child_index(point);

            if(point >= size){
                std::cout << "Ошибка. Бесплодие" << std::endl;
                return tmp_point;
            }
            std::cout << "ОК" << std::endl;

            return point;
        }

        else if(dir == "up"){

            if(point == 0){
                std::cout << "Ошибка! Отсутствует родитель" << std::endl;
                return point;
            }

            point = get_parent_index(point);

            std::cout << "ОК" << std::endl;

            return point;
        }
        return point;
    }
};

   
           



int main (){
std::string user_input;
    int size = 6;
    int* arr = new int[size] {1, 3, 6, 5, 9, 8};
    int point = 0;
    piramid p;
    p.print_orig_arr(arr, size);
    p.print_pira(arr, size);

    for(;;){
        p.print_point(arr, point);

        std::cout << "Введите команду: ";
        std::cin >> user_input;

        if(user_input == "exit"){
            break;
        }

        else if(user_input == "up" ||
                user_input == "right" ||
                user_input == "left"){

            point = p.tree_climbing(arr, size, point, user_input);
        }
        else{
            std::cout<< "Ошибка. Такой команды не существует" << std::endl;
        }
        
    }
    delete[] arr;

}