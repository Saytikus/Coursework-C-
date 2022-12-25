#include <UnitTest++/UnitTest++.h>
#include "/home/stud/C++Projects/Kursach!client/Kursach/Kursach/User.h"
#include "/home/stud/C++Projects/Kursach!client/Kursach/Kursach/Interface.cpp"
#include "/home/stud/C++Projects/Kursach!client/Kursach/Kursach/TCPclient.cpp"
#include "/home/stud/C++Projects/Kursach!client/Kursach/Kursach/User.cpp"
#include "/home/stud/C++Projects/Kursach!client/Kursach/Kursach/UserHandler.cpp"

SUITE(InterfaceTests) {
	Interface interface;
	TEST(UnknownOption) {
		char* argv[2] {"Kursach", "--self_address"};
		int argc = sizeof(argv)/sizeof(argv[0]);
		CHECK_THROW(interface.ReceiveArguments(argc, argv), ErrorHandler<string>);
	}
	TEST(OptionInServerAddress) {
		char* argv[3] {"Kursach", "--server_address", "--output_file"};
		int argc = sizeof(argv)/sizeof(argv[0]);
		CHECK_THROW(interface.ReceiveArguments(argc, argv), ErrorHandler<string>);
	}
	TEST(EmptyAddr) {
		char* argv[3] {"Kursach", "--server_address", ""};
		int argc = sizeof(argv)/sizeof(argv[0]);
		CHECK_THROW(interface.ReceiveArguments(argc, argv), ErrorHandler<string>);
	}
	TEST(ErrorAddr) {
		char* argv[3] {"Kursach", "--server_address", "hey"};
		int argc = sizeof(argv)/sizeof(argv[0]);
		CHECK_THROW(interface.ReceiveArguments(argc, argv), ErrorHandler<string>);
	}
	TEST(ErrorDigitInAddr) {
		char* argv[3] {"Kursach", "--server_address", "f12.0.0.1"};
		int argc = sizeof(argv)/sizeof(argv[0]);
		CHECK_THROW(interface.ReceiveArguments(argc, argv), ErrorHandler<string>);
	}
	TEST(OptionInServerPort) {
		char* argv[3] {"Kursach", "--server_port", "--input_file"};
		int argc = sizeof(argv)/sizeof(argv[0]);
		CHECK_THROW(interface.ReceiveArguments(argc, argv), ErrorHandler<string>);
	}
	TEST(ErrorPort) {
		char* argv[3] {"Kursach", "--server_port", "noport"};
		int argc = sizeof(argv)/sizeof(argv[0]);
		CHECK_THROW(interface.ReceiveArguments(argc, argv), ErrorHandler<string>);
	}
	TEST(ErrorDigitInPort) {
		char* argv[3] {"Kursach", "--server_port", "333g3"};
		int argc = sizeof(argv)/sizeof(argv[0]);
		CHECK_THROW(interface.ReceiveArguments(argc, argv), ErrorHandler<string>);
	}
	TEST(OptionInInputFile) {
		char* argv[3] {"Kursach", "--input_file", "--server_port"};
		int argc = sizeof(argv)/sizeof(argv[0]);
		CHECK_THROW(interface.ReceiveArguments(argc, argv), ErrorHandler<string>);
	}
	TEST(NotRegularFileInInputFile) {
		char* argv[3] {"Kursach", "--input_file", "/home/stud"};
		int argc = sizeof(argv)/sizeof(argv[0]);
		CHECK_THROW(interface.ReceiveArguments(argc, argv), ErrorHandler<string>);
	}
	TEST(EmptyInputFile) {
		char* argv[3] {"Kursach", "--input_file", ""};
		int argc = sizeof(argv)/sizeof(argv[0]);
		CHECK_THROW(interface.ReceiveArguments(argc, argv), ErrorHandler<string>);
	}
	TEST(InvalidInputFile) {
		char* argv[3] {"Kursach", "--input_file", "privet"};
		int argc = sizeof(argv)/sizeof(argv[0]);
		CHECK_THROW(interface.ReceiveArguments(argc, argv), ErrorHandler<string>);
	}
	TEST(OptionInOutputFile) {
		char* argv[3] {"Kursach", "--output_file", "--aut_file"};
		int argc = sizeof(argv)/sizeof(argv[0]);
		CHECK_THROW(interface.ReceiveArguments(argc, argv), ErrorHandler<string>);
	}
	TEST(NotRegularFileInOutputFile) {
		char* argv[3] {"Kursach", "--output_file", "/home"};
		int argc = sizeof(argv)/sizeof(argv[0]);
		CHECK_THROW(interface.ReceiveArguments(argc, argv), ErrorHandler<string>);
	}
	TEST(EmptyOutputFile) {
		char* argv[3] {"Kursach", "--output_file", ""};
		int argc = sizeof(argv)/sizeof(argv[0]);
		CHECK_THROW(interface.ReceiveArguments(argc, argv), ErrorHandler<string>);
	}
	TEST(InvalidOutputFile) {
		char* argv[3] {"Kursach", "--output_file", "zpzvf1"};
		int argc = sizeof(argv)/sizeof(argv[0]);
		CHECK_THROW(interface.ReceiveArguments(argc, argv), ErrorHandler<string>);
	}
	TEST(OptionInAutFile) {
		char* argv[3] {"Kursach", "--aut_file", "--server_address"};
		int argc = sizeof(argv)/sizeof(argv[0]);
		CHECK_THROW(interface.ReceiveArguments(argc, argv), ErrorHandler<string>);
	}
	TEST(NotRegularFileInAutFile) {
		char* argv[3] {"Kursach", "--aut_file", "/home/stud/Desktop"};
		int argc = sizeof(argv)/sizeof(argv[0]);
		CHECK_THROW(interface.ReceiveArguments(argc, argv), ErrorHandler<string>);
	}
	TEST(InvalidAutFile) {
		char* argv[3] {"Kursach", "--aut_file", "zzzzzzzzzzzzzzzzzz"};
		int argc = sizeof(argv)/sizeof(argv[0]);
		CHECK_THROW(interface.ReceiveArguments(argc, argv), ErrorHandler<string>);
	}
}

SUITE() {
	
}
int main()
{
	return UnitTest::RunAllTests();
}