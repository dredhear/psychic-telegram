#include "Function_Read_and_Write.h"

#include <stdio.h>
#include <stdlib.h>

void ReadingBase(TRec* assembly, unsigned* count, const char* filename)
{
    FILE* read = fopen(filename, "r");

    if (!read)
    {
        printf("Ошибка: файл не найден.\n");
        return;
    }
    *count = 0;
    while (fscanf(read, "%s %s %d %s %f %s %f %f",
        assembly[*count].Processor,
        assembly[*count].GraphicsCard,
        &assembly[*count].RAM,
        assembly[*count].HHD_SSD,
        &assembly[*count].Size_Memory,
        assembly[*count].Power_Supply,
        &assembly[*count].Power,
        &assembly[*count].price) == 8)
    {
        (*count)++;
        if (*count >= MAX_SIZE)
        {
            printf("Ошибка: превышен максимальный размер массива.\n");
            break;
        }
    }

    fclose(read);
}

void WriteBase(TRec* assembly, unsigned count, const char* filename)
{
    FILE* write = fopen(filename, "w");

    if (!write)
    {
        printf("Ошибка: не удается открыть файл для записи.\n");
        return;
    }

    for (unsigned i = 0; i < count; ++i)
    {
        fprintf(write, "%s %s %d %s %.2f %s %.2f %.2f\n",
            assembly[i].Processor,
            assembly[i].GraphicsCard,
            assembly[i].RAM,
            assembly[i].HHD_SSD,
            assembly[i].Size_Memory,
            assembly[i].Power_Supply,
            assembly[i].Power,
            assembly[i].price);
    }

    fclose(write);
}