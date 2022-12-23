#include <User.h>

int main(int argc, char* argv[]) {
    try {
        Interface interface; // Блок интерфейса(разбор ком.строки)
        interface.ReceiveArguments(argc, argv); //
        
        User user(interface.GetServerAddress(), interface.GetServerPort(), interface.GetInputFile(), interface.GetOutputFile(), interface.GetAutFile()); // Блок получения ID и пароля
        UserHandler handler;    //
        /*user.SetIdPassword(handler.GetAutData(user.GetAutFile()));  //
        cout << "User id: " << user.GetId() << "\t" << "User password: " << user.GetPassword() << endl; // Тест
        
        user.SetVectorNumberB(handler.GetVectorNumberB(user.GetInputFile()));   // Блок получения числа всех векторов, размера 1 вектора и его элементов(все в двоичном формате)
        cout << "Vector number in bin: " << user.GetVectorNumberB()  << "\tVector number in dec: " << handler.BinToDecInt(stoi(user.GetVectorNumberB())) << endl;    //Тест*/
        
        /*for(int i = 2; i < 2 + handler.BinToDecInt(stoi(user.GetVectorNumberB())); i++) {
            user.SetVectorB(handler.GetVectorB(user.GetInputFile(), i));   //
            cout << "Vector №" << i - 1 << " in bin:";
            user.NapisatVector(); // Тест
        }*/
        
        /*TCPclient client(user); // Блок авторизации
        client.Connection();    //
        client.SendAutMsg(user.GetId());    // Отправляем серверу айди
        user.SetSALT(client.ReceiveAndGetResponce()); // Принимаем от вектора соль
        user.SetHASH(handler.GetHashFromPassword(user.GetSALT(), user.GetPassword())); // Берем соль и пароль из юзера, создаем из них хэш в обработчике и засовываем его в юзера
        client.SendAutMsg(user.GetHASH());  // Отправляем серверу хэш
        client.ReceiveAndGetResponce(); // Принимаем от сервера ответ
        
        //Блок передачи векторов серверу и получения результатов вычислений
        client.SendVectorNumberB(user.GetVectorNumberB()); // Отправляем количество векторов
        
        for(int i = 2; i < 2 + handler.BinToDecInt(stoi(user.GetVectorNumberB())); i++) { // Цикл передачи серверу размера вектора и самого вектора
            user.SetVectorB(handler.GetVectorB(user.GetInputFile(), i));   
            //cout << "Vector №" << i - 1 << " in bin:"; // Тест1
            //user.NapisatVector(); // Тест2
            client.SendVectorSizeB(user.GetVectorSizeB()); // Передаем серверу размер вектора
            client.SendVectorB(user.GetVectorB()); // Передаем серверу вектор
        }
        client.CloseConnection();   */
        
        // Блок передачи векторов на сервер и получения результатов

        //TEST test;
        //cout << handler.GetVectorsNumberB("/home/stud/test/test1") << endl;
        //test.SetTestVector(handler.GetVectorB("/home/stud/test/test1"));
        //test.NapisatVector();
        //cout << test.GetCalcResult() << endl;
        //cout << handler.GetHashFromPassword(Salt, user.GetPassword()) << endl;
        //return 0;
        /*handler.RecordCalcNumber(6, "/home/stud/test/test_output_file");
        for(int i = 0; i<6; i++) {
            handler.RecordCalcResult(12.5, "/home/stud/test/test_output_file");
        }*/
    }
    catch (ErrorHandler<string>& eh) {
        cout << eh << endl;
        return 1;
    }
}