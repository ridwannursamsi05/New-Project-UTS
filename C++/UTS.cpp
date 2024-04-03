#include <iostream>
#include <string>

using namespace std;
// Garis
void garis (){
    cout << "=============================" << endl;
}

// Untuk menyimpan informasi tugas
struct Task {
    string nama;
    bool tselesai;
    Task* next;

    Task() : tselesai(false), next(nullptr) {} // konstruktor
};

// Penerapan linked list
class TaskManager {
private:
    Task* head; // Pointer ke Head untuk save data

public:
    TaskManager() : head(nullptr) {} // konstruktor
    // Menambahkan tugas baru ke save data
    void addTask(string name) {
        Task* newTask = new Task;
        newTask->nama = name;
        newTask->next = head;
        head = newTask;
        cout << ">> Tugas \"" << name << "\" berhasil ditambahkan ! <<" << endl;
    }

    // Menampilkan semua tugas yang ada dalam save data
    void displayTasks() {
        if (!head) {
            cout << ">> Tidak ada tugas yang tersimpan ! <<" << endl;
            return;
        }
        Task* current = head;
        while (current) { // Menandai Selesai
            cout << "- " << current->nama;
            if (current->tselesai) {
                cout << " (Selesai)";
            }
            cout << endl;
            current = current->next;
        }
    }

    // Mengkonfirmasi tugas telah selesai sesuai dengan nama
    void completeTask(string name) {
        Task* current = head;
        while (current) {
            if (current->nama == name) {
                current->tselesai = true;
                cout << ">> Tugas \"" << name << "\" telah ditandai sebagai selesai ! <<" << endl;
                return;
            }
            current = current->next;
        }
        cout << ">> Tugas \"" << name << "\" tidak ditemukan ! <<" << endl;
        cout << ">> Pastikan Data Tugas Tersedia/Tersimpan ! <<" << endl;
    }

    // Menghapus tugas sesuai nama
    void deleteTask(string name) {
        Task* current = head;
        Task* prev = nullptr;
        while (current) {
            if (current->nama == name) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                delete current;
                cout << ">> Tugas \"" << name << "\" berhasil dihapus ! <<" << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << ">> Tugas \"" << name << "\" tidak ditemukan ! <<" << endl;
        cout << ">> Pastikan Data Tugas Tersedia/Tersimpan ! <<" << endl;
    }

    // Destruktor untuk membersihkan memori yang dialokasikan
    ~TaskManager() {
        Task* current = head;
        while (current) {
            Task* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

// Program Utama
int main() {
    string tasksLimit[10]; // Patokan ubah limit
    int currentSize = 0;

    TaskManager taskManager;
    int choice;
    string taskName;

    do {
        cout << endl;
        garis();
        cout << "============ MENU ===========\n"; // Menu
        garis();
        cout << "1. Tambah Tugas\n";
        cout << "2. Tampilkan Tugas\n";
        cout << "3. Simpan Data Tugas\n";
        cout << "4. Tandai Sebagai Selesai\n";
        cout << "5. Hapus Tugas\n";
        cout << "6. Ubah Batas\n";
        cout << "7. Keluar\n";
        garis();
        cout << "Pilih Menu : ";
        cin >> choice;
        system("cls"); // Menghilangkan Tampilan Output ketika sudah selesai digunakan
        cout << endl;

        switch (choice) {
            case 1: // Menambah Data
                if (currentSize >= 10) { // Penggunaan Array untuk simpan data sementara
                    cout << "Tidak dapat menambahkan lebih banyak tugas. Batas maksimum tercapai." << endl;
                } else {
                    cout << "======= Masukan Tugas =======" << endl;
                    cout << "Nama Tugas : ";
                    cin >> taskName;
                    tasksLimit[currentSize] = taskName;
                    currentSize++;
                    system("cls");
                    cout << endl << ">> Tugas \"" << taskName << "\" berhasil ditambahkan ! <<" << endl;
                }
                break;
            case 2: // Tampilan Data
                cout << "======== List Tugas: ========" << endl;
                if (currentSize == 0) {
                    cout << ">> Tidak ada tugas yang tersedia ! <<" << endl;
                } else {
                    for (int i = 0; i < currentSize; ++i) {
                    cout << "- " << tasksLimit[i] << endl;
                    }
                }
                cout << endl;
                cout << "=== List Tugas Tersimpan: ===" << endl;
                taskManager.displayTasks();
                break;
            case 3: // Save Data
                if (currentSize == 0) {
                    cout << ">> Tidak ada tugas yang tersedia untuk disimpan ! <<" << endl;
                } else {
                    for (int i = 0; i < currentSize; ++i) {
                        taskManager.addTask(tasksLimit[i]);
                    }
                    currentSize = 0;
                    cout << ">> Data berhasil disimpan ! <<" << endl;
                }
                break;
            case 4: // Menandai Data
                cout << "=== Masukan Tugas Yang Sudah Selesai ===\n";
                cout << "Nama Tugas : ";
                cin >> taskName;
                system ("cls");
                taskManager.completeTask(taskName);
                break;
            case 5: // Menghapus Data
                cout << "=== Masukan Tugas Yang Ingin Dihapus ===\n";
                cout << "Nama Tugas : ";
                cin >> taskName;
                system ("cls");
                taskManager.deleteTask(taskName);
                break;
            case 6: // Mengubah Limit Data
                int newSize;
                cout << "=== Masukan Batas Penyimpanan Data ===\n";
                cout << "Masukan Batas : ";
                cin >> newSize;
                system ("cls");
                if (newSize > 0) {
                    tasksLimit[10] = {};
                    currentSize = 0;
                    cout << ">> Batas Data Berhasil Diubah Menjadi " << newSize << " ! <<" << endl;
                } else {
                    cout << ">> Ukuran Data Harus Lebih Besar Dari 0 ! <<" << endl;
                }
                break;
            case 7: // Keluar
                cout << "===================" << endl;
                cout << "== Terima Kasih ==" << endl;
                cout << "===================" << endl;
                break;
            default:
                cout << "============================================" << endl;
                cout << "== Pilihan tidak valid! Silakan coba lagi ==" << endl;
                cout << "============================================" << endl;
                break;
        }
    } while (choice != 7);

    return 0;
}