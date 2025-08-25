#include "push_swap.h"

/*void print_stack(int *stack, int size, char *name)
{
    int i;
    
    printf("Stack %s: ", name);
    i = 0;
    while (i < size)
    {
        printf("%d ", stack[i]);
        i++;
    }
    printf("(size: %d)\n", size);
}*/

int is_sorted(int *a, int size_a, int size_b)
{
  int i;

  if (size_b > 0)
    return (0);

  if (size_a <= 1)
    return (1);
  
  i = 0;
  while(i < size_a - 1)
  {
    if (a[i] > a[i + 1])
      return (0);
    i++;
  }
  return (1);
}

void sort_three(int *a, int size_a)
{
  if(size_a != 3)
    return ;

  int max_pos = 0;
  if(a[1] > a[max_pos])
    max_pos = 1;
  if(a[2] > a[max_pos])
    max_pos = 2;

  if(max_pos == 0)
    ra(a, size_a);
  else if(max_pos == 1)
    rra(a, size_a);
  
  if(a[0] > a[1])
    sa(a, size_a);
}

int has_duplicates(int *arr, int size)
{
  int i;
  int j;

  i = 0;
  while(i < size - 1)
  {
    j = i + 1;
    while(j < size)
    {
      if (arr[i] == arr[j])
        return (1);
      j++;
    }
    i++;
  }
  return (0);
}

int *parse_arguments(int argc, char *argv[], int *count)
{
  int *numbers;

  if(argc == 2)
  {
    //SI PASO LOS ARGUMENTOS ASÍ: "1 2 3 4"
    numbers = parse_single_string(argv[1], count);
  }
  else
  {
    //SI PASO LOS ARGUMENTOS ASÍ: 1 2 3
    numbers = parse_multiple_string(argc, argv, count);
  }

  if(numbers && has_duplicates(numbers, *count))
  {
    printf("NUMERO REPETIDO\n");
    free(numbers);
    return (NULL);
  }

  return (numbers);
}

// ============= FUNCIONES AUXILIARES PARA RADIX SORT =============

// Función para encontrar el índice/posición de un número en el array ordenado
// Convierte los números a índices 0, 1, 2, 3... según su orden
void index_array(int *arr, int *indexed, int size)
{
    int i, j, count;
    
    i = 0;
    while (i < size)
    {
        count = 0;
        j = 0;
        while (j < size)
        {
            if (arr[j] < arr[i])
                count++;
            j++;
        }
        indexed[i] = count; // El índice es cuántos números son menores
        i++;
    }
}

// Obtener el índice de un elemento en el array indexado
int get_index_of_element(int *original, int *indexed, int size, int element)
{
    int i = 0;
    
    while (i < size)
    {
        if (original[i] == element)
            return (indexed[i]);
        i++;
    }
    return (0);
}

int get_max_bits(int size)
{
    int max_num = size - 1; // el índice más grande
    int bits = 0;

    while ((max_num >> bits) != 0)
        bits++;
    return bits;
}

// ============= IMPLEMENTACIÓN RADIX SORT =============





// Convertir array a índices normalizados (0, 1, 2, 3...)
void normalize_array(int *arr, int *normalized, int size)
{
    int i, j, count;

    for (i = 0; i < size; i++)
    {
        count = 0;
        for (j = 0; j < size; j++)
        {
            if (arr[j] < arr[i])
                count++;
        }
        normalized[i] = count;
    }
}

// Obtener el índice normalizado de un elemento específico
int get_normalized_index(int *original, int *normalized, int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (original[i] == element)
            return normalized[i];
    }
    return 0;
}

// Función auxiliar: encontrar la posición que tendría un número si estuviera ordenado
int get_sorted_position(int num, int *arr, int size)
{
    int position = 0;
    int i = 0;
    
    while (i < size)
    {
        if (arr[i] < num)
            position++;
        i++;
    }
    
    return (position);
}

// ============= VERSIÓN SIMPLIFICADA (más fácil de entender) =============
void radix_sort_correct(int *a, int *size_a, int *b, int *size_b, int *original, int total_size)
{
    int *normalized;
    int max_bits, bit, i, current_index;
    int original_size_a;
    
    // Reservar memoria para índices normalizados
    normalized = malloc(sizeof(int) * total_size);
    if (!normalized)
        return;
    
    // Normalizar el array (convertir a índices 0,1,2,3...)
    normalize_array(original, normalized, total_size);
    
    // Debug: mostrar normalización
    /*printf("Original: ");
    for (i = 0; i < total_size; i++)
        printf("%d ", original[i]);
    printf("\nNormalizado: ");
    for (i = 0; i < total_size; i++)
        printf("%d ", normalized[i]);
    printf("\n\n");*/
    
    max_bits = get_max_bits(total_size);
    
    // Para cada bit (de menos significativo a más significativo)
    for (bit = 0; bit < max_bits; bit++)
    {
        //printf("=== Procesando bit %d ===\n", bit);
        original_size_a = *size_a;
        
        // Procesar todos los elementos que están inicialmente en A
        for (i = 0; i < original_size_a; i++)
        {
            // Obtener índice normalizado del elemento en el tope de A
            current_index = get_normalized_index(original, normalized, total_size, a[0]);
            
            /*printf("Elemento %d -> índice normalizado %d -> bit %d = %d\n", 
                   a[0], current_index, bit, (current_index >> bit) & 1);*/
            
            // Si el bit es 0, enviar a B
            if (((current_index >> bit) & 1) == 0)
            {
                //printf("  -> pb (bit 0)\n");
                pb(a, size_a, b, size_b);
            }
            else
            {
                //printf("  -> ra (bit 1)\n");
                ra(a, *size_a);
            }
        }
        
        
        //printf("Después del bit %d - A: ", bit);
        //print_stack(a, *size_a, "A");
        //print_stack(b, *size_b, "B");
        
        // Devolver todos los elementos de B a A
        while (*size_b > 0)
        {
            //printf("pa\n");
            pa(a, size_a, b, size_b);
        }
        
        //printf("Después de devolver todo a A: ");
        //print_stack(a, *size_a, "A");
        //printf("\n");
    }
    
    free(normalized);
}

// Función de prueba mejorada
void test_specific_case(void)
{
    int original[] = {9, 8, 4, 2};
    int a[10], b[10];
    int size_a = 4, size_b = 0;
    
    // Copiar a stack A
    for (int i = 0; i < 4; i++)
        a[i] = original[i];
    
    //printf("=== TEST CASO ESPECÍFICO: 9 8 4 2 ===\n");
    //printf("Stack inicial A: ");
    //print_stack(a, size_a, "A");
    
    // Aplicar radix sort
    radix_sort_correct(a, &size_a, b, &size_b, original, 4);
    
    //printf("=== RESULTADO FINAL ===\n");
    //print_stack(a, size_a, "A final");
    //printf("¿Ordenado? %s\n", is_sorted(a, size_a, size_b) ? "SÍ" : "NO");
}


// ============= INTEGRACIÓN CON TU MAIN =============

int main(int argc, char *argv[])
{
    int a[1000], b[1000];
    int size_a = 0, size_b = 0;
    int *numbers;
    int count, i;

    // Si no hay argumentos, ejecutar test específico
    if (argc == 1)
    {
        test_specific_case();
        return 0;
    }

    // Parsing de argumentos
    numbers = parse_arguments(argc, argv, &count);
    if (!numbers)
        return 1;

    // Llenar stack A
    for (i = 0; i < count; i++)
        a[i] = numbers[i];
    size_a = count;

    // Aplicar algoritmo apropiado
    if (count <= 3)
        sort_three(a, size_a);
    else
        radix_sort_correct(a, &size_a, b, &size_b, numbers, count);

    // Verificar resultado
    /*if (is_sorted(a, size_a, size_b))
        //printf("✅ Ordenado correctamente!\n");
    else
        printf("❌ Error en el ordenamiento\n");

        */
    free(numbers);
    return 0;
}
