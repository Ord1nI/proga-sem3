#include <iostream>
#include <string>
#include <cctype> 
#include <fstream>
#include <sstream>

struct Pipe{
    std::string name;
    float length;
    float diameter;
    bool is_reparing;
};

Pipe new_pipe(std::string name, float length, bool is_reparing) {
    Pipe p;
    p.name = name;
    p.length = length;
    p.is_reparing = is_reparing;
    return p;
}

std::string string_pipe(const Pipe & r_pipe) {
    std::stringstream s_string;
    s_string << "Труба " << r_pipe.name << '\n' <<
                 "Длина "  << r_pipe.length << '\n' <<
                 "Диаметр " << r_pipe.diameter << '\n' <<
                 "В ремонте " << ((r_pipe.is_reparing) ? "true" : "false") << '\n';
    return s_string.str(); 
}

struct C_station {
    std::string name;
    int workshops;
    int working_workshops;
    float efficiency;
};

C_station new_c_station(std::string name, int workshops, int working_shops, float efficiency) {
    C_station station;
    station.name = name;
    station.workshops = workshops;
    station.working_workshops = working_shops;
    station.efficiency = efficiency;
    return station;
}

std::string string_c_station(C_station & ptr_station) {
    std::stringstream s_string;
    s_string << "КС " << ptr_station.name << '\n' <<
                 "Количество цехов " << ptr_station.workshops << '\n' <<
                 "Количество цехов в работе " << ptr_station.working_workshops << '\n' <<
                 "эффективность " <<  ptr_station.efficiency << '\n';
    return s_string.str();
}

void draw_main_page() {
    std::cout << "1. Добавить трубу\n" <<
                 "2. Добавить КС\n" <<
                 "3. Просмотр всех объектов\n" <<
                 "4. Редактировать трубу\n" <<
                 "5. Редактировать КС\n" <<
                 "6. Сохранить\n" <<
                 "7. Загрузить\n" <<
                 "0. Выход\n";
}

int get_pos_int(std::string out_str) {
    int res;

    for (;;) {
        std::cout << out_str;

        if(std::cin >> res && res >= 0) {
            return res;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод\n";
        }
    }
}

float get_pos_float(std::string out_str) {
    float res = -1;

    for (;;) {

        std::cout << out_str;
        if(std::cin >> res && res >= 0) {
            return res;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректные данные\n";
        }
    }
}

std::string get_string(std::string out_str) {
    std::string res;

    for (;;) {
        std::cout << "Введите имя: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, res);
        if (!res.empty()) {
            return res;
        }
    }
}

void add_pipe(Pipe & r_pipe) {

    r_pipe.name = get_string("Введите имя: ");

    r_pipe.length = get_pos_float("Введите длину: ");
    r_pipe.diameter = get_pos_float("Введите диаметр: ");

    std::cout << "Труба в ремонте (Y/n)";
    char tmp_inp;
    std::cin >> tmp_inp;
    r_pipe.is_reparing = (tmp_inp == 'y' || tmp_inp == 'Y');
}

void add_c_station(C_station & r_station) {

    r_station.name = get_string("Введите имя: ");

    r_station.workshops = get_pos_int("Введите количество цехов: ");

    for(r_station.working_workshops = get_pos_int("Введите количество цехов в работе: ");
            r_station.working_workshops > r_station.workshops;);

    r_station.efficiency = get_pos_float("Введите эффективность: ");
}

void print_all(Pipe &r_pipe, C_station &r_station) {

    if (r_pipe.name.empty()) {
        std::cout << "Труба не создана\n";
    } else {
        std::cout << string_pipe(r_pipe) << '\n';
    }

    if (r_station.name.empty()) {
        std::cout << "Станция не создана\n";
    } else {
        std::cout << string_c_station(r_station) << '\n';
    }
}

void edit_pipe(Pipe &ptr_pipe) {

    std::cout << "Труба в ремонте? (Y/n): ";
    char inp_tmp;
    std::cin >> inp_tmp;
    
    ptr_pipe.is_reparing = (inp_tmp == 'y' || inp_tmp == 'Y');

}

void edit_c_station(C_station & station) {
    station.working_workshops = get_pos_int("Введите количество цехов в работе: ");
}

void save_to_file(std::string file_name, Pipe & r_pipe, C_station & r_station) {
    std::ofstream file;
    file.open(file_name);

    file << r_pipe.name << ' ' <<
            r_pipe.length << ' ' <<
            r_pipe.diameter << ' ' <<
            r_pipe.is_reparing << ' ';

    file << r_station.name << ' ' <<
            r_station.workshops << ' ' <<
            r_station.working_workshops << ' ' <<
            r_station.efficiency << ' ';

    file.close();
}

void load_from_file(std::string file_name, Pipe & r_pipe, C_station & r_station) {
    std::ifstream file;
    file.open(file_name);

    file >> r_pipe.name >> r_pipe.length >> r_pipe.diameter >> r_pipe.is_reparing
         >> r_station.name >> r_station.workshops >> r_station.working_workshops
            >> r_station.efficiency;

    file.close();
}

int main() {
    Pipe pipe_main {
        .name = "",
        .length = 0,
        .is_reparing = false,
    };
    C_station c_station_main {
        .name = "",
        .workshops = 0,
        .working_workshops = 0,
        .efficiency = 0,
    };
    
    draw_main_page();

    char input;
    while (std::cin >> input) {
        switch (input) {
            case '1': //Добавить трубу
                add_pipe(pipe_main);
                break;
            case '2': //Добавить КС
                add_c_station(c_station_main);
                break;
            case '3': //Просмотр всех объектов
                print_all(pipe_main, c_station_main);
                break;
            case '4': //Редактировать трубу
                edit_pipe(pipe_main);
                break;
            case '5': //Редактировать КС
                edit_c_station(c_station_main);
                break;
            case '6':
                save_to_file("save.txt",pipe_main,c_station_main);
                break;
            case '7': 
                load_from_file("save.txt",pipe_main,c_station_main);
                break;
            case '0': 
                return 0;
            default:
                std::cout << "Введите корректное значение\n";
        }
        draw_main_page();
    }
}
