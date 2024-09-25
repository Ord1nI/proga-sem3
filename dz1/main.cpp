#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
struct Pipe{ std::string name;
    float length;
    float diameter;
    bool is_reparing;
};

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

std::string string_c_station(C_station & r_station) {
    std::stringstream s_string;
    s_string << "КС " << r_station.name << '\n' <<
                 "Количество цехов " << r_station.workshops << '\n' <<
                 "Количество цехов в работе " << r_station.working_workshops << '\n' <<
                 "эффективность " <<  r_station.efficiency << '\n';
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
        std::getline(std::cin>>std::ws, res);
        if (!res.empty()) {
            return res;
        }
    }
}
static bool sup_get_pipe_is_reparing() {
    char inp_tmp;
    std::cout << "Труба в ремонте? (Y/n): ";
    while (std::cin >> inp_tmp) {
        switch(std::tolower(inp_tmp)){
            case 'y':
                return true;
            case 'n':
                return false;
            default:
                std::cout << "Труба в ремонте? (Y/n): ";
        }
    }
}

void add_pipe(Pipe & r_pipe) {

    r_pipe.name = get_string("Введите имя: ");

    r_pipe.length = get_pos_float("Введите длину: ");
    r_pipe.diameter = get_pos_float("Введите диаметр: ");

    r_pipe.is_reparing = sup_get_pipe_is_reparing();
}

void add_c_station(C_station & r_station) {

    r_station.name = get_string("Введите имя: ");

    r_station.workshops = get_pos_int("Введите количество цехов: ");


    for(r_station.working_workshops = get_pos_int("Введите количество цехов в работе: ");
        r_station.working_workshops > r_station.workshops;
        r_station.working_workshops = get_pos_int("Введите количество цехов в работе: "));

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

void edit_pipe(Pipe &r_pipe) {
    if (r_pipe.name == "") {
        std::cout << "Труба не создана\n";
        return;
    }
    r_pipe.is_reparing = sup_get_pipe_is_reparing();
}

void edit_c_station(C_station & r_station) {
    if (r_station.name == "") {
        std::cout << "Станция не создана\n";
        return;
    }

    for(r_station.working_workshops = get_pos_int("Введите количество цехов в работе: ");
        r_station.working_workshops > r_station.workshops;
        r_station.working_workshops = get_pos_int("Введите количество цехов в работе: "));
}

void save_pipe(std::ofstream & file, Pipe & r_pipe) {
    file << "Pipe\n" <<
            r_pipe.name << '\n' <<
            r_pipe.length << '\n' <<
            r_pipe.diameter << '\n' <<
            r_pipe.is_reparing << '\n';
}

void save_station(std::ofstream & file, C_station & r_station) {
    file << "Station\n" <<
            r_station.name << '\n' <<
            r_station.workshops << '\n' <<
            r_station.working_workshops << '\n' <<
            r_station.efficiency << '\n';
}

void load_pipe(std::ifstream & file, Pipe & r_pipe) {
    std::getline(file>>std::ws, r_pipe.name,'\n');
    file >> r_pipe.length >> r_pipe.diameter >> r_pipe.is_reparing;
}

void load_station(std::ifstream & file, C_station & r_station) {
    std::getline(file>>std::ws, r_station.name, '\n');
    file >> r_station.workshops >> r_station.working_workshops
            >> r_station.efficiency;
}

void save_to_file(std::string file_name, Pipe & r_pipe, C_station & r_station) {
    std::ofstream file;

    file.open(file_name);

    if (!file.good()) {
        std::cout << "файл не создан\n";
        return;
    }

    if (r_pipe.name != "") {
        save_pipe(file, r_pipe);
    }
    if (r_station.name != "") {
        save_station(file, r_station);
    }

    file.close();
}

void load_from_file(std::string file_name, Pipe & r_pipe, C_station & r_station) {
    std::ifstream file;
    file.open(file_name);
    if (!file.good()) {
        std::cout << "Файл сохранения не существует\n";
        return;
    }
    if (file.peek() == EOF) {
        std::cout << "Файл пустой\n";
    }

    std::string type;
    while (file >> type){
        if (type == "Pipe") {
            load_pipe(file, r_pipe);
        }
        if (type == "Station") {
            load_station(file, r_station);
        }
    }
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
    

    int input;
    for(;;)  {
        draw_main_page();
        input = get_pos_int("");
        switch (input) {
            case 1: //Добавить трубу
                add_pipe(pipe_main);
                break;
            case 2: //Добавить КС
                add_c_station(c_station_main);
                break;
            case 3: //Просмотр всех объектов
                print_all(pipe_main, c_station_main);
                break;
            case 4: //Редактировать трубу
                edit_pipe(pipe_main);
                break;
            case 5: //Редактировать КС
                edit_c_station(c_station_main);
                break;
            case 6:
                save_to_file("save.txt",pipe_main,c_station_main);
                break;
            case 7: 
                load_from_file("save.txt",pipe_main,c_station_main);
                break;
            case 0: 
                return 0;
            default:
                std::cout << "Введите корректное значение\n";
        }
    }
}
