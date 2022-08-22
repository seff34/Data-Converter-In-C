#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
    uint8_t byte0;
    uint8_t byte1;
    uint8_t byte2;
    uint8_t byte3;
} data32_t;

/**
 * @brief  Convert 32bit to 8 bit 
 * @param  [in]  input  Input Data 
 * @param  [out] output Output Struct
 * @return [int8_t] Function Execute Result
 * @retval [0]   Success
 * @retval [1]   Fail
 */
int8_t dataConverter32(int32_t input, data32_t *output)
{
    if ( input >= (int32_t)INT32_MAX )
    {
        printf("Data Overflow (int32_t)\n");
        exit(EXIT_FAILURE);
    }
    output->byte0 = (uint8_t)input;
    output->byte1 = (uint8_t)(input >> 8) & UCHAR_MAX;
    output->byte2 = (uint8_t)(input >> 16) & UCHAR_MAX;
    output->byte3 = (uint8_t)(input >> 24) & UCHAR_MAX;

    return EXIT_SUCCESS;
}

int main(int argc, char **argv)
{
    if ( argc != 2)
    {
        printf("Enter a integer\n");
        return EXIT_FAILURE;
    }

    int32_t data = atoi(argv[1]);

    data32_t *parse;
    if ((parse = (data32_t *)calloc(1,sizeof(data32_t))) == NULL)
    {
        perror("Memory allocate error\n");
        return EXIT_FAILURE;
    }

    dataConverter32((int32_t)data, parse);

    printf("Byte 0 -> %d\n", parse->byte0);
    printf("Byte 1 -> %d\n", parse->byte1);
    printf("Byte 2 -> %d\n", parse->byte2);
    printf("Byte 3 -> %d\n", parse->byte3);

    free(parse);

    return EXIT_SUCCESS;
}
