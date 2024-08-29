#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX_SIZE 5
typedef unsigned int uint_32;

void Execute_Bubble_Sort (uint_32 Data[], uint_32 Data_Length);
void Swap_Two_Elements (uint_32 *num1, uint_32 *num2);
void Print_Array_Elements (uint_32 Data[], uint_32 Data_Length);
int main()
{
    uint_32 Arr[ARRAY_MAX_SIZE] = {5, 3, 8, 4, 6};
    Print_Array_Elements(Arr, ARRAY_MAX_SIZE);
    Execute_Bubble_Sort(Arr, ARRAY_MAX_SIZE);
    Print_Array_Elements(Arr, ARRAY_MAX_SIZE);
    return 0;
}

void Execute_Bubble_Sort (uint_32 Data[], uint_32 Data_Length)
{
    uint_32 Bubble_Iteration = 0;
    uint_32 Adjacent_Iteration = 0;

    for(Bubble_Iteration = 0 ; Bubble_Iteration < Data_Length - 1 ; Bubble_Iteration++)
    {
        for (Adjacent_Iteration = 0; Adjacent_Iteration < Data_Length - 1 - Bubble_Iteration; Adjacent_Iteration++)
        {
            if (Data[Adjacent_Iteration] > Data[Adjacent_Iteration+1])
            {
                Swap_Two_Elements(&(Data[Adjacent_Iteration]), &(Data[Adjacent_Iteration+1]));
            }
            else{/* Nothing */}
        }
        
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