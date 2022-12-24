#include <User.h>

uint32_t UserHandler::GetVectorNumber(string input_data_file) {
        uint32_t vector_number;
        ifstream file(input_data_file);
        if (file.is_open()) {
            string s;
            getline(file, s);
            vector_number = stoi(s);
            file.close();
        }
        return vector_number;
}
vector <float> UserHandler::GetVector(string input_data_file, int string_number) {
        if (string_number < 2) {
            cerr << "String_number error" << endl;// Блок обработки ошибок
            exit(1);
        }
        vector <float> vs;
        ifstream file(input_data_file);
        if (file.is_open()) {
            for(int i = 1; i < string_number; i++) {
                string garbage;
                getline(file, garbage);
            }
            string s;
            getline(file, s);
            istringstream is(s);
            float word;
            while (is >> word) {
                vs.push_back(word);
            }
            file.close();
        }
        return vs;
}

vector <string>UserHandler::GetAutData(string aut_data_file) {
    vector <string> aut_data;
    string str;
    char delimiter = ' ';
    ifstream file(aut_data_file);
    if (file.is_open()) {
        getline(file, str, delimiter);
        aut_data.push_back(str);
        
        getline(file, str, delimiter);
        str.resize(str.size()-1);
        aut_data.push_back(str);
    }
    return aut_data;
}

string UserHandler::GetHashFromPassword(string Salt, string user_password) {
    string result,Hash, salted_password = Salt + user_password;
    HexEncoder encoder(new StringSink(result));
    Weak::MD5 md5;
    md5.Update((const byte*)&salted_password[0], salted_password.size());
    Hash.resize(md5.DigestSize());
    md5.Final((byte*)&Hash[0]);
    StringSource(Hash, true, new Redirector(encoder));
    return result;
}

/*string UserHandler::DecToBinInt(int number) {
        int temp;
        string str;
        for (temp = 32768; temp > 0; temp = temp / 2) {
            if (temp & number)
                str += "1";
            else
                str += "0";
        }
        return str;
}
string UserHandler::DecToBinFloat(double n) {
        bool neg = n < 0;
        if (neg) n = -n;
        string s = "";
        int d = (int)n;
        if (d)
            for (; d; d /= 2)
                s = char('0' + d % 2) + s;
        else
            s = "0";
        double f = n - (int)n;
        if (f) {
            s += ".";
            for (int i = 10; f && i; i--) {
                f *= 2;
                s += char((int)f + '0');
                f -= (int)f;
            }
        }
        if (neg) s = "-" + s;
        return s;
}

int UserHandler::BinToDecInt(int value) {
        int result = 0;
        for (int i = 1; value; value /= 10, i *= 2) {
            result += i * (value % 10);
        }
        return result;
}*/

int UserHandler::RecordCalcNumber(uint32_t calculations_number, string output_data_file) {
    ifstream check_file(output_data_file);
    if (!check_file.is_open()) {
        // Блок обработки ошибок
    }
    check_file.close();
    ofstream file(output_data_file, ios::binary);
    file.write((char*)&calculations_number, sizeof(calculations_number));
    file.close();
    return 0;
}

int UserHandler::RecordCalcResult(float calculation_result, string output_data_file) {
    ifstream check_file(output_data_file);
    if (!check_file.is_open()) {
        // Блок обработки ошибок
    }
    check_file.close();
    ofstream file(output_data_file, ios::binary | ios::app);
    file.write((char*)&calculation_result, sizeof(calculation_result));
	cout << "Calculations result: " << calculation_result << " was record in file" << endl;
    file.close();
    return 0;
}