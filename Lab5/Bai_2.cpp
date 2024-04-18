#include<iostream>
using namespace std;
struct IntegerSet{
    int *element, size;
};

void creatSet(IntegerSet &set, int size){
    set.element = new int[size];
    set.size = size;
}

void inputSet(IntegerSet &set){
    for(int i = 0; i < set.size; i++)
        cin >> *(set.element + i);
}

void outputSet(IntegerSet set){
    for(int i = 0; i < set.size; i++)
        cout << *(set.element + i) << " ";
    cout << endl;
}

void unionSet(IntegerSet set1, IntegerSet set2){
    IntegerSet set3;
    creatSet(set3, set1.size + set2.size);
    for(int i = 0; i < set1.size; i++)
        *(set3.element + i) = *(set1.element + i);
    for(int i = 0; i < set2.size; i++)
        *(set3.element + set1.size + i) = *(set2.element + i);
    outputSet(set3);
    delete[] set3.element;
}

void intersectionSet(IntegerSet set1, IntegerSet set2){
    IntegerSet set3;
    creatSet(set3, set1.size);
    int count = 0;
    for(int i = 0; i < set1.size; i++){
        for(int j = 0; j < set2.size; j++){
            if(*(set1.element + i) == *(set2.element + j)){
                *(set3.element + count) = *(set1.element + i);
                count++;
            }
        }
    }
    outputSet(set3);
    delete[] set3.element;
}

void differenceSet(IntegerSet set1, IntegerSet set2){
    IntegerSet set3;
    creatSet(set3, set1.size);
    int count = 0;
    for(int i = 0; i < set1.size; i++){
        int check = 0;
        for(int j = 0; j < set2.size; j++){
            if(*(set1.element + i) == *(set2.element + j)){
                check = 1;
                break;
            }
        }
        if(check == 0){
            *(set3.element + count) = *(set1.element + i);
            count++;
        }
    }
    outputSet(set3);
    delete[] set3.element;
}

void subsetSet(IntegerSet set1, IntegerSet set2){
    int check = 0;
    for(int i = 0; i < set1.size; i++){
        int check2 = 0;
        for(int j = 0; j < set2.size; j++){
            if(*(set1.element + i) == *(set2.element + j)){
                check2 = 1;
                break;
            }
        }
        if(check2 == 0){
            check = 1;
            break;
        }
    }
    cout << endl;
    if(check == 0)
        cout << "-Set 1 is a subset of set 2" << endl;
    else
        cout << "-Set 1 is not a subset of set 2" << endl;
}

int main() {
    // Tạo và nhập dữ liệu cho tập hợp 1
    IntegerSet set1;
    int size1;
    cout << "Nhap so phan tu cua tap hop 1: ";
    cin >> size1;
    creatSet(set1, size1);
    cout << "Nhap tap hop 1: ";
    inputSet(set1);

    // Tạo và nhập dữ liệu cho tập hợp 2
    IntegerSet set2;
    int size2;
    cout << "Nhap so phan tu cua tap hop 2: ";
    cin >> size2;
    creatSet(set2, size2);
    cout << "Nhap tap hop 2: ";
    inputSet(set2);

    // // Tạo và nhập dữ liệu cho tập hợp 1
    // IntegerSet set1;
    // creatSet(set1, 5); // Tạo một tập hợp với 5 phần tử
    // set1.element[0] = 1;
    // set1.element[1] = 2;
    // set1.element[2] = 3;
    // set1.element[3] = 4;
    // set1.element[4] = 5;

    // // Tạo và nhập dữ liệu cho tập hợp 2
    // IntegerSet set2;
    // creatSet(set2, 5); // Tạo một tập hợp với 5 phần tử
    // set2.element[0] = 4;
    // set2.element[1] = 5;
    // set2.element[2] = 6;
    // set2.element[3] = 7;
    // set2.element[4] = 8;

    // Gọi các hàm thực hiện các phép toán tập hợp
    cout << "Union of set1 and set2: ";
    unionSet(set1, set2);

    cout << "Intersection of set1 and set2: ";
    intersectionSet(set1, set2);

    cout << "Difference of set1 and set2: ";
    differenceSet(set1, set2);

    cout << "Is set1 a subset of set2? ";
    subsetSet(set1, set2);

    // Giải phóng bộ nhớ của các tập hợp
    delete[] set1.element;
    delete[] set2.element;

    return 0;
}
