/**
 * @file uas.cpp
 * @author Muhammad Naufal Ghulam F
 * @brief 
 * @version 0.1
 * @date 2024-06-24
 * 
 */



#include <iostream>
using namespace std;

/**
 * @class MataKuliah
 * @brief Kelas abstrak untuk mata kuliah umum
 */
class MataKuliah {
private:
    float presensi;
    float activity;
    float exercise;
    float tugasAkhir;

public:
    /**
     * @brief Konstruktor default untuk kelas MataKuliah
     */
    MataKuliah() : presensi(0), activity(0), exercise(0), tugasAkhir(0) {}

    /**
     * @brief Setter untuk nilai presensi
     * @param nilai Nilai presensi
     */
    void setPresensi(float nilai) {
        presensi = nilai;
    }

    /**
     * @brief Getter untuk nilai presensi
     * @return Nilai presensi
     */
    float getPresensi() const {
        return presensi;
    }

    /**
     * @brief Setter untuk nilai activity
     * @param nilai Nilai activity
     */
    void setActivity(float nilai) {
        activity = nilai;
    }

    /**
     * @brief Getter untuk nilai activity
     * @return Nilai activity
     */
    float getActivity() const {
        return activity;
    }

    /**
     * @brief Setter untuk nilai exercise
     * @param nilai Nilai exercise
     */
    void setExercise(float nilai) {
        exercise = nilai;
    }

    /**
     * @brief Getter untuk nilai exercise
     * @return Nilai exercise
     */
    float getExercise() const {
        return exercise;
    }

    /**
     * @brief Setter untuk nilai tugas akhir
     * @param nilai Nilai tugas akhir
     */
    void setTugasAkhir(float nilai) {
        tugasAkhir = nilai;
    }

    /**
     * @brief Getter untuk nilai tugas akhir
     * @return Nilai tugas akhir
     */
    float getTugasAkhir() const {
        return tugasAkhir;
    }

    /**
     * @brief Metode virtual untuk mendapatkan nama mata kuliah
     */
    virtual void namaMataKuliah() const = 0;

    /**
     * @brief Metode virtual untuk input nilai
     */
    virtual void inputNilai() = 0;

    /**
     * @brief Metode virtual untuk menghitung nilai akhir
     * @return Nilai akhir
     */
    virtual float hitungNilaiAkhir() const = 0;

    /**
     * @brief Metode virtual untuk mengecek kelulusan
     */
    virtual void cekKelulusan() const = 0;
};

/**
 * @class Pemrograman
 * @brief Kelas turunan untuk mata kuliah Pemrograman
 */
class Pemrograman : public MataKuliah {
public:
    /**
     * @brief Menampilkan nama mata kuliah
     */
    void namaMataKuliah() const override {
        cout << "Mata Kuliah: Pemrograman" << endl;
    }

    /**
     * @brief Input nilai untuk mata kuliah Pemrograman
     */
    void inputNilai() override {
        float nilai;
        cout << "Masukkan nilai presensi: ";
        cin >> nilai;
        setPresensi(nilai);

        cout << "Masukkan nilai activity: ";
        cin >> nilai;
        setActivity(nilai);

        cout << "Masukkan nilai exercise: ";
        cin >> nilai;
        setExercise(nilai);

        cout << "Masukkan nilai tugas akhir: ";
        cin >> nilai;
        setTugasAkhir(nilai);
    }

    /**
     * @brief Menghitung nilai akhir untuk mata kuliah Pemrograman
     * @return Nilai akhir
     */
    float hitungNilaiAkhir() const override {
        return (getPresensi() * 0.1) + (getActivity() * 0.2) + (getExercise() * 0.3) + (getTugasAkhir() * 0.4);
    }

    /**
     * @brief Mengecek kelulusan berdasarkan nilai akhir
     */
    void cekKelulusan() const override {
        float nilaiAkhir = hitungNilaiAkhir();
        cout << "Nilai Akhir: " << nilaiAkhir << endl;
        if (nilaiAkhir >= 75) {
            cout << "Selamat Anda dinyatakan Lulus" << endl;
        } else {
            cout << "Anda dinyatakan Tidak Lulus" << endl;
        }
    }
};

/**
 * @class Jaringan
 * @brief Kelas turunan untuk mata kuliah Jaringan
 */
class Jaringan : public MataKuliah {
public:
    /**
     * @brief Menampilkan nama mata kuliah
     */
    void namaMataKuliah() const override {
        cout << "Mata Kuliah: Jaringan" << endl;
    }

    /**
     * @brief Input nilai untuk mata kuliah Jaringan
     */
    void inputNilai() override {
        float nilai;
        cout << "Masukkan nilai activity: ";
        cin >> nilai;
        setActivity(nilai);

        cout << "Masukkan nilai exercise: ";
        cin >> nilai;
        setExercise(nilai);
    }

    /**
     * @brief Menghitung nilai akhir untuk mata kuliah Jaringan
     * @return Nilai akhir
     */
    float hitungNilaiAkhir() const override {
        return (getActivity() * 0.6) + (getExercise() * 0.4);
    }

    /**
     * @brief Mengecek kelulusan berdasarkan nilai akhir
     */
    void cekKelulusan() const override {
        float nilaiAkhir = hitungNilaiAkhir();
        cout << "Nilai Akhir: " << nilaiAkhir << endl;
        if (nilaiAkhir >= 75) {
            cout << "Selamat Anda dinyatakan Lulus" << endl;
        } else {
            cout << "Anda dinyatakan Tidak Lulus" << endl;
        }
    }
};

int main() {
    char pilih;
    MataKuliah *mataKuliah;
    Pemrograman pemrograman;
    Jaringan jaringan;

    while (true) {
        cout << "Pilih Mata Kuliah:" << endl;
        cout << "1. Pemrograman" << endl;
        cout << "2. Jaringan" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == '1') {
            mataKuliah = &pemrograman;
        } else if (pilih == '2') {
            mataKuliah = &jaringan;
        } else if (pilih == '3') {
            break;
        } else {
            cout << "Pilihan tidak ada. Silakan coba lagi." << endl;
            continue;
        }


        mataKuliah->inputNilai();
        mataKuliah->cekKelulusan();
       

        cout << endl;
    }

    return 0;
}