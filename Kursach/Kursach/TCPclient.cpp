#include <User.h>

TCPclient::TCPclient(User user)
{
    tcp_socket_ = socket(AF_INET, SOCK_STREAM, 0); 
    if (tcp_socket_ == -1) {
        cerr << "Socket error" << endl;
        exit(1);
    }

    self_addr_ = new (sockaddr_in);
    self_addr_->sin_family = AF_INET; 
    self_addr_->sin_port = htons(77777);
    self_addr_->sin_addr.s_addr = inet_addr("127.0.0.1");

    server_address_ = user.GetServerAddress();
    server_port_ = user.GetServerPort();
}

string TCPclient::GetServerAddress()
{
    return server_address_;
}

string TCPclient::GetServerPort()
{
    return server_port_;
}

int TCPclient::Connection() {
    unsigned int port = stoi(server_port_); // Преобразование порта из строки в целочисленное значение для sin_port
    char* server_address_char = new char[server_address_.length()]; // Блок преобразования строки с адресом в массив чар для sin_addr
    server_address_.copy(server_address_char, server_address_.length());    //
    server_address_char[server_address_.length()] = '\0';//
    
    server_addr_ = new (sockaddr_in);
    server_addr_->sin_family = AF_INET;
    server_addr_->sin_port = htons(port);
    server_addr_->sin_addr.s_addr = inet_addr(server_address_char);

    required_connection_ = connect(tcp_socket_,(const sockaddr*)server_addr_, sizeof(sockaddr_in));
    if (required_connection_ == -1) {
        cerr << "Invalid connection" << endl;
        exit(1);
    }
    return 0;
}

int TCPclient::SendAutMsg(string aut_msg)
{
    char msg_to_sent[aut_msg.length() + 1]; // Блок перевода аутентификационной строки в массив чар для отправки серверу
    aut_msg.copy(msg_to_sent, aut_msg.length() + 1);    //
    msg_to_sent[aut_msg.length()] = '\0';   //

    send(tcp_socket_, msg_to_sent, sizeof(msg_to_sent), 0);
    cout << "Message: " << msg_to_sent << " was sent to server" << endl;
    return 0;
}

int TCPclient::SendVectorNumberB(string vector_number_b) {
    char msg_vector_number_b[vector_number_b.length() + 1]; // Блок перевода строки содержащей число векторов в массив чар для отправки серверу
    vector_number_b.copy(msg_vector_number_b, vector_number_b.length() + 1);    //
    msg_vector_number_b[vector_number_b.length()] = '\0';   //
    
    send(tcp_socket_, msg_vector_number_b, sizeof(msg_vector_number_b), 0);
    cout << "Message vector number in bin: " << msg_vector_number_b << " was sent to server" << endl;
    return 0;
}

int TCPclient::SendVectorSizeB(string vector_size_b) {
    char msg_vector_size_b[vector_size_b.length() + 1]; // Блок перевода строки содержащей размер вектора в массив чар для отправки серверу
    vector_size_b.copy(msg_vector_size_b, vector_size_b.length() + 1);    //
    msg_vector_size_b[vector_size_b.length()] = '\0';   //
    
    send(tcp_socket_, msg_vector_size_b, sizeof(msg_vector_size_b), 0);
    cout << "Message vector size in bin: " << msg_vector_size_b << " was sent to server" << endl;
    
    return 0;
}
int TCPclient::SendVectorB(vector<double> vector_b) {
    //double* p = vector_b.data();
    //for(int i = 0; i < vector_b.size(); i++) {
    //    send(tcp_socket_, *p++, sizeof(p), 0);
    //}
    string str;
    for(int i = 0; i < vector_b.size(); i++) {
        str += to_string(vector_b[i]) + '_';
        if(i == vector_b.size() - 1)
            str += '\0';
    }
    str.erase(str.length() - 2, str.find('_'));
    char msg_vector_char_b[str.length() + 1];
    str.copy(msg_vector_char_b, str.length() + 1);
    msg_vector_char_b[str.length()] = '\0';
    for(auto& c : msg_vector_char_b)
        cout << c;
    cout << endl << "Size: " << sizeof(msg_vector_char_b);
    return 0;
}

string TCPclient::ReceiveAndGetResponce() {
    char received_msg[256];
    recv(tcp_socket_, received_msg, sizeof(received_msg), 0);
    string responce = string(received_msg);
    cout << "Responce from server: " << responce << endl;
    return responce;
}

string TCPclient::ReceiveCalcNumberB() { // Нужен uint32_t
    char received_calc_number_b[256];
    recv(tcp_socket_, received_calc_number_b, sizeof(received_calc_number_b), 0);
    string calc_number_b = string(received_calc_number_b);
    return calc_number_b;
}

string TCPclient::ReceiveCalcResultB() {
    char received_calc_result_b[256];
    recv(tcp_socket_, received_calc_result_b, sizeof(received_calc_result_b), 0);
    string calc_result_b = string(received_calc_result_b);
    return calc_result_b;
}

int TCPclient::CloseConnection() {
    close(tcp_socket_);
    return 0;
}