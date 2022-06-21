#include <stdio.h>
#include <stdlib.h>

#define MAXVALUE 15

struct phonebook {
    char name[50];
    char surname[50];
    char number[15];
} phb[MAXVALUE] = {
    [0].name = "Иван",
    [0].surname = "Петров",
    [0].number = "234255",
    [1].name = "Федор",
    [1].surname = "Сидоров",
    [1].number = "234432",
};

int menu_select (int c) {
    for (;;) {
        if ((c >= 1) && (c <= 5)){
            return c;
        } else {
            printf("Введен неверный номер\n");
            printf("\nВведите номер нужного пункта:\n");
            scanf("%d", &c);
            puts("\n");
            return c;
        }
    }
}

int space_free (void) {
    for (int num = 0; num <= MAXVALUE; num++) {
        if (num == MAXVALUE){
            return -666;
        }
            if (phb[num].name[0] == 0){
            return num;
            }
    }
    return -666;
}

int add (void) {
    int num;
    
    num = space_free();
    if (num == -666) {
        printf ("Нет места");
        return 0;
    }
    
    printf("Введите имя: ");
    scanf("%s", phb[num].name);
    printf("Введите фамилию: ");
    scanf("%s", phb[num].surname);
    printf("Введите номер: ");
    scanf("%s", phb[num].number);
    printf("\nВами была добавлена новая запись:");
    printf("\n#%d: %s %s, %s\n", num+1, phb[num].name, phb[num].surname, phb[num].number);
    
    return 0;
}

int word_in_string(char * word, char * str)
{
    for ( ; *str != '\0'; str++) {
        if (*word == *str) {
            char * temp = word;
            
            for (int i = 0; *temp && *temp == str[i]; i++, temp++);
            
            if (*temp == '\0')
                return 1;
        }
    }
    return 0;
}

int find_name (void) {
    char str[50];
    int count = 0;
    printf("Введите строку из имени: ");
    scanf("%s", str);
    
    for (int i = 0; i < MAXVALUE; i++) {
        if (phb[i].name[0] == '\0')
            break;

        if (word_in_string(str, phb[i].name)) {
            printf("\n#%d: %s %s, %s", i + 1, phb[i].name, phb[i].surname, phb[i].number);
                count++;
        }
    }
    
    printf("\nНашлось записей: %d\n", count);
    return 0;
}

int find_surname (void) {
    char str[50];
    int count = 0;
    printf("Введите строку из фамилии: ");
    scanf("%s", str);
    
    for (int i = 0; i < MAXVALUE; i++) {
        if (phb[i].surname[0] == '\0')
            break;

        if (word_in_string(str, phb[i].surname)) {
            printf("\n#%d: %s %s, %s", i + 1, phb[i].name, phb[i].surname, phb[i].number);
                count++;
        }
    }
    
    printf("\nНашлось записей: %d\n", count);
    return 0;
}

int find_phone (void) {
    char str[50];
    int count = 0;
    printf("Введите строку из телефона: ");
    scanf("%s", str);
    
    for (int i = 0; i < MAXVALUE; i++) {
        if (phb[i].number[0] == '\0')
            break;

        if (word_in_string(str, phb[i].number)) {
            printf("\n#%d: %s %s, %s", i + 1, phb[i].name, phb[i].surname, phb[i].number);
                count++;
        }
    }
    
    printf("\nНашлось записей: %d\n", count);
    return 0;
}

int find_number (void) {
    int i;
    
    printf("Введите порядковый номер: ");
    scanf("%d", &i);
    i = i - 1;
    if (i >= 0 && i < MAXVALUE)
    {
        if (phb[i].name[0] != '\0')
        {
            printf("\n#%d: %s %s, %s\n", i + 1, phb[i].name, phb[i].surname, phb[i].number);
            return 0;
        }
        printf("Запись отсутствует\n");
        return 0;
    }
    printf("Введен некорректный номер\n");
    return 0;
}

int find_menu (void) {
    int select;
    for (;;) {
        printf("\n1. Найти по имени\n");
        printf("2. Найти по фамилии\n");
        printf("3. Найти по номеру телефона\n");
        printf("4. Найти по порядковому номеру\n");
        printf("5. Выход в главное меню\n");
        
        printf("\nВведите номер нужного пункта: ");
        scanf("%d", &select);
        
        switch (select) {
            case 1: find_name();
                break;
            case 2: find_surname();
                break;
            case 3: find_phone();
                break;
            case 4: find_number();
                break;
            case 5: return 0;
            default: return 0;
        }
    }
        return 0;
}

int delete (void) {
    int num = 0;

    printf("Введите № записи: ");
    scanf("%d", &num);
    if(num-1>=0 && num-1 < MAXVALUE) {
        if (phb[num-1].name[0] != '\0') {
            phb[num-1].name[0] = '\0';
            printf("Запись #%d: %s %s удалена\n", num, phb[num-1].name, phb[num-1].surname);
            return 0;
        }
        printf("Запись отсутствует\n");
        return 0;
    }
    printf("Введен некорректный номер\n");
    return 0;
}


int list (void) {
    for (int num = 0; num < MAXVALUE; num++){
        if (phb[num].name[0] != 0) {
            printf("#%d: %s %s, %s\n", num+1, phb[num].name, phb[num].surname, phb[num].number);
        }
    }
    return 0;
}

int main (void) {
    int ms;
    
    puts("Телефонная книга:");
    puts("ВНИМАНИЕ! Программа чувствительна к регистру!");
    for(;;) {
        printf("\n1. Добавить запись\n");
        printf("2. Найти запись\n");
        printf("3. Удалить запись\n");
        printf("4. Вывести список\n");
        printf("5. Выход\n\n");
        
        printf("Введите номер нужного пункта: ");
        scanf("%d", &ms);
        
        ms = menu_select(ms);
        switch (ms) {
            case 1: add();
                break;
            case 2: find_menu();
                break;
            case 3: delete();
                break;
            case 4: list();
                break;
            case 5: exit(0);
            default: menu_select(ms);
        }
    }
    return 0;
}
