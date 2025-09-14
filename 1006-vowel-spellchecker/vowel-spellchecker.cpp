class Solution {
public:
    unordered_set<string>exactMatch;
    unordered_map<string,string>caseMap;
    unordered_map<string,string>vowelMap;
        string toLower(const string& s) {
        string res = s;
        for (char& c : res) {
            c = tolower(c);
        }
        return res;
    }

    string maskVowels(const string& s) {
        string res = s;
        for (char& c : res) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '*';
            }
        }
        return res;
    }

    string check(const string& query) {
        // Exact match
        if (exactMatch.count(query)) {
            return query;
        }

        // Case error match
        string lowerQuery = toLower(query);
        if (caseMap.count(lowerQuery)) {
            return caseMap[lowerQuery];
        }

        // Vowel error match
        string maskedQuery = maskVowels(lowerQuery);
        if (vowelMap.count(maskedQuery)) {
            return vowelMap[maskedQuery];
        }

        // 4. No match
        return "";
    } 
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        exactMatch.clear();
        caseMap.clear();
        vowelMap.clear();

        for(string word:wordlist){
            exactMatch.insert(word);
            string lowercase=toLower(word);

            if(caseMap.find(lowercase)==caseMap.end()){
                caseMap[lowercase]=word;
            }
            string vowelcase=maskVowels(lowercase);
            if(vowelMap.find(vowelcase)==vowelMap.end()){
                vowelMap[vowelcase]=word;
            }
        }
        vector<string>result;
        for(string query:queries){
            result.push_back(check(query));
        }
        return result;
         
    }
};