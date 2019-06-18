//
//  main.c
//  Zadacha2.1
//
//  Created by Masyash on 26.02.2018.
//  Copyright © 2018 Masyash. All rights reserved.
//

#include <stdio.h>


int getInteger()
{
    int number;
    char c; /* Временная переменная для проверки ввода */
    /* Бесконечный цикл, работающий до момента удачного считывания */
    while (1)
    {
        /* Читаем поток ввода, необходимо число завершаемое
         * символом перевода на новую строку и никак иначе
         */
        if (!scanf("%d", &number) || getchar() != '\n')
        {
            /* Очистка потока от оставшихся после чтения символов
             * для предотвращения их прочтения следующимим вызовами scanf
             */
            while ((c = getchar()) != '\n' && c != EOF);
        }
        else return number;
        printf("Необходимо ввести число.\nПовторите ввод: ");
    }
}

void programmInfo (void){
    int choice=1;
    while (choice != 0){
        printf("\n 1.Информация о разработчике;\n2.Легальная информация;\n3.Лицензионное соглашение;\n0.Выход;\n");
    
    choice = getInteger();
        
        switch (choice){
            case 1:
                printf("\n Программу разработал: Карпов М.В, БГУИР, гр.853504, 18 марта 2019г.");
                break;
            case 2:
                printf("\n Все права защищены! И не надо тут!");
                break;
            case 3:
                printf("\n Лицензия разаработчика №853504 от 15.02.2000.");
                break;
            case 0:
                break;
                default:
                printf("\n ОШИБКА! ТАКОГО ВАРИАНТА НЕТ!\n");
                break;
        }
    }
}

struct Project {
    int monthStart;
    int monthFinish;
    int dayStart;
    int dayFinish;
    int programmers;
};

int getMonth (int month){
    do{
    printf("month: ");
        month=getInteger();
        if (month>12 || month<=0){
            printf("\n Введи нормальный месяц!\n");
        }
    }
    while (month>12 || month<=0);
    return month;
}
int getDay (int month, int day)
{
    //Проверка на февраль
    if (month==2)
    {
        do
        {
            printf("day: ");
            day=getInteger();
            if (day<1 || day>28)
            {
                printf("\n В этом месяце такого дня нет!\n");
                                }
            }
        while (day<1 || day>28);
                    }
   else if (month%2==0){
        do{
            printf("day: ");
                  day=getInteger();
            if (day<1 || day>30){
                printf("\n В этом месяце такого дня нет!\n");
            }
        }
        while (day<1 || day>30);
    }
   else {
       do{
           printf("day: ");
              day=getInteger();
           if (day<1 || day>31){
               printf("\n В этом месяце такого дня нет!\n");
           }
       }
       while (day<1 || day>31);
   }
    return day;
}


struct Project getDate (void){
     struct Project P1;
    do
    {
        printf("Введите дату начала проекта:\n");
        P1.monthStart = getMonth(P1.monthStart); // ввод месяца начала
        P1.dayStart = getDay(P1.monthStart, P1.dayStart); // ввод дня начала с учетом месяца
        printf("Введите дату завершения проекта:\n");
        P1.monthFinish = getMonth(P1.monthFinish);
        P1.dayFinish = getDay(P1.monthFinish, P1.dayFinish);

        if (P1.monthStart>P1.monthFinish || (P1.monthStart==P1.monthFinish && P1.dayStart>=P1.dayFinish))
        {
            printf("Вводи все заново!!:");
        }
    }
    while (P1.monthStart>P1.monthFinish || (P1.monthStart==P1.monthFinish && P1.dayStart>=P1.dayFinish));
    return P1;
}

int getNumberOfWorkers(void){
        struct Project P1;
    do{
        printf("\nВведите кол-во работников: ");
        P1.programmers=getInteger();
        if (P1.programmers==0){
            printf("\nХммм... Ну и кто работать то будет?\n");
        }
        else if (P1.programmers<0){
            printf("\nПожалуйста отнеситесь серьезно!\n");
        }
    }while (P1.programmers<=0);
    return P1.programmers;
}

int countOfTime (struct Project P1)
{
    int monthGoing, daysGoing=0;
    monthGoing = P1.monthFinish - P1.monthStart;
    for ( ; monthGoing>0; monthGoing--)
    {
        
        if (P1.monthStart+monthGoing == 2)
        {
            daysGoing+=28;
        }
        else if ((P1.monthStart+monthGoing)%2==0)
        {
            daysGoing+=30;
        }
        else {
            daysGoing+=31;
        }
        
    }
    
    daysGoing+=P1.dayFinish;
    daysGoing=daysGoing-P1.dayStart+1;
    
    int hoursInWork, weeksForWork, manHours;
    
    
    weeksForWork=daysGoing/7;
    hoursInWork=weeksForWork*40;
    manHours=hoursInWork*P1.programmers;
    
    printf("\n Кол-во дней: ");
    printf("%d", daysGoing);
    printf("\n Кол-во часов работы: ");
    printf("%d", hoursInWork);
    printf("\n Кол-во человекочасов: ");
    printf("%d", manHours);
    printf("\n");
    return manHours;
}

void countOfPribil (int manHours, float payPerPerson, struct Project P1){
    float pribilCompanii;
    pribilCompanii = manHours*payPerPerson;
    printf("\nПриблизительная прибыль компании составит:");
    printf("%f", pribilCompanii);
    printf("$\n");
    int daysGoing = (manHours*P1.programmers)/8;
    if (pribilCompanii<1000){
        printf("Программа считает выполнение проекта нецелесообразным!\n");
        if(daysGoing<30 && pribilCompanii>200){
            printf("  Однако проект принесет хорошую прибыль относительно срока выполнения\n");
        }
    }
    else{
        printf("Мои поздравления! Проект прибыльный!\n");
    }
}

int main(int argc, const char * argv[]) {
    int repeat=1;
    while (repeat!=0)
    {
    printf("ДОБРО ПОЖАЛОВАТЬ В ПРОГРАММУ ДЛЯ РАССЧЕТА ПРИБЫЛЬНОСТИ   PM1  !!!!\n\n");
    
    const float programmerPayment=2.3; //Зарплата программиста за час
    const float companyRate=9; //Часовая ставка компании
    const float edditionalWaste=5.75; //Накладные расходы
    float payPerPerson = companyRate-programmerPayment-edditionalWaste;
    
       
            struct Project P1;
        P1.programmers=0;
        P1.dayStart=0;
         float manHours=0;
        while (repeat !=0)
        {
        printf("\nВведите номер варианта: \n");
            printf("\n1.Ввод даты начала и конца проекта;\n2.Ввод кол-ва работников;\n3.Рассчет времени и человекочасов;");
            printf("\n4.Рассчет прибыльности проекта;\n5.Информация о разработчике;\n6.Выход/повтор программы;\n ");
            int littleChoice;
            littleChoice=getInteger();
        
            switch (littleChoice) { //реализация меню программы через switch case
                case 1:
                     P1=getDate();
                    // Ввод данных по началу и завершению проекта с провкой на макаку
                    //Рассчет времени проекта идет в рамках одного года
                    break;
                case 2:
                     P1.programmers = getNumberOfWorkers();
                    // Ввод кол-ва программистов
                    break;
               case 3:
                    if (P1.dayStart==0){
                        printf("\nВы не ввели даты начала и окончания проекта! \n");
                        break;
                    }
                    if (P1.programmers==0){
                        printf("\nВы не ввели кол-во работников!\n ");
                        break;
                    }
                 manHours = countOfTime(P1);
                    break;
              case 4:
                    if (P1.dayStart==0)
                    {
                        printf("\nВы не ввели даты начала и окончания проекта!\n ");
                        break;
                    }
                    if (P1.programmers==0)
                    {
                        printf("\nВы не ввели кол-во работников! \n");
                        break;
                    }
                    if (manHours==0){
                        if (P1.dayStart==0){
                            printf("\nВы не ввели даты начала и окончания проекта! \n");
                            break;
                        }
                        
                        if (P1.programmers==0){
                            printf("\nВы не ввели кол-во работников!\n ");
                            break;
                        }
                        manHours = countOfTime(P1);
                    }
                     countOfPribil(manHours, payPerPerson, P1);
                    break;
                case 5:
                    programmInfo();
                    break;
                case 6:
                    repeat=0;
                    break;
                  
                default:
                    printf("\n ОШИБКА! ТАКОГО ВАРИАНТА НЕТ!\n");
                    repeat = 10;
                    break;
            }
        }
      printf("Чтобы выйти из программы ввеите '0', для повторения введите любую цифру :  ");
        repeat=getInteger();
    }
    return 0;
}
