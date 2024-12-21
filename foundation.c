#include "foundation.h"
#include "Function_Read_and_Write.h"
#include "fundamentfunc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Menu(int* actions) 
{
    system("cls"); // ������� ������
    printf("1. ������ ������ �� �����\n");
    printf("2. �������� ������\n");
    printf("3. �������������� ������\n");
    printf("4. ���������� ������\n");
    printf("5. �������� ������\n");
    printf("6. ���������� �������\n");
    printf("7. ����� �������\n");
    printf("8. ������ ������ � ����\n");
    printf("9. ��������� ��������� ������\n");
    printf("0. �����\n");

    printf("�������� ��������: ");
    scanf("%d", actions); // ��������� ����� ������������
}

int main()
{
    system("chcp 1251");
    TRec assembly[MAX_SIZE];

    unsigned count = 0;
    int actions;
    char filename[100];
    char searchname[30];
    int ML; // ������ ��� ������

    while (1)
    {   
        Menu(&actions);
        
        switch (actions)
        {
        case 1:
            printf("������� ��� ����� ��� ������: ");
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
            printf("������� 1 ��� ���������� �� �����������, 0 ��� ��������: ");
            scanf("%d", &ML);
            SortAssembly(assembly, count, ML);
            system("pause");
            break;

        case 7:
            printf("������� �������� ��� ������: ");
            scanf("%s", searchname);
            SearchAssembly(assembly, count, searchname);
            system("pause");
            break;

        case 8:
            printf("������� ��� ����� ��� ������: ");
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
            printf("������������ �����, ���������� ��� ���.\n");
        }
    }
    return 0;
}