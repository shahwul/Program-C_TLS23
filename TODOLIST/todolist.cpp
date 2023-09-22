#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Struct untuk merepresentasikan tugas
struct Tugas {
    string deskripsi;
};

int main() {
    vector<Tugas> toDoList;  // Vektor untuk menyimpan tugas
    
    while (true) {
        int choice;
        cout << "\nDaftar Tugas:\n";
            for (size_t i = 0; i < toDoList.size(); ++i) {
                cout << i + 1 << ". " << toDoList[i].deskripsi << "\n";
            }

        cout << "\nAplikasi To-Do List by Syahrul\n";
        cout << "1. Tambah Tugas\n";
        cout << "2. Hapus Tugas\n";
        cout << "3. Tampilkan Tugas Tersimpan\n";
        cout << "4. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        if (choice == 1) {
            Tugas newTask;
            cin.ignore();  // Membersihkan newline karakter dari buffer
            cout << "Masukkan deskripsi tugas: ";
            getline(cin, newTask.deskripsi);
            toDoList.push_back(newTask);
            system("cls");
            cout << "Tugas berhasil ditambahkan.\n";
        } else if (choice == 2) {
            int index;
            cout << "Masukkan nomor tugas yang akan dihapus: ";
            cin >> index;

            if (index >= 1 && index <= static_cast<int>(toDoList.size())) {
                toDoList.erase(toDoList.begin() + index - 1);
                system("cls");
                cout << "Tugas berhasil dihapus.\n";
            } else {
                system("cls");
                cout << "Nomor tugas tidak valid.\n";
            }
        } else if (choice == 3) {
            fstream dia;
            dia.open("temp.txt",ios::in);
             if (dia.is_open()){
             Tugas temp;
             while (getline(dia,temp.deskripsi)){
                toDoList.push_back(temp);
             }
            }
            system("cls");
            cout << "Tugas berhasil dimuat.\n";
            dia.close();
        } else if (choice == 4) {
            system("cls");
            cout << "\nTerima Kasih!!!";
            break;
        } else {
            system("cls");
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    }

    ofstream akuu;
    akuu.open("File.txt");
        for (size_t i = 0; i < toDoList.size(); ++i) {
                akuu << i + 1 << ". " << toDoList[i].deskripsi << "\n";
            }
    akuu.close();
    
    akuu.open("temp.txt");
        for (size_t i = 0; i < toDoList.size(); ++i) {
                akuu << toDoList[i].deskripsi << "\n";
            }
    akuu.close();
    
    return 0;
}
