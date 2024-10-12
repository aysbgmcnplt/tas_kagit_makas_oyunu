#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ta�, Ka��t, Makas i�in sabitler
#define TAS 0
#define KAGIT 1
#define MAKAS 2

// Kullan�c� ve bilgisayar se�imlerini yazd�rmak i�in fonksiyon
const char* secimAdlari(int secim) {
    switch (secim) {
        case TAS:
            return "Tas";
        case KAGIT:
            return "Kagit";
        case MAKAS:
            return "Makas";
        default:
            return "Bilinmeyen";
    }
}

// Oyunun sonucunu belirlemek i�in fonksiyon
void sonucBelirle(int kullaniciSecimi, int bilgisayarSecimi) {
    if (kullaniciSecimi == bilgisayarSecimi) {
        printf("Berabere! Her ikisi de %s secti.\n", secimAdlari(kullaniciSecimi));
    } else if ((kullaniciSecimi == TAS && bilgisayarSecimi == MAKAS) ||
               (kullaniciSecimi == KAGIT && bilgisayarSecimi == TAS) ||
               (kullaniciSecimi == MAKAS && bilgisayarSecimi == KAGIT)) {
        printf("Kazandiniz! Siz %s sectiniz, bilgisayar %s secti.\n", secimAdlari(kullaniciSecimi), secimAdlari(bilgisayarSecimi));
    } else {
        printf("Kaybettiniz. Siz %s sectiniz, bilgisayar %s secti.\n", secimAdlari(kullaniciSecimi), secimAdlari(bilgisayarSecimi));
    }
}

int main() {
    int kullaniciSecimi;
    int bilgisayarSecimi;

    // Rastgele say� �reticisini ba�lat
    srand(time(NULL));

    while (1) {
        // Kullan�c�dan se�im al
        printf("Tas (0), Kagit (1), Makas (2) secin (Cikmak icin 3): ");
        scanf("%d", &kullaniciSecimi);

        if (kullaniciSecimi == 3) {
            printf("Oyun bitti.\n");
            break;
        } else if (kullaniciSecimi < 0 || kullaniciSecimi > 2) {
            printf("Gecersiz secim! L�tfen tekrar deneyin.\n");
            continue;
        }

        // Bilgisayar�n se�imi
        bilgisayarSecimi = rand() % 3;

        // Se�imleri ve sonucu yazd�r
        printf("Siz: %s, Bilgisayar: %s\n", secimAdlari(kullaniciSecimi), secimAdlari(bilgisayarSecimi));
        sonucBelirle(kullaniciSecimi, bilgisayarSecimi);
    }

    return 0;
}

