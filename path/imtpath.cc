#include "imtpath.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
//#include <vector>
#include <string>

//using namespace std;
void
imtPath::getpath() {

    std::ifstream file("/home/wenjie/car-sim/path/path.csv", ios::in); // 打开文件

    // 检查文件是否成功打开
    if (!file.is_open()) {
        std::cerr << "Could not open the file: " << std::endl;
    }

    std::string line; // 用于存储每一行
    while (std::getline(file, line)) { // 逐行读取文件
        std::istringstream ss(line); // 使用字符串流处理当前行
        std::string value;
        std::vector<float> row; // 用于存储当前行的数据

        while (std::getline(ss, value, ',')) { // 以逗号为分隔符读取数据
            try {
                row.push_back(std::stof(value)); // 将字符串转换为float并存储
            } catch (const std::invalid_argument&) {
                std::cerr << "Invalid number format: " << value << std::endl;
                row.push_back(0.0f); // 处理无效的数字格式
            }
        }

        if (!row.empty()) {
            data.push_back(row); // 将当前行存入数据
        }
    }

    file.close(); // 关闭文件
}


void
imtPath::printpath() {

	ofstream f;

	f.open("path.txt");

	for(int i = 0; i < data.size(); i++) {
		pp.ptfile(data[i][0], data[i][1], data[i][2], f); 
	}
}
