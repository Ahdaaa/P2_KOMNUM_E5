
# P2_Komnum_E5

Anggota Kelompok 5 :
  1. Ahda Filza Ghaffaru, 5025211144
  2. Muhammad Rafi Insan Fillah, 5025211169
  3. Muhammad Rafi Sutrisno, 5025211167

Referensi : 
https://towardsdatascience.com/numerical-integration-romberg-integration-3f54002ab538
https://math.stackexchange.com/questions/3088392/romberg-integration-relative-error

Screenshot Jalannya Program:
![image](https://user-images.githubusercontent.com/99827242/209153853-178aa6e1-ee55-4e83-81c8-d815c84f769b.png)


Penjelasan Singkat:

1. Fungsi yang kami buat ada 5 yang pertama fungsi untuk Integral yang kami gunakan adalah : " 1.75x<sup>1.75</sup> ", lalu fungsi doubleEquals untuk mengecek apakah hasil iterasi ke N sama dengan hasil iterasi ke N-1, yang kedua adalah fungsi getH untuk mendapatkan h yang digunakan pada fungsi CTR, lalu ada fungsi romberg, dan fungsi CTR. 
2. Langkah pertama adalah memasukkan batas2 integral dan iterasi yang diinginkan.
3. Lalu looping barisnya sebanyak iterasi karena banyak baris matriks nya pasti sebesar iterasinya.
4. Lalu kami nestedLoop didalam looping baris tadi sebagai kolomnya dengan batas kolomnya sama dengan barisnya.
5. Lalu disetiap isi looping kolom kami cek jika kolom index nya 1 maka gunakan fungsi CTR, jika kolom lebih dari 1 gunakan fungsi romberg dan masukkan hasilnya ke dalam vector.
6. Lalu pada setiap looping baris kami cek apakah hasil iterasi ke N sama dengan hasil iterasi ke N-1 dengan fungsi doubleEquals, jika benar sama maka akan langsung kami break karena hasil setelahnya akan tetap sama dan jika terus dilanjutkan hanya akan membuang-buang waktu compiling.
7. Setelah looping selesai maka hasilnya adalah ada pada nilai di index terakhir vector. lalu print nilai tersebut.
