#include "fundamentfunc.h"

#include <stdio.h>
#include <stdlib.h>

void WatchAssembly(TRec* assembly, unsigned number)
{
    printf("|No  | Процессор                  | Видеокарта                 | RAM  | HHD/SSD | Размер память | Блок Питания                | Мощность   | Цена    |\n");

    for (unsigned i = 0; i < number; ++i)
    {
        printf("|%-3u | %-26s | %-26s | %-4d | %-7s | %-13.2f | %-27s | %-10.2f | %-7.2f |\n",
            i + 1,
            assembly[i].Processor,
            assembly[i].GraphicsCard,
            assembly[i].RAM,
            assembly[i].HHD_SSD,
            assembly[i].Size_Memory,
            assembly[i].Power_Supply,
            assembly[i].Power,
            assembly[i].price);
    }
}

void EditAssembly(TRec* assembly, unsigned count)
{
    unsigned index;
    printf("Введите номер записи для редактирования: ");
    scanf("%u", &index);

    if (index < 1 || index > count)
    {
        printf("Ошибка: неправильный номер записи.\n");
        return;
    }
    index--;

    printf("Введите Процессор, Видеокарту, RAM, HHD/SSD, Размер памяти, Блока питания, Мощность БП и Цену: ");
    scanf("%s %s %d %s %f %s %f %f",
        assembly[index].Processor,
        assembly[index].GraphicsCard,
        &assembly[index].RAM,
        assembly[index].HHD_SSD,
        &assembly[index].Size_Memory,
        assembly[index].Power_Supply,
        &assembly[index].Power,
        &assembly[index].price);
}

void AddAssembly(TRec* assembly, unsigned* count)
{
    if (*count >= MAX_SIZE)
    {
        printf("Нет места для новой записи.\n");
        return;
    }

    printf("Введите Процессор, Видеокарту, RAM, HHD/SSD, Размер памяти, Блока питания, Мощность БП и Цену: ");
    scanf("%s %s %d %s %f %s %f %f",
        assembly[*count].Processor,
        assembly[*count].GraphicsCard,
        &assembly[*count].RAM,
        assembly[*count].HHD_SSD,
        &assembly[*count].Size_Memory,
        assembly[*count].Power_Supply,
        &assembly[*count].Power,
        &assembly[*count].price);
    (*count)++;
}

void DelAssembly(TRec* assembly, unsigned* count)
{
    unsigned index;
    printf("Введите номер записи для удаления: ");
    scanf("%u", &index);

    if (index < 1 || index > *count)
    {
        printf("Ошибка: неправильный номер записи.\n");
        return;
    }

    index--; // Преобразуем в индекс массива
    for (unsigned i = index; i < *count - 1; ++i)
    {
        assembly[i] = assembly[i + 1];
    }

    (*count)--;
}

void SortAssembly(TRec* assembly, unsigned count, int ML)
{
    for (unsigned i = 0; i < count - 1; ++i) {
        for (unsigned j = i + 1; j < count; ++j)
        {
            int compare = strcmp(assembly[i].Processor, assembly[j].Processor);
            if ((ML && compare > 0) || (!ML && compare < 0))
            {
                TRec temp = assembly[i];
                assembly[i] = assembly[j];
                assembly[j] = temp;
            }
        }
    }
}

void SearchAssembly(TRec* assembly, unsigned count, const char* name)
{
    for (unsigned i = 0; i < count; ++i)
    {
        if (strstr(assembly[i].Processor, name) != NULL || strstr(assembly[i].GraphicsCard, name) != NULL)
        {
            printf("%-3u  %-26s  %-26s  %-4d  %-7s  %-11.2f  %-27s  %-7.2f  %-7.2f\n",
                i + 1,
                assembly[i].Processor,
                assembly[i].GraphicsCard,
                assembly[i].RAM,
                assembly[i].HHD_SSD,
                assembly[i].Size_Memory,
                assembly[i].Power_Supply,
                assembly[i].Power,
                assembly[i].price);
        }
    }
}

void PriceProcAssembly(TRec* assembly, unsigned count)
{
    if (count == 0)
    {
        printf("Нет данных для обработки.\n");
        return;
    }

    float sumPrice = 0;
    float maxPrice = assembly[0].price;
    float minPrice = assembly[0].price;

    for (unsigned i = 0; i < count; ++i)
    {
        sumPrice += assembly[i].price;

        if (assembly[i].price > maxPrice) maxPrice = assembly[i].price;
        if (assembly[i].price < minPrice) minPrice = assembly[i].price;
    }
    printf("Минимальная цена: %.2f\n", minPrice);
    printf("Средняя цена: %.2f\n", sumPrice / count);
    printf("Максимальная цена: %.2f\n", maxPrice);
}