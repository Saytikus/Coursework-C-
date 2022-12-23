#include <User.h>

int Interface::GetReference() { cout << interface_reference_ << endl; return 0;}

string Interface::GetServerAddress() { return server_address_; }
string Interface::GetServerPort() { return server_port_; }
string Interface::GetInputFile() { return input_data_file_; }
string Interface::GetOutputFile() { return output_data_file_; }
string Interface::GetAutFile() { return aut_data_file_; }

int Interface::ReceiveArguments(int argc, char* argv[]) {
    if (argc == 1) {
        GetReference();
        exit(0);
    }
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
                check = optarg;
                if (check.find('-') != -1) {
                    cerr << "Invalid argument in operation: serveraddress" << endl;
                    exit(1);
                }
                server_address_ = check;
                break;
            
            case '1':
                check = optarg;
                if (check.find('-') != -1) {
                    cerr << "Invalid argument in operation: serverport" << endl;
                    exit(1);
                }
                server_port_ = check;
                break;
                
            case '2':
                check = optarg;
                if (check.find('-') != -1) {
                    cerr << "Invalid argument in operation: inputfile" << endl;
                    exit(1);
                }
                input_data_file_ = check;
                break;
            
            case '3':
                check = optarg;
                if (check.find('-') != -1) {
                    cerr << "Invalid argument in operation: outputfile" << endl;
                    exit(1);
                }
                output_data_file_ = check;
                
            case '4':
                check = optarg;
                if (check.find('-') != -1) {
                    cerr << "Invalid argument in operation: autfile" << endl;
                    exit(1);
                }
                aut_data_file_ = check;
        }
        if (server_address_ == "")
            throw ErrorHandler("No server address (no call function --server_address with start programm)", "server_address_", "ReceiveArguments()");
        //if (input_data_file_ == "")
            //throw ErrorHandler("No input file (no call function --input_file with start programm)", "input_file_", "ReceiveArguments()");
        //if (output_data_file_ == "")
            //throw ErrorHandler("No output file (no call function --output_file with start programm)", "output_file_", "ReceiveArguments()");
    }
    cout << "\n" << "address: " << server_address_ << "\nport: " << server_port_ << "\ninputfile: " << input_data_file_ << "\noutputfile: " << output_data_file_ << "\nautfile: " << aut_data_file_ << "\n\n";
    return 0;
}