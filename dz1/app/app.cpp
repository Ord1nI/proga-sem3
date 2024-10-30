#include "./app.h"
#include <iostream>
#include "../utils/utils.h"

App::App() {
    this->pipeline = Pipeline();
    this->factory = Factory();
}

void App::show_main_page() {
    std::cout << "1. Pipe operations\n" <<
                 "2. Station operations\n" <<
                 "3. Show all objects\n" <<
                 "4. Save\n" <<
                 "5. Load\n" <<
                 "0. Exit\n";
}

void App::run() {
    int input;
    for(;;)  {
        show_main_page();
        input = get_pos_number<int>("");
        switch (input) {
            case 1: //Операции с трубами
                pipe_operation();
                break;
            case 2: //Операции со станциями
                c_station_operation();
                break;
            case 3: //Просмотр всех объектов
                print_all();
                break;
            case 4:
                save_to_file();
                break;
            case 5: 
                load_from_file();
                break;
            case 0: 
                return;
            default:
                std::cout << "Введите корректное значение\n";
        }
    }
}

void App::print_all() {
    std::cout << "----Pipes-----\n" 
              << pipeline.string_pipelines();
    std::cout << "----Stations----\n"
              << factory.string_factory();
};

void App::save_to_file() {
    std::string file_name = get_string("Введите файл сохранения: ");
    std::ofstream file(file_name);
    if (!file.good()) {
        // ERR("Error while saving ","File ", _SAVE_FILE_, " doesn't exits");

        std::cout << "File doesn't exits\n";
        return;
    }
    pipeline.save(file);
    factory.save(file);

    file.close();
}

void App::load_from_file() {
    std::string file_name = get_string("Введите файл сохранения: ");
    std::ifstream file(file_name);

    if (!file.good()) {
        // ERR("Error while loading ","File ", _SAVE_FILE_, " doesn't exits");

        std::cout << "File doesn't exitst\n";
        return;
    }
    if (file.peek() == EOF) {
        std::cout << "File is empty\n";
    }

    std::string type;
    while (file >> type){
        if (type == "PIPELINE") {
            pipeline.load(file);
        }
        if (type == "FACTORY") {
            factory.load(file);
        }
    }

    file.close();
}
