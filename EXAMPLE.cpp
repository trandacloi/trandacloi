// EXAMPLE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{

    string filename("Books_rating-1.csv");
    // Khai báo vector để lưu các dòng đọc được
    vector<string> lines;
    string line;

    //Mở file bằng ifstream
    ifstream input_file(filename);
    //Kiểm tra file 
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
            << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    //Đọc từng dòng trong
    while (getline(input_file, line, ' ')) {
        lines.push_back(line);   //Lưu từng dòng như một phần tử vào vector lines.
    }
    //Mở file bằng ofstream 
    ofstream ofs("Book_Id.txt");
    //Kiểm tra file
    if (!ofs) {
        cerr << "Error: file not opened." << endl;
        return 1;
    }
    //Xuất từng dòng từ lines và in ra màn hình
    for (const auto& i : lines)
       ofs << i ;

    ofs.close();

    input_file.close();
    return 0;
}