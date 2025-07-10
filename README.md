# FC Cakrawala Muda - Factory Method Implementation in C++

Proyek ini adalah simulasi berbasis C++ dari struktur organisasi tim sepak bola **FC Cakrawala Muda**, sebuah klub binaan Universitas Cakrawala yang memiliki tim U-23. Program ini dirancang menggunakan **Object-Oriented Programming (OOP)** dan menerapkan **Factory Method Pattern**.

## 🧠 Tujuan
- Menerapkan konsep inheritance, polymorphism, dan abstract class di C++.
- Menggunakan pola desain **Factory Method** untuk menciptakan objek `Coach`, `Player`, dan `Staff`.
- Memberikan antarmuka input sederhana yang memungkinkan pengguna menambahkan data tim secara interaktif.

---

## 🏗️ Struktur Kelas

### 1. Abstract Class: `Person`
Mewakili entitas umum dalam tim (Coach, Player, Staff).  
Berisi atribut:
- `name` : string
- `age` : int  
Dan method virtual:
- `displayRole()` (pure virtual)

### 2. Subclass:
- `Coach` (punya atribut `license`)
- `Player` (punya atribut `number`, `position`)
- `Staff` (punya atribut `role`)

### 3. Factory Pattern:
- Interface: `PersonFactory`  
- Concrete Factories:
  - `CoachFactory`
  - `PlayerFactory`
  - `StaffFactory`  
Setiap factory bertugas membuat instance dari subclass `Person` yang sesuai.

---

## 🚀 Cara Menjalankan

### ✅ Compile dengan G++
```bash
g++ -std=c++14 -o fc_cakrawala main.cpp
