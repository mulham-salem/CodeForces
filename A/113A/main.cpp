#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string getType(const string& word) {
    if (word.size() >= 4 && word.substr(word.size() - 4) == "lios") return "adj_m";
    if (word.size() >= 5 && word.substr(word.size() - 5) == "liala") return "adj_f";
    if (word.size() >= 3 && word.substr(word.size() - 3) == "etr") return "noun_m";
    if (word.size() >= 4 && word.substr(word.size() - 4) == "etra") return "noun_f";
    if (word.size() >= 6 && word.substr(word.size() - 6) == "initis") return "verb_m";
    if (word.size() >= 6 && word.substr(word.size() - 6) == "inites") return "verb_f";
    return "invalid";
}

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<string> words;
    string w;
    while (ss >> w) words.push_back(w);

    // Check if all words are valid
    for (const string& word : words) {
        if (getType(word) == "invalid") {
            cout << "NO" << endl;
            return 0;
        }
    }

    // Single word case
    if (words.size() == 1) {
        cout << "YES" << endl;
        return 0;
    }

    // Multiple words: check gender and order
    string gender = "";
    bool seenNoun = false;
    bool valid = true;

    for (size_t i = 0; i < words.size(); i++) {
        string type = getType(words[i]);

        // Determine gender from first word
        if (i == 0) {
            if (type == "adj_m" || type == "noun_m" || type == "verb_m") gender = "m";
            else gender = "f";
        } else {
            // Check same gender
            string g = (type == "adj_m" || type == "noun_m" || type == "verb_m") ? "m" : "f";
            if (g != gender) {
                valid = false;
                break;
            }
        }

        // Check order
        if (type.find("adj") != string::npos) {
            if (seenNoun) { valid = false; break; }
        } else if (type.find("noun") != string::npos) {
            if (seenNoun) { valid = false; break; }
            seenNoun = true;
        } else if (type.find("verb") != string::npos) {
            if (!seenNoun) { valid = false; break; }
        }
    }

    if (valid && seenNoun) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
