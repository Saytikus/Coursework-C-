#include <User.h>

int Interface::GetReference() { cout << interface_reference_ << endl; return 0;}

string Interface::GetServerAddress() { return server_address_; }
string Interface::GetServerPort() { return server_port_; }
string Interface::GetInputFile() { return input_data_file_; }
string Interface::GetOutputFile() { return output_data_file_; }
string Interface::GetAutFile() { return aut_data_file_; }

int Interface::ReceiveArguments(int argc, char* argv[]) {
    if (argc == 1)
        throw ErrorHandler<string>("Error: programm call without operations");
    static struct option long_options[] = {
        {"reference", 0, 0, 'h'},
        {"server_address", 1, 0, '0'},
        {"server_port", 1, 0, '1'},
        {"input_file", 1, 0, '2'},
        {"output_file", 1, 0, '3'},
        {"aut_file", 1, 0, '4'},
        {0, 0, 0, 0}
    };
    int opt;
    while ((opt = getopt_long(argc, argv, ":h0:1::2:3:4::", long_options, NULL)) != -1)
    {
        string check;
        switch(opt) {
            case 'h':
                GetReference();
                exit(0);
                
            case '0':
                server_address_ = optarg;
                break;
            
            case '1':
                server_port_ = optarg;
                break;
                
            case '2':
                input_data_file_ = optarg;
                break;
            
            case '3':
                output_data_file_ = optarg;
                
            case '4':
                aut_data_file_ = optarg;
        }
    }
    CheckServerAddress(server_address_);
    CheckServerPort(server_port_);
    CheckInputFile(input_data_file_);
    CheckOutputFile(output_data_file_);
    CheckAutFile(aut_data_file_);
    cout << "\n" << "address: " << server_address_ << "\nport: " << server_port_ << "\ninputfile: " << input_data_file_ << "\noutputfile: " << output_data_file_ << "\nautfile: " << aut_data_file_ << "\n\n";
    return 0;
}

int Interface::CheckServerAddress(string server_address) {
    if(server_address.empty())
        throw ErrorHandler<string>("Empty server address", "server_address_ = ", server_address, "ReceiveArguments()::CheckServerAddress()");
    vector<string> server_address_vector;   // Создаем вектор для проверки каждого числа адреса
    boost::split(server_address_vector, server_address, boost::is_any_of(".")); // Разбиваем строку с адресом вектора на элементы
    if(server_address_vector.size() != 4)
        throw ErrorHandler<string>("Invalid server address", "server_address_ = ", server_address, "ReceiveArguments()::CheckServerAddress()");
    for(auto& server_address_digit : server_address_vector) {   // Блок проверки каждого числа в адресе
        if(!isNumber(server_address_digit) || stoi(server_address_digit) < 0 || stoi(server_address_digit) > 255) 
            throw ErrorHandler<string>("Invalid digit in server address", "server_address_digit = ", server_address_digit, "ReceiveArguments()::CheckServerAddress");
    }
    return 0;
}

int Interface::CheckServerPort(string server_port) {
    vector<string> server_port_vector;
    boost::split(server_port_vector, server_port, boost::is_any_of(""));
    for(auto& server_port_digit : server_port_vector) {
        if(!isNumber(server_port_digit))
            throw ErrorHandler<string>("Invalid digit in server port", "server_port_digit = ", server_port_digit, "ReceiveArguments()::CheckServerPort()");
    }
    if(stoi(server_port) < 1024 || stoi(server_port) > 65535)
        throw ErrorHandler<string>("Invalid server port", "server_port_ = ", server_port, "ReceiveArguments()::CheckServerPort()");
}

int Interface::CheckInputFile(string input_data_file) {
    if(input_data_file.empty())
        throw ErrorHandler<string>("Empty input file", "input_data_file_ = ", input_data_file, "ReceiveArguments()::CheckInputFile()");
    if(is_regular_file(input_data_file))
        throw ErrorHandler<string>("Input file is not regular", "input_data_file_ = ", input_data_file, "ReceiveArguments()::CheckInputFile()");
    ifstream check_file(input_data_file);
    if(check_file.is_open() == false)
        throw ErrorHandler<string>("Invalid input file", "input_data_file_ = ", input_data_file_, "ReceiveArguments()::CheckInputFile()");
}
int Interface::CheckOutputFile(string output_data_file) {
    if(output_data_file.empty())
        throw ErrorHandler<string>("Empty output file", "output_data_file_ = ", output_data_file, "ReceiveArguments()::CheckOutputFile()");
    if(is_regular_file(output_data_file))
        throw ErrorHandler<string>("Output file is not regular", "output_data_file_ = ", output_data_file, "ReceiveArguments()::CheckOutputFile()");
    ifstream check_file(output_data_file);
    if(check_file.is_open() == false)
        throw ErrorHandler<string>("Invalid output file", "input_data_file_ = ", output_data_file_, "ReceiveArguments()::CheckOutputFile()");
}
int Interface::CheckAutFile(string aut_data_file) {
    if(aut_data_file == output_data_file_)
        aut_data_file_ = "/home/stud/test/.config/vclient.conf";
    if(is_regular_file(aut_data_file))
        throw ErrorHandler<string>("Autentification file is not regular", "aut_data_file_ = ", aut_data_file, "ReceiveArguments()::CheckAutFile()");
    ifstream check_file(aut_data_file);
    if(check_file.is_open() == false)
        throw ErrorHandler<string>("Invalid autentification file", "aut_data_file_ = ", aut_data_file_, "ReceiveArguments()::CheckAutFile()");
}

bool Interface::isNumber(const string str) {
    return !str.empty() && (str.find_first_not_of("[0123456789]") == string::npos);
}