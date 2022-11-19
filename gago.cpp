#include <iostream>
#include <vector>
#include <sstream>

std::vector<std::string> split(std::string text, char sep) {
    std::vector<std::string> vet;
    std::stringstream ss(text);
    std::string part;
    while(getline(ss, part, sep))
        vet.push_back(part);
    return vet;
    
}

bool is_vogal(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return true;
    return false;
}

std::string get_silaba(std::string text) {
    std::string silaba{};
    if((int) text.size() <= 3) return silaba;
    for(int i = 0; i < (int) text.size(); i++)
        if(is_vogal(text[i])) {
            silaba = text.substr(0, i + 1);
            break;
        }
    return silaba;
}

int main() {
    std::string line;
    getline(std::cin, line);
    auto palavras = split(line, ' ');
    for(auto elem : palavras) {
        std::string silaba = get_silaba(elem);
        elem = silaba + silaba + elem;
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}