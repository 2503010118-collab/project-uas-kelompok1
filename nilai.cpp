#include "nilai.h"

StackNilai::StackNilai() {
    top = -1;
}

bool StackNilai::isEmpty() {
    return top == -1;
}

bool StackNilai::isFull() {
    return top == MAX_NILAI - 1;
}

void StackNilai::inputNilai() {
    if (isFull()) {
        cout << "Stack penuh!\n";
        return;
    }

    top++;

    cout << "\n=== Input Nilai ===\n";
    cout << "NIS : ";
    cin >> stack[top].nis;

    cin.ignore();

    cout << "Mata Pelajaran : ";
    getline(cin, stack[top].mataPelajaran);

    cout << "Nilai : ";
    cin >> stack[top].nilai;

    cout << "Data berhasil ditambahkan.\n";
}

void StackNilai::tampilkanNilai() {
    if (isEmpty()) {
        cout << "\nData nilai kosong.\n";
        return;
    }

    cout << "\n=== Data Nilai ===\n";

    for (int i = top; i >= 0; i--) {
        cout << "NIS            : " << stack[i].nis << endl;
        cout << "Mata Pelajaran : " << stack[i].mataPelajaran << endl;
        cout << "Nilai          : " << stack[i].nilai << endl;
        cout << "--------------------------\n";
    }
}

void StackNilai::editNilai() {
    if (isEmpty()) {
        cout << "\nData nilai kosong.\n";
        return;
    }

    string nisCari;
    string mapelCari;

    cout << "\nMasukkan NIS : ";
    cin >> nisCari;

    cin.ignore();

    cout << "Masukkan Mata Pelajaran : ";
    getline(cin, mapelCari);

    bool ditemukan = false;

    for (int i = 0; i <= top; i++) {
        if (stack[i].nis == nisCari &&
            stack[i].mataPelajaran == mapelCari) {

            cout << "Nilai lama : " << stack[i].nilai << endl;
            cout << "Nilai baru : ";
            cin >> stack[i].nilai;

            cout << "Data berhasil diubah.\n";
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Data tidak ditemukan.\n";
    }
}
