static bool is_match(const std::string& text, const std::string& pattern)
{
    // FIXME TODO use actual (posix?) regex, boost regex, regex++ or whatnot
    return std::string::npos != text.find(pattern);
}


int main(int argc, const char* argv[])
{
    switch(argc)
    {
        case 0: case 1:
            std::cerr << "specify the pattern" << std::endl;
            return 254;
        case 2:
            break;
        default:
            std::cerr << "not implemented" << std::endl;
            return 255;
    }
    const std::string pattern(argv[1]);

    std::string line;
    while (std::getline(std::cin, line))
    {
        if (is_match(line, argv[1]))
            std::cout << line << std::endl;
    }

    return 0;
}