#include "data_collector.h"

DataCollector* DataCollector::data_collector = nullptr;

DataCollector* DataCollector::GetInstance(std::string input_file_path) {
    if(data_collector == nullptr) {
        data_collector = new DataCollector(input_file_path);
    }
    return data_collector;
}

DataCollector::DataCollector(std::string input_file_path) {
    out_file = fopen(input_file_path.c_str(), "w");
    fprintf(out_file, "Ent-Type,Pos-X,Pos-Y,Pos-Z,Speed,Dir-X,Dir-Y,Dir-Z\n");
}

DataCollector::~DataCollector() {
    fclose(out_file);
    delete data_collector;
}

void DataCollector::InputData(std::string data) {
    fprintf(out_file, data.c_str());
}