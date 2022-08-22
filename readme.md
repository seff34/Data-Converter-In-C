
# Data Convertor in C

Big Data to Low Data in C Standart Libs.



## API Functions

#### Data Structure
```http
typedef struct{
    uint8_t byte0;
    uint8_t byte1;
    uint8_t byte2;
    uint8_t byte3;
} data32_t;
```



#### Data Converter
```http
int8_t dataConverter32(int32_t input, data32_t *output);
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `input` | `int32_t` | Input Value|
| `output` | `data_t` | Output Value|


## Download Code

Clone Project

```bash
  git clone https://github.com/seff34/Data-Converter-In-C
```


  