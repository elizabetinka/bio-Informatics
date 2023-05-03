#include <iostream>
#include <vector>

std::vector<int>chetU{2,6,14};
std::vector<int>NechetU{5,13,19};
std::vector<int>chetA{4,12,18};
std::vector<int>NechetA{3,7,15};

std::vector<int>chetC{0,8};
std::vector<int>NechetC{11,17};
std::vector<int>chetG{10,16};
std::vector<int>NechetG{1,9};

int* a;

bool NextSet(int *a2, int n, int m)
{
    int k = m;
    for (int i = k - 1; i >= 0; --i)
        if (a[i] < n - k + i + 1)
        {
            ++a[i];
            for (int j = i + 1; j < k; ++j)
                a[j] = a[j - 1] + 1;
            return true;
        }
    return false;
}

uint64_t countE=0;
uint64_t countV=20;
std::vector<std::pair<int,int>> edges;

bool checkCnK(){
    std::vector<bool>used(20,false);
    bool flag=true;
    for (uint64_t i=0;i<10;++i){
        for (uint64_t j=i+1;j<10;++j){
            /*
                if (used[edges[a[i]].first]){
                    return false;
                }
                if (used[edges[a[i]].second]){
                    return false;
                }
                if (used[edges[a[j]].first]){
                    return false;
                }
                if (used[edges[a[j]].second]){
                    return false;
                }
                */
                used[edges[a[i]].first]= true;
                used[edges[a[i]].second]= true;
                used[edges[a[j]].first]= true;
                used[edges[a[j]].second]= true;

                if (edges[a[i]].first<edges[a[j]].first && edges[a[i]].second>edges[a[j]].first && edges[a[j]].second>edges[a[i]].second){
                    return false;
                }
                if (edges[a[j]].first < edges[a[i]].first && edges[a[j]].second>edges[a[i]].first && edges[a[i]].second>edges[a[j]].second){
                    return false;
                }
            }

        }

    for (uint64_t i=0;i<20;++i){
        if (!used[i]){
            return false;
        }
    }

    return true;
}

uint64_t GLOBAL_ANS=0;

int main() {
    std::vector<char> graph{'C', 'G', 'U', 'A', 'A', 'U', 'U', 'A', 'C', 'G', 'G', 'C', 'A', 'U', 'U', 'A', 'G', 'C',
                            'A', 'U'};


    for (uint64_t i = 0; i < countV; ++i) {
        if (graph[i] == 'C') {
            if (i % 2 == 0) {
                for (uint64_t j = 0; j < NechetG.size(); ++j) {
                    if (NechetG[j] > i) {
                        edges.push_back(std::make_pair(i, NechetG[j]));
                    }
                    countE++;
                }
            } else {
                for (uint64_t j = 0; j < chetG.size(); ++j) {
                    if (chetG[j] > i) {
                        edges.push_back(std::make_pair(i, chetG[j]));
                    }
                    countE++;
                }
            }

        } else if (graph[i] == 'G') {
            if (i % 2 == 0) {
                for (uint64_t j = 0; j < NechetC.size(); ++j) {
                    if (NechetC[j] > i) {
                        edges.push_back(std::make_pair(i, NechetC[j]));
                    }
                    countE++;
                }
            } else {
                for (uint64_t j = 0; j < chetC.size(); ++j) {
                    if (chetC[j] > i) {
                        edges.push_back(std::make_pair(i, chetC[j]));
                    }
                    countE++;
                }
            }

        } else if (graph[i] == 'A') {
            if (i % 2 == 0) {
                for (uint64_t j = 0; j < NechetU.size(); ++j) {
                    if (NechetU[j] > i) {
                        edges.push_back(std::make_pair(i, NechetU[j]));
                    }
                    countE++;
                }
            } else {
                for (uint64_t j = 0; j < chetU.size(); ++j) {
                    if (chetU[j] > i) {
                        edges.push_back(std::make_pair(i, chetU[j]));
                    }
                    countE++;
                }
            }

        } else if (graph[i] == 'U') {
            if (i % 2 == 0) {
                for (uint64_t j = 0; j < NechetA.size(); ++j) {
                    if (NechetA[j] > i) {
                        edges.push_back(std::make_pair(i, NechetA[j]));
                    }
                    countE++;
                }
            } else {
                for (uint64_t j = 0; j < chetA.size(); ++j) {
                    if (chetA[j] > i) {
                        edges.push_back(std::make_pair(i, chetA[j]));
                    }
                    countE++;
                }
            }

        }
    }
    countE = countE / 2;

    // первая перестановка
    a = new int[countV/2];
    for (int i = 0; i < countV/2; i++)
        a[i] = i;


    if (checkCnK()) {
        ++GLOBAL_ANS;
    }
    while (NextSet(a, countE-1, countV/2)){
        if (checkCnK()) {
            ++GLOBAL_ANS;
        }
}
    std::cout<<"Global ans: "<<GLOBAL_ANS;



    delete[] a;

}


