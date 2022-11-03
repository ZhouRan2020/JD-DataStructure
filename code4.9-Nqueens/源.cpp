#include<vector>
#include<string>
using namespace std;
class Solution {
private:
    vector<string> convert(vector<int> qpos) {
        vector<string> r;
        int n = qpos.size();
        for (auto q : qpos) {
            string s1;
            for (int i = 0; i < q; ++i) {
                s1 += '.';
            }
            string s2;
            for (int i = 0; i < n - 1 - q; ++i) {
                s2 += '.';
            }
            r.push_back(s1 + 'Q' + s2);
        }
        return r;
    }
    inline bool valid(int layer, const vector<int>& qpos) {
        //if(qpos[layer]>=qpos.size()||qpos[layer]<=-1)return false;
        for (int i = 0; i < layer; ++i) {
            if (qpos[layer] == qpos[i] || layer + qpos[layer] == i + qpos[i] || layer - qpos[layer] == i - qpos[i])
            {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n == 1) return vector<vector<string>>{ {"Q"}};
        vector<vector<string>> ans;
        vector<int> qpos(n, -1);
        int layer{ -1 };
        int c{ 0 };
        while (true) {
            //if(qpos[0]==n)return ans;
            if (layer != n - 1)
                ++layer;
           //+qpos[layer];
            ++qpos[layer];
            while (qpos[layer] == n) {
                qpos[layer] = -1;
                --layer;
                if (layer == -1 || c == 3)return ans;
                ++qpos[layer];
            }
            //forever attempt to set a queen at layer on position qpos[layer]
            while (!valid(layer, qpos)) {
                ++qpos[layer];
                while (qpos[layer] == n) {
                    qpos[layer] = -1;
                    --layer;
                    if (layer == -1 || c == 3)return ans;
                    ++qpos[layer];
                }
            }//here,qpos valid
            if (layer == n - 1) { ans.push_back(convert(qpos)); c++; }
        }
    }
};
int main() {
    Solution s;
    s.solveNQueens(5);
}