#include <stdio.h>
#include <stdlib.h>  




int main(void) {
    int numbers[45];
    int previous_elem, next_elem;
// забиваем массив рандомными числами
    for (int i = 0; i <= (*(&numbers + 1) - numbers)-1; i++){
        numbers[i] = rand();
    }
// цикл проходящий все элементы массива
    for (int i = 0; i<= (*(&numbers + 1) - numbers)-1; i++){
        printf("Element number %d, %d \n", (i+1), numbers[i]);
        //проверка для первого элемента массива
        if(i == 0){
            if(numbers[i] > numbers[i+1]){
                printf(" Local max: %d \n", numbers[i]);
            }
        }
        //проверка для второго элемента массива
        if(i == (*(&numbers + 1) - numbers)-1){
            printf("Local max: %d \n", numbers[i]);
        }
        //проверка для остальных
        else {
            previous_elem = numbers[i-1];
            next_elem = numbers[i+1];
            if(numbers[i] > previous_elem && numbers[i] > next_elem) {
                printf("Local max: %d \n", numbers[i]);
            }
        }
    }

}
