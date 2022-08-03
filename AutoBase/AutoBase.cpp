#include "MainHeader.h" //Підключення головного хедеру
int main()
{
    SetConsoleCP(1251);                 //Встановлення підтримки української мови
    SetConsoleOutputCP(1251);           

    Manager manager;               //Об'єкт Менеджер 
    vector<Order> orders;          //Ініціалізація "Бази" замовлень

    int menu = 0;           //Ініціалізація меню/подменю
    int podmenu = 0;
    int numberoforders = 0; //Лічильник, що рахує кількість замовлень
    Menu mainmenu; mainmenu.header();
    while (menu != 4) {
        if (menu == 0)
        {
            system("Color E0");         //Встановлення кольору консолі
            mainmenu.showbasemenu();    
            cin >> menu;
        }
        else if (menu == 1) {
            system("cls");
            mainmenu.showusermenu();
            while (podmenu != 3) {
                cin >> podmenu;
                if (podmenu == 1) {             //Створення замовлення
                    system("cls");
                    cout << "Прийнято!\n\n" << endl;
                    Auto defaultauto("АХ 5667 ВК", "КамАЗ-5320", "бортовий великотоннажний вантажний автомобіль", 15, 34.5, "Харків");      //Дефолтне авто автобази

                    cout << "!Автомобіль, що буде призначений для рейсів - " << defaultauto.GetModel() << endl << endl; cout << defaultauto << endl << endl;
                    Order order; cin >> order;      

                    order.SetNumber(numberoforders + 1); order.SetRouteAmount(defaultauto);
                    cout << "\n\nЗамовлення, що буде занесено до бази: " << endl; cout << order;  cout << "Натисніть будь-яку клавішу "; string flag; cin >> flag;

                    system("cls"); system("Color 02");

                    cout << "!Панель менеджера" << endl;        //Передача уаправління менеджеру, зміна теми консолі
                    cout << "Кількість рейсів для замовлення:  " << order.GetRouteAmount() << endl;
                    try {
                        Timetable timetable(order.GetRouteAmount());
                        cin >> timetable; order.SetAllFuel(timetable); cout << "\nПрограмно було розраховано загальні витрати пального:  " << order.GetAllFuel() << endl;
                        string filename; cout << "Введіть назву файлу для створення звіту з рейсів по замовленню у форматі 'Замовлення<номер>.txt' ";
                        cin >> filename; cout << "Звіт з вашого замовлення успішно створений!" << endl;
                        for (int i = 0; i < timetable.GetSize(); i++) {   //Створення звіту
                            timetable[i].WriteStringData(filename);
                        }
                    }
                    catch (ErrorMessage* error) {       //Ловимо виключення
                        string flag;
                        error->printmessage();
                        cout << "Натисніть будь-яку клавішу "; cin >> flag; system("Color E0"); system("cls"); menu = 0;
                        break;
                    }
                    catch (...) { cout << "Помилка створення"; }

                    orders.push_back(order);    //збільшення бази на одне замовлення
                    numberoforders++;           
                    cout << "Натисніть будь-яку клавішу "; cin >> flag;
                    system("Color E0");
                }
                else if (podmenu == 2) {        //Інформація про автобазу
                    system("cls");
                    mainmenu.autobaseinfo();
                    menu = 0;
                    cout << endl << endl;
                }
                else if (podmenu == 3) //Вихід до головного меню
                {
                    system("cls");
                    podmenu = 0;
                    menu = 0;
                    break;
                }
                else {
                    cout << "Невірно вибраний варіант,спробуйте ще" << endl;
                }
                break;
            }
        }
        else if (menu == 2) { //Меню менеджера
            if (menu == 0)
            {
                mainmenu.showservicemenu();
                cin >> menu;
            }
            menu = 0;
            if (!mainmenu.check()) {        //Перевірка на ключ
                cout << "Ключ невірний! аварійне завершення програми"; break;
            }
            else {
                system("cls"); system("Color 02");
                cout << "Ключ вірний! Будь-ласка авторизуйтесь: "; cin >> manager; cout << endl << manager; //авторизація за логіном
                mainmenu.showservicemenu();
                while (podmenu != 4) {
                    cin >> podmenu;
                    if (podmenu == 1) {         //Реєстрація нових водіїв
                        cout << "!Прийнято\n\n"; int size;
                        cout << "Кількість нових водіїв: "; cin >> size;
                        try {
                            Drivers drivers(size);
                            cin >> drivers;

                            cout << "!Нові працівники" << endl;
                            cout << drivers << endl << endl;

                            int answer; cout << "!Збільшити зарплату новим працівникам? 1.так 2.ні \n"; cin >> answer; //Додаткова функція
                            if (answer == 1) {
                                int up; cout << "Збільшити на ? "; cin >> up;
                                for (int i = 0; i < drivers.GetSize(); i++) {
                                    drivers[i](up);
                                }
                                cout << "\n\nНові дані:\n"; cout << drivers;
                            }
                            else if (answer == 2) { menu = 0; break; }
                            else { menu = 0; break; }
                            
                        }
                        catch (ErrorMessage* error) {       //Ловимо виключення
                            string flag;
                            error->printmessage();
                            cout << "Натисніть будь-яку клавішу "; cin >> flag; system("Color E0"); system("cls"); menu = 0;
                            break;
                        }
                        catch (...) {
                            cout << "Помилка" << endl;
                        }

                        menu = 0;
                        break;
                    }
                    else if (podmenu == 2) {        //Відображення "бази" замовлень
                        system("cls");
                        try {
                            if (orders.size() == 0) { throw orders.size(); }
                            for (int i = 0; i < orders.size(); i++) {
                                cout << orders[i] << endl;
                            }
                        }
                        catch (...) {
                            cout << "!Список замовлень порожній" << endl;
                        }
                        string flag;
                        cout << "Натисніть будь-яку клавішу "; cin >> flag; cout << endl << endl;
                        menu = 0;
                        break;
                    }
                    else if (podmenu == 3) { //Вихід до головного меню
                        system("cls");
                        podmenu = 0;
                        menu = 0;
                        break;
                    }

                    else {
                        cout << "Невірно вибраний варіант,спробуйте ще" << endl;
                    }
                    break;
                }
            }
        }
        else if (menu == 3) {       //Розділ тестування
        system("Color 02"); system("cls");
        cout << "!Цей розділ створений для тестування конструкторів, методів та операторів,що не використовувалися\nв основній програмі\n\n\n";

        //Auto
        Auto auto1("VALUE", "VALUE2", "VALUE3", 124.2, 245.3, "VALUE4"); // Конструктор зі списком ініціалізації
        Auto auto2(auto1);      // Конструктор копіювання класу Auto
        Auto auto3; auto3 = auto2; //Оператор =
        Auto auto4; cin >> auto4;  //Оператор >>
        cout << auto1 << endl << auto2 << endl << auto3 << endl << auto4 << endl << endl;  //Виведення об'єктів
        ////////////////////////////////////////
        //Driver
        Driver driver1("Петренко.С.І.", 1234, 6000); // Конструктор зі списком ініціалізації
        Driver driver2(driver1);        // Конструктор копіювання
        Driver driver3 = driver2;       //Оператор =
        cout << driver1 << endl << driver2 << endl << driver3 << endl << endl;   //Виведення об'єктів
        ////////////////////////////////////////
        //Route
        Route route1({1,2,3}, "VALUE", 120, 120, "VALUE2", "VALUE3", "VALUE4", 131, 2, "VALUE5", "VALUE6", 321, 121); //Конструктор зі списком ініціалізації
        Route route2; route2 = route1;      //Оператор = 
        cout << route1 << endl << route2 << endl << endl;
        ////////////////////////////////////////

        cout << "!Тестування завершено,всі методи,оператори працюють корректно." << endl;
        menu = 0;
        }
        else if (menu == 4) { break; } //Завершення програми
    }
}