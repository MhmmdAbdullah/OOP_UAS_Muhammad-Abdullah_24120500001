# FC Cakrawala Muda - Penerapan Factory Method Pattern dalam C++

## 📌 Deskripsi Umum

Proyek ini merupakan simulasi program C++ berbasis Object-Oriented Programming (OOP) untuk manajemen tim sepak bola **FC Cakrawala Muda**, klub binaan Universitas Cakrawala untuk kelompok umur U-23.

Program ini:
1. Mengimplementasikan hubungan antar kelas sesuai dengan **desain OOP** dan **UML Class Diagram**.
2. Menerapkan **pola desain Factory Method** untuk pembuatan objek dinamis (`Coach`, `Player`, `Staff`).
3. Mempunyai sistem input/output interaktif untuk menambah dan menampilkan anggota tim.

---

## ✅ Soal 1 – Implementasi Kode Sesuai Deskripsi FC Cakrawala

### Struktur Tim:
- 1 orang **Head Coach**
- 1 orang **Assistant Coach**
- 15 orang **Player**
- (opsional) beberapa **Staff** pendukung

Program ini memungkinkan user untuk menginput data secara dinamis sesuai struktur tersebut, dan menampilkannya kembali.

---

## ✅ Soal 2 – Perbaikan UML dengan Pola Factory Method

Diagram UML telah diperbaiki agar sesuai dengan **Factory Method Pattern**, dengan komponen utama sebagai berikut:

### 📦 Class Hierarchy:
- `Person` *(abstract class)* ➝ base class untuk semua peran
- Subclass:
  - `Coach`
  - `Player`
  - `Staff`

### 🏭 Factory Classes:
- Interface: `PersonFactory` *(abstract factory)*
- Implementasi:
  - `CoachFactory`
  - `PlayerFactory`
  - `StaffFactory`

Setiap factory bertanggung jawab menciptakan objek turunannya masing-masing dengan menyembunyikan proses instansiasi dari pengguna (decoupled creation).

Diagram UML dapat dilihat di folder `uml_diagram.png`.

---

## ✅ Soal 3 – Revisi Kode agar Sesuai dengan UML Factory Method

Program utama (`main.cpp`) telah diperbarui agar sesuai dengan diagram UML dan menerapkan **Factory Method Pattern** dengan benar.

Struktur class dan dependency-nya telah mengikuti relasi inheritance dan interface seperti yang ditampilkan dalam diagram UML.

---

## 🔧 Cara Menjalankan Program

### Compile (C++14 atau lebih tinggi):
```bash
g++ -std=c++14 -o fc_cakrawala fc_cakrawala_factory_method.cpp
