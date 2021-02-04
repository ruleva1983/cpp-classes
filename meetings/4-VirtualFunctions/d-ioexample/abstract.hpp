#include <string>
#include <sstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;
namespace pt = boost::property_tree;

class IOHandler{
protected:
    virtual void read(string filename) = 0;
    virtual void write(vector<string> keys,
                       vector<int> values) = 0;
    string filename;

};

class IOJson : public IOHandler{

public:
    void read(string filename){
        boost::property_tree::read_json(filename, root);
    }

    void write(vector<string> keys = {}, vector<int> values = {}){
        assert (keys.size() == values.size());
        if (keys.size() != 0){
             for(int i = 0 ; i < keys.size() ; ++i)
                 root.put(keys[i], values[i]);     
        }
        pt::write_json(cout, root);
    }

    int get_value(string key){
        return root.get<int>(key);
    }


private:
    boost::property_tree::ptree root;
};


class IOCSV : public IOHandler{
public:
    void read(string filename){

        std::ifstream infile(filename);
        std::string line;
        while (std::getline(infile, line)){
                std::istringstream iss(line);
                int value;
                string key;
                if (!(iss >> key >> value)) { break; } // error
                first_col.push_back(key);
                second_col.push_back(value);
        }
    }

    void write(vector<string> keys = {}, vector<int> values = {}){
    
        for (int i = 0 ; i < first_col.size() ; ++i)
            cout << first_col[i] << "    " << second_col[i] << endl;
        
    }
private:
    vector<string> first_col;
    vector<int> second_col;
 
};