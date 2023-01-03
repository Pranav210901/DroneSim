#ifndef DATA_COLLECTOR_H_
#define DATA_COLLECTOR_H_

//done by tran0607 - Ethan M Tran
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A class used to collect data for the simulation.
 * Uses a singleton pattern to allow only one instance of the class.
 * Outputs data about entities to a csv.
 */
class DataCollector{
public:
    /**
    * @brief Creates an instance of the class if one does not exist.
    * If an instance does exist, returns the existing instance.
    * Takes a string denoting the file path
    */
    static DataCollector* GetInstance(std::string input_file_path);

    /**
    * @brief Deconstructor for the Data Collector.
    * Closes the output file and deletes any existing instance.
    */
    ~DataCollector();

    /**
    * @brief Prints a line to the csv given input data.
    * Takes a string of input data.
    */
    void InputData(std::string data);

    /**
    * @brief Prevents cloning.
    */
    DataCollector(const DataCollector& other) = delete;
    /**
    * @brief Prevents assigning.
    */
    DataCollector& operator=(const DataCollector& other) = delete;

private:
    /**
    * @brief Constructor for the Data Collector.
    * Takes a string for the file path, opens the file as write,
    * and writes out a line to help organize.
    */
    DataCollector(std::string input_file_path);
    /**
    * @brief Static variable for a DataCollector instance.
    */
    static DataCollector* data_collector;
    /**
    * @brief File pointer for the output file.
    */
    FILE* out_file;
};

#endif