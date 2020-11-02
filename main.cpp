#include <bits/stdc++.h>

using namespace std;

void fillRandom(vector<int> &cont, int n) {
    cont.insert(cont.end(), 1);
    for (int i = 0; i < n - 1; i++) {
        cont.insert(cont.end(), cont[i]+rand());
    }
}

void show(vector<int> &cont) {
    auto print = [](const int &n) { cout << " " << n; };
    for_each(cont.begin(), cont.end(), print);
    cout << "\n\n";
}

void stand(vector<int> &a, vector<int> &b, vector<int> &c){
    int start = clock();
    for (int i = 0; i < b.size(); ++i) {
        c.push_back(b[i]);
        c.push_back(a[i]);
    }
    sort(c.begin(), c.end());
    int endd = clock();
    cout<< "stand" << endl;
    show(c);
    cout << "stand = " << endd - start << endl;
    cout << "stand ID potoka = " << this_thread::get_id() << endl;
}

void vectoriz(vector<int> &a, vector<int> &b, vector<int> &c){
#pragma ivdep
    int start = clock();
    for (int i = 0; i < b.size(); ++i) {
        c.push_back(b[i]);
        c.push_back(a[i]);
    }
    sort(c.begin(), c.end());
    int endd = clock();
    cout<< "vectoriz" << endl;
    show(c);
    cout << "vectoriz = " << endd - start << endl;
    cout << "vectoriz ID potoka = " << this_thread::get_id() << endl;
}

void raspar(vector<int> &a, vector<int> &b, vector<int> &c){
    int start = clock();
    for (int i = 0; i < b.size(); ++i) {
        c.push_back(b[i]);
        c.push_back(a[i]);
    }
    sort(c.begin(), c.end());
    int endd = clock();
    cout<< "raspar" << endl;
    show(c);
    cout << "raspar = " << endd - start << endl;
    cout << "raspar ID potoka = " << this_thread::get_id() << endl;
}

int main() {
    int n = 5;
    vector<int> v1_ras, v1_st, v1_vec;
    vector<int> v2_ras, v2_st, v2_vec;
    vector<int> v_ras, v_stand, v_vec;

    //распараллеливание
    fillRandom(v1_ras, n);
    fillRandom(v2_ras, n);
    show(v1_ras);
    show(v2_ras);
    thread t(raspar, std::ref(v1_ras), std::ref(v2_ras), std::ref(v_ras));
    cout << endl;

    //стандарт
    fillRandom(v1_st, n);
    fillRandom(v2_st, n);
    show(v1_st);
    show(v2_st);
    stand(v1_st, v2_st, v_stand);
    cout << endl;

    //векторизация
    fillRandom(v1_vec, n);
    fillRandom(v2_vec, n);
    show(v1_vec);
    show(v2_st);
    vectoriz(v1_vec, v2_st, v_vec);
    cout << endl;

    t.join();

    return 0;
}