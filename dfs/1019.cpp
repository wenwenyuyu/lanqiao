#include<iostream>
#include<string>

using namespace std;

const int N = 25; 
int n, ans;
int used[N];
string word[N];

void dfs(string x){
    int l = x.size();
    ans = max(ans, l);
    // printf("in_string: %s\n", x.c_str());
    for(int i = 0; i < n; i++){
        if(used[i] >= 2) continue;
        string w = word[i];
        // printf("choose_string: %s\n", w.c_str());
        int slen = w.size();
        for(int j = 1; j < l && j < slen; j++){
            if(w.substr(0, j) == x.substr(l - j)){
                used[i]++;
                dfs(x + w.substr(j));
                used[i]--;
                break; //贪心
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> word[i];
    string start;
    cin >> start;
    dfs("*" + start);
    cout << ans - 1;
}