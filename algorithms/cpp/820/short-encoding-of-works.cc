#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie trie;
        for (auto& word : words)
            trie.insert(word);
        return trie.travel();
    }

private:
    static int const NODES_MAX = 1024;
    static int const ALPHA_MAX = 26;
    class Trie {
        int next[NODES_MAX][ALPHA_MAX];
        bool exist[NODES_MAX];
        int cnt;

    public:
        void insert(string& word) {
            int p = 0;
            for (int e = word.size()-1; e >= 0; e--) {
                int d = word[e]-'a';
                if (!next[p][d])
                    next[p][d] = ++cnt;
                p = next[p][d];
            }
            exist[p] = true;
        }

        int travel(int p=0, int l=0) {
            int sum = 0;
            bool end = true;
            for (int d = 0; d < ALPHA_MAX; d++) {
                if (next[p][d]) {
                    end = false;
                    sum += travel(next[p][d], l+1);
                }
            }
            if (end && exist[p])
                sum += l + 1;
            return sum;
        }
    };
};

int main()
{
    Solution slv;
    vector<string> words = {
        "t", "t",
    };
    std::cout << slv.minimumLengthEncoding(words) << std::endl;
    return 0;
}
