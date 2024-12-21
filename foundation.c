#include "foundation.h"
#include "Function_Read_and_Write.h"
#include "fundamentfunc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Menu(int* actions) 
{
    system("cls"); // Очистка экрана
    printf("1. Чтение данных из файла\n");
    printf("2. Просмотр данных\n");
    printf("3. Редактирование записи\n");
    printf("4. Добавление записи\n");
    printf("5. Удаление записи\n");
    printf("6. Сортировка записей\n");
    printf("7. Поиск записей\n");
    printf("8. Запись данных в файл\n");
    printf("9. Численная обработка данных\n");
    printf("0. Выход\n");

    printf("Выберите действие: ");
    scanf("%d", actions); // Считываем выбор пользователя
}

int main()
{
    system("chcp 1251");
    TRec assembly[MAX_SIZE];

    unsigned count = 0;
    int actions;
    char filename[100];
    char searchname[30];
    int ML; // больше или меньше

    while (1)
    {   
        Menu(&actions);
        
        switch (actions)
        {
        case 1:
            printf("Введите имя файла для чтения: ");
            scanf("%s", filename);
            ReadingBase(assembly, &count, filename);
            system("pause");
            break;

        case 2:
            WatchAssembly(assembly, count);
            system("pause");
            break;

        case 3:
            EditAssembly(assembly, count);
            system("pause");
            break;

        case 4:
            AddAssembly(assembly, &count);
            system("pause");
            break;

        case 5:
            DelAssembly(assembly, &count);
            system("pause");
            break;

        case 6:
            printf("Введите 1 для сортировки по возрастанию, 0 для убывания: ");
            scanf("%d", &ML);
            SortAssembly(assembly, count, ML);
            system("pause");
            break;

        case 7:
            printf("Введите название для поиска: ");
            scanf("%s", searchname);
            SearchAssembly(assembly, count, searchname);
            system("pause");
            break;

        case 8:
            printf("Введите имя файла для записи: ");
            scanf("%s", filename);
            WriteBase(assembly, count, filename);
            system("pause");
            break;

        case 9:
            PriceProcAssembly(assembly, count);
            system("pause");
            break;

        case 0:
            return 0;

        default:
            printf("Неправильный выбор, попробуйте еще раз.\n");
        }
    }
    return 0;
}