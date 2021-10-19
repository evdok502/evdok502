#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>

std::string Version()
{
	const std::string file_version = "VERSION";
	std::string line{};

	std::ifstream in( file_version.c_str() );
	if( ! in.is_open() )
	{
		std::cerr << "Error opening version" << std::endl;
		return {};
	}

	if( ! getline( in, line ) )
	{
		std::cerr << "Error reading version" << std::endl;
		return {};
	}

	in.close();

	return line;
}

void Help()
{
	std::cout << "wtime_control version: " << Version() << std::endl;
	std::cout << "-h (--help): helper" << std::endl;
	std::cout << "-v (--version): version" << std::endl;	
}

int main( int argc, char* argv[] )
{
	enum class modeMain{help, version, unknown} mode;

	int rez = 0;
	mode = modeMain::unknown;
	while( ( rez = getopt( argc, argv, "::h::v" ) ) != -1 )
	{
		switch( rez )
		{
			case 'h':
				mode = modeMain::help;
				break;
			case 'v':
				mode = modeMain::version;
				break;
		}
	};

	switch( mode )
	{
		case modeMain::help:
			Help();
			break;
		case modeMain::version:
			std::cout << Version() << std::endl;
			break;
		case modeMain::unknown:
			std::cout << std::endl;
			break;
	}

	return EXIT_SUCCESS;
}
