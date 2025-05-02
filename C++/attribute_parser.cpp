// Problem: Attribute Parser
// Link: https://www.hackerrank.com/challenges/attribute-parser/problem
// Language: C++
// Difficulty: Medium

#include <iostream>
#include <map>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    cin.ignore();  // To handle the newline character after integers

    // Data structure to store tag attributes
    map<string, map<string, string>> tagMap;
    stack<string> tagStack;  // Stack to track the current tag hierarchy

    // Reading and processing the HRML lines
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);

        if (line.substr(0, 2) == "</") {
            // Closing tag, pop from stack
            tagStack.pop();
        } else {
            // Parse opening tag
            stringstream ss(line);
            string tag, attr, eq, val;
            ss >> tag;

            tag = tag.substr(1);  // Remove '<' character from tag name
            if (tag.back() == '>') tag.pop_back();  // Remove '>' if it exists

            // Construct the full tag path considering nesting
            string currentPath = tagStack.empty() ? tag : tagStack.top() + "." + tag;
            tagStack.push(currentPath);

            // Parse attributes of the tag
            while (ss >> attr) {
                ss >> eq >> val;  // Skip '=' and extract the value

                // Remove trailing '>' if it's part of the value
                if (val.back() == '>') val.pop_back();
                // Remove quotes around the attribute value
                if (val.front() == '"' && val.back() == '"') {
                    val = val.substr(1, val.size() - 2);
                }

                // Store the attribute and its value
                tagMap[currentPath][attr] = val;
            }
        }
    }

    // Handling queries
    for (int i = 0; i < q; ++i) {
        string query;
        getline(cin, query);

        // Split query into tag path and attribute
        size_t pos = query.find('~');
        string path = query.substr(0, pos);
        string attr = query.substr(pos + 1);

        // Check if the tag path and attribute exist in the map
        if (tagMap.count(path) && tagMap[path].count(attr)) {
            cout << tagMap[path][attr] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}
