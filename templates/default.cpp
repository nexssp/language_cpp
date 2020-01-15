#include <iostream>
#include <string>
#include "rapidjson/document.h"
#include "rapidjson/pointer.h"
#include "rapidjson/stringbuffer.h"
#include <rapidjson/writer.h>

using namespace std;
using namespace rapidjson;

template <typename T>
string stringify(const T &o)
{
    StringBuffer sb;
    Writer<StringBuffer> writer(sb);
    o.Accept(writer);
    return sb.GetString();
}

int main()
{
    Document document;
    StringBuffer sb;
    // Document::AllocatorType &allocator = document.GetAllocator();

    for (std::string line; std::getline(std::cin, line);)
    {

        document.Parse<0>(line.c_str());
        //document["start"] = 1000000000;
        // FIXME: fix the printf to format string.. bow output is wrong __cplusplus_
        Pointer("/test").Set(document, "test");
        //document.AddMember("outputCPP", "Hello from C++! ");

        std::cout << stringify(document) << std::endl;
    }
    return 0;
}