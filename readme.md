
# Data Convertor in C

Big Data to Low Data in C Standart Libs.



## Functions

#### Data Structure
```c
typedef struct{
    uint8_t byte0;
    uint8_t byte1;
    uint8_t byte2;
    uint8_t byte3;
} data32_t;
```



#### Data Converter
```c
int8_t dataConverter32(int32_t input, data32_t *output);
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `input` | `int32_t` | Input Value|
| `output` | `data_t` | Output Value|

#### Example Code
```c
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
```


## Download Code

Clone Project

```bash
  git clone https://github.com/seff34/Data-Converter-In-C
```


  
