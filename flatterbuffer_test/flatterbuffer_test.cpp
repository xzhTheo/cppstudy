//#include "flatbuffers/flatbuffers.h"
#include "AdcBridge_generated.h"
#include <iostream> // C++ header file for printing
#include <fstream> // C++ header file for file access

using namespace com::nio::map::adas::flat;
int main()
{
    //read

    std::ifstream infile;
    infile.open("MapTbtInfo.pb.dat", std::ios::binary | std::ios::in);
    infile.seekg(0, std::ios::end);
    int length = infile.tellg();
    infile.seekg(0, std::ios::beg);
    char* data = new char[length];
    infile.read(data, length);
    infile.close();
    auto sdMapTable = GetSDMapTable(data);
    //auto monster = GetMonster(data);

    //write
    // flatbuffers::FlatBufferBuilder build_data;
    // int32_t requestId = 0;
    // auto sdmapinfo =
    // CreateSDMapTable(build_data,);

    return 0;
}