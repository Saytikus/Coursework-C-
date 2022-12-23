#include <User.h>

int TEST::SetTestVector(vector <double> test_vector) {
        test_vector_ = test_vector;
        return 0;
}
int TEST::NapisatVector() {
        for (double c : test_vector_)
            cout << setprecision(10) << c << " ";
        cout << endl;
        return 0;
}
double TEST::GetCalcResult() {
        double result = 0;
        for (double c : test_vector_)
            result += BinToDec(c);

        return result;
}
unsigned TEST::BinToDec(unsigned Value) {
        unsigned result = 0;
        for (unsigned i = 1; Value; Value /= 10, i *= 2) {
            result += i * (Value % 10);
        }
        return result;
}
