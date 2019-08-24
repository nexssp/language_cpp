// More here https://stackoverflow.com/questions/191757/how-to-concatenate-a-stdstring-and-an-int

std::string name = "John";
int age = 21;
std::string result;

// 1. with Boost
result = name + boost::lexical_cast<std::string>(age);

// 2. with C++11
result = name + std::to_string(age);

// 3. with FastFormat.Format
fastformat::fmt(result, "{0}{1}", name, age);

// 4. with FastFormat.Write
fastformat::write(result, name, age);

// 5. with the {fmt} library
result = fmt::format("{}{}", name, age);

// 6. with IOStreams
std::stringstream sstm;
sstm << name << age;
result = sstm.str();

// 7. with itoa
char numstr[21]; // enough to hold all numbers up to 64-bits
result = name + itoa(age, numstr, 10);

// 8. with sprintf
char numstr[21]; // enough to hold all numbers up to 64-bits
sprintf(numstr, "%d", age);
result = name + numstr;

// 9. with STLSoft's integer_to_string
char numstr[21]; // enough to hold all numbers up to 64-bits
result = name + stlsoft::integer_to_string(numstr, 21, age);

// 10. with STLSoft's winstl::int_to_string()
result = name + winstl::int_to_string(age);

// 11. With Poco NumberFormatter
result = name + Poco::NumberFormatter().format(age);