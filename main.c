#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX_SIZE 10
typedef unsigned int uint_32;
typedef signed int sint_32;

void Execute_Bubble_Sort (uint_32 Data[], uint_32 Data_Length);
void Execute_Insertion_Sort (uint_32 Data[], uint_32 Data_Length);
void Execute_Selection_Sort (uint_32 Data[], uint_32 Data_Length);
void Swap_Two_Elements (uint_32 *num1, uint_32 *num2);
void Print_Array_Elements (uint_32 Data[], uint_32 Data_Length);

int main()
{
    uint_32 Arr[ARRAY_MAX_SIZE] =  {8, 1, 9, 5, 0, 7, 3, 2, 4, 6};
    uint_32 Arr2[ARRAY_MAX_SIZE] = {8, 1, 9, 5, 0, 7, 3, 2, 4, 6};
    uint_32 Arr3[6] = {3, 6, 1, 8, 4, 5};

    Print_Array_Elements(Arr, ARRAY_MAX_SIZE);
    Execute_Bubble_Sort(Arr, ARRAY_MAX_SIZE);
    Print_Array_Elements(Arr, ARRAY_MAX_SIZE);

    Print_Array_Elements(Arr2, ARRAY_MAX_SIZE);
    Execute_Insertion_Sort(Arr2, ARRAY_MAX_SIZE);
    Print_Array_Elements(Arr2, ARRAY_MAX_SIZE);

    Print_Array_Elements(Arr3, 6);
    Execute_Selection_Sort(Arr3, 6);
    Print_Array_Elements(Arr3, 6);

    return 0;
}

/**
 * @brief  Implementing Bubble Sorting Algorithm 
 * @param  Data  Array of data which is needed to be sorted
 * @param  Data_Length  Size of Data Array
 * @retval  void Function does not return anything
 * @note  Not recommended for large data because of long execution time because of Worst Case Scenario Time Complexity (O(n^2))
 * @note  Make it adaptive manually by managing the test case of passing sorted data to the Function by using Sorted_Flag
 * @note  Stable Sorting algorithm -> if there are two equal elements in the passed array of data, there will be no problem they will be adjacent
 *        after sorting
 * @note  It is Possible to get the Maximum Elements at any Iterations
 */
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

/**
 * @brief  Implementing Insertion Sorting Algorithm 
 * @param  Data  Array of data which is needed to be sorted
 * @param  Data_Length  Size of Data Array
 * @retval  void Function does not return anything
 * @note  Not recommended for large data because of long execution time because of Worst Case Scenario Time Complexity (O(n^2))
 * @note  it is automatically adaptive by managing the test case of passing sorted data to the Function by using Sorted_Flag
 * @note  Stable Sorting algorithm -> if there are two equal elements in the passed array of data, there will be no problem they will be adjacent after sorting
 *        
 * @note  It is recommended with Linked list Sorting  "Linked List Sorting == Insertion Sort"
 * @note  It is Not Possible to get the Maximum Elements at any Iterations
 */
void Execute_Insertion_Sort (uint_32 Data[], uint_32 Data_Length)
{
    uint_32 Adjacent_Iter = 0;
    sint_32 Compare_Iter = 0;
    uint_32 Temp = 0;
    for (Adjacent_Iter = 1; Adjacent_Iter < Data_Length-1; Adjacent_Iter++)
    {
        Temp = Data[Adjacent_Iter];
        Compare_Iter = Adjacent_Iter - 1;
        while ((Temp < Data[Compare_Iter]) && (Compare_Iter >= 0))
        {
            Data[Compare_Iter + 1] = Data[Compare_Iter];
            Compare_Iter--;
        }
        Data[Compare_Iter+1] = Temp;  
    }
}

/**
 * @brief  Implementing Selection Sorting Algorithm 
 * @param  Data  Array of data which is needed to be sorted
 * @param  Data_Length  Size of Data Array
 * @retval  void Function does not return anything
 * @note  It is Possible to get the Minimum Elements at any Iterations 
 * @note  The Chosen Sorting algorithm if it is required from you a sorting algorithm that perform only one swap each one iteration which is 
 *        Opposite in case of Bubble sort which makes many swaps in one iteration
 * @note  Not Adaptive but I make it Manually
 * @note  Not Stable in case of finding equal elements their locations could simply change
 */
void Execute_Selection_Sort (uint_32 Data[], uint_32 Data_Length)
{
    uint_32 Selection_Iter = 0;
    uint_32 Compare_Iter = 0;
    uint_32 Smallest_Elem_Iter = 0;
    for(Selection_Iter = 0 ; Selection_Iter < Data_Length ; Selection_Iter++)
    {
        Smallest_Elem_Iter = Selection_Iter;
        for(Compare_Iter = Selection_Iter + 1 ; Compare_Iter < Data_Length ; Compare_Iter++)
        {
            if (Data[Smallest_Elem_Iter] > Data[Compare_Iter])
            {
                Smallest_Elem_Iter = Compare_Iter;
            }
            else{/* Nothing */}
        }
        if (Smallest_Elem_Iter != Selection_Iter)
            Swap_Two_Elements(&(Data[Selection_Iter]), &(Data[Smallest_Elem_Iter]));
        else {/* Nothing */}
    }
}