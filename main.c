#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX_SIZE 10
typedef unsigned int uint_32;

void Execute_Bubble_Sort (uint_32 Data[], uint_32 Data_Length);
void Swap_Two_Elements (uint_32 *num1, uint_32 *num2);
void Print_Array_Elements (uint_32 Data[], uint_32 Data_Length);

int main()
{
    uint_32 Arr[ARRAY_MAX_SIZE] = {8, 1, 9, 5, 0, 7, 3, 2, 4, 6};
    Print_Array_Elements(Arr, ARRAY_MAX_SIZE);
    Execute_Bubble_Sort(Arr, ARRAY_MAX_SIZE);
    Print_Array_Elements(Arr, ARRAY_MAX_SIZE);
    return 0;
}

void Execute_Bubble_Sort (uint_32 Data[], uint_32 Data_Length)
{
    uint_32 Bubble_Iteration = 0;
    uint_32 Adjacent_Iteration = 0;
    uint_32 Sorted_Flag = 0;

    for(Bubble_Iteration = 0 ; Bubble_Iteration < Data_Length - 1 ; Bubble_Iteration++)
    {
        for (Adjacent_Iteration = 0; Adjacent_Iteration < Data_Length - 1 - Bubble_Iteration; Adjacent_Iteration++)
        {
            if (Data[Adjacent_Iteration] > Data[Adjacent_Iteration+1])
            {
                Swap_Two_Elements(&(Data[Adjacent_Iteration]), &(Data[Adjacent_Iteration+1]));
                Sorted_Flag = 1;
            }
            else{/* Nothing */}
        }
        /* In case of Sorted Array The Function will terminate from the first Bubble_Iteration*/
        if (0 == Sorted_Flag)
        {
            return;
        }
        else{/* Nothing */}
        
    }
}

void Swap_Two_Elements (uint_32 *num1, uint_32 *num2)
{
    uint_32 Temp = *num2;
    *num2 = *num1;
    *num1 = Temp;
}

void Print_Array_Elements (uint_32 Data[], uint_32 Data_Length)
{
    uint_32 Iterator = 0;
    for (Iterator = 0; Iterator < Data_Length; Iterator++)
    {
        printf("%i \t", Data[Iterator]);
    }
    printf("\n");
}