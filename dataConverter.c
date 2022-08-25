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

