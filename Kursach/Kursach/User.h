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
#include <cryptopp/files.h>
#include <getopt.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <boost/algorithm/string.hpp>
#include <string>
#include <experimental/filesystem>
using namespace std;
using namespace CryptoPP;
namespace fs = std::experimental::filesystem::v1;

class Interface {
    string interface_reference_ = "Потом напишу справку";
    string server_address_, server_port_, input_data_file_, output_data_file_, aut_data_file_;
	int CheckServerAddress(string server_address);
    int CheckServerPort(string server_port);
    int CheckInputFile(string input_data_file);
    int CheckOutputFile(string output_data_file);
    int CheckAutFile(string aut_data_file);
    bool isNumber(const string str);
public:
    int GetReference();
    int ReceiveArguments(int argc, char* argv[]);
    string GetServerAddress();
    string GetServerPort();
    string GetInputFile();
    string GetOutputFile();
    string GetAutFile();
};



template <typename T>
class ErrorHandler {
    string what_error_, what_arg_, what_func_;
    const T arg_value_;
public:
    explicit ErrorHandler<T>(string what_error, string what_arg, const T& arg_value, string what_func) :
    what_error_{ what_error + '\n' }, what_arg_{ what_arg }, arg_value_ { string(arg_value) + '\n'}, what_func_{ what_func} { }
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
    string user_SALT_;
	string user_HASH_;
    uint32_t vector_number_;
    uint32_t vector_size_;
    vector<float> vector_;
    uint32_t calculation_number_;
    float calculation_result_;
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
    uint32_t GetVectorNumber();
    uint32_t GetVectorSize();
    vector<float> GetVector();
    uint32_t GetCalcNumber();
    float GetCalcResult();
    int SetIdPassword(vector<string> aut_data);
    int SetSALT(string SALT);
    int SetHASH(string HASH);
    int SetVectorNumber(uint32_t vector_number);
    int SetVector(vector<float> vector);
    int SetCalcNumber(uint32_t calculation_number);
    int SetCalcResult(float calculation_result);
};



class UserHandler {
public:
    uint32_t GetVectorNumber(string input_data_file);
    vector <float> GetVector(string input_data_file, int string_number);
    vector<string>GetAutData(string aut_data_file);
    string GetHashFromPassword(string Salt, string user_password);
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
    int SendVectorNumber(uint32_t vector_number);
    int SendVectorSize(uint32_t vector_size);
    int SendVector(vector<float> vectorvr);
    string ReceiveAndGetResponce();
    float ReceiveCalcResult();
    int CloseConnection();
};