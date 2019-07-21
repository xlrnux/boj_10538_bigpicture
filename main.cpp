#include <iostream>
#include <cstdio>

#define NMAX 2000
#define MMAX 2000
#define NSZ 2048
#define MSZ 2048
//#define RHASH
using namespace std;

template<typename T>
class vector{
private:
    T DATA[100];
    int _size;
public:
    vector() : _size(0){}
    void clear(){
        _size = 0;
    }
    void push_back(const T& val){
        DATA[_size++] = val;
    }
    int size() const {
        return _size;
    }
    T&operator [] (const int& pos){
        return DATA[pos];
    }
    T operator [] (const int& pos) const{
        return DATA[pos];
    }
};

unsigned int mod[7] = {1,2,4,8,16,32,64};
int map[NSZ][MSZ];
unsigned long Small[7][NSZ][MSZ]; // Small[0] 은 걸작 맵과 같다
unsigned long Big[7][NSZ][MSZ]; // Big[0] 은 큰그림 맵과 같다
unsigned long _Hash[7] = {0lu,};
int conv['x'+2] = {0,};
int N,M;
int sN, sM;
vector<int> uParts[2]; // unique
vector<int> Parts[2];

template<typename T>
void getParts(T Size, int dep, const char& _idx){
    int idx = _idx == 'n' ? 0 : 1;
    if(dep == -1 || Size == 0) return;
    if(Size / mod[dep] == 0) getParts(Size, dep-1, _idx);
    else{
        uParts[idx].push_back(dep);
        for(int i = 0; i < (Size/mod[dep]); i++) Parts[idx].push_back(dep);
        getParts(Size%mod[dep], dep-1, _idx);
    }
}

void init(){
    uParts[0].clear();
    uParts[1].clear();
    Parts[0].clear();
    Parts[1].clear();
    for(int i = 0; i < 7; i++){
        _Hash[i] = 0lu;
    }
}
int main() {
    int TC = 1;
    freopen("input.txt","r",stdin); cin >> TC;
    ios::sync_with_stdio(false), cin.tie(0);
    conv['o'] = 1;

    for(int tc = 1; tc <= TC; tc++){
        cin >> sN >> sM >> N >> M;
        init();
        getParts(sN, 6, 'n');
        getParts(sM, 6, 'm');

        // 작은그림 입력
        for(int n = 0; n < sN; n++){
            unsigned long _hash = 0lu;
            for(int m = 0; m < sM; m++){
                cin >> Small[n][m][0];
                for(int i = 0; i < 2; i++){ // n==0, m==1
                    for(int j = 0; j < uParts[i].size(); j++){
                        if()
                    }
                }

            }
        }


        // 큰그림 입력
        for(int n = 0; n < sN; n++){
            for(int m = 0; m < sM; m++){

            }

            for(int m = sM; m < M; m++){

            }

        }

        for(int n = sN; n < N; n++){

        }

        for(int i = 0; i < uParts[0].size(); i++){
            cout << mod[uParts[0][i]] << " ";
        }cout << "\n";
        for(int i = 0; i < Parts[0].size(); i++){
            cout << mod[Parts[0][i]] << " ";
        }cout << "\n";
        for(int i = 0; i < uParts[1].size(); i++){
            cout << mod[uParts[1][i]] << " ";
        }cout << "\n";
        for(int i = 0; i < Parts[1].size(); i++){
            cout << mod[Parts[1][i]] << " ";
        }cout << "\n";
    }

    return 0;
}