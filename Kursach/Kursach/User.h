#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <limits>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cryptopp/cryptlib.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h>
#include <cryptopp/hex.h>
#include <getopt.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <boost/algorithm/string.hpp>
#include <string>
#include <filesystem>
using namespace std;
using namespace CryptoPP;
using namespace std::filesystem;

class Interface {
    string interface_reference_ = "Потом напишу справку";
    string server_address_, server_port_ = "33333", input_data_file_, output_data_file_, aut_data_file_ = "/home/stud/test/.config/vclient.conf";
public:
    int GetReference();
    int ReceiveArguments(int argc, char* argv[]);
    string GetServerAddress();
    string GetServerPort();
    string GetInputFile();
    string GetOutputFile();
    string GetAutFile();
    
    // Блок методов, которые нужно перенести в private
    int CheckServerAddress(string server_address);
    int CheckServerPort(string server_port);
    int CheckInputFile(string input_data_file);
    int CheckOutputFile(string output_data_file);
    int CheckAutFile(string aut_data_file);
    bool isNumber(const string str);
};



template <typename T>
class ErrorHandler {
    string what_error_, what_arg_, what_func_;
    const T arg_value_;
public:
    explicit ErrorHandler<T>(string what_error, string what_arg, const T& arg_value, string what_func) :
    what_error_{ what_error + '\n' }, what_arg_{ what_arg }, arg_value_ { string(arg_value) + '\n'}, what_func_{ what_func + '\n'} { }
    explicit ErrorHandler<T>(string what_error) :
    what_error_{ what_error } { }
    string GetError() { return what_error_; }
    string GetArg() { return what_arg_; }
    string GetFunc() { return what_func_; }
    T GetArgValue() { return arg_value_; }
    friend ostream& operator<<(ostream& os, ErrorHandler& er) {
        return os << er.GetError() << er.GetArg() << er.GetArgValue() << er.GetFunc();
    }
};



class User {
    string server_address_, server_port_, input_data_file_, output_data_file_, aut_data_file_;
    string user_id_, user_password_;
    string user_SALT_, user_HASH_;
    string vector_number_b_;
    string vector_size_b_;
    vector<double> vector_b_;
    string calculation_number_b_;
    string calculation_result_b_;
public:
    User() = delete;
    User(string server_address, string server_port, string input_data_file, string output_data_file, string aut_data_file);
    string GetInputFile();
    string GetOutputFile();
    string GetAutFile();
    string GetServerAddress();
    string GetServerPort();
    string GetId();
    string GetPassword();
    string GetSALT();
    string GetHASH();
    string GetVectorNumberB();
    string GetVectorSizeB();
    vector<double> GetVectorB();
    string GetCalcNumberB();
    string GetCalcResultB();
    int SetIdPassword(vector<string> aut_data);
    int SetSALT(string SALT);
    int SetHASH(string HASH);
    int SetVectorNumberB(string vector_number_b);
    int SetVectorB(vector<double> vector_b);
    int SetCalcNumberB(string calculation_number_b);
    int SetCalcResultB(string calculation_result_b);
    int NapisatVector();  // ВНИМАНИЕ!!! Тестовый метод
};



class UserHandler {
public:
    string GetVectorNumberB(string input_data_file);
    vector <double> GetVectorB(string input_data_file, int string_number);
    vector<string>GetAutData(string aut_data_file);
    string GetHashFromPassword(string Salt, string user_password);
    string DecToBinInt(int number);
    string DecToBinFloat(double n);
    int BinToDecInt(int value);
    int RecordCalcNumber(uint32_t calculations_number, string output_data_file);
    int RecordCalcResult(float calculation_result, string output_data_file);
};



class TCPclient {
    string server_address_, server_port_;
    struct sockaddr_in {
        short sin_family;
        unsigned short sin_port;
        struct in_addr sin_addr;
        char sin_zero[8];
    };
    struct in_addr {
        unsigned long s_addr;
    };
    sockaddr_in * self_addr_;
    sockaddr_in * server_addr_;
    int tcp_socket_;
    int required_connection_;
    
public:
    TCPclient() = delete;
    TCPclient(User user);
    string GetServerAddress();
    string GetServerPort();
    int Connection();
    int SendAutMsg(string aut_msg);
    int SendVectorNumberB(string vector_number_b);
    int SendVectorSizeB(string vector_size_b);
    int SendVectorB(vector<double> vector_b);
    string ReceiveAndGetResponce();
    string ReceiveCalcNumberB();
    string ReceiveCalcResultB();
    int CloseConnection();
};



class TEST {
    vector <double> test_vector_;
public:
    int SetTestVector(vector <double> test_vector);
    int NapisatVector();
    double GetCalcResult();
    unsigned BinToDec(unsigned Value);
};