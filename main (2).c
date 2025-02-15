#include <stdio.h>
#include <math.h>

#define MAHALLE_SAYISI 3
#define KRITER_SAYISI 5

// Softmax hesaplama fonksiyonum
void softmax(double puanlar[], double sonuc[], int n) {
    double toplam = 0.0;
    for (int i = 0; i < n; i++) {
        sonuc[i] = exp(puanlar[i]);
        toplam += sonuc[i];
    }
    for (int i = 0; i < n; i++) {
        sonuc[i] /= toplam;
    }
}

int main() {
    // Kriter aðýrlýklarý
    double agirliklar[KRITER_SAYISI] = {0.3, 0.2, 0.2, 0.15, 0.15};
    
    // Mahalle isimleri
    char *mahalleler[MAHALLE_SAYISI] = {"Ä°stasyon Mahallesi", "DemirtaÅŸ Mahallesi", "KarahÄ±dÄ±r Mahallesi"};
    
    // Kullanýcýdan kriter deðerlerini alma
    double kriterler[MAHALLE_SAYISI][KRITER_SAYISI];
    for (int i = 0; i < MAHALLE_SAYISI; i++) {
        printf("%s için kriterleri girin (Nüfus Yoðunluðu, Ulaþým Altyapýsý, Maliyet, çevresel Etki, Sosyal Fayda):\n", mahalleler[i]);
        for (int j = 0; j < KRITER_SAYISI; j++) {
            scanf("%lf", &kriterler[i][j]);
        }
    }
    
    // Toplam puan hesaplama
    double toplamPuanlar[MAHALLE_SAYISI];
    for (int i = 0; i < MAHALLE_SAYISI; i++) {
        toplamPuanlar[i] = 0;
        for (int j = 0; j < KRITER_SAYISI; j++) {
            toplamPuanlar[i] += kriterler[i][j] * agirliklar[j];
        }
    }
    
    // Softmax puanlarýný hesaplama
    double softmaxPuanlar[MAHALLE_SAYISI];
    softmax(toplamPuanlar, softmaxPuanlar, MAHALLE_SAYISI);
    
    // Sonuçlarý yazdýrma
    printf("\nMahallelerin Softmax Puanlarý:\n");
    int enUygunIndex = 0;
    for (int i = 0; i < MAHALLE_SAYISI; i++) {
        printf("%s: %.4f\n", mahalleler[i], softmaxPuanlar[i]);
        if (softmaxPuanlar[i] > softmaxPuanlar[enUygunIndex]) {
            enUygunIndex = i;
        }
    }
    
    printf("\nEn uygun güzergah: %s\n", mahalleler[enUygunIndex]);
    return 0;
}
