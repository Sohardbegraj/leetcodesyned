class Solution {
public:
    string addOperation(string s, int a) {
    for (int i = 1; i < s.size(); i += 2) {
        s[i] = ((s[i] - '0' + a) % 10) + '0';
    }
    return s;
}

string rotateOperation(string s, int b) {
    int n = s.size();
    b %= n;
    return s.substr(n - b) + s.substr(0, n - b);
}

string findLexSmallestString(string s, int a, int b) {
    queue<string> q;
    unordered_set<string> vis;
    string ans = s;

    q.push(s);
    vis.insert(s);

    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        ans = min(ans, curr);

        // Operation 1: Add 'a' to odd indices
        string added = addOperation(curr, a);
        if (!vis.count(added)) {
            vis.insert(added);
            q.push(added);
        }

        // Operation 2: Rotate by 'b'
        string rotated = rotateOperation(curr, b);
        if (!vis.count(rotated)) {
            vis.insert(rotated);
            q.push(rotated);
        }
    }

    return ans;
}
};