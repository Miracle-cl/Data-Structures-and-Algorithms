#include <iostream>
#include <vector>
#include <string>
#include <map>

using std::string;
using std::vector;
using std::cin;
using std::map;

struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    map <int, string> contacts;
    map <int, string> :: iterator iter; // iterator
    for (size_t i = 0; i < queries.size(); ++i) {
        if (queries[i].type == "add") {
            contacts[queries[i].number] = queries[i].name; // insert
        }
        else if (queries[i].type == "del") {
            iter = contacts.find(queries[i].number); //  key in map or not
            if (iter != contacts.end()) // key in map
                contacts.erase(iter); // delete key
        }
        else {
            iter = contacts.find(queries[i].number);
            if (iter != contacts.end())
                result.push_back(contacts[queries[i].number]);
            else
                result.push_back("not found");
        }
    }

    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
