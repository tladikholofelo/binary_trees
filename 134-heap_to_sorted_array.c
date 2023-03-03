#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to
 *                        a sorted array of integers
 * @heap: Pointer to the root node of the heap to convert
 * @size: The size of the array
 *
 * Return: Pointer to the array sorted in descending order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int i, *a = NULL;

    if (!heap || !size)
        return (NULL);

    *size = tree_size(heap) + 1;

    a = malloc(sizeof(int) * (*size));

    if (!a)
        return (NULL);

    for (i = 0; heap; i++)
        a[i] = heap_extract(&heap);

    return (a);
}
